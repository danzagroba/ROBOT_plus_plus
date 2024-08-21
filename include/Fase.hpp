#pragma once

#include <SFML/Graphics.hpp>

#include "Jogador.hpp"
#include "Gerenciador_Grafico.hpp"

namespace Fases
{
    class Fase
    {
    private:
        Gerenciadores::Gerenciador_Grafico* gerGraf;
        
        Entidades::Personagens::Jogador* jogador;
        Entidades::Personagens::Jogador* jogadordois;
        
        float comprimentoTile;

        int altura;
        int largura;
        short int** tiles;

    private:
        void destruirTiles();

    public:
        Fase(const char* caminho = nullptr, 
             Gerenciadores::Gerenciador_Grafico* pGG = nullptr,
             Entidades::Personagens::Jogador* jgdr = nullptr,
             Entidades::Personagens::Jogador* jgdrdois = nullptr,
             float comprimento = 32.0f);
        ~Fase();

        void carregar(const char* caminho);

        const float getComprimentoTile() const;
        const int getAltura() const;    
        const int getLargura() const;   

        void desenhar();
    
        const bool posicaoValida(const int x, const int y) const;
        const short int getTile(const int x, const int y) const;
        const bool eMuro(const int x, const int y) const;
    
        const bool mapaCarregado() const;
    };
}
