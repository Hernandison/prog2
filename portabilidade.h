/*void limpatela() {
    system("cls");
    //system("clear");
}*/

void limpatela() {
    #ifdef WINDOWS
        system("cls");

    #else
        system("clear");
    #endif
}