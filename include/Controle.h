#ifndef CONTROLE_H
#define CONTROLE_H

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>

#include "BinaryTree.h"

using namespace std;

class Controle
{
    public:
        Controle();
        void run();
    protected:

    private:
        static const int NUM_LINHA = 200;
        fstream arqTexto, arqPalavrasChave, arqIndice;
        vector<string> sTexto;//200 linhas
        vector<string> palavras;
        vector<int> paginasPalavras;//50 palavras por linha
        BinaryTree pcTree;

        string toLowerCase(string);
        void splitarTexto(vector<string>);
        string filtrarPalavra(string);
        bool isValida(string);
        void gerarArvPC();
        void getTextoFromTXT();
        void mostrar();
        int sameW;
};

#endif // CONTROLE_H
