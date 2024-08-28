#include "Fase.hpp"
#include "json.hpp"
#include "Gumbot.hpp"
#include "Agua.hpp"
#include "ProjectileBot.hpp"
#include "Plataforma.hpp"
#include "Gerenciador_Grafico.hpp"
#include "Gerenciador_Colisoes.hpp"
#include "Gerenciador_Estados.hpp"
#include "Gerenciador_Eventos.hpp"
#include "Gerenciador_Inputs.hpp"
#include "Jogador.hpp"

#include <iostream>
#include <fstream>

using namespace std;

namespace Fases
{
    float Fase::gravidade(0.01);

    Fase::Fase(const char* caminho, float comprimento)
        : Ente(),
          gerGraf(Gerenciador_Grafico::getGerenciador_Grafico()), 
          gerColisoes(Gerenciador_Colisoes::getGerenciador_Colisoes()),
          gerInputs(Gerenciador_Inputs::getGerenciador_Inputs()),
          gerEventos(Gerenciador_Eventos::getGerenciador_Eventos()),
          gerEstados(Gerenciador_Estados::getGerenciador_Estados()),
          comprimentoTile(comprimento),
          altura(0),
          largura(0),
          tiles(NULL),
          entidades(),
          pjogadorum(new Entidades::Jogador(sf::Vector2f(0.0f, 0.0f), 3, sf::Vector2f(25.0f, 25.0f), "../assets/heart1.png")),
        pjogadordois(Entidades::Jogador::getdoisjogadores() ? new Entidades::Jogador(sf::Vector2f(0.0f, 0.0f), 3, sf::Vector2f(25.0f, 25.0f), "../assets/heart2.png") : NULL)
    {
        if(gerColisoes)
        {
            pjogadorum->setFigura(SPRITE_PATHP1);
            gerColisoes->inserirJogadores(pjogadorum);
            entidades.inserirNoFim(pjogadorum);

            gerInputs->vincularcomando(sf::Keyboard::W, std::bind(&Personagem::pulo, pjogadorum));
            gerInputs->vincularcomando(sf::Keyboard::A, std::bind(&Personagem::setXvel, pjogadorum,(-0.1)));
            gerInputs->vincularcomando(sf::Keyboard::D, std::bind(&Personagem::setXvel, pjogadorum,(0.1)));
            gerInputs->vincularcomandoTeclaSolta(sf::Keyboard::W, std::bind(&Personagem::permitirPulo, pjogadorum));

            if(Entidades::Jogador::getdoisjogadores())
            {
                if(pjogadordois==NULL)
                {
                    cerr<<"Erro ao alocar jogador dois"<<endl;
                    exit(1);
                }
                else
                {
                    pjogadordois->setFigura(SPRITE_PATHP2);
                    gerColisoes->inserirJogadores(pjogadordois);
                    entidades.inserirNoFim(pjogadordois);
                    gerInputs->vincularcomando(sf::Keyboard::Up, std::bind(&Personagem::pulo, pjogadordois));
                    gerInputs->vincularcomando(sf::Keyboard::Left, std::bind(&Personagem::setXvel, pjogadordois,(-0.1)));
                    gerInputs->vincularcomando(sf::Keyboard::Right, std::bind(&Personagem::setXvel, pjogadordois,(0.1)));
                    gerInputs->vincularcomandoTeclaSolta(sf::Keyboard::Up, std::bind(&Personagem::permitirPulo, pjogadordois));
                }
            }
        }

        if(caminho)
            carregar(caminho);

        Textura.loadFromFile("../assets/stoneBrick.png");
        Figura.setTexture(Textura);
        Figura.setScale(comprimentoTile / Textura.getSize().x, comprimentoTile / Textura.getSize().y);
    
        Entidades::Entidade::setGravidade(gravidade);
    }

    Fase::~Fase()
    {
        destruirTiles();

        for(Listas::Lista<Entidade*>::Iterator it = entidades.inicio(); it != entidades.fim(); ++it)
        {
            delete *it;
        }

        entidades.limpar();

        std::cout << "fase destruida\n";
    }

