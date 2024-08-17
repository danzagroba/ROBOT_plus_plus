#include "Jogo.hpp"

Jogo::Jogo()
    : gerGraf(Gerenciador_Grafico::getGerenciador_Grafico()),
      deltaTime(0.0f),
      clock(),
      jogador(10.0f, 3, sf::Vector2f(100.0f, 100.0f))
{
    gerGraf->setLimiteFPS(FPS);
    gerGraf->setTamanhoJanela(WINDOW_WIDTH, WINDOW_HEIGHT);
    gerGraf->configurar();

    jogador.setFigura(SPRITE_PATH);    
}

Jogo::~Jogo()
{}

void Jogo::atualizarDeltaTime()
{
    deltaTime = clock.restart().asMilliseconds();
}

void Jogo::processarEventos()
{
    gerGraf->processarEvento();

    // inputs do jogador

    sf::Vector2f dir(0, 0);

    // Mais de uma tecla pode ser pressionada por vez,
    // portanto, sao checadas todas as teclas
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        dir += sf::Vector2f(0, -1);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        dir += sf::Vector2f(0, 1);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        dir += sf::Vector2f(-1, 0);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        dir += sf::Vector2f(1, 0);
    
    //
    // Normalizar vetor de direcao
    //
    
    if((dir.x*dir.x + dir.y*dir.y) == 2)
    {
        // 1.41421356f = sqrt(2)
        dir.x /= 1.41421356f;
        dir.y /= 1.41421356f;
    }

    jogador.mover(dir*deltaTime);
}

void Jogo::executar()
{
    while (gerGraf->getisOpen())
    {
        atualizarDeltaTime();
        processarEventos();
        gerGraf->clear();

        jogador.desenhar();

        gerGraf->display();
    }
}
