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
    string quantidade;
};

using namespace std;

void listarmedicamentos(int acao) {
    limpatela();
    ifstream arqMedicamentos;
    string medicamento;

    arqMedicamentos.open("medicamentos.txt");
    if(arqMedicamentos.is_open()){
        
        Remedio remedioSaida;

        do
        {
            remedioSaida.nome = "";
            remedioSaida.laboratorio = "";
            remedioSaida.codBarras = "";
            remedioSaida.quantidade = "";
            getline(arqMedicamentos,remedioSaida.nome);
            getline(arqMedicamentos,remedioSaida.laboratorio);
            getline(arqMedicamentos,remedioSaida.quantidade);
            getline(arqMedicamentos,remedioSaida.codBarras);

            if(remedioSaida.nome != ""){
                cout << "Nome: " << remedioSaida.nome << "\n"
                    << "Laboratório: " << remedioSaida.laboratorio << "\n"
                    << "Código de barras: " << remedioSaida.codBarras << "\n"
                    << "Quantidade: " << remedioSaida.quantidade << "\n\n";
        }
        
        } while (remedioSaida.nome != "");
        

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

    cout << "Informe a quantidade:  (não adicione espaços):";
    cin >> remedio.quantidade;

    cout << "Informe o código de barras:  (não adicione espaços):";
    cin >> remedio.codBarras;

    limpatela();

    cout << "Deseja proceguir com o cadastro? \n\n\tNome: "
         << remedio.nome
         << "\n\tLaboratório: "
         << remedio.laboratorio
         << "\n\tCodigo de barras: "
         << remedio.codBarras 
         << "\n\tQuantidade: "
         << remedio.quantidade
         << endl;
    
    cout << "\n\n\t1 - sim" << endl << "\t2 - não" << endl << "Opção: ";

    int opc;
    cin >> opc;
    ofstream medicamentos;

    switch(opc) {
        case 1:
            
            medicamentos.open("medicamentos.txt",ios::app);

            medicamentos << remedio.nome << "\n" 
                         << remedio.laboratorio << "\n" 
                         << remedio.quantidade << "\n"
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
    Remedio remedioSaida;

    string letra;

    limpatela();
    cout << "Menu de remoção de remédios: \n\n";
    cout << "\t1 - Inserir código para remover.\n"
         << "\t2 - Listar todos os remédios e inserir código.\n"
         << "\nOpção: ";
    
    cin >> opc;

    switch(opc){
    case 2:
        listarmedicamentos(0);
        cout << "\n\n";
    case 1:
        cout << "\n\nInforme o código do medicamento para remover."
             << "\n\nCódigo: ";
        cin >> cod;

        listaMedicamentos.open("medicamentos.txt",ios::in);
        listaMedicamentosCopia.open("medicamentosc.txt",ios::trunc);
        remedioSaida.nome = "a";
        while (remedioSaida.nome != ""){
            remedioSaida.nome = "";
            remedioSaida.laboratorio = "";
            remedioSaida.codBarras = "";
            remedioSaida.quantidade = "";
            getline(listaMedicamentos,remedioSaida.nome);
            getline(listaMedicamentos,remedioSaida.laboratorio);
            getline(listaMedicamentos,remedioSaida.quantidade);
            getline(listaMedicamentos,remedioSaida.codBarras);

            

            if(remedioSaida.codBarras != cod){
                listaMedicamentosCopia 
                    << remedioSaida.nome << "\n"
                    << remedioSaida.laboratorio << "\n"
                    << remedioSaida.quantidade << "\n"
                    << remedioSaida.codBarras << "\n";
            }
            cout << remedioSaida.nome;
        
        }
        
        listaMedicamentosCopia.close();
        listaMedicamentos.close();
        SubstituirArquivoMedicamento();
        cout << "Medicamento removido com sucesso.\n Pressione enter para continuar...";
        getchar();
        getchar();

        break;
    default:
        cout << "Saindo...";
        break;
    }
}