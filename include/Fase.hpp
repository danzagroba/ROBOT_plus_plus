#pragma once

#include <SFML/Graphics.hpp>

#include "Jogador.hpp"
#include "ListaEntidades.hpp"
#include "Obstaculo.hpp"
#include "Texto.hpp"
#define SPRITE_PATHP1 "../assets/player1.png"
#define SPRITE_PATHP2 "../assets/player2.png"


namespace Gerenciadores
{
    class Gerenciador_Grafico;
    class Gerenciador_Colisoes;
    class Gerenciador_Estados;
    class Gerenciador_Inputs;
    class Gerenciador_Eventos;
    
}

namespace Fases
{
    class Fase : public Ente
    {
    protected:
        static float gravidade;

        Gerenciadores::Gerenciador_Grafico* gerGraf;
        Gerenciadores::Gerenciador_Colisoes* gerColisoes;
        Gerenciadores::Gerenciador_Inputs* gerInputs;
        Gerenciadores::Gerenciador_Eventos* gerEventos;
        Gerenciadores::Gerenciador_Estados* gerEstados;
        Entidades::Personagens::Jogador* pjogadorum;
        Entidades::Personagens::Jogador* pjogadordois;
        Listas::ListaEntidades entidades;

        float comprimentoTile;

        Texto pontos;
        int altura;
        int largura;
        short int** tiles;

    public:
        Fase(const char* caminho = nullptr, float comprimento = 16.0f);
        virtual ~Fase();

    protected:
        void destruirTiles();
        void criarPlataforma(const sf::Vector2i& posicaoFinal, const sf::Vector2i& posicaoInicial);
        void criarPlataformas();
        virtual void criarEntidades() = 0;

    public:
        void carregar(const char* caminho);

        const float getComprimentoTile() const;
        const int getAltura() const;
        const int getLargura() const;

        void desenharVidas();
        void desenhar();
        void atualizarprojeteis();
        
        const bool posicaoValida(const int x, const int y) const;
        const short int getTile(const int x, const int y) const;
        const bool eMuro(const int x, const int y) const;
    
        void executar();
    };
}
