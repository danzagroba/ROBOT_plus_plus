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

void Gerenciador_Inputs::processainput(sf::Keyboard::Key key, const bool pressionado) 
{
    // Check if the key is pressed
    if(pressionado) 
    {
        map<sf::Keyboard::Key, std::function<void()>>::iterator it = tecla_comando.find(key);
        if (it != tecla_comando.end()) 
        {
            it->second();
        }
    }
    else 
    {
        map<sf::Keyboard::Key, std::function<void()>>::iterator it  = tecla_soltou_comando.find(key);
        if (it != tecla_soltou_comando.end()) 
        {
            it->second();
        }
    }
}
