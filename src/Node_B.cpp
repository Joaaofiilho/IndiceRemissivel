#include "Node_B.h"

Node_B::Node_B(string data)
{
    this->data = data;
    left = NULL;
    right = NULL;
}

Node_B::Node_B(){
    data = "";
    left = NULL;
    right = NULL;
}

void Node_B::adicionarLinha(int num)
{
    if(!linhas.contem(num))
        linhas.adicionaFinal(num);
}
