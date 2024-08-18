#include "Jogo.hpp"

Jogo::Jogo(): 
      gerGraf(Gerenciador_Grafico::getGerenciador_Grafico()),
      gerInputs(Gerenciador_Inputs::getGerenciador_Inputs()),
      jogador(10.0f, 3, sf::Vector2f(100.0f, 100.0f)),
      fase(LEVEL_PATH, gerGraf, &jogador, 64.0f)
{
    gerGraf->setLimiteFPS(FPS);
    gerGraf->setTamanhoJanela(WINDOW_WIDTH, WINDOW_HEIGHT);
    gerGraf->configurar();

    jogador.setFigura(SPRITE_PATH);
    gerInputs->vincularcomando(sf::Keyboard::W, std::bind(&Entidade::mover, &jogador, sf::Vector2f(0, -1)));
    gerInputs->vincularcomando(sf::Keyboard::S, std::bind(&Entidade::mover, &jogador, sf::Vector2f(0, 1)));
    gerInputs->vincularcomando(sf::Keyboard::A, std::bind(&Entidade::mover, &jogador, sf::Vector2f(-1, 0)));
    gerInputs->vincularcomando(sf::Keyboard::D, std::bind(&Entidade::mover, &jogador, sf::Vector2f(1, 0)));
}

Jogo::~Jogo()
{}

void Jogo::processarEventos()
{

    // inputs do jogador

    gerInputs->processainput(*gerGraf->getJanela());
    
    /*if((dir.x*dir.x + dir.y*dir.y) == 2)
    {
        // 1.41421356f = sqrt(2)
        dir.x /= 1.41421356f;
        dir.y /= 1.41421356f;
    }*/

    //jogador.mover(dir*deltaTime);
}

void Jogo::executar()
{
    while (gerGraf->getisOpen())
    {
        gerGraf->atualizarDeltaTime();
        processarEventos();
        gerGraf->setCamera(jogador.getPos());
        gerGraf->clear();

        fase.desenhar();
        jogador.desenhar();

        gerGraf->display();
    }
}

