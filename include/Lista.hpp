#pragma once

#include <iostream>

// Iterator define um interface para iterar sobre a lista:
//    1: permite acessar atual, 2: verificar fim, 3: pegar prox elemento
// Encapsula estrutura da coleção
// Iterador é separado da coleção de maneira que mais de um iterador itere a lista ao mesmo tempo

namespace Listas
{
    template <class T>

    class Lista
    {
    private:
        template <class Type> 

        class Elemento
        {
        private:
            Type data;
            Elemento<Type>* prox;
            Elemento<Type>* ant;

        public:
            Elemento(Type dat, Elemento<Type>* anterior = NULL, Elemento<Type>* prx = NULL)
                : data(dat), 
                  ant(anterior), 
                  prox(prx)
            {}

            Elemento()
                : data(Type()), 
                  ant(NULL), 
                  prox(NULL)
            {}

            ~Elemento()
            {
                prox = NULL;
                ant = NULL;
            }

            void setAnt(Elemento<Type>* anterior)
            {
                ant = anterior;
            }
            Elemento<Type>* getAnt() const
            {
                return ant;
            }

            void setProx(Elemento<Type>* prx)
            {
                prox = prx;
            }
            Elemento<Type>* getProx() const
            {
                return prox;
            }

            void setData(const Type dat)
            {
                data = dat;
            }
            const Type getData() const
            {
                return data;
            }
        };

    private:
        Elemento<T>* cabeca;
        Elemento<T>* cauda;
        int tam;

    public:
        class Iterator
        {
        private:
            Elemento<T>* atual;

        public:
            Iterator(Elemento<T>* cabeca = NULL)
                : atual(cabeca)
            {}

            ~Iterator()
            {
                atual = NULL;
            }

            T operator*()
            {
                return atual->getData();
            }

            Iterator& operator++()
            {
                if(atual)
                    atual = atual->getProx();
                return *this;
            }

            const bool operator==(const Iterator& outro) const
            {
                return atual == outro.atual;
            }

            const bool operator!=(const Iterator& outro) const
            {
                return atual != outro.atual;
            }

            Elemento<T>* getAtual() const
            {
                return atual;
            }
        };
    
    public:
        Lista()
            : cabeca(NULL), 
              cauda(NULL), 
              tam(0)
        {}

        ~Lista()
        {
            limpar();
        }

        void limpar()
        {
            while(cabeca)
            {
                Elemento<T>* temp = cabeca->getProx();
                delete cabeca;
                cabeca = temp;
                --tam;
            }
            cabeca = NULL;
            cauda = NULL;
        }

        void inserirNoFim(const T data)
        {
            if(!cabeca)    // Lista vazia
            {
                cauda = new Elemento<T>(data);
                cabeca = cauda;
                ++tam;
                return;
            }
            Elemento<T>* temp = new Elemento<T>(data);
            temp->setAnt(cauda);
            cauda->setProx(temp);
            cauda = temp;
            ++tam;
        }

        void inserirNoInicio(const T data)
        {
            if(!cauda)    // Lista vazia
            {
                cabeca = new Elemento<T>(data);
                cauda = cabeca;
                ++tam;
                return;
            }
            Elemento<T>* temp = new Elemento<T>(data);
            temp->setProx(cabeca);
            cabeca->setAnt(temp);
            cabeca = temp;
            ++tam;
        }

        void removerDoInicio()
        {
            if(!cauda)    // Lista vazia
                return;
            Elemento<T>* temp = cabeca->getProx();
            if(temp)
                temp->setAnt(NULL);
            else
                cauda = NULL;
            delete cabeca;
            cabeca = temp;
            --tam;
        }

        void removerDoFim()
        {
            if(!cauda)    // Lista vazia
                return;
            Elemento<T>* temp = cauda->getAnt();
            if(temp)
                temp->setProx(NULL);
            else
                cabeca = NULL;
            delete cauda;
            cauda = temp;
            --tam;
        }

        Iterator inicio()
        {
            return Iterator(cabeca);
        }

        Iterator fim()
        {
            return Iterator(NULL);
        }

        const int getTam() const
        {
            return tam;
        }

        Iterator apagar(Iterator& it)
        {
            if(!cabeca || it == fim())
                return fim();

            Elemento<T>* temp = it.getAtual();

            if(temp->getAnt())
                temp->getAnt()->setProx(temp->getProx());
            else
                cabeca = temp->getProx();
            if(temp->getProx())
                temp->getProx()->setAnt(temp->getAnt());
            else
                cauda = temp->getAnt();
            Iterator proxIt(temp->getProx());
            delete temp;
            --tam;
            return proxIt;
        }
    };
}
