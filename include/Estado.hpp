#pragma once

#include <vector>
#include<iostream>
using namespace std;
#include "Botao.hpp"

namespace Gerenciadores
{
    class Gerenciador_Estados;
}

//Padrão de projeto State
namespace Estados
{
    class Estado
    {
        protected:
            int id;
            vector<Botao*> vetorbotoes;
            static Gerenciadores::Gerenciador_Estados* pGE;

        public:
            Estado(int idd);
            virtual ~Estado();
            const int getid()const;
            vector<Botao*>* getvetorbotoes();
            virtual void executar() = 0;
    };
}using namespace Estados;