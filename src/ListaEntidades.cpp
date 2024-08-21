#include "ListaEntidades.hpp"

namespace Listas
{
    ListaEntidades::Iterator::Iterator(Lista<Entidade*>::Iterator iter)
        : it(iter)
    {}

    ListaEntidades::Iterator::Iterator()
        : it()
    {}

    ListaEntidades::Iterator::~Iterator()
    {}

    Entidade* ListaEntidades::Iterator::operator*()
    {
        return *it;
    }

    ListaEntidades::Iterator& ListaEntidades::Iterator::operator++()
    {
        ++it;
        return *this;
    }

    const bool ListaEntidades::Iterator::operator==(const Iterator& other) const
    {
        return it == other.it;
    }

    const bool ListaEntidades::Iterator::operator!=(const Iterator& other) const
    {
        return it != other.it;
    }

    Lista<Entidade*>::Iterator& ListaEntidades::Iterator::getIt()
    {
        return it;
    }

    ListaEntidades::ListaEntidades()
    {}

    ListaEntidades::~ListaEntidades()
    {
        limpar();
    }

    void ListaEntidades::limpar()
    {
        lista.limpar();
    }

    void ListaEntidades::inserirNoFim(Entidade* e)
    {
        lista.inserirNoFim(e);
    }

    void ListaEntidades::inserirNoInicio(Entidade* e)
    {
        lista.inserirNoInicio(e);
    }

    void ListaEntidades::removerDoInicio()
    {
        lista.removerDoInicio();
    }

    void ListaEntidades::removerDoFim()
    {
        lista.removerDoFim();
    }

    ListaEntidades::Iterator ListaEntidades::inicio()
    {
        return Iterator(lista.inicio());
    }

    ListaEntidades::Iterator ListaEntidades::fim()
    {
        return Iterator(lista.fim());
    }

    const int ListaEntidades::getTam() const
    {
        return lista.getTam();
    }

    ListaEntidades::Iterator ListaEntidades::apagar(Iterator& it)
    {
        return Iterator(lista.apagar(it.getIt()));
    }
}