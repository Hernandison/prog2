#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;

void limpatela();
void dashboard();

struct Cliente
{
    string nome;
    string idade;
    string cpf;
};

using namespace std;

void listarclientes(int acao) {
    limpatela();
    ifstream arqClientes;
    string cliente;

    arqClientes.open("clientes.txt");
    if(arqClientes.is_open()){
        
        Cliente clienteSaida;

        do
        {
            clienteSaida.nome = "";
            clienteSaida.idade = "";
            clienteSaida.cpf = "";
            getline(arqClientes,clienteSaida.nome);
            getline(arqClientes,clienteSaida.idade);
            getline(arqClientes,clienteSaida.cpf);

            if(clienteSaida.nome != ""){
                cout << "Nome: " << clienteSaida.nome << "\n"
                    << "Idade: " << clienteSaida.idade << "\n"
                    << "CPF: " << clienteSaida.cpf << "\n\n";
        }
        
        } while (clienteSaida.nome != "");
        

    }else{
        cout << "Estamos com problemas para listar os clientes";
    }
    arqClientes.close();
    if(acao == 1) {
        cout << "\n\nprecione ENTER para voltar para o menu...\n";
        getchar();
        getchar();
        dashboard();
    }
}

void cadastrarcliente() {

    limpatela();

    Cliente cliente;

    cout << "Informe o nome: (não adicione espaços):";
    cin >> cliente.nome;

    cout << "Informe a idade:  (não adicione espaços):";
    cin >> cliente.idade;


    

    limpatela();

    bool validadeCpf;

    do
    {
        limpatela();
        if(!validadeCpf)
            cout << "Informe um CPF válido.\n\n";
         
        cout << "Informe o CPF:  (não adicione espaços):";
        cin >> cliente.cpf;
    
        int n = cliente.cpf.length(); 
    
        char cpf[n + 1]; 
    
        strcpy(cpf, cliente.cpf.c_str()); 

        if(verificarCpf(cpf)) {
            validadeCpf = true;
            
        }else {
            validadeCpf = false;
        }
    } while (validadeCpf != true);

    cout << "Deseja proceguir com o cadastro? \n\n\tNome: "
         << cliente.nome
         << "\n\tLaboratório: "
         << cliente.idade
         << "\n\tCodigo de barras: "
         << cliente.cpf << endl;
    
    cout << "\n\n\t1 - sim" << endl << "\t2 - não" << endl << "Opção: ";

    int opc;
    cin >> opc;
    ofstream medicamentos;

    switch(opc) {
        case 1:
            
            medicamentos.open("clientes.txt",ios::app);

            medicamentos << cliente.nome << "\n" 
                         << cliente.idade << "\n" 
                         << cliente.cpf 
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

void removercliente() {

    int opc, i, contadorSaida = 0;
    string cod, codDoc, medicamento, medicamentoSaida;
    ifstream listaClientes;
    ofstream listaClientesCopia;
    Cliente clienteSaida;

    string letra;

    limpatela();
    cout << "Menu de remoção de clientes: \n\n";
    cout << "\t1 - Inserir código para remover.\n"
         << "\t2 - Listar todos os clientes e inserir código.\n"
         << "\nOpção: ";
    
    cin >> opc;

    switch(opc){
    case 2:
        listarclientes(0);
        cout << "\n\n";
    case 1:
        cout << "\n\nInforme o código do clientes para remover."
             << "\n\nCódigo: ";
        cin >> cod;

        listaClientes.open("clientes.txt",ios::in);
        listaClientesCopia.open("clientes.txt",ios::trunc);

        while (clienteSaida.nome != ""){
            clienteSaida.nome = "";
            clienteSaida.idade = "";
            clienteSaida.cpf = "";
            getline(listaClientes,clienteSaida.nome);
            getline(listaClientes,clienteSaida.idade);
            getline(listaClientes,clienteSaida.cpf);

            

            if(clienteSaida.cpf != cod){
                listaClientesCopia << clienteSaida.nome << "\n"
                    << clienteSaida.idade << "\n"
                    << clienteSaida.cpf << "\n\n";
            }
        
        }
        
        listaClientesCopia.close();
        listaClientes.close();
        SubstituirArquivoClientes();
        cout << "Cliente removido com sucesso.\n Pressione enter para continuar...";
        getchar();
        getchar();

        break;
    default:
        cout << "Saindo...";
        break;
    }
}