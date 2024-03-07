#include <stdio.h>

int main()
{
    int raio;
    float pi = 3.1415, perimetro;

    printf("Insira o raio da circunferencia:\n");
    scanf("%d", &raio);

    perimetro = 2 * pi * (float)raio;
    printf("O perimetro da circunferencia = %0.2f", perimetro);
    
    return 0;
}
