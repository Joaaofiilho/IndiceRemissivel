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

    void adicionar(int dado, No *raiz)
    {
        if(raiz == NULL)
            raiz = new No(dado);
        else
        {
            if(raiz->getDado() < dado)
            {
                if(raiz->getLeft() == NULL)
                    raiz->setLeft(new No(dado));
                else
                    adicionar(dado, raiz->getLeft());
                    //if (adicionar(dado, raiz->getLeft())){
                    //    fb++;
                    //    return !(fb == 0);
                    //}
            }
            if(raiz->getDado() > dado)
            {
                if(raiz->getRight() == NULL)
                    raiz->setRight(new No(dado));
                else
                    adicionar(dado, raiz->getRight());

            }
        }
    }

    No* buscar(No* atual, int dado)
    {
        if(atual == NULL)
            return NULL;
        else
        {
            if(atual->getDado() < dado)
                return buscar(atual->getLeft(), dado);
            else if(atual->getDado() > dado)
                return buscar(atual->getRight(), dado);
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
            if(atual->getDado() < dado)
                remover(atual->getLeft(), dado, atual);

            if(atual->getDado() > dado)
                remover(atual->getRight(), dado, atual);

            if(atual->getDado() == dado){
                if(atual->getLeft() == NULL && atual->getRight() == NULL){

                    if(pai->getLeft() == atual)
                        pai->setLeft(NULL);
                    else
                        pai->setRight(NULL);
                    delete atual;

                }else if(atual->getLeft() == NULL || atual->getRight() == NULL){
                    //Pegar o filho do que vai ser removido
                    No *filho;
                    if(atual->getLeft() == NULL)
                        filho = atual->getRight();
                    else
                        filho = atual->getLeft();

                    //Ligar o pai ao filho do que vai ser removido
                    if(pai->getLeft() == atual)
                        pai->setLeft(filho);
                    else
                        pai->setRight(filho);

                    delete atual;
                }else{
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

    int buscarMenorDireita(No *atual){
        if(atual->getLeft() == NULL)
            return atual->getDado();
        else return buscarMenorDireita(atual->getLeft());
    }

    int altura(No *n){
        if(n->getLeft() == n->getRight())
            return 1;

        int he = altura(n->getLeft());
        int hd = altura(n->getRight());

        if(he > hd)
            return he+1;
        else
            return hd+1;
    }

    void balancear(){

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
};
