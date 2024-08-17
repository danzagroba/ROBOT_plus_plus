#pragma once

#include "Lista.hpp"

class Entidade;

namespace Listas
{
    class ListaEntidades
    {
    private:
        Lista<Entidade*> lista;

    public:
        class Iterator
        {
        private:
            Lista<Entidade*>::Iterator it;
        
        public:
            Iterator(Lista<Entidade*>::Iterator iter);
            Iterator();
            ~Iterator();

            Entidade* operator*();
            Iterator& operator++();
            const bool operator==(const Iterator& other) const;
            const bool operator!=(const Iterator& other) const;

            friend class ListaEntidades;
        };

    public:
        ListaEntidades();
        ~ListaEntidades();

        void limpar();

        void inserirNoFim(Entidade* e);
        void inserirNoInicio(Entidade* e);

        void removerDoInicio();
        void removerDoFim();

        Iterator inicio();
        Iterator fim();

        const int getTam() const;

        Iterator apagar(Iterator& it);
    };
}