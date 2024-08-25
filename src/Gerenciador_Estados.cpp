#include "Gerenciador_Estados.hpp"

Gerenciador_Estados::Gerenciador_Estados()
{

}
Gerenciador_Estados::~Gerenciador_Estados()
{
    
}

Gerenciador_Estados* Gerenciador_Estados::getGerenciador_Estados()
{
    if(pgerestados == NULL)
    {
        pgerestados = new Gerenciador_Estados();
        if(pgerestados == NULL)
        {
            cout<<"Erro ao alocar gerenciador grafico, fechando execução"<<endl;
            exit(1);
        }
    }
    return pgerestados;
}