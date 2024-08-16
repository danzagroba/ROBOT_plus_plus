#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>

#include "Ente.hpp"
#include "Entidade.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define SPRITE_PATH "../assets/subZero.png"

class Player
{
private:
    sf::Vector2f pos;
    float vel;
    sf::Sprite spr;

public:
    Player(const sf::Texture& texture, const sf::Vector2f& position, const float velocity)
        : spr(texture), pos(position), vel(velocity)
    {
        // Seta posicao do sprite para se referir ao centro do sprite
        spr.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
        spr.setPosition(pos);
    }

    void move(float deltaTime, const sf::Vector2f& dir)
    {
        pos += (dir * vel * deltaTime);
        spr.setPosition(pos);
    }

    void handleInput(float deltaTime)
    {
        // Mais de uma tecla pode ser pressionada por vez,
        // portanto, sao checadas todas as teclas
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            move(deltaTime, sf::Vector2f(0, -1));

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            move(deltaTime, sf::Vector2f(0, 1));

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            move(deltaTime, sf::Vector2f(-1, 0));

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            move(deltaTime, sf::Vector2f(1, 0));
    }

    void draw(sf::RenderWindow& window)
    {
        window.draw(spr);
    }

    sf::Vector2f getPos()
    {
        return pos;
    }
};

float getDeltaTime()
{
    static sf::Clock clock;
    return clock.restart().asMilliseconds();
}

int main()
{
    // Carrega textura do sprite
    sf::Texture texture;
    texture.loadFromFile(SPRITE_PATH);

    // Cria janela chamada "simao" e seta seu framerate maximo para 60
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "simao");
    window.setFramerateLimit(60);

    Player player(texture, sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2), 0.5f);

    // Variavel que armazena o tempo entre frames
    float deltaTime = 0;

    while(window.isOpen())
    {
        deltaTime = getDeltaTime();

        // Tratamento de eventos
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }
        player.handleInput(deltaTime);

        // Limpa a janela
        window.clear();

        player.draw(window);

        // Exibe a janela
        window.display();
    }

    return 0;

}