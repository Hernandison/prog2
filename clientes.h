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
    string cpf;
    string idade;
};

using namespace std;

void listarclientes(int acao) {
    limpatela();
    ifstream arqClientes;
    string cliente,separador="!";
    int tamanho,i;
    string letra;
    int tag = 1;

    arqClientes.open("clientes.txt");
    if(arqClientes.is_open()){
        
        while (getline(arqClientes,cliente))
        {
            if(tag == 1){
                cout << "Nome: ";
                tag++;
            }

            while(cliente[i]){
                
                letra = cliente[i];
                
                if(letra=="!"){
                    cout<<"\n";

                    if(tag == 2){
                        cout << "Idade: ";
                        tag++;
                    }
                    else if(tag == 3){
                        cout << "Cpf: ";
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
        cout << "Estamos com problemas para listar os Clientes";
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

    cout << "Informe o nome do cliente: (não adicione espaços Ex: JoãoCarlosPinto):";
    cin >> cliente.nome;

    cout << "Informe a idade:  (não adicione espaços Ex: JoãoCarlosPinto):";
    cin >> cliente.idade;

    cout << "Informe o CPF:  (não adicione espaços Ex: 123456789):";
    cin >> cliente.cpf;

    limpatela();

    cout << "Deseja proceguir com o cadastro? \n\n\tNome: "
         << cliente.nome
         << "\n\tIdade: "
         << cliente.idade
         << "\n\tCPF: "
         << cliente.cpf << endl;
    
    cout << "\n\n\t1 - sim" << endl << "\t2 - não" << endl << "Opção: ";

    int opc;
    cin >> opc;
    ofstream clientes;

    switch(opc) {
        case 1:
            
            clientes.open("clientes.txt",ios::app);

            clientes << cliente.nome << "!" 
                         << cliente.idade << "!" 
                         << cliente.cpf 
                         << "\n";

            clientes.close();

            cout << "O cliente foi cadastrado com sucesso.";

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
    string cod, codDoc, cliente, clienteSaida;
    ifstream listaClientes;
    ofstream listaClientesCopia;

    string letra;

    limpatela();
    cout << "Menu de remoção de clientes: \n\n";
    cout << "\t1 - Inserir código para remover.\n"
         << "\t2 - Listar todos os clientes e inserir código.\n"
         << "\nOpção: ";
    
    cin >> opc;
    switch (opc)
    {
    case 2:
        listarclientes(0);
        cout << "\n\n";
    case 1:
        cout << "\n\nInforme o CPF do cliente para remover."
             << "\n\nCPF: ";
        cin >> cod;

        listaClientes.open("clientes.txt",ios::in);
        listaClientesCopia.open("clientesc.txt",ios::trunc);
        
        while(getline(listaClientes,cliente)){
            i = cliente.length();
            do
            {
                letra = cliente[i];
                if(letra == "!")
                break;
                i--;
            } while (cliente[i]);

            i+=1;

            while (i < cliente.length())
            {
                clienteSaida += cliente[i];
                contadorSaida++;
                i++;
            }

            
            contadorSaida = 0;


            
            if(cod != clienteSaida) {
                listaClientesCopia << cliente << endl;
            }
            
            
            clienteSaida = "";
        }

        
        listaClientesCopia.close();
        listaClientes.close();
        SubstituirArquivoCliente();

        cout << "\n\nCliente removido com sucesso.\n Pressione enter para voltar ao menu...";
        getchar();
        getchar();
        dashboard();

        break;
    default:
        break;
    }
}