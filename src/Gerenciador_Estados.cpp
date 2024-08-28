#include "Gerenciador_Estados.hpp"

Gerenciador_Estados* Gerenciador_Estados::pgerestados = NULL;
Gerenciador_Estados::Gerenciador_Estados():
pilhaestados()
{


}
Gerenciador_Estados::~Gerenciador_Estados()
{
    std::cout << "gerenciador de estados destruido\n";
}
void Gerenciador_Estados::executar()
{
    getEstadoatual()->executar();
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

void Gerenciador_Estados::criarEstadojogar()
{
    adicionarEstado(new JogarFase());
}

Estado* Gerenciador_Estados::getEstadoatual()
{
    return pilhaestados.top();
}
const int Gerenciador_Estados::getidEstadoatual()
{
    return (getEstadoatual())->getid();
}