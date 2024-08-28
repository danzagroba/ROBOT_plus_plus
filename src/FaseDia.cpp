#include "FaseDia.hpp"
#include "ProjectileBot.hpp"
#include "Gumbot.hpp"
#include "Agua.hpp"
#include "ProjectileBot.hpp"
#include "Plataforma.hpp"
#include "Gerenciador_Grafico.hpp"
#include "Gerenciador_Colisoes.hpp"
#include "Gerenciador_Estados.hpp"
#include "Gerenciador_Eventos.hpp"
#include "Gerenciador_Inputs.hpp"

#include <cstdlib>
#include <ctime>

namespace Fases
{
    FaseDia::FaseDia(float comprimento)
        : Fase(FASE_DIA_PATH, comprimento)
    {
        criarEntidades();
    }

    FaseDia::~FaseDia()
    {
        std::cout << "fase dia destruida\n";
    }

    void FaseDia::criarEntidades()
    {
        if(!tiles)
            return;

        srand(time(NULL));

        criarPlataformas();

        int nGumbots = 0;
        int nProjectileBots = 0;
        Agua* agua;
        rand()%5;
        rand()%5;
        rand()%5;

        for(int i = 0; i < altura; ++i)
        {
            for(int j = 0; j < largura; ++j)
            {
                switch(getTile(j, i))
                {
                case 2:
                    agua = new Agua(sf::Vector2f(j*comprimentoTile, i*comprimentoTile));
                    gerColisoes->inserirObstaculos(agua);
                    entidades.inserirNoFim(static_cast<Entidade*>(agua));
                    break;
                
                case 3:
                    if(nProjectileBots < 3 || ((rand()%5) > 1))
                    {
                        ProjectileBot* pprojectilebot = new ProjectileBot(sf::Vector2f(j*comprimentoTile, i*comprimentoTile));
                        gerColisoes->inserirInimigos(pprojectilebot);
                        entidades.inserirNoFim(static_cast<Entidade*>(pprojectilebot));
                        ++nProjectileBots;
                    }
                    break;

                case 4:
                    if(nGumbots < 3 || ((rand()%5) > 1))
                    {
                        Gumbot* pgumbot = new Gumbot(sf::Vector2f(j*comprimentoTile, i*comprimentoTile));
                        gerColisoes->inserirInimigos(pgumbot);
                        entidades.inserirNoFim(static_cast<Entidade*>(pgumbot));
                        ++nGumbots;
                    }
                    break;
                case 6:
                    if((rand()%5) > 1)
                    {
                        agua = new Agua(sf::Vector2f(j*comprimentoTile, i*comprimentoTile));
                        gerColisoes->inserirObstaculos(agua);
                        entidades.inserirNoFim(static_cast<Entidade*>(agua));
                    }
                    break;
                case 7:
                {
                    Plataforma* plat = new Plataforma(sf::Vector2f(j*comprimentoTile, i*comprimentoTile),sf::Vector2f(0.0f, 0.0f), false);
                    entidades.inserirNoInicio(static_cast<Entidade*>(plat));
                    break;
                }

                default:
                    break;
                }
            }
        }
    }
}