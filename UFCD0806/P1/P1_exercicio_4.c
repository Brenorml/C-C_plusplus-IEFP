#include <stdio.h>

int main(){
    int num1, num2;

    printf("Escreva os valores que deseja calcular:\n");
    scanf("%d%d", &num1, &num2);    
    printf("x * y = %d\n", num1 * num2);

    return 0;
}