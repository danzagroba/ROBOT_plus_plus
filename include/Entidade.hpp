#ifndef _ENTIDADE_H_
#define _ENTIDADE_H_

#include "Ente.hpp"

class Entidade: public Ente
{
    protected:
        int x;
        int y;
    public:
        Entidade();
        ~Entidade();
        virtual void executar() = 0;
        virtual void salvar() = 0;
};

#endif