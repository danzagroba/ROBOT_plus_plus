#include "Gerenciador_Colisoes.hpp"
#include "Entidade.hpp"

Gerenciador_Colisoes* Gerenciador_Colisoes::pgercol = NULL;

Gerenciador_Colisoes::Gerenciador_Colisoes()
    : obstaculos(NULL),
      jogadores(NULL),
      inimigos(NULL)
{}

Gerenciador_Colisoes::~Gerenciador_Colisoes()
{
    inimigos = NULL;
    jogadores = NULL;
    obstaculos = NULL;
}

Gerenciador_Colisoes* Gerenciador_Colisoes::getGerenciador_Colisoes()
{
    if(pgercol == NULL)
    {
        pgercol = new Gerenciador_Colisoes;
        if(pgercol == NULL)
        {
            cout<<"Erro ao alocar gerenciador de colisões, fechando execução"<<endl;
            exit(1);
        }
    }
    return pgercol;
}

void Gerenciador_Colisoes::setObstaculos(ListaEntidades* obst)
{
    obstaculos = obst;
}

void Gerenciador_Colisoes::setJogadores(ListaEntidades* jogs)
{
    jogadores = jogs;
}

void Gerenciador_Colisoes::setInimigos(ListaEntidades* inims)
{
    inimigos = inims;
}

bool Gerenciador_Colisoes::calculaColisao(Entidade* e1, Entidade* e2)
{
    return e1->getBoundingBox().intersects(e2->getBoundingBox());
}

void Gerenciador_Colisoes::tratarColisao(Entidade* e1, Entidade* e2) {
    //e1 seria um personagem, e2 há de ser um obstaculo ou chão 
    sf::FloatRect b1 = e1->getBoundingBox();
    sf::FloatRect b2 = e2->getBoundingBox();

    //Calcuando sobreposições
    float sbpesquerda = (b1.left + b1.width) - b2.left;
    float sbpdireita = (b2.left + b2.width) - b1.left;
    float sbpcima = (b1.top + b1.height) - b2.top;
    float sbpbaixo = (b2.top + b2.height) - b1.top;

    bool fromLeft = std::abs(sbpesquerda) < std::abs(sbpdireita);
    bool fromTop = std::abs(sbpcima) < std::abs(sbpbaixo);

    float minspbX = fromLeft ? sbpesquerda : sbpdireita;
    float minspbY = fromTop ? sbpcima : sbpbaixo;

    if (std::abs(minspbX) < std::abs(minspbY))
        e1->setPos(e1->getPos().x + minspbX * (fromLeft ? -1 : 1), e1->getPos().y);
    else
        e1->setPos(e1->getPos().x, e1->getPos().y + minspbY * (fromTop ? -1 : 1));
}

void Gerenciador_Colisoes::inserirentidade(Entidade* e)
{
    obstaculos->inserirNoFim(e);
}

void Gerenciador_Colisoes::checarColisoesObstaculos()
{
    //Serve pra interações entre players e entidades, para com obstaculos
    for(ListaEntidades::Iterator it = jogadores->inicio(); it!=jogadores->fim(); ++it) 
        for(ListaEntidades::Iterator it2 = obstaculos->inicio(); it2 != obstaculos->fim(); ++it2) 
            if(calculaColisao(*it, *it2))          
                tratarColisao(*it, *it2);

}
/*
    ListaEntidades::Iterator it = jogadores->inicio();
    ListaEntidades::Iterator it2 = plistaentidades->inicio();
    ++it2;
    for(it; it!=plistaentidades->fim(); ++it)
    {   
        it2 = it;
        ++it2;
        for(it2; it2 != plistaentidades->fim(); ++it2)
        {
            if(calculaColisao(*it, *it2))
            {
                //tratarcolisao;
                //it->getID();
            }
        }
    }
*/