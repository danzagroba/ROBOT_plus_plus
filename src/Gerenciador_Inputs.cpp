#include "Gerenciador_Inputs.hpp"
using namespace std;
#include <iostream>


Gerenciador_Inputs* Gerenciador_Inputs::pgerinputs = NULL;

Gerenciador_Inputs::Gerenciador_Inputs()
{
    tecla_comando.clear();
    cout<<"Gerenciador de Inputs criado"<<endl;
}

Gerenciador_Inputs::~Gerenciador_Inputs()
{
    tecla_comando.clear();
}


void Gerenciador_Inputs::vincularcomando(sf::Keyboard::Key tcl, const Command& cmnd) {
    tecla_comando[tcl] = cmnd;
}

Gerenciador_Inputs* Gerenciador_Inputs::getGerenciador_Inputs()
{
    if(pgerinputs == NULL)
    {
        pgerinputs = new Gerenciador_Inputs();
        if(pgerinputs == NULL)
        {
            cout<<"Erro ao alocar gerenciador de inputs, fechando execução"<<endl;
            exit(1);
        }
    }
    return pgerinputs;
}

void Gerenciador_Inputs::processainput(sf::Window& window)
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
        window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            map<sf::Keyboard::Key, std::function<void()>>::iterator it = tecla_comando.find(event.key.code);
            if (it != tecla_comando.end()) {
                it->second(); //essa função faz o comando conforme está no map
            }
        }
    }
}