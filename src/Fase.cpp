#include "Fase.hpp"

namespace Fases
{
    Fase::Fase(const char* caminho, Gerenciadores::Gerenciador_Grafico* pGG, Entidades::Personagens::Jogador* jgdr,Entidades::Personagens::Jogador* jgdrdois, float comprimento)
        : mapa(caminho), 
          gerGraf(pGG), 
          jogador(jgdr),
          jogadordois(jgdrdois),
          comprimentoTile(comprimento)
    {}

    Fase::~Fase()
    {}

    const float Fase::getComprimentoTile() const
    {
        return comprimentoTile;
    }

    const int Fase::getAltura() const
    {
        return mapa.getAltura();
    }

    const int Fase::getLargura() const
    {
        return mapa.getLargura();
    }

    void Fase::carregar(const char* caminho)
    {
        mapa.carregar(caminho);
    }

    void Fase::desenhar()
    {
        if(!gerGraf || !mapa.mapaCarregado())
            return;

        int iInicial = (int)((gerGraf->getCamera().getCenter().y - gerGraf->getCamera().getSize().y / 2.0f) / comprimentoTile);
        if(iInicial < 0)
            iInicial = 0;
        
        int iFinal = (int)((gerGraf->getCamera().getCenter().y + gerGraf->getCamera().getSize().y / 2.0f) / comprimentoTile) + 1;
        if(iFinal > mapa.getAltura())
            iFinal = mapa.getAltura();

        int jInicial = (int)((gerGraf->getCamera().getCenter().x - gerGraf->getCamera().getSize().x / 2.0f) / comprimentoTile);
        if(jInicial < 0)
            jInicial = 0;

        int jFinal = (int)((gerGraf->getCamera().getCenter().x + gerGraf->getCamera().getSize().x / 2.0f) / comprimentoTile) + 1;
        if(jFinal > mapa.getLargura())
            jFinal = mapa.getLargura();

        std::cout << "iInicial: " << iInicial << std::endl;
        std::cout << "iFinal: " << iFinal << std::endl;
        std::cout << "jInicial: " << jInicial << std::endl;
        std::cout << "jFinal: " << jFinal << std::endl;
        
        sf::RectangleShape tile(sf::Vector2f(comprimentoTile, comprimentoTile));
        tile.setFillColor(sf::Color::White);
        
        for(int i = iInicial; i < iFinal; ++i)
            for(int j = jInicial; j < jFinal; ++j)
                if(mapa.eMuro(j, i))
                {
                    tile.setPosition(j * comprimentoTile, i * comprimentoTile);
                    gerGraf->desenhar(tile);
                }
    }
}

