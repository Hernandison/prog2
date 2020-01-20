#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;

bool novoadm() {
    bool validadeCpf = true;
    string senha;
    string cpfs;
    do
    {
        limpatela();
        if(!validadeCpf)
            cout << "Informe um CPF válido.\n\n";
         
        cout << "\tInsira o seu CPF. Apenas os números: ";
        cin >> cpfs;
    
        int n = cpfs.length(); 
    
        char cpf[n + 1]; 
    
        strcpy(cpf, cpfs.c_str()); 

        if(verificarCpf(cpf)) {
            validadeCpf = true;
            cout << "\tInsira sua senha: ";
            cin >> senha;

            ofstream admData;
            admData.open("admData.txt",ios::app);

            admData << cpfs << "\n";
            admData << senha;
        }else {
            validadeCpf = false;
        }
    } while (validadeCpf != true);
    return validadeCpf;
}

bool loginadm() {

    ifstream admData;
    string cpf,senha,cpfA,senhaA;
    bool login = true;

    do{
        limpatela();
        if(login == false)
            cout << "Nossos minions não encontraram você nas nossas planilhas, tente novamente.\n\n";

        cout << "\tInforme o CPF do administrador: ";
        cin >> cpf;
        cout << "\tInforme a senha: ";
        cin >> senha;

        admData.open("admData.txt");
        if(admData.is_open()) {
            getline(admData,cpfA);
            getline(admData,senhaA);

            if(cpf != cpfA || senha != senhaA) {
                login = false;
                cout << "Os dados de loginn não correspondem com o cadastro, tente novamente.\n\n";
            }else {
                login = true;
            }
            
        }else
        {
            cout << "Nossos minions não encontraram você nas nossas planilhas, tente novamente.";
        }
    }while(login == false);
    return login;
    
}

bool init() {
    bool status = true;

    FILE *admData;

    admData = fopen("admData.txt","r");

    if(admData == NULL) {
        novoadm();
    }else {
        fclose(admData);
        status = loginadm();
    }

    return status;
}