#include <stdio.h>
#include <stdlib.h>

int criarAdm(){

    char cpf[12];
    char senha[9];

    FILE *arquivoAdm;
    arquivoAdm = fopen("admUser.txt", "w");

    printf("Insira o CPF: ");
    scanf("%s",&cpf);
    fprintf(arquivoAdm, "%s\n",cpf);

    printf("Insira uma senha de no maximo 8 caracteres: ");
    scanf("%s",&senha);
    fprintf(arquivoAdm, "%s",senha);

    fclose(arquivoAdm);
}

int verificarAdm() {
    FILE *arquivoAdm;
    arquivoAdm = fopen("admUser.txt", "r");

    if(arquivoAdm == NULL){
        fclose(arquivoAdm);
        criarAdm();
    }
}

int init() {
    if(!verificarAdm()==false){
        return 0;
    }
}