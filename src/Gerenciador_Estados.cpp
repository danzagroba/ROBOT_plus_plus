#include "Gerenciador_Estados.hpp"

Gerenciador_Estados* Gerenciador_Estados::pgerestados = NULL;
Gerenciador_Estados::Gerenciador_Estados():
pilhaestados()
{

}
Gerenciador_Estados::~Gerenciador_Estados()
{
    
}
void Gerenciador_Estados::adicionarEstado(Estado* ea)
{
    pilhaestados.push(ea);
}
void Gerenciador_Estados::popEstadoatual()
{
    pilhaestados.pop();
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
Estado* Gerenciador_Estados::getEstadoatual()
{
    return pilhaestados.top();
}