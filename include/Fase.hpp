#pragma once

#include <SFML/Graphics.hpp>

#include "Jogador.hpp"
#include "Gerenciador_Grafico.hpp"
#include "Gerenciador_Colisoes.hpp"
#include "ListaEntidades.hpp"
#include "Obstaculo.hpp"

namespace Gerenciadores
{
    class Gerenciador_Colisoes;
}

namespace Fases
{
    class Fase : public Ente
    {
    protected:
        static float gravidade;

        Gerenciadores::Gerenciador_Grafico* gerGraf;
        Gerenciadores::Gerenciador_Colisoes* gerColisoes;

        Listas::ListaEntidades entidades;

        float comprimentoTile;

        int altura;
        int largura;
        short int** tiles;

    public:
        Fase(const char* caminho = nullptr, 
             Gerenciadores::Gerenciador_Grafico* pGG = nullptr,
             Gerenciadores::Gerenciador_Colisoes* pCO = nullptr,
             Entidades::Personagens::Jogador* jgdr = nullptr,
             Entidades::Personagens::Jogador* jgdrdois = nullptr,
             float comprimento = 16.0f);
        virtual ~Fase();

    protected:
        void destruirTiles();
        void criarPlataforma(const sf::Vector2i& posicaoFinal, const sf::Vector2i& posicaoInicial);
        void criarPlataformas();
        virtual void criarEntidades();

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
