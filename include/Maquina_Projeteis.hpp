#include "Obstaculo.hpp"
#include "Projetil.hpp"

#define SPRITE_PATHMAQUINAPROJETEIS "../assets/maquinaprojeteis.png"

namespace Entidades
{
    namespace Obstaculos
    {
        class Maquina_Projeteis: public Obstaculo
        {
            private:
                static list<Projetil*> projeteismaquina;
                sf::Clock timer;
            public:
                Maquina_Projeteis(const sf::Vector2f& pos = sf::Vector2f(0.0f, 0.0f));
                ~Maquina_Projeteis();

                void criartiromaquina();
                static void removertiromaquina(Projetil* ep);
                static std::list<Projetil*>* getprojeteismaquina();

                void executar();
                void salvar();
                void obstacular(Jogador* pJogador);
        };
    } using namespace Obstaculos;
} using namespace Entidades;