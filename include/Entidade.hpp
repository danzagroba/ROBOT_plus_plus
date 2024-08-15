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
        void setX(const int xx);
        void setY(const int yy);
        void moveX(const int xx);
        void moveY(const int yy);
        virtual void executar() = 0;
        virtual void salvar() = 0;
};

#endif