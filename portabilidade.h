/*void limpatela() {
    system("cls");
    //system("clear");
}*/

void limpatela() {
    #ifdef __linux__
        system("clear");

    #else
        system("cls");
    #endif
}

void SubstituirArquivoMedicamento() {
    #ifdef __linux__
        system("rm medicamentos.txt");
        system("mv medicamentosc.txt medicamentos.txt");
    #else
        system("del medicamentos.txt");
        system("RENAME medicamentosc.txt medicamentos.txt");
    #endif
}