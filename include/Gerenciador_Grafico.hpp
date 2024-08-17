#pragma once
#include <iostream>
using namespace std;

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

//Padrão de proj SINGLETON colocar na uml depois
class Ente;
namespace Gerenciadores 
{
    class Gerenciador_Grafico
    {
        private:
            static Gerenciador_Grafico* pgergraf;
            sf::RenderWindow window;

        private:
            Gerenciador_Grafico();
            ~Gerenciador_Grafico();
        public:
            static Gerenciador_Grafico* getGerenciador_Grafico();
            void desenharEnte(Ente* pE);

    };
} using namespace Gerenciadores;