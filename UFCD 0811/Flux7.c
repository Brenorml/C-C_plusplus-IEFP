#include <stdio.h>

int main()
{
    int valor;

    printf("Indique um valor de 1 a 12: ");
    scanf("%d", &valor);

    if(valor > 0 && valor <=2 || valor == 12)
        printf("Inverno");
    else if(valor > 2 && valor <= 5)
        printf("Primavera");
    else if(valor > 5 && valor <= 8)
        printf("Verao");
    else if(valor > 8 && valor <= 11)
        printf("Outono");
    else
        printf("Valor invalido"); 
}