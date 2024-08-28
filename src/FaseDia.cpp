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

namespace Fases
{
    FaseDia::FaseDia(float comprimento)
        : Fase(FASE_DIA_PATH, comprimento)
    {}

    FaseDia::~FaseDia()
    {
        std::cout << "fase dia destruida\n";
    }

    void FaseDia::criarEntidades()
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
    }
}