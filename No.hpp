#include <iostream>

class No{
public:
    No(int dado){
        left = NULL;
        right = NULL;
        this->dado = dado;
        fb = 0;
    }

    void setLeft(No *left){
        this->left = left;
    }
    No* getLeft(){
        return this->left;
    }
    void setRight(No *right){
        this->right = right;
    }
    No* getRight(){
        return this->right;
    }
    void setDado(int dado){
        this->dado = dado;
    }
    int getDado(){
        return dado;
    }
    void incFb(){
        fb++;
    }
    void decFb(){
        fb--;
    }
    int getFb(){
        return fb;
    }

private:
    No *left;
    No *right;
    int dado;
    int fb;
};
