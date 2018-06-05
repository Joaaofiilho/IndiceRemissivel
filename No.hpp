#include <iostream>

class No{
public:
    No(string dado){
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
    void setDado(string dado){
        this->dado = dado;
    }
    string getDado(){
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
    void setFb(int fb){
        this->fb = fb;
    }

private:
    No *left;
    No *right;
    string dado;
    int fb;
};
