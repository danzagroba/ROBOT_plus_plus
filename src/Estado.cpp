#include "Estado.hpp"
#include "Gerenciador_Estados.hpp"

Gerenciadores::Gerenciador_Estados* Estado::pGE = Gerenciador_Estados::getGerenciador_Estados();

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
