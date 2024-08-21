#include "Jogo.hpp"

Jogo::Jogo(): 
      gerGraf(Gerenciador_Grafico::getGerenciador_Grafico()),
      gerInputs(Gerenciador_Inputs::getGerenciador_Inputs()),
      gerColisoes(Gerenciador_Colisoes::getGerenciador_Colisoes()),
      jogador(10.0f, 3, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(32.0f, 32.0f)),
      pjogadordois(new Entidades::Jogador(10.0f, 3, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(32.0f, 32.0f))),
      fase(LEVEL_PATH, gerGraf, gerColisoes, &jogador, pjogadordois, 64.0f)
{

    jogador.setFigura(SPRITE_PATH);
    gerInputs->vincularcomando(sf::Keyboard::W, std::bind(&Entidade::mover, &jogador, sf::Vector2f(0, -1)));
    gerInputs->vincularcomando(sf::Keyboard::S, std::bind(&Entidade::mover, &jogador, sf::Vector2f(0, 1)));
    gerInputs->vincularcomando(sf::Keyboard::A, std::bind(&Entidade::mover, &jogador, sf::Vector2f(-1, 0)));
    gerInputs->vincularcomando(sf::Keyboard::D, std::bind(&Entidade::mover, &jogador, sf::Vector2f(1, 0)));
    
    if(Entidades::Jogador::getdoisjogadores())
    {
        //pjogadordois = new Entidades::Jogador(10.0f, 3, sf::Vector2f(100.0f, 100.0f));
        if(pjogadordois==NULL)
        {
            cout<<"Erro ao alocar jogador dois"<<endl;
            exit(1);
        }
        pjogadordois->setFigura(SPRITE_PATH);
        gerInputs->vincularcomando(sf::Keyboard::Up, std::bind(&Entidade::mover, pjogadordois, sf::Vector2f(0, -1)));
        gerInputs->vincularcomando(sf::Keyboard::Down, std::bind(&Entidade::mover, pjogadordois, sf::Vector2f(0, 1)));
        gerInputs->vincularcomando(sf::Keyboard::Left, std::bind(&Entidade::mover, pjogadordois, sf::Vector2f(-1, 0)));
        gerInputs->vincularcomando(sf::Keyboard::Right, std::bind(&Entidade::mover, pjogadordois, sf::Vector2f(1, 0)));
    }

    gerGraf->setLimiteFPS(FPS);
    gerGraf->setTamanhoJanela(WINDOW_WIDTH, WINDOW_HEIGHT);
    gerGraf->setMaximosCamera(fase.getLargura()*fase.getComprimentoTile(), fase.getAltura()*fase.getComprimentoTile());
    gerGraf->configurar();
}

Jogo::~Jogo()
{
    if(pjogadordois)
    {
        delete pjogadordois;
    }
}

void Jogo::processarEventos()
{

    // inputs do jogador

    gerInputs->processainput(*gerGraf->getJanela());


    //jogador.mover(dir*deltaTime);
}

void Jogo::executar()
{
    while (gerGraf->getisOpen())
    {
        gerGraf->atualizarDeltaTime();
        processarEventos();
        gerColisoes->checarColisoesObstaculos();

        sf::Vector2f proxPos = Entidades::Jogador::getdoisjogadores() ? (jogador.getPos()+(pjogadordois->getPos()))/2.0f : jogador.getPos();
        gerGraf->setCamera(proxPos);
        gerGraf->clear();

        fase.desenhar();
        jogador.desenhar();
        if(pjogadordois)
            pjogadordois->desenhar();   

        gerGraf->display();
    }
}

