#include "Plataforma.hpp"

Plataforma::Plataforma():
Obstaculo()
{
    danoso = false;
    id = 8;
    setFigura("../assets/plataforma.png");
}
Plataforma::~Plataforma()
{

}
void Plataforma::executar() {}
void Plataforma::obstacular() {}
