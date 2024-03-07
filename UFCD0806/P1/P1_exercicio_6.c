#include <stdio.h>

int main(){
    int num1, num2;
    printf("Inisira os numeros:\n");
    scanf("%d%d", &num1, &num2);
    //Assumindo que não é necessário guardar o valor do cálculo na memória
    printf("O resultado de %d - %d = %d\n", num1, num2, num1 - num2);
    return 0;
}