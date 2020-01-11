#include <locale.h>
#include <iostream>
#include <string.h>
using namespace std;

#include "portabilidade.h"
#include "cpf.h"
#include "init.h"

int main() {

    if(!init()) {
        cout << "Ocorreu um erro inesperado na execução do aplicativo. Por favor contate o suporte.";
    }else{
        cout << "\n\n\tO usuáro está logado!!";
    }

    return 0;
}

