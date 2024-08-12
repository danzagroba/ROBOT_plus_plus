#ifndef _PERSONAGEM_H_
#define _PERSONAGEM_H_

#include "Entidade.hpp"

class Personagem: public Entidade 
{
    protected:
        int num_vidas;
    public:
        Personagem();
        ~Personagem();
        void setNumVidas(const int nVidas);
        virtual void executar() = 0;
};



#endif