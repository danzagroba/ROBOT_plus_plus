#include "Gerenciador_Colisoes.hpp"
#include "Entidade.hpp"
#include "Agua.hpp"
#include "ProjectileBot.hpp"

Gerenciador_Colisoes* Gerenciador_Colisoes::pgercol = NULL;

Gerenciador_Colisoes::Gerenciador_Colisoes():
      LJs(),
      LIs(),
      LOs(),
      LPs()
{
    LIs.clear();
    LOs.clear();
    LJs.clear();
    LPs.clear();
    cout<<"Gerenciador de Colisões criado"<<endl;
}

Gerenciador_Colisoes::~Gerenciador_Colisoes()
{
    LIs.clear();
    LOs.clear();
    LJs.clear();
    LPs.clear();

    std::cout << "gerenciador de colisaos destruido\n";
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
        if(e1->getid()==5)
        {
            Gumbot* ponteirogumbot = dynamic_cast<Gumbot*> (e1);
            ponteirogumbot->trocalado();
        }
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
        ponteiropersonagem->setYvel(0); 
    }
}

void Gerenciador_Colisoes::tratarColisaoInimigo(Entidade* e1, Entidade* e2) {
    //e1 seria um inimigo, e2 há de ser um obstaculo ou chão 
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
    {
        e1->setPos(e1->getPos().x + minspbX * (fromLeft ? -1 : 1), e1->getPos().y);
    }
    if(e1->getid()==5)
    {
        Gumbot* ponteirogumbot = dynamic_cast<Gumbot*> (e1);
        ponteirogumbot->trocalado();
    }
}
void Gerenciador_Colisoes::tratarColisaoJogadorInimigo(Entidade* e1, Entidade* e2)
{
    Jogador* ponteiropersonagem = dynamic_cast<Jogador*> (e1);
    Inimigo* ponteiroinimigo = dynamic_cast<Inimigo*> (e2);
    
    ponteiroinimigo->danificar(ponteiropersonagem);
}
void Gerenciador_Colisoes::inserirObstaculos(Obstaculo* e)
{
    LOs.push_back(e);
}

void Gerenciador_Colisoes::inserirInimigos(Inimigo* e)
{
    LIs.push_back(e);
}

void Gerenciador_Colisoes::inserirJogadores(Jogador* e)
{
    LJs.push_back(e);
}

void Gerenciador_Colisoes::inserirProjetil(Projetil* e)
{
    if((LPs.find(e)==LPs.end()))
    {
        LPs.insert(e);
    }
}

void Gerenciador_Colisoes::checarColisoesObstaculos()
{
    //Serve pra interações entre players e entidades, para com obstaculos
    for(vector<Jogador*>::iterator it = LJs.begin(); it != LJs.end(); ++it) {
        for(list<Obstaculo*>::iterator it2 = LOs.begin(); it2 != LOs.end(); ++it2) {
            if(calculaColisao(*it, *it2))
            {
                if((*it2)->eDanoso())
                    (*it)->tomarDano(Entidades::Obstaculos::Agua::getDano());
                else
                    tratarColisao(*it, *it2);  
            }
        }
    }
    //Serve pra interações entre inimigos, para com obstaculos
    for(vector<Inimigo*>::iterator it = LIs.begin(); it!=LIs.end(); ++it) {
        for(list<Obstaculo*>::iterator it2 = LOs.begin(); it2 != LOs.end(); ++it2) {
            if(calculaColisao(*it, *it2))
            {
                tratarColisao(*it, *it2);             
            }
        }
    }
    for(vector<Jogador*>::iterator it = LJs.begin(); it != LJs.end(); ++it) {
        for(vector<Inimigo*>::iterator it2 = LIs.begin(); it2!=LIs.end(); ++it2) {
            if(calculaColisao(*it, *it2))
            {
                tratarColisaoJogadorInimigo(*it, *it2);             
            }
        }
    }   

    // Serve para interações entre projéteis e obstáculos
    for (set<Projetil*>::iterator it = LPs.begin(); it != LPs.end();)
    {
        bool apagado = false;
        for (list<Obstaculo*>::iterator it2 = LOs.begin(); it2 != LOs.end(); ++it2)
        {
            if (calculaColisao(*it, *it2))
            {
                if((*it)->getid()==20)
                {
                    ProjectileBot::removertiro(*it);
                }
                else if((*it)->getid()==30)
                {
                    Jogador::removertirojogador(*it);
                }
                (*it)->resetar();
                it = LPs.erase(it);  // Apaga e obtém o próximo iterador válido
                apagado = true;
                break; // Sai do loop interno, pois o iterador foi invalidado
            }
        }
        if (!apagado)
        {
            ++it; // Incrementa somente se não foi apagado
        }
    }

    // Serve para interações entre projéteis e jogadores
    for (set<Projetil*>::iterator it = LPs.begin(); it != LPs.end();)
    {
        bool apagado = false;
        for (vector<Jogador*>::iterator it2 = LJs.begin(); it2 != LJs.end(); ++it2)
        {
            if (calculaColisao(*it, *it2) && (*it)->getid() == 20)
            {
                (*it2)->tomarDano((*it)->getDano());
                (*it)->resetar();
                ProjectileBot::removertiro(*it);
                it = LPs.erase(it);  // Apaga e obtém o próximo iterador válido
                apagado = true;
                break; // Sai do loop interno, pois o iterador foi invalidado
            }
        }
        if (!apagado)
        {
            ++it; // Incrementa somente se não foi apagado
        }
    }
    for (set<Projetil*>::iterator it = LPs.begin(); it != LPs.end();)
    {
        bool apagado = false;
        for (vector<Inimigo*>::iterator it2 = LIs.begin(); it2 != LIs.end(); ++it2)
        {
            if (calculaColisao(*it, *it2) && (*it)->getid() == 30)
            {
                if((*it2)->atacado())
                {
                    LIs.erase(it2);
                }
                (*it)->resetar();
                Jogador::removertirojogador(*it);
                it = LPs.erase(it);  // Apaga e obtém o próximo iterador válido
                apagado = true;
                break; // Sai do loop interno, pois o iterador foi invalidado
            }
        }
        if (!apagado)
        {
            ++it; // Incrementa somente se não foi apagado
        }
    }
}