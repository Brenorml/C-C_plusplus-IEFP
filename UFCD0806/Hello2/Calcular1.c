#include <stdio.h>

int main(){
    int x, y;

    printf("Escreva os valores que deseja calcular:\n");
    scanf("%d%d", &x, &y);
    printf("x + y = %d\n", x + y);
    printf("x * y = %d\n", x * y);

    return 0;
}