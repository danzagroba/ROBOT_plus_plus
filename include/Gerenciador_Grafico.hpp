#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

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

            // Limites da camera
            float maxX;
            float maxY;

            int limitefps;
            static Gerenciador_Grafico* pgergraf;
            sf::RenderWindow* window;
            
            sf::View camera;
            sf::View posInicial;

            bool fundodia;
            float deltaTime;
            sf::Clock clock;    // Usado para medir deltaTime

        private:
            Gerenciador_Grafico();
            ~Gerenciador_Grafico();

            const float lerp(const float a, const float b, const float t) const;

        public:
            static Gerenciador_Grafico* getGerenciador_Grafico();
            sf::RenderWindow* getJanela();
            void desenharEnte(Ente* pE);
            void desenhar(const sf::Drawable& desenho);
            void desenhartxt(sf::Text* txt);
            bool getisOpen();
            void setTamanhoJanela(int lar, int alt);
            void setMaximosCamera(float x, float y);
            void setLimiteFPS(int lfps);
            void setfundo(bool fundod);
            void clear();
            void display();
            void configurar();
            void fecharjanela();
            void processarEvento();
            void setCamera(const sf::Vector2f& centro);
            void setCameraSize(const float width, const float height);
            void atualizarDeltaTime();
            const float getDeltaTime() const;
            const sf::View& getCamera() const;
            void resetCamera();
    };
} using namespace Gerenciadores;


