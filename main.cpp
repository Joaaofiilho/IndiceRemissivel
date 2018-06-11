#include <iostream>
#include <locale.h>

#include "Controle.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    Controle c;
    c.run();
    return 0;
}
