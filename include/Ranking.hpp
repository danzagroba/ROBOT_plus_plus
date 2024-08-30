#pragma once

#include "Estado.hpp"

namespace Estados
{
    class Ranking : public Estado
    {
    private:
        Texto colocacao;
        Texto primeiro;
        Texto segundo;
        Texto terceiro;
        Botao irAoMenu;

    public:
        Ranking();
        ~Ranking();
    
    private:
        void carregarRanking();
    
    public:
        void executar();
        void desenhar();

        void menu();
    };
}