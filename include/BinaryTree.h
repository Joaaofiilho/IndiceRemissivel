#ifndef BINARYTREE_H
#define BINARYTREE_H
#define MAXLEN 100

#include <fstream>
#include <regex>
#include <algorithm>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <locale>
#include <locale.h>
#include "Node_B.h"

using namespace std;

class BinaryTree
{
    public:
        BinaryTree();
        void criarArquivoIndice(Node_B *, fstream&, int);
        void criarArquivoIndice(fstream&, int);

        void mostrarEmOrdem();
        Node_B* inserir(string);
        Node_B* buscar(string dado);
    protected:

    private:
        Node_B *root;

        Node_B* inserir(Node_B *aux, string dado);
        Node_B* balancear(Node_B *aux);
        Node_B* rotacaoEsquerda(Node_B *aux);
        Node_B* rotacaoDireita(Node_B *aux);

        void mostrarEmOrdem(Node_B *atual);
        Node_B* buscar(string dado, Node_B *atual);
        bool hasApostrofo(string);
        string filtrarApostrofo(string);
};

#endif // BINARYTREE_H
