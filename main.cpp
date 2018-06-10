#include <iostream>

#include "Controle.h"
using namespace std;

int main()
{
    Controle *c = new Controle("texto2", "palavras-chave");
    c->run();
    return 0;
}
