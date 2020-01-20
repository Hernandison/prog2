void interface() {
    cout << "Menu principal:\n\n";

    cout << "\t1 - Listar todos os medicamentos.\n";
    cout << "\t2 - Cadastrar medicamento.\n";
    cout << "\t3 - Remover medicamento.\n";
    cout << "\t4 - Listar todos os clientes.\n";
    cout << "\t5 - Cadastrar clientes.\n";
    cout << "\t6 - Remover clientes.\n";
    cout << "\n\t Outro número - Sair do programa\n";

    cout << "\nOpção: ";
}

void dashboard() {
    bool status = true;
    int opc;
    limpatela();

    interface();
    
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
    case 4:
        listarclientes(1);
        break;
    
    case 5:
        cadastrarcliente();
        break;
    
    case 6:
        removercliente();
        break;
    case 0:
        break;

    default:
        break;
    }

}