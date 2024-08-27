#ifndef _JOGADOR_H_
#define _JOGADOR_H_

#include "Personagem.hpp"
#include <string>
using namespace std;

namespace Entidades
{
    namespace Personagens
    {
        class Jogador:public Personagem
        {
            private:
                int pontos;
                string nome;
                static bool doisjogadores;

                sf::Texture texturaVida;
                sf::Sprite spriteVida;

            public:
                Jogador(const sf::Vector2f& vel = sf::Vector2f(0.0f, 0.0f), 
                        const int nVidas = 0, 
                        const sf::Vector2f& pos = sf::Vector2f(0.0f, 0.0f),
                        const string& caminhoParaVida = " ");
                ~Jogador();
                
                static bool getdoisjogadores();
                void tomarDano(const int dano);
                void executar();
                void salvar();
                void setSpriteVidaPos(const sf::Vector2f& pos);
                const sf::Texture& getTextureVida() const;
                const sf::Sprite& getSpriteVida() const;
                //void processarInput(const sf::Keyboard::Key tecla, const bool pressionada);
        };
    } using namespace Personagens;
} using namespace Entidades;


#endif

