#pragma once

#include<Estado.hpp>
#include "JogarFase.hpp"

#include <iostream>
#include <stack>
using namespace std;

// video do monitor Giovane usado como base para implementação da classe:
//https://www.youtube.com/playlist?list=PLR17O9xbTbIBBoL3lli44N8LdZVvg-_uZ.

//Padrão de projeto singleton 
namespace Gerenciadores {
    class Gerenciador_Estados {
        public:
            static Gerenciador_Estados* getGerenciador_Estados();
            void executar();
            void adicionarEstado(Estado* ea);
            void popEstadoatual();            
            void criarEstadojogar(int* numfase);
            void criarEstadoRanking();
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