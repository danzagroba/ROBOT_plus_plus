#include "Inimigo.hpp"
#include "Projetil.hpp"
#define BYTECRUSHER_SPRITE_PATH "../assets/ByteCrusher.png"

namespace Entidades
{
    namespace Personagens
    {
        class ByteCrusher: public Inimigo
        {
            private:
                int etapaataque;
                static list<Projetil*> projeteischefao;
                sf::Clock tempo;
            
            public:
                ByteCrusher(const sf::Vector2f& pos = sf::Vector2f(0.0f, 0.0f));
                ~ByteCrusher();

                void criartirochefao();
                static void removertirochefao(Projetil* ep);
                static std::list<Projetil*>* getprojeteischefao();

                void executar();
                void salvar();
        };
    } using namespace Personagens;
} using namespace Entidades;