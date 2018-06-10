#include "Controle.h"

Controle::Controle()
{
    sameW = 0;
}

void Controle::run()
{
    gerarArvPC();
    getTextoFromTXT();
    splitarTexto(sTexto);
    int tam = palavras.size();
    for(int i = 0; i < tam; i++)
    {
        int tamPal = palavras[i].size();
        if(tamPal > sameW)
            sameW = tamPal;

        palavras[i] = filtrarPalavra(palavras[i]);
        Node_B* plvChave = pcTree.buscar(palavras[i]);
        if(plvChave != NULL)
        {
            plvChave->adicionarLinha(paginasPalavras[i]);
        }
    }
    sameW += 5;
    pcTree.criarArquivoIndice(arqIndice, sameW);
    mostrar();
}

void Controle::mostrar()
{
    //pcTree.mostraremordem();
    //int tam = palavras.size();
    //for(int i = 0; i < tam; i++)
    //{
    //    cout << palavras[i] << "\n";
    //}
    //cout << endl;
    arqIndice.open("arquivos/indice.txt", ios::in);
    if(arqIndice.is_open())
    {
        string linha;
        while(getline(arqIndice, linha))
        {
            cout << linha << endl;
        }
    }else cout << "Nao foi possivel criar/abrir o arquivo \"indice\"" << endl;
    arqIndice.close();
}

void Controle::splitarTexto(vector<string> texto)
{
    int tam = texto.size();
    for(int i = 0; i < tam; i++)
    {
        string aux = "";
        int tamLinha = texto[i].length();
        for(int j = 0; j < tamLinha; j++)
        {
            if(texto[i].at(j) == ' ' || j == tamLinha-1)
            {
                if(j == tamLinha-1)
                    aux += texto[i].at(j);
                palavras.push_back(aux);
                paginasPalavras.push_back(i+1);
                aux="";
                continue;
            }
            aux += texto[i].at(j);
        }
        //string palavra(tokens);
        //palavras.push_back(palavra);
    }
}
string Controle::filtrarPalavra(string palavra)
{
    regex apostrofoEnd(".*\'");
    regex pontuacaoEnd(".*[\\W\\d]$"); //verifica se termina com ponto ou virgula
    while(regex_match(palavra, pontuacaoEnd) && !regex_match(palavra, apostrofoEnd))
    {
        palavra.erase(palavra.end()-1,palavra.end());
    }
    return palavra;
}

string Controle::filtrarApostrofo(string palavra)
{
    return "";
}

bool Controle::isValida(string palavra)
{
    return false;
}

void Controle::gerarArvPC()
{
    arqPalavrasChave.open("arquivos/palavras-chave2.txt", ios::in);

    if(arqPalavrasChave.is_open())
    {
        string linha;
        while(getline(arqPalavrasChave, linha))
        {
            pcTree.inserir(linha);
        }
    }else cout << "Nao foi possivel abrir o arquivo \"palavras-chave\"" << endl;
    arqPalavrasChave.close();
}

void Controle::getTextoFromTXT()
{
    arqTexto.open("arquivos/texto2.txt", ios::in);

    if(arqTexto.is_open())
    {
        string linha;
        while(getline(arqTexto, linha))
            sTexto.push_back(linha);
    }else cout << "Nao foi possivel abrir o arquivo \"texto\"" << endl;
    arqTexto.close();
}
