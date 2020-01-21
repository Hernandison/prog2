void gerenciarMedicamentos() {
    bool status = true;
    int opc;
    limpatela();
    do{
        
        cout << "Gerenciador de medicamentos:\n\n";

        cout << "\t1 - Listar todos os medicamentos.\n";
        cout << "\t2 - Cadastrar medicamento.\n";
        cout << "\t3 - Remover medicamento.\n"
            << "\n\t 0 - Voltar ao menu anterior.";

        cout << "\nOpção: ";

        cin >> opc;

        switch (opc)
        {
        case 1:
            listarmedicamentos(1);
            break;
        
        case 2:
            cadastrarmedicamento();
            break;
        
        case 3:
            removermedicamento();
            break;

        default:
            break;
            limpatela();
            cout << "Informe uma opção válida." << endl;
        }
    }while(status);
}

void gerenciarClientes() {
    bool status = true;
    int opc;
    limpatela();
    do{
        
        cout << "Gerenciador de medicamentos:\n\n";

        cout << "\t1 - Listar todos os medicamentos.\n";
        cout << "\t2 - Cadastrar medicamento.\n";
        cout << "\t3 - Remover medicamento.\n"
            << "\n\t 0 - Voltar ao menu anterior.";

        cout << "\nOpção: ";

        cin >> opc;

        switch (opc)
        {
        case 1:
            listarclientes(1);
            break;
        
        case 2:
            cadastrarcliente();
            break;
        
        case 3:
            removercliente();
            break;

        default:
            break;
            limpatela();
            cout << "Informe uma opção válida." << endl;
        }
    }while(status);
}

void dashboard() {
    bool status = true;
    int opc;
    limpatela();
    do{
        
        cout << "Gerenciador de medicamentos:\n\n";

        cout << "\t1 - Gerenciar medicamentos.\n";
        cout << "\t2 - Gerenciar clientes.\n"
             << "\n\t 0 - Voltar ao menu anterior.";

        cout << "\nOpção: ";

        cin >> opc;

        switch (opc)
        {
        case 1:
            gerenciarMedicamentos();
            break;
        
        case 2:
            gerenciarClientes();
            break;
        default:
            break;
            limpatela();
            cout << "Informe uma opção válida." << endl;
        }
    }while(status);

}