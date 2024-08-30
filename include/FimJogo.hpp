#pragma once 

#include "Estado.hpp"

#include <string>

namespace Estados
{
    class FimJogo : public Estado
    {
    private:
        bool terminouFaseDois;
        Texto fimDeJogo;
        Texto inserirNome;
        Texto nome;
        Botao irAoMenu;
        
        std::string input;

    public:
        FimJogo(const bool terminou = false);
        ~FimJogo();

        void executar();
        void desenhar();

        void menu();
    };
}