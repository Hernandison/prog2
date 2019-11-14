#include <stdio.h>
#include <stdlib.h>

#include "init.cc"

int main() {

    if(!init()==false){
        printf("Ocorreu um erro na inicializacao do programa!!\n");
        system("pause");
        return 0;
    }

    

    return 0;
}