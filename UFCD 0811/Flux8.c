#include <stdio.h>

int main()
{
    float valor;

    printf("Indique o valor do ordenado: ");
    scanf("%f", &valor);

    if (valor)
    {
        if (valor <= 850)
            valor -= valor * 0.06;
        else if (valor > 850 && valor <= 980)
            valor -= valor * 0.1;
        else if (valor > 980 && valor <= 1200)
            valor -= valor * 0.14;
        else if (valor > 1200 && valor <= 1600)
            valor -= valor * 0.2;
        else if (valor > 1600 && valor <= 2400)
            valor -= valor * 0.28;
        else if (valor > 2400 && valor <= 3500)
            valor -= valor * 0.36;
        else if (valor > 3500 && valor <= 6000)
            valor -= valor * 0.44;
        else
            valor -= valor * 0.52;
        printf("O valor liquido do ordenado sera: %0.2f", valor);
    }
    else
        printf("Valor invalido");

    
}