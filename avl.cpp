#include <iostream>

using namespace std;

class No
{
public:
    int valor;
    No *esq;
    No *dir;
    int altura;
};

class AVL
{
    No *root;

    No *inserir(int x, No *t)
    {
        if (t == NULL)
        {
            t = new No;
            t->valor = x;
            t->altura = 0;
            t->esq = t->dir = NULL;
        }
        else if (x < t->valor)
        {
            t->esq = inserir(x, t->esq);
            if (altura(t->esq) - altura(t->dir) == 2)
            {
                if (x < t->esq->valor)
                    t = rotacaoSimplesDireita(t);
                else
                    t = rotacaoDuplaDireita(t);
            }
        }
        else if (x > t->valor)
        {
            t->dir = inserir(x, t->dir);
            if (altura(t->dir) - altura(t->esq) == 2)
            {
                if (x > t->dir->valor)
                    t = rotacaoSimplesEsquerda(t);
                else
                    t = rotacaoDuplaEsquerda(t);
            }
        }

        t->altura = max(altura(t->esq), altura(t->dir)) + 1;
        return t;
    }

    No *rotacaoSimplesDireita(No *&t)
    {
        No *u = t->esq;
        t->esq = u->dir;
        u->dir = t;
        t->altura = max(altura(t->esq), altura(t->dir)) + 1;
        u->altura = max(altura(u->esq), t->altura) + 1;
        return u;
    }

    No *rotacaoSimplesEsquerda(No *&t)
    {
        No *u = t->dir;
        t->dir = u->esq;
        u->esq = t;
        t->altura = max(altura(t->esq), altura(t->dir)) + 1;
        u->altura = max(altura(t->dir), t->altura) + 1;
        return u;
    }

    No *rotacaoDuplaEsquerda(No *&t)
    {
        t->dir = rotacaoSimplesDireita(t->dir);
        return rotacaoSimplesEsquerda(t);
    }

    No *rotacaoDuplaDireita(No *&t)
    {
        t->esq = rotacaoSimplesEsquerda(t->esq);
        return rotacaoSimplesDireita(t);
    }

    int altura(No *t)
    {
        return (t == NULL ? -1 : t->altura);
    }

    void emOrdem(No *t)
    {
        if (t == NULL)
            return;
        emOrdem(t->esq);
        cout << t->valor << " ";
        emOrdem(t->dir);
    }

public:
    AVL()
    {
        root = NULL;
    }

    void inserir(int x)
    {
        root = inserir(x, root);
    }

    void exibir()
    {
        emOrdem(root);
        cout << endl;
    }
};

int main()
{
    AVL t;
    t.inserir(61);
    t.inserir(7);
    t.inserir(4);
    t.inserir(160);
    t.inserir(13);
    t.inserir(58);
    t.inserir(35);
    t.inserir(77);
    t.inserir(142);
    t.inserir(212);
    t.inserir(101);
    t.inserir(89);
    t.inserir(81);
    t.inserir(24);
    t.inserir(64);
    t.inserir(84);
    t.inserir(26);
    t.inserir(7);
    t.inserir(356);
    t.inserir(1);
    t.exibir();
    
}