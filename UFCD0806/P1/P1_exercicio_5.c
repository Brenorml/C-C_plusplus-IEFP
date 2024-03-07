#include <stdio.h>

int main()
{
    float valor;    

    printf("Insira o valor em euros:\n");
    scanf("%f", &valor);
    printf("O valor em escudos e: %0.2f", valor * 200.482);    
    return 0;
}