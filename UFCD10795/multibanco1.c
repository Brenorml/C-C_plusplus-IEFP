#include <stdio.h>

int Levantamento(int valor, int valores[4][2])
{
    if (valor > 0)
    {
        while (valor > 0)
        {
            if (valor >= 100)
            {
                valor -= valores[0][0];
                valores[0][1]++;
            }
            else if (valor >= 50)
            {
                valor -= valores[1][0];
                valores[1][1]++;
            }
            else if (valor >= 20)
            {
                valor -= valores[2][0];
                valores[2][1]++;
            }
            else
            {
                valor -= valores[3][0];
                valores[3][1]++;
            }           
        }
    }
    else
    {
        return 0;
    }
}

int main()
{
    int valor = 0;
    int valores[4][2] = {{100, 0}, {50, 0}, {20, 0}, {10, 0}};
    printf("Insira o valor: ");
    scanf("%d", &valor);

    if (valor % 10 == 0)
    {
        Levantamento(valor, valores);        
        for (int i = 0; i < 4; i++){
            if(valores[i][1] > 0){
                printf("%d nota(s) de %d\n", valores[i][1], valores[i][0]);
            }            
        }
    }
    else
    {
        printf("Nao tem notas com valor menor que 10.");
    }
}