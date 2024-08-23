#include "Fase.hpp"
#include "json.hpp"

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
          obstaculos(),
          jogador(jgdr),
          jogadorDois(jgdrdois),
          jogadores()
    {
        if(jgdr)
            jogadores.inserirNoFim(jgdr);
        if(jgdrdois)
            jogadores.inserirNoFim(jgdrdois);

        if(caminho)
            carregar(caminho);

        Textura.loadFromFile("../assets/stoneBrick.png");
        Figura.setTexture(Textura);
        Figura.setScale(comprimentoTile / Textura.getSize().x, comprimentoTile / Textura.getSize().y);
    }

    Fase::~Fase()
    {
        destruirTiles();

        for(Listas::Lista<Entidade*>::Iterator it = obstaculos.inicio(); it != obstaculos.fim(); ++it)
            delete *it;
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
                    if(eraMuro)
                    {
                        posicaoFinal = sf::Vector2i(j, i+1);
                        sf::Vector2f posicao((float)posicaoInicial.x*comprimentoTile, (float)posicaoInicial.y*comprimentoTile);
                        sf::Vector2f dimensoes((float)(posicaoFinal.x-posicaoInicial.x)*comprimentoTile, (float)(posicaoFinal.y-posicaoInicial.y)*comprimentoTile);
                        Obstaculo* pobstaculo = new Entidades::Obstaculo(posicao, dimensoes);
                        gerColisoes->inserirObstaculos(pobstaculo);
                        obstaculos.inserirNoFim(pobstaculo);
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
                obstaculos.inserirNoFim(pobstaculo);
            }
            eraMuro = false;
        }

        Obstaculo* obstaculo = new Entidades::Obstaculo(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(comprimentoTile, altura*comprimentoTile));
        gerColisoes->inserirObstaculos(obstaculo);
        obstaculos.inserirNoFim(obstaculo);

        obstaculo = new Entidades::Obstaculo(sf::Vector2f((float)(largura-1)*comprimentoTile, 0.0f), sf::Vector2f(comprimentoTile, altura*comprimentoTile));
        gerColisoes->inserirObstaculos(obstaculo);
        obstaculos.inserirNoFim(obstaculo);

        if(gerColisoes)
        {
            gerColisoes->setJogadores(&jogadores);
        }

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
        atualizarJogador(jogador);
        atualizarJogador(jogadorDois);
    }
    
    void Fase::gerenciarColisoes()
    {
        gerColisoes->checarColisoesObstaculos();
    }

    void Fase::atualizarJogador(Entidades::Personagens::Jogador* jog)
    {
        (jog)->aplicarForcaY(gravidade);
        jog->mover();
        jog->setXvel(0.0f);
    }
}