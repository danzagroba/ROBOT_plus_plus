#ifndef _JOGADOR_H_
#define _JOGADOR_H_

#include "Personagem.hpp"
#include <list>
#include <string>
using namespace std;

namespace Entidades
{
    class Projetil;
    namespace Personagens
    {
        class Jogador:public Personagem
        {
            private:
                static int pontuacao;
                static bool doisjogadores;
                static list<Projetil*> projeteisjogador;
                sf::Texture texturaVida;
                sf::Sprite spriteVida;
                sf::Clock recoiltime;

            public:
                Jogador(const sf::Vector2f& vel = sf::Vector2f(0.0f, 0.0f), 
                        const int nVidas = 0, 
                        const sf::Vector2f& pos = sf::Vector2f(0.0f, 0.0f),
                        const string& caminhoParaVida = " ");
                ~Jogador();
                
                static bool getdoisjogadores();
                static void setDoisJogadores();
                static std::list<Projetil*>* getprojeteisjogador();
                static void removertirojogador(Projetil* ep);
                static void aumentarpontuação(int p);
                static const int getpontuacao();
                void tomarDano(const int dano);
                void atacar();
                void executar();
                void salvar();
                void setSpriteVidaPos(const sf::Vector2f& pos);
                const sf::Texture& getTextureVida() const;
                const sf::Sprite& getSpriteVida() const;
        };
    } using namespace Personagens;
} using namespace Entidades;


#endif

