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

        tiles = new char*[altura];
        for(int i = 0; i < altura; i++)
        {
            tiles[i] = new char[largura];
            for(int j = 0; j < largura; j++)
            {
                std::string tileStr = jsonTiles[i][j];    // cada tile é representado como string de um caractere
                if (!tileStr.empty())
                    tiles[i][j] = tileStr[0];    // conversao para char
                else
                    tiles[i][j] = ' ';    // considera espaco vazio se nao houver tile
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

    const char Mapa::getTile(const int x, const int y) const
    {
        // considera espaco vazio se a posicao nao for valida
        if(posicaoValida(x, y))
            return tiles[y][x];
        return ' ';
    }

    const bool Mapa::eMuro(const int x, const int y) const
    {
        if(!posicaoValida(x, y))
            return true;
        return tiles[y][x] != ' ';
    }

    const bool Mapa::mapaCarregado() const
    {
        return tiles != nullptr;
    }
}

