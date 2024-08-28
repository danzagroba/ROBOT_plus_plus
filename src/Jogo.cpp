#include "Jogo.hpp"

Jogo::Jogo(): 
      gerGraf(Gerenciador_Grafico::getGerenciador_Grafico()),
      gerInputs(Gerenciador_Inputs::getGerenciador_Inputs()),
      gerColisoes(Gerenciador_Colisoes::getGerenciador_Colisoes()),
      gerEstados(Gerenciador_Estados::getGerenciador_Estados())
{

    gerGraf->setLimiteFPS(FPS);
    gerGraf->setTamanhoJanela(WINDOW_WIDTH, WINDOW_HEIGHT);
    gerGraf->setMaximosCamera(800, 600);
    gerGraf->configurar();

    gerEstados->adicionarEstado(new MenuPrincipal());
}

Jogo::~Jogo()
{
    std::cout << "jogo destruido\n";
}

void Jogo::executar()
{
    while (gerGraf->getisOpen())
    {
        gerGraf->clear();
        gerGraf->atualizarDeltaTime();
        
        gerEventos->executar(gerGraf->getJanela());
        
        gerEstados->executar();

        gerGraf->display();
    }
}

