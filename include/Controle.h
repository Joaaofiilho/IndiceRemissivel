#ifndef CONTROLE_H
#define CONTROLE_H

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <regex>

#include "BinaryTree.h"

using namespace std;

class Controle
{
    public:
        Controle(string, string);
        void run();
    protected:

    private:
        static const int NUM_LINHA = 200;
        fstream arqTexto, arqPalavrasChave, arqIndice;
        string nomeArqTexto, nomeArqPC;
        vector<string> sTexto;//200 linhas
        vector<string> palavras;
        vector<int> paginasPalavras;//50 palavras por linha
        BinaryTree pcTree;

        void splitarTexto(vector<string>);
        string filtrarPalavra(string);
        string filtrarApostrofo(string);
        bool isValida(string);
        bool hasApostrofo(string);
        void gerarArvPC();
        void getTextoFromTXT();
        void mostrar();
};

#endif // CONTROLE_H
