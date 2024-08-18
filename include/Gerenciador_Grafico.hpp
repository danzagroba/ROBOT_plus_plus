#pragma once
#include <iostream>
using namespace std;

//Padrão de proj SINGLETON colocar na uml depois
class Ente;
namespace Gerenciadores 
{
    class Gerenciador_Grafico
    {
        private:
            int largura;
            int altura;
            int limitefps;
            static Gerenciador_Grafico* pgergraf;
            sf::RenderWindow* window;
            sf::View camera;
            float deltaTime;
            sf::Clock clock;    // Usado para medir deltaTime

        private:
            Gerenciador_Grafico();
            ~Gerenciador_Grafico();
        public:
            static Gerenciador_Grafico* getGerenciador_Grafico();
            sf::RenderWindow* getJanela();
            void desenharEnte(Ente* pE);
            void desenhar(const sf::Drawable& desenho);
            bool getisOpen();
            void setTamanhoJanela(int lar, int alt);
            void setLimiteFPS(int lfps);
            void clear();
            void display();
            void configurar();
            void processarEvento();
            void setCamera(const sf::Vector2f& pos);
            void atualizarDeltaTime();
            const float getDeltaTime() const;
    };
} using namespace Gerenciadores;

