#include "JogarFase.hpp"

JogarFase::JogarFase():
Estado(10),
faseescolhida(1),
pfasedia(NULL)//,
//pfasenoite(NULL)
{
    if(faseescolhida==1)
    {
        pfasedia = new FaseDia;
        if(pfasedia == NULL)
        {
            cerr<<"Erro ao abrir fase dia"<<endl;
            exit(1);
        }
    }
    else if(faseescolhida == 2)
    {
        /*pfasenoite = new FaseNoite;
        if(pfasenoite == NULL)
        {
            cerr<<"Erro ao criar fase noite"<<endl;
            exit(1);
        }*/
    }
}

JogarFase::~JogarFase()
{
    std::cout << "jogar fase criado\n";
}

void JogarFase::executar()
{
    if(faseescolhida==1)
    {
        pfasedia->executar();
    }
    else if(faseescolhida==2)
    {
        //pfasenoite->executar();
    }

}