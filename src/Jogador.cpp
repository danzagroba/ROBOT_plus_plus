#include "Jogador.hpp"
#include <iostream>
using namespace std;

bool Jogador::doisjogadores = true;

Jogador::Jogador(const sf::Vector2f& vel, 
                 const int nVidas, 
                 const sf::Vector2f& pos,
                 const string& caminhoParaVida)
    : Personagem(nVidas, pos),
      pontos(0),
      nome(),
      texturaVida(),
      spriteVida()
{
    id = 1; // ID utilizado pra jogadores
    texturaVida.loadFromFile(caminhoParaVida);
    spriteVida.setTexture(texturaVida);
}

Jogador::~Jogador()
{

}

bool Jogador::getdoisjogadores()
{
    return doisjogadores;
}

void Jogador::executar()
{
    aplicarForcaY(gravidade);
    mover();
    setXvel(0.0f);
    //desenhar();
}

void Jogador::tomarDano(const int dano)
{
    if((relogio.getElapsedTime()).asSeconds()>0.5)
    {
        cout<<"Dano tomado! vidas:"<<num_vidas<<endl;
        num_vidas -= dano;
        no_ar = false;
        setYvel(0.0);
        permitirPulo();
        pulo();
        relogio.restart();
    }
}

void Jogador::salvar()
{

}

void Jogador::setSpriteVidaPos(const sf::Vector2f& pos)
{
    spriteVida.setPosition(pos);
}

const sf::Texture& Jogador::getTextureVida() const
{
    return texturaVida;
}

const sf::Sprite& Jogador::getSpriteVida() const
{
    return spriteVida;
}

/*void Jogador::processarInput(const sf::Keyboard::Key tecla, const bool pressionada)
{
    if(pressionada)
    {
        switch(tecla)
        {
            case sf::Keyboard::Space:
                pulo();
                break;
            case sf::Keyboard::Left:
                setXvel(-0.1f);
                break;
            case sf::Keyboard::Right:
                setXvel(0.1f);
                break;
            default:
                break;
        }
    }
    else if(tecla == sf::Keyboard::W)
        puloBloqueado = false;
}*/