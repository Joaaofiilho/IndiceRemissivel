//
// Created by joa-o on 13/03/2018.
//

#include "DoublyLinkedList.h"

using namespace std;

DoublyLinkedList::DoublyLinkedList()
{
    primeiro = NULL;
    ultimo = NULL;
    tam = 0;
}

void DoublyLinkedList::adicionaFinal(int valor) {
    No *novo = new No(valor);
    if(primeiro == NULL){
        primeiro = novo;
        ultimo = novo;
    }
    else {
        ultimo->proximo = novo;
        novo->anterior = ultimo;
        ultimo = novo;
    }
    tam++;
}

void DoublyLinkedList::removerFinal() {
    if(primeiro == NULL) cout << "Lista vazia!" << endl;
    else if(primeiro == ultimo) {
        primeiro = NULL;
        ultimo = NULL;
        delete primeiro;
        delete ultimo;
        tam--;
    }else{
        No *aux = ultimo->anterior;
        ultimo->anterior->proximo = NULL;
        ultimo->anterior = NULL;
        delete ultimo;
        ultimo = aux;
        tam--;
    }
}

void DoublyLinkedList::adicionaInicio(int valor) {
    No *novo = new No(valor);
    if(primeiro == NULL){
        primeiro = novo;
        ultimo = novo;
    }else{
        novo->proximo = primeiro;
        primeiro->anterior = novo;
        primeiro = novo;
    }
    tam++;
}

void DoublyLinkedList::removerInicio() {
    if(primeiro == NULL) cout << "Lista vazia!" << endl;
    else{
        No *aux = primeiro;
        primeiro = primeiro->proximo;
        primeiro->anterior->proximo = NULL;
        primeiro->anterior = NULL;
        delete aux;
        tam--;
    }
}

void DoublyLinkedList::adicionarPosicao(int index, int valor) {
    if (index < 0) cout << "Index não pode ser menor que 0!" << endl;
    else {
        No *novo = new No(valor);
        No *aux = primeiro;
        for (int i = 0; i < index - 1; i++)
            aux = aux->proximo;

        if (aux == NULL) cout << "Este index é inatingível" << endl;
        else {
            if (aux == primeiro) {
                novo->proximo = primeiro;
                primeiro = novo;
            }else {
                novo->proximo = aux->proximo;
                aux->proximo = novo;
            }
            tam++;
        }
    }
}

void DoublyLinkedList::removerPosicao(int index) {
    if(index < 0) cout << "Index não pode ser menor que 0!" << endl;
    else{
        No *aux = primeiro;
        for(int i = 0; i < index-1; i++)
            aux = aux->proximo;

        if(aux->proximo == NULL) cout << "Este index eh inatingivel" << endl;
        else{
            if(aux == primeiro){
                delete primeiro;
                primeiro = aux->proximo;
            }else if(aux->proximo == ultimo){
                aux->proximo = NULL;
                delete ultimo;
                ultimo = aux;
            }else if(primeiro == ultimo) {
                primeiro = NULL;
                ultimo = NULL;
                delete primeiro;
                delete ultimo;
            }else {
                delete aux->proximo;
                aux->proximo = aux->proximo->proximo;
            }
            tam--;
        }

    }
}

void DoublyLinkedList::exibir() {
    if(primeiro == NULL) cout << "Lista vazia!" << endl;
    else{
        No *aux = primeiro;
        while(aux != NULL) {
            cout << aux->dado << " ";
            aux = aux->proximo;
        }
        cout << endl;
    }
}

bool DoublyLinkedList::contem(int num)
{
    if(!primeiro==NULL)
    {
        No *aux = primeiro;
        while(aux != NULL) {
            if(aux->dado == num)
                return true;
            aux = aux->proximo;
        }
        return false;
    }
}

int DoublyLinkedList::getTam()
{
    return tam;
}

int DoublyLinkedList::get(int index)
{
    if(index < tam && index > -1)
    {
        No *aux = primeiro;
        for (int i = 0; i < index; i++)
            aux = aux->proximo;

        if(aux != NULL)
            return aux->dado;
    }else return NULL;
}
