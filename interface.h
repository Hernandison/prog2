void interface() {
    cout << "Menu principal:\n\n";

    cout << "\t1 - Listar todos os medicamentos.\n";
    cout << "\t2 - Cadastrar medicamento.\n";
    cout << "\t3 - Remover medicamento.\n";

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
    case 0:
        break;

    default:
        break;
    }

}