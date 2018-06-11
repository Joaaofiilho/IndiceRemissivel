#include "BinaryTree.h"



BinaryTree::BinaryTree()
{
    root = NULL;
    setlocale(LC_ALL, "");
}

Node_B* BinaryTree::inserir(string dado)
{
    root = inserir(root, dado);
    root->calcularFB();
    return root;
}

void BinaryTree::mostrarEmOrdem()
{

    if(root != NULL)
    {
        mostrarEmOrdem(root);
    }
}

Node_B* BinaryTree::buscar(string dado)
{
    if (root == NULL)
        return NULL;
    else
        return buscar(dado, root);
}

void BinaryTree::criarArquivoIndice(fstream& arqIndice, int sameW)
{
    arqIndice.open("arquivos/indice.txt", ios::out);
    if(arqIndice.is_open())
        criarArquivoIndice(root, arqIndice, sameW);
    else
        cout << "Nao foi possivel criar/abrir o arquivo \"indice\"" << endl;
    arqIndice.close();
}

void BinaryTree::criarArquivoIndice(Node_B *tree, fstream& arqIndice, int sameW)
{
    if (tree == NULL)
        return;
    criarArquivoIndice(tree->getLeft(), arqIndice, sameW);

    if(arqIndice.is_open() && tree->linhas.getTam() != 0)
    {
        string pal(tree->dado);
        string aux = filtrarApostrofo(pal);
        arqIndice << aux << ":";
        int tamP = filtrarApostrofo(pal).size();
        int tab = sameW - tamP;
        for(int i = 0; i < tab; i++)
            arqIndice << " ";
        for(int i = 0; i < tree->linhas.getTam(); i++)
        {
            int num = tree->linhas.get(i);
            string format = to_string(num);
            while(num < 100)
            {
                format = "0" + format;
                num *= 10;
            }
            arqIndice << format << " ";
        }

        arqIndice << "\n";
    }

    criarArquivoIndice(tree->getRight(), arqIndice, sameW);
}

bool BinaryTree::hasApostrofo(string palavra)
{
    regex r("^.*\'.*$");
    return regex_match(palavra, r);
}

string BinaryTree::filtrarApostrofo(string palavra)
{
    regex r(".*\'(.*)?$");
    while(regex_match(palavra, r))
        palavra.erase(palavra.end()-1,palavra.end());
    return palavra;
}

Node_B* BinaryTree::inserir(Node_B *aux, string dado)
{
    Node_B *novo;
    if (aux == NULL)
    {
        novo = new Node_B(dado);
        aux = novo;
    }
    else if (dado < aux->getDado())
    {
        aux->setLeft(inserir(aux->getLeft(), dado));

        aux->calcularFB();
        aux = balancear(aux);
    }
    else
    {
        aux->setRight(inserir(aux->getRight(), dado));

        aux->calcularFB();
        aux = balancear(aux);
    }
    return aux;
}

//Balancear
Node_B* BinaryTree::balancear(Node_B *aux)
{
    int fb = aux->getFB();
    int fb2;
    if (fb == -2)
    {
        fb2 = aux->getRight()->getFB();
        if (fb2 <= 0)
        {
            aux = rotacaoEsquerda(aux);
        }
        else
        {
            aux->setRight(rotacaoDireita(aux->getRight()));
            aux = rotacaoEsquerda(aux);
        }
    }
    else if (fb == 2)
    {
        fb2 = aux->getLeft()->getFB();
        if (fb2 >= 0)
        {
            aux = rotacaoDireita(aux);
        }
        else
        {
            aux->setLeft(rotacaoEsquerda(aux->getLeft()));
            aux = rotacaoDireita(aux);
        }
    }
    return aux;
}

//Rotacao esquerda
Node_B* BinaryTree::rotacaoEsquerda(Node_B *aux)
{
    Node_B* x;
    Node_B* y;

    x = aux->getRight();
    y = x->getLeft();
    aux->setRight(y);
    x->setLeft(aux);

    //if (aux->getRight() == NULL || aux == raizPrincipal) aux->setFB(0);
    //else if (aux->getRight()->getFB() != 0 || aux->getRight()->isFolha()) aux->incrementarFB();
    //if (x->getLeft()->getFB() != 0 || x->getLeft()->isFolha()) x->incrementarFB();
    aux->calcularFB();
    x->calcularFB();

    return x;
}

//Rotacao direita
Node_B* BinaryTree::rotacaoDireita(Node_B *aux)
{
    Node_B* x;
    Node_B* y;

    x = aux->getLeft();
    y = x->getRight();
    aux->setLeft(y);
    x->setRight(aux);

    //if (aux->getLeft() == NULL || aux == raizPrincipal) aux->setFB(0);
    //else if (aux->getLeft()->getFB() != 0 || aux->getLeft()->isFolha()) aux->decrementarFB();
    //if (x->getRight()->getFB() != 0 || x->getRight()->isFolha()) x->decrementarFB();
    aux->calcularFB();
    x->calcularFB();

    return x;
}

void BinaryTree::mostrarEmOrdem(Node_B *atual)
{
    if (atual->getLeft() != NULL)
    {
        mostrarEmOrdem(atual->getLeft());
    }

    cout << atual->getDado() << " ";

    if (atual->getRight() != NULL)
    {
        mostrarEmOrdem(atual->getRight());
    }
}

Node_B* BinaryTree::buscar(string dado, Node_B *atual)
{
    if (dado < atual->getDado() && atual->getLeft() != NULL)
        return buscar(dado, atual->getLeft());
    else if (dado > atual->getDado() && atual->getRight() != NULL)
        return buscar(dado, atual->getRight());
    else if (dado == atual->getDado())
        return atual;
    else
        return NULL;
}
