#include "Node_B.h"

Node_B::Node_B(string dado)
{
    this->dado = dado;
    left = NULL;
    right = NULL;
}

Node_B::Node_B()
{
    dado = "";
    left = NULL;
    right = NULL;
}

void Node_B::adicionarLinha(int num)
{
    if(!linhas.contem(num))
        linhas.adicionaFinal(num);
}

Node_B* Node_B::getLeft()
{
    return left;
}

Node_B* Node_B::getRight()
{
    return right;
}
void Node_B::setLeft(Node_B *left)
{
    this->left = left;
}

void Node_B::setRight(Node_B *right)
{
    this->right = right;
}

void Node_B::setDado(string dado)
{
    this->dado = dado;
}

string Node_B::getDado()
{
    return dado;
}

void Node_B::setFB(int fb)
{
    this->fb = fb;
}

int Node_B::getFB()
{
    return fb;
}

void Node_B::incrementarFB()
{
    fb++;
}

void Node_B::decrementarFB()
{
    fb--;
}

int Node_B::getAltura()
{
    return getAltura(this);
}

int Node_B::getAltura(Node_B *atual)
{
    if (atual == NULL){
        return 0;
    } else {
        int ae = getAltura(atual->getLeft());
        int ad = getAltura(atual->getRight());

        if (ae > ad) return ae+1;
        else return ad+1;
    }
}

int Node_B::calcularFB()
{
    int ae = 0, ad = 0;

    if (this->getLeft() != NULL)
        ae = this->getAltura(this->getLeft());
    if (this->getRight() != NULL)
        ad = this->getAltura(this->getRight());
    this->setFB(ae - ad);
    return (ae - ad);
}
