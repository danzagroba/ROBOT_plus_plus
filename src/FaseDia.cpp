#include "FaseDia.hpp"
#include "ProjectileBot.hpp"

namespace Fases
{
    FaseDia::FaseDia(Gerenciadores::Gerenciador_Grafico* pGG,
                     Gerenciadores::Gerenciador_Colisoes* pCO,
                     Entidades::Personagens::Jogador* jgdr,
                     Entidades::Personagens::Jogador* jgdrdois,
                     float comprimento)
        : Fase(FASE_DIA_PATH, pGG, pCO, jgdr, jgdrdois, comprimento)
    {}

    FaseDia::~FaseDia()
    {}

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
        gerColisoes->inserirProjetil(pprojectilebot->getProjetil());
        entidades.inserirNoFim(static_cast<Entidade*>(pprojectilebot->getProjetil()));

        std::cout<<"gumbot criado"<<endl;
    }
}