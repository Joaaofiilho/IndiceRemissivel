#include <iostream>

#include "No.hpp"
class BinaryTree
{
private:
    No *raiz;
    void exibirPreOrdem(No *raiz)
    {
        //A ordem de exibir muda totalmente a ordem que a arvore sai
        std::cout << raiz->getDado() << " ";
        if(raiz->getLeft() != NULL)
            exibirPreOrdem(raiz->getLeft());
        if(raiz->getRight() != NULL)
            exibirPreOrdem(raiz->getRight());
    }

    void exibirEmOrdem(No *raiz)
    {
        if(raiz->getLeft() != NULL)
            exibirEmOrdem(raiz->getLeft());
        //A ordem de exibir muda totalmente a ordem que a arvore sai
        std::cout << raiz->getDado() << " ";
        if(raiz->getRight() != NULL)
            exibirEmOrdem(raiz->getRight());
    }

    void exibirPosOrdem(No *raiz)
    {
        if(raiz->getLeft() != NULL)
            exibirPosOrdem(raiz->getLeft());
        if(raiz->getRight() != NULL)
            exibirPosOrdem(raiz->getRight());
        //A ordem de exibir muda totalmente a ordem que a arvore sai
        std::cout << raiz->getDado() << " ";
    }

    bool adicionar(int dado, No *atual)
    {
        if(dado > atual->getDado())
        {
            if(atual->getRight() == NULL)
            {
                atual->setRight(new No(dado));
                atual->decFb();
            }
            else
            {
                if (adicionar(dado, atual->getRight()))
                {
                    atual->decFb();
                    if(atual->getFb() > 1 || atual->getFb() < -1)
                        balancear(atual);
                }
                else
                    return false;
            }
            return !(atual->getFb() == 0);
        }
        else if(dado < atual->getDado())
        {
            if(atual->getLeft() == NULL)
            {
                atual->setLeft(new No(dado));
                atual->incFb();
            }
            else
            {
                if(adicionar(dado, atual->getLeft()))
                    atual->incFb();
                if(atual->getFb() > 1 || atual->getFb() < -1)
                    balancear(atual);
                else
                    return false;
            }
            return !(atual->getFb() == 0);
        }
    }

    No* buscar(No* atual, int dado)
    {
        if(atual == NULL)
            return NULL;
        else
        {
            if(dado > atual->getDado())
                return buscar(atual->getRight(), dado);
            else if(dado < atual->getDado())
                return buscar(atual->getLeft(), dado);
            else
                return atual;
        }
    }

    void remover(No* atual, int dado, No* pai)
    {
        /*
        Nenhum filho: So remove
        Um filho: O nó é removido da árvore e o único filho é ligado ao pai
        Dois filhos:
        Encontrar o menor valor da direita ou maior da esquerda
        Substituir o local do Nó encontrado (o la de baixo) pelo Nó a ser removido
        remover o Nó encontrado (o la de baixo)
        */
        if(atual != NULL)
        {
            if(dado > atual->getDado())
                remover(atual->getRight(), dado, atual);

            if(dado < atual->getDado())
                remover(atual->getLeft(), dado, atual);

            if(atual->getDado() == dado)
            {
                if(atual->getLeft() == NULL && atual->getRight() == NULL)
                {
                    if(pai->getLeft() == atual)
                    {
                        pai->setLeft(NULL);
                        pai->decFb();
                    }
                    else
                    {
                        pai->setRight(NULL);
                        pai->incFb();
                    }

                    delete atual;
                }
                else if(atual->getLeft() == NULL || atual->getRight() == NULL)
                {
                    //Pegar o filho do que vai ser removido
                    No *filho;
                    if(atual->getLeft() == NULL)
                        filho = atual->getRight();
                    else
                        filho = atual->getLeft();

                    //Ligar o pai ao filho do que vai ser removido
                    if(pai->getLeft() == atual)
                    {
                        pai->setLeft(filho);
                        pai->decFb();
                    }
                    else
                    {
                        pai->setRight(filho);
                        pai->incFb();
                    }
                    delete atual;
                }
                else
                {
                    //Encontrar o menor valor da direita ou maior da esquerda
                    int dadoSubstituto = buscarMenorDireita(atual->getRight());

                    //remover o Nó encontrado (o la de baixo)
                    remover(atual, buscar(dadoSubstituto)->getDado(), pai);

                    //Substituir o local do Nó encontrado (o la de baixo) pelo Nó a ser removido
                    atual->setDado(dadoSubstituto);
                }
            }
        }
    }

    int buscarMenorDireita(No *atual)
    {
        if(atual->getLeft() == NULL)
            return atual->getDado();
        else return buscarMenorDireita(atual->getLeft());
    }

    int altura(No *n)
    {
        if(n->getLeft() == n->getRight())
            return 1;

        int he = altura(n->getLeft());
        int hd = altura(n->getRight());

        if(he > hd)
            return he+1;
        else
            return hd+1;
    }

    void balancear(No *atual)
    {
        if(atual->getLeft() != NULL)
            balancear(atual->getLeft());
        if(atual->getRight() != NULL)
            balancear(atual->getRight());

        if(atual->getFb() > 1)
        {
            if(atual->getLeft() != NULL && atual->getLeft()->getFb() < 0)
                RDD(atual);
            else
                RDS(atual);
        }
        else if(atual->getFb() < -1)
        {
            if(atual->getRight() != NULL && atual->getRight()->getFb() > 0)
                RDE(atual);
            else
                RES(atual);
        }
    }
    //Falta atualizar os FBs
    void RES(No *atual)
    {
        No *subDireita = atual->getRight();
        atual->setRight(subDireita->getLeft());
        subDireita->setLeft(atual);
        if(atual == raiz)
            raiz = subDireita;
    }
    void RDS(No *atual)
    {
        No *subEsquerda = atual->getLeft();
        atual->setLeft(subEsquerda->getRight());
        subEsquerda->setRight(atual);
        if(atual == raiz)
            raiz = subEsquerda;
    }
    void RDE(No *atual)
    {
        RDS(atual->getRight());
        RES(atual);
    }
    void RDD(No *atual) {
        RES(atual->getLeft());
        RDS(atual);
    }

public:
    BinaryTree()
    {
        raiz = NULL;
    }

    void adicionar(int dado)
    {
        if(raiz == NULL)
            raiz = new No(dado);
        else
            adicionar(dado, raiz);
    }
    void exibirPreOrdem()
    {
        exibirPreOrdem(raiz);
        cout << endl;
    }
    void exibirEmOrdem()
    {
        exibirEmOrdem(raiz);
        cout << endl;
    }
    void exibirPosOrdem()
    {
        exibirPosOrdem(raiz);
        cout << endl;
    }

    No* buscar(int dado)
    {
        return buscar(this->raiz, dado);
    }

    void remover(int dado)
    {
        remover(raiz, dado, NULL);
    }

    void getFb(int num)
    {
        cout << buscar(raiz, num)->getFb() << endl;
    }
};
