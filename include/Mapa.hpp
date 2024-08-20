#pragma once

namespace Fases
{
    class Mapa
    {
    private:
        int altura;
        int largura;
        char** tiles;

    private:
        void destruirTiles();

    public:
        void carregar(const char* caminho);
        Mapa(const char* caminho = nullptr);
        ~Mapa();

        const int getAltura() const;
        const int getLargura() const;
    
        const bool posicaoValida(const int x, const int y) const;
        const char getTile(const int x, const int y) const;
        const bool eMuro(const int x, const int y) const;
    
        const bool mapaCarregado() const;
    };
}

