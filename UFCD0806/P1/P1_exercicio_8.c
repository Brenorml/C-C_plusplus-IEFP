#include <stdio.h>

int main()
{
    int i = 3, num , calc = 1;

    printf("Insira os 3 valores a multiplicar:\n");
    while(i > 0){        
        scanf("%d", &num);
        calc *= num;
        i--;
    }    
    printf("O resultado da multiplicacao e: %d", calc);    
    return 0;
}