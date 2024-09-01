#include "JogarFase.hpp"
#include "Jogador.hpp"
#include "FimJogo.hpp"
#include "Gerenciador_Estados.hpp"

JogarFase::JogarFase(int numf):
Estado(10),
faseescolhida(numf),
pfasedia(NULL),
pfasenoite(NULL)
{

    cout<<"Fase esoclhida [e a numero]"<<faseescolhida<<endl;
    if(faseescolhida==1)
    {
        cout << "fase 1 selecionada\n";
        pfasedia = new FaseDia;
        if(pfasedia == NULL)
        {
            cerr<<"Erro ao abrir fase dia"<<endl;
            exit(1);
        }
    }
    if(faseescolhida==2)
    {
        cout << "fase dois selecionada\n";
        pfasenoite = new FaseNoite;
        if(pfasenoite == NULL)
        {
            cerr<<"Erro ao abrir fase noite"<<endl;
            exit(1);
        }
    }
}

JogarFase::~JogarFase()
{
    if(pfasedia)
    {
        delete pfasedia;
        pfasedia = NULL;
    }

    if(pfasenoite)
    {
        delete pfasenoite;
        pfasenoite = NULL;
    }
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
        if(pfasedia->playersvivos() == false)
        {
            bool concluiu = pfasedia->faseConcluida();
            delete pfasedia;
            pfasedia = NULL;
            pGE->popEstadoatual();
            pGE->adicionarEstado(new FimJogo(concluiu));
        }
        else if(pfasedia->faseConcluida())
            irprafasedois();
        else
            pfasedia->executar();
    }
    else if(faseescolhida==2)
    {
        if(pfasenoite->playersvivos() == false)
        {
            bool concluiu = pfasenoite->faseConcluida();
            delete pfasenoite;
            pfasenoite = NULL;
            pGE->popEstadoatual();
            pGE->adicionarEstado(new FimJogo(concluiu));
            std::cout << "player nao estao vivos\n";
        }
        else if(pfasenoite->faseConcluida())
        {
            bool concluiu = pfasenoite->faseConcluida();
            pGE->popEstadoatual();
            pGE->adicionarEstado(new FimJogo(concluiu));
        } 
        else
            pfasenoite->executar();
    }

}