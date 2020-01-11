
#include <stdio.h>

///RECEBE UM ARRAY DE 11 ESPAÇOS QUE CONTEM O CPF SEM CARACTERES ESPECIAIS
///RETORNA UM VALOR DO TIPO BOOL QUE INFORMA SE O CPF E VALIDO OU NÃO

/////MODO DE USAR
/*

char cpf[10] = {0,0,0,0,0,0,0,0,0,0};
    
    scanf("%s",&cpf);
    
    
    if(verificarCpf(cpf)) {
        //Codigo para um cpf válido
    }else {
        //Codigo para um cpf inválido
    }
*/

bool verificarCpf(char cpf[10]) {

    bool verificador = true;
    int soma = 0;
    int numero = 0;
    int j = 0;

    for (int i = 10; i >= 2; i--)
    {
        numero = cpf[j] - '0';
        soma = soma + (i * numero);
        j++;
    }


    soma = soma*10%11;

    if(soma==10){soma = 0;}

    if(soma != (cpf[9] - '0')) {
        verificador = false;
    }
    //FIM DA PRIMEIRA CAMADA DE VERIFICAÇAO

    soma = 0;
    numero = 0;
    j = 0;

    for (int i = 11; i >= 2; i--)
    {
        numero = cpf[j] - '0';
        soma = soma + (i * numero);
        j++;
    }


    soma = soma*10%11;

    if(soma==10){soma = 0;}

    if(soma != (cpf[10] - '0')) {
        verificador = false;
    }
    //FIM DA SEGUNDA CAMADA DE VERIFICAÇAO

    if(strlen(cpf) != 11)
        verificador = false;

    //FIM DA TERCEIRA VERIFICAÇAO

    return verificador;
    
}

//FIM DA VERIFICAÇÂO DE CPF