#include "json.hpp"
#include "Mapa.hpp"

#include <iostream>
#include <fstream>

namespace Fases
{
    void Mapa::destruirTiles()
    {
        if(!tiles)
            return;

        for (int i = 0; i < altura; i++)
            delete[] tiles[i];
        delete[] tiles;

        tiles = nullptr;
        altura = 0;
        largura = 0;
    }

    void Mapa::carregar(const char* caminho)
    {
        destruirTiles();

        std::ifstream arquivo(caminho);
        if(!arquivo.is_open())
        {
            std::cout << "Erro, mapa nao pode ser aberto\n";
            return;
        }

        nlohmann::json jsonObj;
        arquivo >> jsonObj;

        auto jsonTiles = jsonObj["tiles"];
        altura = jsonTiles.size();
        largura = jsonTiles.empty() ? 0 : jsonTiles[0].size();

        tiles = new short int*[altura];
        for(int i = 0; i < altura; i++)
        {
            tiles[i] = new short int[largura];
            for(int j = 0; j < largura; j++)
            {
                tiles[i][j] = jsonTiles[i][j];
            }
        }

        std::cout << "altura: " << altura << " largura: " << largura << std::endl;
    }

    Mapa::Mapa(const char* caminho)
        : altura(0), largura(0), tiles(nullptr)
    {
        if(caminho)
            carregar(caminho);
    }

    Mapa::~Mapa()
    {
        destruirTiles();
    }

    const int Mapa::getAltura() const
    {
        return altura;
    }

    const int Mapa::getLargura() const
    {
        return largura;
    }

    const bool Mapa::posicaoValida(const int x, const int y) const
    {
        return tiles && x >= 0 && x < largura && y >= 0 && y < altura;
    }

    // Retorna 0 se a posição não for válida
    const short int Mapa::getTile(const int x, const int y) const
    {
        if(posicaoValida(x, y))
            return tiles[y][x];
        return 0;
    }

    const bool Mapa::eMuro(const int x, const int y) const
    {
        if(!posicaoValida(x, y))
            return true;
        return tiles[y][x] == 1;
    }

    const bool Mapa::mapaCarregado() const
    {
        return tiles != nullptr;
    }
}