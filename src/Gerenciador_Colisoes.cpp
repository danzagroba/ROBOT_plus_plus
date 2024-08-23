#include "Gerenciador_Colisoes.hpp"
#include "Entidade.hpp"

Gerenciador_Colisoes* Gerenciador_Colisoes::pgercol = NULL;

Gerenciador_Colisoes::Gerenciador_Colisoes():
      jogadores(NULL),
      inimigos(NULL)
{
    LIs.clear();
    LOs.clear();
    cout<<"Gerenciador de Colisões criado"<<endl;
}

Gerenciador_Colisoes::~Gerenciador_Colisoes()
{
    inimigos = NULL;
    jogadores = NULL;
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


bool Gerenciador_Colisoes::calculaColisao(Entidade* e1, Entidade* e2)
{
    return e1->getBoundingBox().intersects(e2->getBoundingBox());
}

void Gerenciador_Colisoes::tratarColisao(Entidade* e1, Entidade* e2) {
    //e1 seria um personagem, e2 há de ser um obstaculo ou chão 
    sf::FloatRect b1 = e1->getBoundingBox();
    sf::FloatRect b2 = e2->getBoundingBox();        
    Personagem* ponteiropersonagem = dynamic_cast<Personagem*> (e1);


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
    {
        e1->setPos(e1->getPos().x + minspbX * (fromLeft ? -1 : 1), e1->getPos().y);
    }
    else
    {
        if(fromTop)
        {
            ponteiropersonagem->setPos(e1->getPos().x, e1->getPos().y + minspbY * -1);
            ponteiropersonagem->setno_ar(false); 
        }
        else
        {
            ponteiropersonagem->setPos(e1->getPos().x, e1->getPos().y + minspbY);
        }
        Personagem* ponteiropersonagem = dynamic_cast<Personagem*> (e1);
        ponteiropersonagem->setYvel(0);
    }
}

void Gerenciador_Colisoes::setJogadores(ListaEntidades* jogs)
{
    jogadores = jogs;
}

void Gerenciador_Colisoes::inserirObstaculos(Obstaculo* e)
{
    LOs.push_back(e);
}

void Gerenciador_Colisoes::inserirInimigos(Inimigo* e)
{
    LIs.push_back(e);
}


void Gerenciador_Colisoes::checarColisoesObstaculos()
{
    //Serve pra interações entre players e entidades, para com obstaculos
    for(Listas::Lista<Entidade*>::Iterator it = jogadores->inicio(); it!=jogadores->fim(); ++it) {
        for(list<Obstaculo*>::iterator it2 = LOs.begin(); it2 != LOs.end(); ++it2) {
            if(calculaColisao(*it, *it2))
            {
                std::cout << "Colisão detectada entre entidades" << std::endl;
                tratarColisao(*it, *it2);             
            }
        }
    }
    for(vector<Inimigo*>::iterator it = LIs.begin(); it!=LIs.end(); ++it) {
        for(list<Obstaculo*>::iterator it2 = LOs.begin(); it2 != LOs.end(); ++it2) {
            if(calculaColisao(*it, *it2))
            {
                tratarColisao(*it, *it2);             
            }
        }
    }           

}