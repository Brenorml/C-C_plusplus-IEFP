#include <stdio.h>

int main()
{
    int raio;
    float pi = 3.1415, area;

    printf("Insira o raio da circunferencia:\n");
    scanf("%d", &raio);

    area = pi * (float)(raio * raio);
    printf("A area da circunferencia = %0.2f", area);
    
    return 0;
}