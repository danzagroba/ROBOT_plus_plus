#ifndef _ENTE_H_
#define _ENTE_H_

class Gerenciador_Grafico;
class Figura;

class Ente 
{
    protected:
        int id;
        static Gerenciador_Grafico* pGG;
        Figura* pFig;
    public:
        Ente();
        ~Ente();
        virtual void executar() = 0;
        void desenhar();
};


#endif