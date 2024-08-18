#include "Ente.hpp"
#include "Gerenciador_Grafico.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>


Gerenciador_Grafico* Gerenciador_Grafico::pgergraf = NULL;

Gerenciador_Grafico::Gerenciador_Grafico():
largura(800),
altura(600),
limitefps(60),
window(NULL),
camera(),
deltaTime(0.0f),
clock()
{
    cout<<"Gerenciador Gráfico criado"<<endl;
}
Gerenciador_Grafico::~Gerenciador_Grafico()
{
    if(window)
    {
        delete window;
    }
    if(pgergraf)
    {
        delete pgergraf;
    }
    pgergraf = NULL;
}
Gerenciador_Grafico* Gerenciador_Grafico::getGerenciador_Grafico()
{
    if(pgergraf == NULL)
    {
        pgergraf = new Gerenciador_Grafico();
        if(pgergraf == NULL)
        {
            cout<<"Erro ao alocar gerenciador grafico, fechando execução"<<endl;
            exit(1);
        }
    }
    return pgergraf;
}
sf::RenderWindow* Gerenciador_Grafico::getJanela()
{
    if(pgergraf)
    {
        return this->window;
    }
    return NULL;
}
void Gerenciador_Grafico::desenharEnte(Ente* pE)
{
    if(window)
    {
        window->draw(pE->getFigura());
    }
}
void Gerenciador_Grafico::desenhar(const sf::Drawable& desenho)
{
    if(window)
        window->draw(desenho);
}
bool Gerenciador_Grafico::getisOpen(){ return window->isOpen(); }
void Gerenciador_Grafico::setTamanhoJanela(int lar, int alt)
{
    largura = lar;
    altura = alt;
    camera.setSize(lar, alt);
}
void Gerenciador_Grafico::setLimiteFPS(int lfps)
{
    limitefps = lfps;
}
void Gerenciador_Grafico::clear()
{
    if(window)
    {
        window->clear();
    }
}
void Gerenciador_Grafico::display()
{
    if(window)
    {
        window->display();
    }
}
void Gerenciador_Grafico::configurar()
{
    if(window)
    {
        delete window;
    }
    window = new sf::RenderWindow(sf::VideoMode(largura, altura), "simao");
    if(!window)
    {
        cout<<"Erro ao configurar janela, fechando execução"<<endl;
        exit(1);
    }
    window->setFramerateLimit(limitefps);
}

void Gerenciador_Grafico::processarEvento()
{
    if(!window)
        return;
    sf::Event event;
    while(window->pollEvent(event))
        if(event.type == sf::Event::Closed)
            window->close();
}

void Gerenciador_Grafico::setCamera(const sf::Vector2f& centro)
{
    camera.setCenter(centro);
    window->setView(camera);
}

void Gerenciador_Grafico::atualizarDeltaTime()
{
    deltaTime = clock.restart().asMilliseconds();
}

const float Gerenciador_Grafico::getDeltaTime() const
{
    return deltaTime;
}

