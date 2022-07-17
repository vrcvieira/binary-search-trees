#include <iostream>

using namespace std;

class No
{
public:
    int valor, altDir, altEsq;
    No *esq;
    No *dir;
};

class AVL
{
public:
    No *raiz;

    // Construtor para inicializar a árvore com a raiz nula.
    AVL()
    {
        raiz = NULL;
    }

    // Método para inserir elementos na árvore, recebendo como parâmetro o valor que será inserido.
    void insere(int valor)
    {
        // Criando o nó, que recebe o valor passado por parâmetro e ponteiros de esquerda e direita para nulo.
        No *novo = new No();
        novo->valor = valor;
        novo->altEsq = 0;
        novo->altDir = 0;
        novo->esq = NULL;
        novo->dir = NULL;

        if (raiz == NULL)
        {
            // Significa que não há elementos na árvore e o que for inserido será a raiz.
            raiz = novo;
        }
        else
        {
            // Significa que existe pelo menos um elemento na árvore. Agora, vamos buscar onde inserir.

            // São utilizados dois ponteiros do tipo No para armazenar a raiz e salvar no qual nó estávamos antes de percorrer um novo nó, a partir da estrutura de repetição abaixo.
            No *atual = raiz;
            No *anterior;
            // Essa estrutura de repetição vai executar até que encontremos onde inserir o novo nó.
            while (true)
            {
                // Salvando onde estamos na árvore.
                anterior = atual;

                if (valor <= atual->valor)
                {
                    // Vai para a esquerda.
                    atual = atual->esq;
                    
                    if (atual == NULL)
                    {
                        // Se for nulo, insere.
                        anterior->esq = novo;
                        // Fazer esquema para inserir chamada do balanceamento aqui...
                        return;
                    }
                }
                else
                {
                    // Vai para a direita.
                    atual = atual->dir;
                    if (atual == NULL)
                    {
                        // Se for nulo, insere.
                        anterior->dir = novo;
                        // Fazer esquema para inserir chamada do balanceamento aqui...
                        return;
                    }
                }
            }
        }
    }

    void emOrdem(No *no)
    {
        if (no)
        {
            emOrdem(no->esq);
            cout << " " << no->valor;
            emOrdem(no->dir);
        }
    }
};

int main()
{
    AVL arvore;
    arvore.insere(6);
    arvore.insere(4);
    arvore.insere(7);
    arvore.insere(1);
    arvore.insere(5);
    arvore.insere(8);
    arvore.insere(9);
    arvore.emOrdem(arvore.raiz);
    return 0;
}
