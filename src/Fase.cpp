#include "Fase.hpp"

namespace Fases
{
    Fase::Fase(const char* caminho, Gerenciadores::Gerenciador_Grafico* pGG, Entidades::Personagens::Jogador* jgdr, float comprimento)
        : mapa(caminho), 
          gerGraf(pGG), 
          jogador(jgdr), 
          comprimentoTile(comprimento)
    {}

    Fase::~Fase()
    {}

    void Fase::carregar(const char* caminho)
    {
        mapa.carregar(caminho);
    }

    void Fase::desenhar()
    {
        sf::RectangleShape tile;
        for(int i = 0; i < mapa.getAltura(); i++)
            for(int j = 0; j < mapa.getLargura(); j++)
                if(mapa.eMuro(j, i))
                {
                    // TODO: Usar texturas diferente para cada tile
                    tile.setFillColor(sf::Color::White);
                    tile.setSize(sf::Vector2f(comprimentoTile, comprimentoTile));
                    tile.setPosition(j * comprimentoTile, i * comprimentoTile);
                    gerGraf->desenhar(tile);
                }
    }
}
