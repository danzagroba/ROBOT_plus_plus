#pragma once
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <map>
#include <functional>

#include "Gerenciador_Estados.hpp"

using namespace std;

// Padrão de projeto Singleton Command 
namespace Gerenciadores {
    class Gerenciador_Inputs {
    public:
        using Command = function<void()>;

        static Gerenciador_Inputs* getGerenciador_Inputs();

        void vincularcomando(sf::Keyboard::Key tcl, const Command& cmnd);
        void vincularcomandoTeclaSolta(sf::Keyboard::Key tcl, const Command& cmnd); // Adicionado para teclas soltas
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
        map<sf::Keyboard::Key, Command> tecla_soltou_comando; // Adicionado para comandos de teclas soltas
        map<Botao*, Command> botao_comando;
    };

} using namespace Gerenciadores;