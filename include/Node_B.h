#ifndef NODE_B_H
#define NODE_B_H

#include "DoublyLinkedList.h"
class Node_B
{
    public:
        Node_B(string);
        Node_B();
        DoublyLinkedList linhas;
        string dado;
        void setLeft(Node_B *left);
        void setRight(Node_B *right);
        Node_B* getLeft();
        Node_B* getRight();

        void setDado(string dado);
        string getDado();
        void setFB(int fb);
        int getFB();
        void incrementarFB();
        void decrementarFB();

        int getAltura();
        int getAltura(Node_B *atual);
        int calcularFB();
        void adicionarLinha(int num);
    protected:

    private:
        int fb;
        Node_B *left;
        Node_B *right;
};

#endif // NODE_B_H
