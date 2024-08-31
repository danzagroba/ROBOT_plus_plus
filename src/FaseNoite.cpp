#include "FaseNoite.hpp"
#include "Gumbot.hpp"
#include "Agua.hpp"
#include "ByteCrusher.hpp"
#include "Maquina_Projeteis.hpp"
#include "Plataforma.hpp"
#include "Gerenciador_Grafico.hpp"
#include "Gerenciador_Colisoes.hpp"
#include "Gerenciador_Estados.hpp"
#include "Gerenciador_Eventos.hpp"
#include "Gerenciador_Inputs.hpp"
#include "Bandeira.hpp"

#include <cstdlib>
#include <ctime>

namespace Fases
{
    FaseNoite::FaseNoite(float comprimento)
        : Fase(FASE_NOITE_PATH, comprimento),
          maxGumbots(6),
          maxByteCrushers(4),
          maxMaquinaProjeteis(6),
          maxAgua(6),
          minAguas(3),
          minGumbots(3),
          minByteCrushers(3),
          minMaquinaProjeteis(3)
    {
        criarEntidades();
    }

    FaseNoite::~FaseNoite()
    {
        std::cout << "fase Noite destruida\n";
    }

    void FaseNoite::criarGumbots()
    {
        int nGumbots = 0;

        for(int i = 0; i < altura && nGumbots < maxGumbots; ++i)
            for(int j = 0; j < largura && nGumbots < maxGumbots; ++j)
                if(getTile(j, i) == 4)
                    if(nGumbots < minGumbots || ((rand()%5) > 1))
                    {
                        Gumbot* pgumbot = new Gumbot(sf::Vector2f(j*comprimentoTile, i*comprimentoTile));
                        gerColisoes->inserirInimigos(pgumbot);
                        entidades.inserirNoFim(static_cast<Entidade*>(pgumbot));
                        ++nGumbots;
                    }
    }
    void FaseNoite::criarByteCrushers()
    {
        int nByteCrushers = 0;

        for(int i = 0; i < altura && nByteCrushers < maxByteCrushers; ++i)
            for(int j = 0; j < largura && nByteCrushers < maxByteCrushers; ++j)
                if(getTile(j, i) == 8)
                    if(nByteCrushers < minByteCrushers || ((rand()%5) > 1))
                    {
                        ByteCrusher* pbytecrusher = new ByteCrusher(sf::Vector2f(j*comprimentoTile, i*comprimentoTile));
                        gerColisoes->inserirInimigos(pbytecrusher);
                        entidades.inserirNoFim(static_cast<Entidade*>(pbytecrusher));
                        ++nByteCrushers;
                    }
    }
    
    void FaseNoite::criarMaquinaProjeteis()
    {
        int nMaquinaProjeteis = 0;

        for(int i = 0; i < altura && nMaquinaProjeteis < maxMaquinaProjeteis; ++i)
            for(int j = 0; j < largura && nMaquinaProjeteis < maxMaquinaProjeteis; ++j)
                if(getTile(j, i) == 5)
                    if(nMaquinaProjeteis < minMaquinaProjeteis || ((rand()%5) > 1))
                    {
                        Maquina_Projeteis* pmaquinaprojeteis = new Maquina_Projeteis(sf::Vector2f(j*comprimentoTile, i*comprimentoTile+6));
                        entidades.inserirNoInicio(static_cast<Entidade*>(pmaquinaprojeteis));
                        ++nMaquinaProjeteis;
                    }
    }

    void FaseNoite::criarAgua()
    {
        int nAgua = 0;

        for(int i = 0; i < altura && nAgua < maxAgua; ++i)
            for(int j = 0; j < largura && nAgua < maxAgua; ++j)
                if(getTile(j, i) == 2)
                    if(nAgua < minAguas || ((rand()%5) > 1))
                    {
                        Agua* agua = new Agua(sf::Vector2f(j*comprimentoTile, i*comprimentoTile));
                        gerColisoes->inserirObstaculos(agua);
                        entidades.inserirNoFim(static_cast<Entidade*>(agua));
                        ++nAgua;
                    }
    }

    void FaseNoite::criarPilares()
    {
        for(int i = 0; i < altura; ++i)
            for(int j = 0; j < largura; ++j)
                if(getTile(j, i) == 7)
                {    
                    Plataforma* plat = new Plataforma(sf::Vector2f(j*comprimentoTile, i*comprimentoTile), sf::Vector2f(16.0f, 16.0f), false);
                    entidades.inserirNoInicio(static_cast<Entidade*>(plat));
                }
    }

    void FaseNoite::criarEntidades()
    {
        if(!tiles)
            return;

        srand(time(NULL));

        criarPlataformas();
        criarPilares();
        criarAgua();
        criarGumbots();
        criarByteCrushers();
        criarMaquinaProjeteis();

        entidades.inserirNoFim(new Bandeira(sf::Vector2f(1*16.0f, 6*16.0f), this, pjogadorum, pjogadordois));
    }
}