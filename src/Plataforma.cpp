#include "Plataforma.hpp"

Plataforma::Plataforma():
Obstaculo()
{
    danoso = false;
    setFigura("../assets/plataforma.png");
}
Plataforma::~Plataforma()
{

}
void Plataforma::executar() {}
void Plataforma::obstacular() {}
