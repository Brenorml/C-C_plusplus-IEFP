#include <stdio.h>

int main(){
    int i, num;

    puts("Indique um numero:");
    scanf("%d", &num);

    for (i = 0; i <= num; i++)
            printf("%d ", i); 
}