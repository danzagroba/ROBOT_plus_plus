#pragma once

#include<Estado.hpp>
#include "JogarFase.hpp"

#include <iostream>
#include <stack>
using namespace std;

//Padrão de projeto singleton 
namespace Gerenciadores {
    class Gerenciador_Estados {
        public:
            static Gerenciador_Estados* getGerenciador_Estados();
            void executar();
            void adicionarEstado(Estado* ea);
            void popEstadoatual();            
            void criarEstadojogar();
            //void criarMenuprincipal();
            Estado* getEstadoatual();
            const int getidEstadoatual();

        private:
            static Gerenciador_Estados* pgerestados;
            stack<Estado*> pilhaestados;
    
            Gerenciador_Estados();
            ~Gerenciador_Estados();
    };
} 
using namespace Gerenciadores;