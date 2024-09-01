#include "MenuPrincipal.hpp"
#include "Jogador.hpp"

MenuPrincipal::MenuPrincipal():
Estado(1),
numjogadores(Jogador::getdoisjogadores() ? "2 Jogadores" : "1 Jogador", sf::Vector2f(300.0f, 230.0f)),
escolhefase("Fase Dia",sf::Vector2f(300.0f,300.0f)),
novojogo("Novo Jogo",sf::Vector2f(300.0f,370.0f)),
ranking("Ranking",sf::Vector2f(300.0f,440.0f)),
sair("Sair", sf::Vector2f(300.0f,510.0f))
{
    fase = 1;
    titulo.settexto("ROBOT++");
    titulo.tamanhofonte(70);
    titulo.settextopos(sf::Vector2f(100,100));

    vetorbotoes.push_back(&numjogadores);
    vetorbotoes.push_back(&novojogo);
    vetorbotoes.push_back(&escolhefase);
    vetorbotoes.push_back(&ranking);
    vetorbotoes.push_back(&sair);

    (Gerenciador_Inputs::getGerenciador_Inputs())->vincularcomandobotao(&numjogadores, std::bind(&MenuPrincipal::doisjogadores, this));
    (Gerenciador_Inputs::getGerenciador_Inputs())->vincularcomandobotao(&escolhefase, std::bind(&MenuPrincipal::trocarfase, this));
    (Gerenciador_Inputs::getGerenciador_Inputs())->vincularcomandobotao(&novojogo, std::bind(&Gerenciador_Estados::criarEstadojogar, Gerenciador_Estados::getGerenciador_Estados(), &fase));
    (Gerenciador_Inputs::getGerenciador_Inputs())->vincularcomandobotao(&sair, std::bind(&MenuPrincipal::sairjogo, this));
    (Gerenciador_Inputs::getGerenciador_Inputs())->vincularcomandobotao(&ranking, std::bind(&Gerenciador_Estados::criarEstadoRanking, Gerenciador_Estados::getGerenciador_Estados()));
}



MenuPrincipal::~MenuPrincipal()
{
    std::cout << "menu principal destruido\n";
}

void MenuPrincipal::executar()
{
        desenhar();
}
void MenuPrincipal::desenhar()
{
    numjogadores.desenhar();
    titulo.desenhar();
    novojogo.desenhar();
    escolhefase.desenhar();
    ranking.desenhar();
    sair.desenhar();
}

void MenuPrincipal::sairjogo()
{
    Gerenciador_Estados::getGerenciador_Estados()->popEstadoatual();
    Gerenciador_Grafico::getGerenciador_Grafico()->fecharjanela();
}

void MenuPrincipal::doisjogadores()
{
    Jogador::setDoisJogadores();
    numjogadores.trocarTexto(Jogador::getdoisjogadores() ? "2 Jogadores" : "1 Jogador");
}

void MenuPrincipal::trocarfase()
{
    if(fase == 1)
    {
        fase = 2;
        escolhefase.trocarTexto( "Fase Noite");
    }
    else if(fase == 2)
    {
        fase = 1;
        escolhefase.trocarTexto( "Fase Dia");
    }
}