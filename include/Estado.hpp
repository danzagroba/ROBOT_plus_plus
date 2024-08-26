#pragma once

//Padrão de projeto State
namespace Estados
{
    class Estado
    {
        public:
            Estado();
            virtual ~Estado();
            virtual void executar() = 0;


    };
}using namespace Estados;