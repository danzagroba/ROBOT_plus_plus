#include "ListaEntidades.hpp"

namespace Listas
{
    ListaEntidades::ListaEntidades()
        : lista(),
          it()
    {}

    ListaEntidades::~ListaEntidades()
    {
        limpar();
        std::cout << "lista destruido";
    }

    void ListaEntidades::limpar()
    {
        lista.limpar();
    }

    void ListaEntidades::inserirNoFim(Entidade* ent)
    {
        if(ent)
            lista.inserirNoFim(ent);
    }

    void ListaEntidades::inserirNoInicio(Entidade* ent)
    {
        if(ent)
            lista.inserirNoInicio(ent);
    }

    void ListaEntidades::removerDoInicio()
    {
        lista.removerDoInicio();
    }

    void ListaEntidades::removerDoFim()
    {
        lista.removerDoFim();
    }

    const int ListaEntidades::getTam() const
    {
        return lista.getTam();
    }

    Lista<Entidade*>::Iterator ListaEntidades::apagar(Lista<Entidade*>::Iterator iter)
    {
        return lista.apagar(iter);
    }

    Lista<Entidade*>::Iterator ListaEntidades::inicio()
    {
        return lista.inicio();
    }

    Lista<Entidade*>::Iterator ListaEntidades::fim()
    {
        return lista.fim();
    }

    void ListaEntidades::executar()
    {
        for(it = inicio(); it != fim(); ++it)
            (*it)->executar();
    }

    void ListaEntidades::salvar()
    {
        for(it = inicio(); it != fim(); ++it)
            (*it)->salvar();
    }

    void ListaEntidades::desenhar()
    {
        for(it = inicio(); it != fim(); ++it)
            (*it)->desenhar();
    }
    
    void ListaEntidades::desalocar()
    {
        it = inicio();
        while(it != fim())
        {
            if((*it)->getid() == 0)
            {
                Entidade* temp = *it;
                it = apagar(it);
                delete temp;
            }
            else
                ++it;
        }
    }
}