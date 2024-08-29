#include "Jogador.hpp"
#include "Projetil.hpp"
#include <iostream>
using namespace std;

int Jogador::pontuacao = 0;
bool Jogador::doisjogadores = true;
list<Projetil*> Jogador::projeteisjogador;
string Jogador::nome;

Jogador::Jogador(const sf::Vector2f& vel, 
                 const int nVidas, 
                 const sf::Vector2f& pos,
                 const string& caminhoParaVida)
    : Personagem(nVidas, pos),
      texturaVida(),
      spriteVida()
{
    id = 1; // ID utilizado pra jogadores
    texturaVida.loadFromFile(caminhoParaVida);
    spriteVida.setTexture(texturaVida);
    recoiltime.restart();
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

void Jogador::aumentarpontuação(int p)
{
    pontuacao += p;
}

const int Jogador::getpontuacao()
{
    return pontuacao;
}

void Jogador::atacar()
{
    if(recoiltime.getElapsedTime().asSeconds()>0.6)
    {
        if(ladodireito)
        {
            cout<<"Tdste\n";
            Projetil* pprojetiljogador = new Projetil(this, 1, sf::Vector2f(0.2f, -0.1f),30);
            if(pprojetiljogador)
            {
                projeteisjogador.push_back(pprojetiljogador);
                cout<<"Criando tiro ponteiro"<< pprojetiljogador<<endl;
                recoiltime.restart();
            }
        }else
        {
            Projetil* pprojetiljogador = new Projetil(this, 1, sf::Vector2f(-0.2f, -0.1f),30);
            if(pprojetiljogador)
            {
                projeteisjogador.push_back(pprojetiljogador);
                cout<<"Criando tiro ponteiro"<< pprojetiljogador<<endl;
                recoiltime.restart();
            }
        }

    }
}
std::list<Projetil*>* Jogador::getprojeteisjogador() {
    return &projeteisjogador;
}

void Jogador::removertirojogador(Projetil* ep)
{
    cout<<"removendo endereço:"<< ep<<endl;
    list<Projetil*>::iterator it = std::find(projeteisjogador.begin(), projeteisjogador.end(), ep);
    if (it != projeteisjogador.end()) {
        projeteisjogador.erase(it);
    }
}
void Jogador::tomarDano(const int dano)
{
    if((relogio.getElapsedTime()).asSeconds()>0.5)
    {
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
