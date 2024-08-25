#include "Gerenciador_Inputs.hpp"
using namespace std;
#include <iostream>

Gerenciador_Inputs* Gerenciador_Inputs::pgerinputs = NULL;

Gerenciador_Inputs::Gerenciador_Inputs() 
{
    tecla_comando.clear();
    tecla_soltou_comando.clear(); // Inicializa o mapa para comandos de tecla solta
    cout<<"Gerenciador de Inputs criado"<<endl;
}

Gerenciador_Inputs::~Gerenciador_Inputs() 
{
    tecla_comando.clear();
    tecla_soltou_comando.clear(); // Limpa o mapa para comandos de tecla solta
}

void Gerenciador_Inputs::vincularcomando(sf::Keyboard::Key tcl, const Command& cmnd) 
{
    tecla_comando[tcl] = cmnd;
}

void Gerenciador_Inputs::vincularcomandoTeclaSolta(sf::Keyboard::Key tcl, const Command& cmnd) 
{
    tecla_soltou_comando[tcl] = cmnd; // Associa o comando à tecla solta
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
        if (event.type == sf::Event::Closed) 
        {
            window.close();
        }

        if (event.type == sf::Event::KeyReleased) 
        {
            auto it = tecla_soltou_comando.find(event.key.code);
            if (it != tecla_soltou_comando.end()) 
            {
                it->second(); // Executa o comando associado à tecla solta
            }
        }
    }

    for (auto it = tecla_comando.begin(); it != tecla_comando.end(); ++it) 
    {
        if (sf::Keyboard::isKeyPressed(it->first)) 
        {
            it->second(); // Executa o comando associado à tecla pressionada
        }
    }
}
