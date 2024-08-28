#include "Estado.hpp"

Estado::Estado(int idd = 0):
id(idd),
vetorbotoes()
{
    vetorbotoes.clear();
}

Estado::~Estado()
{

}
vector<Botao*>* Estado::getvetorbotoes()
{
    return &vetorbotoes;
}
const int Estado::getid()const
{
    return id;
}
