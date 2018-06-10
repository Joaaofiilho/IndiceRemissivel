#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <fstream>
#include <regex>
#include <algorithm>
#include "Node_B.h"

using namespace std;

class BinaryTree
{
    public:
        BinaryTree();
        void inserir(string dado);
        void mostraremordem();
        void criarArquivoIndice(Node_B *, fstream&, int);
        void criarArquivoIndice(fstream&, int);
        Node_B* buscar(string);
    protected:

    private:
        Node_B *root;

        int height(Node_B *);
        int diff(Node_B *);
        Node_B *rr_rotation(Node_B *);
        Node_B *ll_rotation(Node_B *);
        Node_B *lr_rotation(Node_B *);
        Node_B *rl_rotation(Node_B *);
        Node_B* balance(Node_B *);
        Node_B* insert(Node_B *, string );
        Node_B* buscar(Node_B *, string );
        void inorder(Node_B *);
        void preorder(Node_B *);
        void postorder(Node_B *);
        string filtrarAcento(string);
        bool hasApostrofo(string);
        string filtrarApostrofo(string);
};

#endif // BINARYTREE_H
