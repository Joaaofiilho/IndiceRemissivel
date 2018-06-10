#ifndef NODE_B_H
#define NODE_B_H

#include "DoublyLinkedList.h"
class Node_B
{
    public:
        Node_B(string data);
        Node_B();

        DoublyLinkedList linhas;
        string data;
        Node_B *left, *right;

        void adicionarLinha(int num);
    protected:

    private:
};

#endif // NODE_B_H
