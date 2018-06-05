#include <iostream>
#include <fstream>

class Controle{
private:
    fstream texto;
    fstream palavrasChave;
public:
    void carregarTexto(){
        texto.open("texto.txt", ios::app);
    }
    void carregarPC(){
        palavrasChave.open("palavraschave.txt", ios::app);
    }

    string getPalavras(){
        return "";
    }
};
