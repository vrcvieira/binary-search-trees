// AVL

#include <iostream>
#include <chrono>

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
    No *raiz;

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

    No *acharMenor(No *t)
    {
        if (t == NULL)
            return NULL;
        else if (t->esq == NULL)
            return t;
        else
            return acharMenor(t->esq);
    }

    No *remover(int x, No *t)
    {
        No *temp;

        // Elemento não encontrado
        if (t == NULL)
            return NULL;

        // Procurando pelo elemento
        else if (x < t->valor)
            t->esq = remover(x, t->esq);
        else if (x > t->valor)
            t->dir = remover(x, t->dir);

        // Elemento encontrado e possui dois filhos
        else if (t->esq && t->dir)
        {
            temp = acharMenor(t->dir);
            t->valor = temp->valor;
            t->dir = remover(t->valor, t->dir);
        }
        // Elemento encontrado e possui apenas um ou zero filhos
        else
        {
            temp = t;
            if (t->esq == NULL)
                t = t->dir;
            else if (t->dir == NULL)
                t = t->esq;
            delete temp;
        }
        if (t == NULL)
            return t;

        t->altura = max(altura(t->esq), altura(t->dir)) + 1;

        // Se o nó estiver desbalanceado
        if (altura(t->esq) - altura(t->dir) == 2)
        {
            if (altura(t->esq->esq) - altura(t->esq->dir) == 1)
                return rotacaoSimplesEsquerda(t);
            else
                return rotacaoDuplaEsquerda(t);
        }
        // Desbalanceado para o outro lado
        else if (altura(t->dir) - altura(t->esq) == 2)
        {
            if (altura(t->dir->dir) - altura(t->dir->esq) == 1)
                return rotacaoSimplesDireita(t);
            else
                return rotacaoDuplaDireita(t);
        }
        return t;
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
        raiz = NULL;
    }

    void inserir(int x)
    {
        raiz = inserir(x, raiz);
    }

    void remover(int x)
    {
        raiz = remover(x, raiz);
    }

    void exibir()
    {
        emOrdem(raiz);
        cout << endl;
    }
};

int main()
{
    auto start = chrono::steady_clock::now();
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
    t.remover(81);
    t.remover(101);
    t.remover(6);
    t.exibir();
    auto end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = end-start;
    cout << "Tempo de exec.: " << elapsed_seconds.count() << "s\n";
}