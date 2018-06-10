//
// Created by joa-o on 08/03/2018.
//

#ifndef LISTADINAMICA_NO_H
#define LISTADINAMICA_NO_H

#include <iostream>

using namespace std;

class No {
public:
    No(int valor){
        dado = valor;
        proximo = NULL;
        anterior = NULL;
    }

    No *proximo;
    No *anterior;
    int dado;
private:
};


#endif //LISTADINAMICA_NO_H
