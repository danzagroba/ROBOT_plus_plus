#include "Gerenciador_Inputs.hpp"
using namespace std;
#include <iostream>

Gerenciador_Inputs* Gerenciador_Inputs::pGI = NULL;
Gerenciador_Estados* Gerenciador_Inputs::pGE = Gerenciador_Estados::getGerenciador_Estados();
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

void Gerenciador_Inputs::vincularcomandobotao(Botao* pbotao, const Command& cmnd) 
{
    botao_comando[pbotao] = cmnd;
    std::cout << "a vincular comando\n";
}

Gerenciador_Inputs* Gerenciador_Inputs::getGerenciador_Inputs() 
{
    if(pGI == NULL) 
    {
        pGI = new Gerenciador_Inputs();
        if(pGI == NULL) 
        {
            cout<<"Erro ao alocar gerenciador de inputs, fechando execução"<<endl;
            exit(1);
        }
    }
    return pGI;
}

void Gerenciador_Inputs::processainput(sf::Keyboard::Key key, const bool pressionado) 
{
    // Check if the key is pressed
    if(pGE->getidEstadoatual()==10)
    {
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
}

void Gerenciador_Inputs::processainput(sf::Vector2i pos) 
{
    if(pGE->getidEstadoatual() == 1)
    {
        std::cout << "acessadndo vetor\n";
        for(vector<Botao*>::iterator it = ((pGE->getEstadoatual())->getvetorbotoes())->begin(); it!=(pGE->getEstadoatual())->getvetorbotoes()->end(); ++it)
        {
            if(*it)
            {
                if((*it)->getretangulo().getGlobalBounds().contains(static_cast<sf::Vector2f>(pos)))
                {
                    map<Botao*, std::function<void()>>::iterator mapit = botao_comando.find(*it);
                    if (mapit != botao_comando.end()) 
                    {
                        std::cout << "achou\n";
                        mapit->second();
                    }
                   // cout<<"esta funcionando"<<endl;
                }
            }
            
        }
    }
}
