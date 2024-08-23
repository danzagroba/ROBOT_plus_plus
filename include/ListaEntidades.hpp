#pragma once

#include "Lista.hpp"
#include "Entidade.hpp"

namespace Listas
{
    class ListaEntidades
    {
    private:
        Lista<Entidade*> lista;
        Lista<Entidade*>::Iterator it;

    public:
        ListaEntidades();
        ~ListaEntidades();

        void limpar();

        void inserirNoFim(Entidade* ent);
        void inserirNoInicio(Entidade* ent);

        void removerDoInicio();
        void removerDoFim();

        const int getTam() const;
    
        Lista<Entidade*>::Iterator apagar(Lista<Entidade*>::Iterator iter);
        Lista<Entidade*>::Iterator inicio();
        Lista<Entidade*>::Iterator fim();

        void executar();
        void salvar();        
    };
} using namespace Listas;