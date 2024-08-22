#pragma once
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <map>
#include <functional>

using namespace std;

// Padrão de projeto Singleton Command 
namespace Gerenciadores {
    class Gerenciador_Inputs {
    public:
        using Command = function<void()>;

        static Gerenciador_Inputs* getGerenciador_Inputs();

        void vincularcomando(sf::Keyboard::Key tcl, const Command& cmnd);
        void vincularcomandoTeclaSolta(sf::Keyboard::Key tcl, const Command& cmnd); // Adicionado para teclas soltas

        void processainput(sf::Window& window);

    private:
        Gerenciador_Inputs();
        ~Gerenciador_Inputs();

        static Gerenciador_Inputs* pgerinputs;

        Gerenciador_Inputs& operator=(const Gerenciador_Inputs&) = delete;

        map<sf::Keyboard::Key, Command> tecla_comando;
        map<sf::Keyboard::Key, Command> tecla_soltou_comando; // Adicionado para comandos de teclas soltas
    };

} using namespace Gerenciadores;