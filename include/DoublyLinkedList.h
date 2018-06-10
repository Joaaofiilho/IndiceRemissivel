//
// Created by joa-o on 13/03/2018.
//

#ifndef LISTADINAMICA_DOUBLELINKEDLIST_H
#define LISTADINAMICA_DOUBLELINKEDLIST_H

#include <iostream>
#include "No.h"

using namespace std;

class DoublyLinkedList {
public:
    DoublyLinkedList();
    void adicionaFinal(int valor);
    void adicionaInicio(int valor);
    void removerFinal();
    void removerInicio();
    void adicionarPosicao(int index, int valor);
    void removerPosicao(int index);
    void exibir();
    bool contem(int num);
    int getTam();
    int get(int);
private:
    No *primeiro;
    No *ultimo;
    int tam;
};


#endif //LISTADINAMICA_DOUBLELINKEDLIST_H
