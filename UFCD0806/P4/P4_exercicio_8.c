#include <stdio.h>

int main(){
    int i, num1, num2;

    puts("Indique o primeiro numero:");
    scanf("%d", &num1);
    puts("Indique o segundo numero:");
    scanf("%d", &num2);

    for (i = num1 + 1; i < num2; i++)
            printf("%d ", i); 
}