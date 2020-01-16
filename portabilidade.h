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