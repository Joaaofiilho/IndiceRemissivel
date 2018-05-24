#include <iostream>

using namespace std;

#include "BinaryTree.hpp"
int main()
{
    BinaryTree tree;
    tree.adicionar(7);
    tree.adicionar(5);
    tree.adicionar(12);
    tree.adicionar(2);
    tree.adicionar(6);
    tree.adicionar(9);
    tree.adicionar(21);
    tree.adicionar(19);
    tree.adicionar(25);

    tree.exibirPreOrdem();
    tree.getFb(12);
    //cout << tree.getAltura(7);
    return 0;
}
