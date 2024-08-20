#pragma once

namespace Fases
{
    class Mapa
    {
    private:
        int altura;
        int largura;
        short int** tiles;  // Updated to use short int**

    private:
        void destruirTiles();

    public:
        void carregar(const char* caminho);
        Mapa(const char* caminho = nullptr);
        ~Mapa();

        const int getAltura() const;
        const int getLargura() const;
    
        const bool posicaoValida(const int x, const int y) const;
        const short int getTile(const int x, const int y) const;
        const bool eMuro(const int x, const int y) const;
    
        const bool mapaCarregado() const;
    };
}