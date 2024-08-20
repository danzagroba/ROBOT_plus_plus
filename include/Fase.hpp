#pragma once

#include <SFML/Graphics.hpp>

#include "Mapa.hpp"
#include "Jogador.hpp"
#include "Gerenciador_Grafico.hpp"

namespace Fases
{
    class Fase
    {
    private:
        Mapa mapa;
        Gerenciadores::Gerenciador_Grafico* gerGraf;
        Entidades::Personagens::Jogador* jogador;
        Entidades::Personagens::Jogador* jogadordois;
        float comprimentoTile;

    public:
        Fase(const char* caminho = nullptr, 
             Gerenciadores::Gerenciador_Grafico* pGG = nullptr,
             Entidades::Personagens::Jogador* jgdr = nullptr,
             Entidades::Personagens::Jogador* jgdrdois = nullptr,
             float comprimento = 32.0f);
        ~Fase();

        const float getComprimentoTile() const;
        const int getAltura() const;
        const int getLargura() const;

        void carregar(const char* caminho);
        void desenhar();
    };
}

