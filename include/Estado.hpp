#pragma once

#include <vector>
#include<iostream>
using namespace std;
#include "Botao.hpp"
//Padrão de projeto State
namespace Estados
{
    class Estado
    {
        protected:
        int id;
        vector<Botao*> vetorbotoes;

        public:
            Estado(int idd);
            virtual ~Estado();
            const int getid()const;
            vector<Botao*>* getvetorbotoes();
            virtual void executar() = 0;
    };
}using namespace Estados;