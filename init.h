#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;

void novoadm() {
    printf("Novo adm..\n");
    bool validadeCpf = true;
    string senha;
    string cpfs;
    do
    {
        limpatela();
        if(!validadeCpf)
            cout << "Informe um CPF válido.\n\n";
         
        cout << "Insira o seu CPF. Apenas os números: ";
        cin >> cpfs;
    
        int n = cpfs.length(); 
    
        char cpf[n + 1]; 
    
        strcpy(cpf, cpfs.c_str()); 

        if(verificarCpf(cpf)) {
            validadeCpf = true;
            cout << "Insira sua senha: ";
            cin >> senha;

            ofstream admData;
            admData.open("admData.txt",ios::app);

            admData << cpfs << "\n";
            admData << senha;
        }else {
            validadeCpf = false;
        }
    } while (validadeCpf != true);
    
}

void loginadm() {
    printf("Fazendo o login: \n");
}

bool init() {
    bool status = true;

    FILE *admData;

    admData = fopen("admData.txt","r");

    if(admData == NULL) {
        novoadm();
    }else {
        fclose(admData);
        loginadm();
    }

    return status;
}