#include "Personagem.hpp"

Personagem::Personagem():
num_vidas(3),
velocidade(0)
{

}
Personagem::~Personagem()
{

}
void Personagem::setNumVidas(const int nVidas)
{
    num_vidas = nVidas;
}