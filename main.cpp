#include <iostream>

using namespace std;

#include "BinaryTree.hpp"
#include "Controle.hpp"
int main()
{
    //indice remissivo como uma árvore AVL
    //em cada Nó da arvore deverá ter uma lista que contém os numeros das linhas que a palavra aparece
    //O texto e as palavras chaves ficam em arquivos distintos
    //
    BinaryTree tree;
    Controle controle;

    controle.carregarTexto();
    controle.carregarPC();

    //tree.exibirPreOrdem();
    //cout << tree.getAltura(7);
    return 0;
}
