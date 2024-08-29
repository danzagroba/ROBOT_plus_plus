#include "JogarFase.hpp"
#include "Jogador.hpp"
JogarFase::JogarFase():
Estado(10),
faseescolhida(1),
pfasedia(NULL),
pfasenoite(NULL)
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
}

JogarFase::~JogarFase()
{
    std::cout << "jogar fase criado\n";
}
void JogarFase::irprafasedois()
{
    delete pfasedia;
    pfasedia = NULL;
    faseescolhida = 2;
    pfasenoite = new FaseNoite;
    if(pfasenoite == NULL)
    {
        cerr<<"Erro ao abrir fase noite"<<endl;
        exit(1);
    }
}

void JogarFase::executar()
{  
    if(faseescolhida==1)
    {
        if(pfasedia->faseConcluida())
            irprafasedois();
        else
            pfasedia->executar();
    }
    else if(faseescolhida==2)
    {
        pfasenoite->executar();
    }

}