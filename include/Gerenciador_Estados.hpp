#pragma once

#include <iostream>
#include <stack>
using namespace std;

//Padrão de projeto singleton e STATE
namespace Gerenciadores {
    class Gerenciador_Estados {
        public:
            static Gerenciador_Estados* getGerenciador_Estados();
            void trocarestado();
        private:
            static Gerenciador_Estados* pgerestados;
            int idestado;
            stack<int> pilha;
            Gerenciador_Estados();
            ~Gerenciador_Estados();
    
    };
} 
using namespace Gerenciadores;