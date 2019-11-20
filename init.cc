#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

int loginADM() {

    char usuarioArquivoADM[12],senhaArquivoADM[9];
    char usuarioAtualADM[12],senhaAtualADM[9];
    char tratamentoUsuario[12],tratamentoSenha[9];

    FILE *arquivoAdm;
    arquivoAdm = fopen("admUser.txt", "r");

    fscanf(arquivoAdm, "%s\n%s",&usuarioArquivoADM, &senhaArquivoADM);

    system("cls");
    cout << "Insira o seu CPF cadastrado: ";
    cin >> usuarioAtualADM;
    cout << "Insira o sua senha cadastrada: ";
    cin >> senhaAtualADM;

    
    
    

    if((strcmp(usuarioArquivoADM,usuarioAtualADM) == 0) && (strcmp(senhaArquivoADM,senhaAtualADM)) == 0 ){
        cout<< "USUARIO LOGADO";
    }else {
        cout<< "Fez merda ai patrao";
    }


    return 0;

}

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

    else {
        fclose(arquivoAdm);
        loginADM();
    }
}

int init() {
    verificarAdm();
    
}