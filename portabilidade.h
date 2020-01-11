/*void limpatela() {
    system("cls");
    //system("clear");
}*/

void limpatela() {
    #ifdef WINDOWS

    //...codigo apenas pro windows aqui
        system("cls");

    #else

    //...codigo pra outro sistema
        system("clear");
    #endif
}