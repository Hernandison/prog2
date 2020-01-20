#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;

void limpatela();
void dashboard();

struct Remedio
{
    string nome;
    string laboratorio;
    string codBarras;
};

using namespace std;

void listarmedicamentos(int acao) {
    limpatela();
    ifstream arqMedicamentos;
    string medicamento,separador="!";
    int tamanho,i;
    string letra;
    int tag = 1;

    arqMedicamentos.open("medicamentos.txt");
    if(arqMedicamentos.is_open()){
        
        while (getline(arqMedicamentos,medicamento))
        {
            if(tag == 1){
                cout << "Nome: ";
                tag++;
            }

            while(medicamento[i]){
                
                //cout << medicamento[i];
                letra = medicamento[i];
                
                if(letra=="!"){
                    cout<<"\n";

                    if(tag == 2){
                        cout << "Laboratório: ";
                        tag++;
                    }
                    else if(tag == 3){
                        cout << "Código de barras: ";
                        tag++;
                    }
                    
                }else{
                    cout << letra;
                }
                i++;
            }
            cout << "\n\n";
            i=0;
            tag = 1;
        }
        

    }else{
        cout << "Estamos com problemas para listar os medicamentos";
    }
    arqMedicamentos.close();
    if(acao == 1) {
        cout << "\n\nprecione ENTER para voltar para o menu...\n";
        getchar();
        getchar();
        dashboard();
    }
}

void cadastrarmedicamento() {

    limpatela();

    Remedio remedio;

    cout << "Informe o nome do remédio: (não adicione espaços):";
    cin >> remedio.nome;

    cout << "Informe o laboratório:  (não adicione espaços):";
    cin >> remedio.laboratorio;

    cout << "Informe o código de barras:  (não adicione espaços):";
    cin >> remedio.codBarras;

    limpatela();

    cout << "Deseja proceguir com o cadastro? \n\n\tNome: "
         << remedio.nome
         << "\n\tLaboratório: "
         << remedio.laboratorio
         << "\n\tCodigo de barras: "
         << remedio.codBarras << endl;
    
    cout << "\n\n\t1 - sim" << endl << "\t2 - não" << endl << "Opção: ";

    int opc;
    cin >> opc;
    ofstream medicamentos;

    switch(opc) {
        case 1:
            
            medicamentos.open("medicamentos.txt",ios::app);

            medicamentos << remedio.nome << "!" 
                         << remedio.laboratorio << "!" 
                         << remedio.codBarras 
                         << "\n";

            medicamentos.close();

            cout << "O medicamento foi cadastrado com sucesso.";

            break;
        case 2:
            dashboard();
            break;
    }
    cout << "\n\nprecione ENTER para voltar para o menu...\n";
    getchar();
    getchar();
    dashboard();
}

void removermedicamento() {

    int opc, i, contadorSaida = 0;
    string cod, codDoc, medicamento, medicamentoSaida;
    ifstream listaMedicamentos;
    ofstream listaMedicamentosCopia;

    string letra;

    limpatela();
    cout << "Menu de remoção de remédios: \n\n";
    cout << "\t1 - Inserir código para remover.\n"
         << "\t2 - Listar todos os remédios e inserir código.\n"
         << "\nOpção: ";
    
    cin >> opc;
    switch (opc)
    {
    case 2:
        listarmedicamentos(0);
        cout << "\n\n";
    case 1:
        cout << "\n\nInforme o código do medicamento para remover."
             << "\n\nCódigo: ";
        cin >> cod;

        listaMedicamentos.open("medicamentos.txt",ios::in);
        listaMedicamentosCopia.open("medicamentosc.txt",ios::trunc);
        
        while(getline(listaMedicamentos,medicamento)){
            i = medicamento.length();
            do
            {
                letra = medicamento[i];
                if(letra == "!")
                break;
                i--;
            } while (medicamento[i]);

            i+=1;

            while (i < medicamento.length())
            {
                medicamentoSaida += medicamento[i];
                contadorSaida++;
                i++;
            }

            
            contadorSaida = 0;


            
            if(cod != medicamentoSaida) {
                listaMedicamentosCopia << medicamento << endl;
            }
            
            
            medicamentoSaida = "";
        }

        
        listaMedicamentosCopia.close();
        listaMedicamentos.close();
        SubstituirArquivoMedicamento();
        cout << "Medicamento removido com sucesso.\n Pressione enter para continuar...";
        getchar();
        getchar();

        break;
    default:
        break;
    }
}