#include "Entidade.hpp"

Entidade::Entidade():
x(0),
y(0)
{

}
Entidade::~Entidade()
{

}
void Entidade::setX(const int xx)
{
    x = xx;
}
void Entidade::setY(const int yy)
{
    y = yy;
}