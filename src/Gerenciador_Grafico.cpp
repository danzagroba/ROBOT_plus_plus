#include <SFML/Graphics.hpp>
#include "Ente.hpp"
#include <SFML/Window/Event.hpp>
#include "Gerenciador_Grafico.hpp"


Gerenciador_Grafico* Gerenciador_Grafico::pgergraf = NULL;

Gerenciador_Grafico::Gerenciador_Grafico():
window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "simao")
{
    window.setFramerateLimit(60);
    cout<<"Gerenciador Gráfico criado"<<endl;
}
Gerenciador_Grafico::~Gerenciador_Grafico()
{
    delete pgergraf;
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
void Gerenciador_Grafico::desenharEnte(Ente* pE)
{
    window.draw(pE->getFigura());
}