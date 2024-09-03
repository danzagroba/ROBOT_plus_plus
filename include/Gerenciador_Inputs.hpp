#pragma once
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <map>
#include <functional>

#include "Gerenciador_Estados.hpp"

using namespace std;

// Padrão de projeto Singleton Command 
//Encapsula solicitações como objetos:
// Isso é feito no std::function<void()> para encapsular comandos
//Separação do Emissor e do Executor:
//A classe Gerenciador de Inputs atua como emissor, enquanto os comandos encapsulados são os executores
//Mapeamento de Comandos: 
//O uso de mapas (map<sf::Keyboard::Key, Command> e map<Botao*, Command>
//Flexibilidade e Extensibilidade: 
//novos comandos podem ser facilmente adicionados através dos métodos vincularcomando, vincularcomandoTeclaSolta e vincularcomandobotao.

namespace Gerenciadores {
    class Gerenciador_Inputs {
    public:
        using Command = function<void()>;

        static Gerenciador_Inputs* getGerenciador_Inputs();

        void vincularcomando(sf::Keyboard::Key tcl, const Command& cmnd);
        void vincularcomandoTeclaSolta(sf::Keyboard::Key tcl, const Command& cmnd);
        void vincularcomandobotao(Botao* pbotao, const Command& cmnd);

        void processainput(sf::Keyboard::Key key, const bool pressionado);
        void processainput(sf::Vector2i pos);

    private:
        Gerenciador_Inputs();
        ~Gerenciador_Inputs();

        static Gerenciador_Inputs* pGI;
        static Gerenciador_Estados* pGE;

        Gerenciador_Inputs& operator=(const Gerenciador_Inputs&) = delete;

        map<sf::Keyboard::Key, Command> tecla_comando;
        map<sf::Keyboard::Key, Command> tecla_soltou_comando;
        map<Botao*, Command> botao_comando;
    };

} using namespace Gerenciadores;