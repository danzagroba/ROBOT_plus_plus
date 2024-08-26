#include "Jogo.hpp"

Jogo::Jogo(): 
      gerGraf(Gerenciador_Grafico::getGerenciador_Grafico()),
      gerInputs(Gerenciador_Inputs::getGerenciador_Inputs()),
      gerColisoes(Gerenciador_Colisoes::getGerenciador_Colisoes()),
      jogador(sf::Vector2f(0.0f, 0.0f), 3, sf::Vector2f(25.0f, 25.0f), "../assets/heart1.png"),
      pjogadordois(Entidades::Jogador::getdoisjogadores() ? new Entidades::Jogador(sf::Vector2f(0.0f, 0.0f), 3, sf::Vector2f(25.0f, 25.0f), "../assets/heart2.png") : NULL),
      fase(gerGraf, gerColisoes, &jogador, pjogadordois, 16.0f)
{
    jogador.setFigura(SPRITE_PATHP1);
    gerInputs->vincularcomando(sf::Keyboard::W, std::bind(&Personagem::pulo, &jogador));
    gerInputs->vincularcomando(sf::Keyboard::A, std::bind(&Personagem::setXvel, &jogador,(-0.1)));
    gerInputs->vincularcomando(sf::Keyboard::D, std::bind(&Personagem::setXvel, &jogador,(0.1)));
    gerInputs->vincularcomandoTeclaSolta(sf::Keyboard::W, std::bind(&Personagem::permitirPulo, &jogador));

    if(Entidades::Jogador::getdoisjogadores())
    {
        //pjogadordois = new Entidades::Jogador(10.0f, 3, sf::Vector2f(100.0f, 100.0f));
        if(pjogadordois==NULL)
        {
            cout<<"Erro ao alocar jogador dois"<<endl;
            exit(1);
        }
        pjogadordois->setFigura(SPRITE_PATHP2);
        gerInputs->vincularcomando(sf::Keyboard::Up, std::bind(&Personagem::pulo, pjogadordois));
        gerInputs->vincularcomando(sf::Keyboard::Left, std::bind(&Personagem::setXvel, pjogadordois,(-0.1)));
        gerInputs->vincularcomando(sf::Keyboard::Right, std::bind(&Personagem::setXvel, pjogadordois,(0.1)));
        gerInputs->vincularcomandoTeclaSolta(sf::Keyboard::Up, std::bind(&Personagem::permitirPulo, pjogadordois));
    }

    gerGraf->setLimiteFPS(FPS);
    gerGraf->setTamanhoJanela(WINDOW_WIDTH, WINDOW_HEIGHT);
    gerGraf->setMaximosCamera(fase.getLargura()*fase.getComprimentoTile(), fase.getAltura()*fase.getComprimentoTile());
    gerGraf->configurar();
}

Jogo::~Jogo()
{
    if(pjogadordois)
        delete pjogadordois;
}

void Jogo::executar()
{
    while (gerGraf->getisOpen())
    {
        gerGraf->clear();
        gerGraf->atualizarDeltaTime();
        
        gerInputs->processainput(*gerGraf->getJanela());

        fase.executar();
        sf::Vector2f proxPos = Entidades::Jogador::getdoisjogadores() ? (jogador.getPos()+(pjogadordois->getPos()))/2.0f : jogador.getPos();
        gerGraf->setCamera(proxPos);
        
        gerGraf->display();
    }
}

