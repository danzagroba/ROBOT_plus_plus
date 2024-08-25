#include "Fase.hpp"
#include "json.hpp"
#include "Gumbot.hpp"
#include "Agua.hpp"
#include "ProjectileBot.hpp"

#include <iostream>
#include <fstream>

namespace Fases
{
    float Fase::gravidade(0.01);

    Fase::Fase(const char* caminho, 
               Gerenciadores::Gerenciador_Grafico* pGG, 
               Gerenciadores::Gerenciador_Colisoes* pCO, 
               Entidades::Personagens::Jogador* jgdr,
               Entidades::Personagens::Jogador* jgdrdois, 
               float comprimento)
        : Ente(),
          gerGraf(pGG), 
          gerColisoes(pCO),
          comprimentoTile(comprimento),
          altura(0),
          largura(0),
          tiles(NULL),
          entidades()
    {
        if(jgdr)
            entidades.inserirNoFim(static_cast<Entidade*>(jgdr));
        if(jgdrdois)
            entidades.inserirNoFim(static_cast<Entidade*>(jgdrdois));

        if(gerColisoes)
        {
            gerColisoes->inserirJogadores(jgdr);
            if(jgdrdois)
                gerColisoes->inserirJogadores(jgdrdois);
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

        entidades.removerDoInicio();
        if(Entidades::Personagens::Jogador::getdoisjogadores())
            entidades.removerDoInicio();

        for(Listas::Lista<Entidade*>::Iterator it = entidades.inicio(); it != entidades.fim(); ++it)
        {
            delete *it;
        }

        entidades.limpar();
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

    void Fase::criarEntidades()
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
                    {
                        posicaoFinal = sf::Vector2i(j, i);
                    }
                    else
                    {
                        posicaoInicial = sf::Vector2i(j, i);
                        eraMuro = true;
                    } 
                }
                else
                {
                    if(getTile(j, i) == 2)
                    {
                        Entidades::Obstaculos::Agua* agua = new Entidades::Obstaculos::Agua(sf::Vector2f(j*comprimentoTile, i*comprimentoTile));
                        gerColisoes->inserirObstaculos(agua);
                        entidades.inserirNoFim(static_cast<Entidade*>(agua));
                    }
                    if(eraMuro)
                    {
                        posicaoFinal = sf::Vector2i(j, i+1);
                        sf::Vector2f posicao((float)posicaoInicial.x*comprimentoTile, (float)posicaoInicial.y*comprimentoTile);
                        sf::Vector2f dimensoes((float)(posicaoFinal.x-posicaoInicial.x)*comprimentoTile, (float)(posicaoFinal.y-posicaoInicial.y)*comprimentoTile);

                        Obstaculo* pobstaculo = new Entidades::Obstaculo(posicao, dimensoes);
                        gerColisoes->inserirObstaculos(pobstaculo);
                        entidades.inserirNoFim(static_cast<Entidade*>(pobstaculo));
                    }
                    eraMuro = false;
                }
            }

            if(eraMuro)
            {
                posicaoFinal = sf::Vector2i(j, i+1);
                sf::Vector2f posicao((float)posicaoInicial.x*comprimentoTile, (float)posicaoInicial.y*comprimentoTile);
                sf::Vector2f dimensoes((float)(posicaoFinal.x-posicaoInicial.x)*comprimentoTile, (float)(posicaoFinal.y-posicaoInicial.y)*comprimentoTile);

                Obstaculo* pobstaculo = new Entidades::Obstaculo(posicao, dimensoes);
                gerColisoes->inserirObstaculos(pobstaculo);
                entidades.inserirNoFim(static_cast<Entidade*>(pobstaculo));
            }
            eraMuro = false;
            
        }

        Obstaculo* obstaculo = new Entidades::Obstaculo(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(comprimentoTile, altura*comprimentoTile));
        gerColisoes->inserirObstaculos(obstaculo);
        entidades.inserirNoFim(static_cast<Entidade*>(obstaculo));

        obstaculo = new Entidades::Obstaculo(sf::Vector2f((float)(largura-1)*comprimentoTile, 0.0f), sf::Vector2f(comprimentoTile, altura*comprimentoTile));
        gerColisoes->inserirObstaculos(obstaculo);
        entidades.inserirNoFim(static_cast<Entidade*>(obstaculo));
        
        Gumbot* pgumbot = new Gumbot(sf::Vector2f(25.0f, 25.0f));
        gerColisoes->inserirInimigos(pgumbot);
        entidades.inserirNoFim(static_cast<Entidade*>(pgumbot));

        ProjectileBot* pprojectilebot = new ProjectileBot(sf::Vector2f(4.0f*comprimentoTile, 25.0f));
        gerColisoes->inserirInimigos(pprojectilebot);
        entidades.inserirNoFim(static_cast<Entidade*>(pprojectilebot));
        gerColisoes->inserirProjetil(pprojectilebot->getProjetil());
        entidades.inserirNoFim(static_cast<Entidade*>(pprojectilebot->getProjetil()));

        std::cout<<"gumbot criado"<<endl;
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

    const bool Fase::mapaCarregado() const
    {
        return tiles != nullptr;
    }

    void Fase::executar()
    {
        desenhar();
        desenharVidas();
        entidades.executar();
        gerColisoes->checarColisoesObstaculos();
        entidades.desenhar();
    }
}