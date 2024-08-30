#include "MenuPrincipal.hpp"
#include "Jogador.hpp"

MenuPrincipal::MenuPrincipal():
Estado(1),
numjogadores(Jogador::getdoisjogadores() ? "2 Jogadores" : "1 Jogador", sf::Vector2f(300.0f, 230.0f)),
novojogo("Novo Jogo",sf::Vector2f(300.0f,300.0f)),
continuar("Continuar",sf::Vector2f(300.0f,370.0f)),
ranking("Ranking",sf::Vector2f(300.0f,440.0f)),
sair("Sair", sf::Vector2f(300.0f,510.0f))
{
    titulo.settexto("ROBOT++");
    titulo.tamanhofonte(70);
    titulo.settextopos(sf::Vector2f(100,100));

    vetorbotoes.push_back(&numjogadores);
    vetorbotoes.push_back(&novojogo);
    vetorbotoes.push_back(&continuar);
    vetorbotoes.push_back(&ranking);
    vetorbotoes.push_back(&sair);

    (Gerenciador_Inputs::getGerenciador_Inputs())->vincularcomandobotao(&numjogadores, std::bind(&MenuPrincipal::doisjogadores, this));
    (Gerenciador_Inputs::getGerenciador_Inputs())->vincularcomandobotao(&novojogo, std::bind(&Gerenciador_Estados::criarEstadojogar, Gerenciador_Estados::getGerenciador_Estados()));
    (Gerenciador_Inputs::getGerenciador_Inputs())->vincularcomandobotao(&sair, std::bind(&MenuPrincipal::sairjogo, this));
    (Gerenciador_Inputs::getGerenciador_Inputs())->vincularcomandobotao(&ranking, std::bind(&Gerenciador_Estados::criarEstadoRanking, Gerenciador_Estados::getGerenciador_Estados()));
}



MenuPrincipal::~MenuPrincipal()
{
    std::cout << "menu principal destruido\n";
}

void MenuPrincipal::executar()
{
    //while(Gerenciador_Grafico::getGerenciador_Grafico()->getisOpen())
    //{
        //Gerenciador_Grafico::getGerenciador_Grafico()->clear();
        //Gerenciador_Grafico::getGerenciador_Grafico()->atualizarDeltaTime();
        //Gerenciador_Eventos::getGerenciador_Eventos()->executar(Gerenciador_Grafico::getGerenciador_Grafico()->getJanela());
        desenhar();
        //Gerenciador_Grafico::getGerenciador_Grafico()->display();
    //}
}
void MenuPrincipal::desenhar()
{
    numjogadores.desenhar();
    titulo.desenhar();
    novojogo.desenhar();
    continuar.desenhar();
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