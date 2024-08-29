#include "JogarFase.hpp"
#include "Jogador.hpp"
JogarFase::JogarFase():
Estado(10),
faseescolhida(1),
pfasedia(NULL)//,
//pfasenoite(NULL)
{
    pontos.tamanhofonte(70);
    pontos.settextopos(sf::Vector2f(100.0,100.0));

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
    pontos.settexto(std::to_string(Jogador::getpontuacao()));
    pontos.desenhar();    
    if(faseescolhida==1)
    {
        pfasedia->executar();
    }
    else if(faseescolhida==2)
    {
        //pfasenoite->executar();
    }

}