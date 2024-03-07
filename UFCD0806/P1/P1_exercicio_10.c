#include <stdio.h>

int main()
{
    int prazo;
    float capital, taxa;
    double juros;

    printf("Insira o capital a solicitar:\n");
    scanf("%f", &capital);
    printf("Insira a taxa de juros:\n");
    scanf(" %f", &taxa);
    printf("Insira a quantidade de anos:\n");
    scanf("%d", &prazo);
    
    juros = capital * (taxa/100) * prazo;
    
    printf("O total de juros do emprestimo e %0.2lf", juros);    
    return 0;
}