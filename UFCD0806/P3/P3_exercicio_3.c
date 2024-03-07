#include <stdio.h>

int main()
{
    float peso, altura, imc;

    printf("Indique o peso:\n");
    scanf("%f0.2", &peso);
    printf("Indique a altura:\n");
    scanf("%f0.2", &altura);

    imc = peso / (altura * altura);

    if(imc > 25)
        printf("IMC %0.2f esta obeso", imc);
    if(imc < 18.5)
        printf("IMC %0.2f esta muito baixo. Va ao medico", imc);

    return 0;
}