    void Fase::destruirTiles()
    {
        if(!tiles)
            return;

        for (int i = 0; i < altura; i++)
            delete[] tiles[i];
        delete[] tiles;

        tiles = nullptr;
        altura = 0;
        largura = 0;
    }

    void Fase::criarPlataforma(const sf::Vector2i& posicaoFinal, const sf::Vector2i& posicaoInicial)
    {
        sf::Vector2f posicao((float)posicaoInicial.x*comprimentoTile, (float)posicaoInicial.y*comprimentoTile);
        sf::Vector2f dimensoes((float)(posicaoFinal.x-posicaoInicial.x)*comprimentoTile, (float)(posicaoFinal.y-posicaoInicial.y)*comprimentoTile);

        Plataforma* pobstaculo = new Plataforma(posicao, dimensoes);
        gerColisoes->inserirObstaculos(pobstaculo);
        entidades.inserirNoFim(static_cast<Entidade*>(pobstaculo));
    }

    void Fase::criarPlataformas()
    {
        if(!tiles)
            return;
        
        bool eraMuro = false;
        sf::Vector2i posicaoInicial(0, 0);
        sf::Vector2i posicaoFinal(0, 0);

        for(int i = 0; i < altura; ++i)
        {
            int j;
            for(j = 1; j < largura-1; ++j)
            {
                if(eMuro(j, i))
                {
                    if(eraMuro)
                        posicaoFinal = sf::Vector2i(j, i);
                    else
                    {
                        posicaoInicial = sf::Vector2i(j, i);
                        eraMuro = true;
                    } 
                }
                else
                {
                    if(eraMuro)
                    {
                        posicaoFinal = sf::Vector2i(j, i+1);
                        criarPlataforma(posicaoFinal, posicaoInicial);
                    }
                    eraMuro = false;
                }
            }

            if(eraMuro)
            {
                posicaoFinal = sf::Vector2i(j, i+1);
                criarPlataforma(posicaoFinal, posicaoInicial);
            }
            eraMuro = false;
        }

        Plataforma* obstaculo = new Plataforma(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(comprimentoTile, altura*comprimentoTile));
        gerColisoes->inserirObstaculos(obstaculo);
        entidades.inserirNoFim(static_cast<Entidade*>(obstaculo));

        obstaculo = new Plataforma(sf::Vector2f((float)(largura-1)*comprimentoTile, 0.0f), sf::Vector2f(comprimentoTile, altura*comprimentoTile));
        gerColisoes->inserirObstaculos(obstaculo);
        entidades.inserirNoFim(static_cast<Entidade*>(obstaculo));
    }

    void Fase::criarEntidades()
    {
        if(!tiles)
            return;
        
        criarPlataformas();

        Gumbot* pgumbot = new Gumbot(sf::Vector2f(25.0f, 25.0f));
        gerColisoes->inserirInimigos(pgumbot);
        entidades.inserirNoFim(static_cast<Entidade*>(pgumbot));

        ProjectileBot* pprojectilebot = new ProjectileBot(sf::Vector2f(4.0f*comprimentoTile, 25.0f));
        gerColisoes->inserirInimigos(pprojectilebot);
        entidades.inserirNoFim(static_cast<Entidade*>(pprojectilebot));
        //entidades.inserirNoFim(static_cast<Entidade*>());
    }

    void Fase::carregar(const char* caminho)
    {
        destruirTiles();

        std::ifstream arquivo(caminho);
        if(!arquivo.is_open())
        {
            std::cout << "Erro, mapa nao pode ser aberto\n";
            return;
        }

        nlohmann::json jsonObj;
        arquivo >> jsonObj;

        auto jsonTiles = jsonObj["tiles"];
        altura = jsonTiles.size();
        largura = jsonTiles.empty() ? 0 : jsonTiles[0].size();

        tiles = new short int*[altura];
        for(int i = 0; i < altura; i++)
        {
            tiles[i] = new short int[largura];
            for(int j = 0; j < largura; j++)
            {
                tiles[i][j] = jsonTiles[i][j];
            }
        }

        criarEntidades();
    }

    const float Fase::getComprimentoTile() const
    {
        return comprimentoTile;
    }

