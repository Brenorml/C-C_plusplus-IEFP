#include <stdio.h>

int main()
{
    int lado1, lado2;
   
    printf("Escreva o lado 1:\n");
    scanf("%d", &lado1);
    printf("Escreva o lado 2:\n");
    scanf("%d", &lado2);
    
    if(lado1 == lado2)
        printf("Quadrado");
    else
        printf("O perimetro do rectangulo e %d", (lado1 * 2) + (lado2 * 2));

    return 0;
}
