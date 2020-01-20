#include <locale.h>
#include <iostream>
#include <string.h>
using namespace std;

#include "portabilidade.h"
#include "medicamentos.h"
#include "clientes.h"
#include "cpf.h"
#include "init.h"
#include "interface.h"

int main() {
    setlocale(LC_ALL,"portuguese");


    if(!init()) {
        cout << "Ocorreu um erro inesperado na execução do aplicativo. Por favor contate o suporte.";
    }else{

        limpatela();
        
        dashboard();
    }

    return 0;
}