    const int Fase::getAltura() const
    {
        return altura;
    }

    const int Fase::getLargura() const
    {
        return largura;
    }

    void Fase::desenharVidas()
    {
        if(!gerGraf)
            return;

        int playerIndex = 0; // Player sendo processado

        for(Listas::Lista<Entidade*>::Iterator it = entidades.inicio(); it != entidades.fim(); ++it)
        {
            Entidades::Personagens::Jogador* pjogador = dynamic_cast<Entidades::Personagens::Jogador*>(*it);
            if(pjogador)
            {
                float comprimento = pjogador->getTextureVida().getSize().x;
                float offsetX;

                if (playerIndex == 0)
                    offsetX = -gerGraf->getCamera().getSize().x / 2.0f;
                else
                    offsetX = gerGraf->getCamera().getSize().x / 2.0f - comprimento * pjogador->getNumVidas();

                for(int i = 0; i < pjogador->getNumVidas(); ++i)
                {
                    pjogador->setSpriteVidaPos(sf::Vector2f(gerGraf->getCamera().getCenter().x + offsetX + i * comprimento, 
                                                            gerGraf->getCamera().getCenter().y - gerGraf->getCamera().getSize().y / 2.0f));
                    gerGraf->desenhar(pjogador->getSpriteVida());
                }

                ++playerIndex;
            }
        }
    }

    void Fase::desenhar()
    {
        if(!gerGraf || !tiles)
            return;

        int iInicial = (int)((gerGraf->getCamera().getCenter().y - gerGraf->getCamera().getSize().y / 2.0f) / comprimentoTile);
        if(iInicial < 0)
            iInicial = 0;
        
        int iFinal = (int)((gerGraf->getCamera().getCenter().y + gerGraf->getCamera().getSize().y / 2.0f) / comprimentoTile) + 1;
        if(iFinal > altura)
            iFinal = altura;

        int jInicial = (int)((gerGraf->getCamera().getCenter().x - gerGraf->getCamera().getSize().x / 2.0f) / comprimentoTile);
        if(jInicial < 0)
            jInicial = 0;

        int jFinal = (int)((gerGraf->getCamera().getCenter().x + gerGraf->getCamera().getSize().x / 2.0f) / comprimentoTile) + 1;
        if(jFinal > largura)
            jFinal = largura;
        
        for(int i = iInicial; i < iFinal; ++i)
            for(int j = jInicial; j < jFinal; ++j)
                if(eMuro(j, i))
                {
                    Figura.setPosition(j * comprimentoTile, i * comprimentoTile);
                    gerGraf->desenhar(Figura);
                }

    }
    void Fase::atualizarprojeteis()
    {
        for(list<Projetil*>::iterator it = ProjectileBot::getprojeteis()->begin(); it!= ProjectileBot::getprojeteis()->end();it++)
        {
            if(*it)
            {
                if ((*it)->getinserido()==false)
                {
                    gerColisoes->inserirProjetil(*it);
                    entidades.inserirNoFim(*it);
                    (*it)->inseridonalista();
                }
            }
        }
    }

    const bool Fase::posicaoValida(const int x, const int y) const
    {
        return tiles && x >= 0 && x < largura && y >= 0 && y < altura;
    }

    // Retorna 0 se a posição não for válida
    const short int Fase::getTile(const int x, const int y) const
    {
        if(posicaoValida(x, y))
            return tiles[y][x];
        return 0;
    }

    const bool Fase::eMuro(const int x, const int y) const
    {
        if(!posicaoValida(x, y))
            return true;
        return tiles[y][x] == 1;
    }

    void Fase::executar()
    {
        desenhar();
        desenharVidas();
        atualizarprojeteis();
        entidades.executar();
        gerColisoes->checarColisoesObstaculos();
        entidades.desenhar();
        entidades.desalocar();
    
        sf::Vector2f proxPos = Entidades::Jogador::getdoisjogadores() ? (pjogadorum->getPos()+(pjogadordois->getPos()))/2.0f : pjogadorum->getPos();
        gerGraf->setCamera(proxPos);
    }
}