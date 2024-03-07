#include <stdio.h>

int main()
{
    int nota;

    printf("Indique um valor de 1 a 20: ");
    scanf("%d", &nota);

    if(nota > 0 && nota <=4)
        nota = 1;
    else if(nota > 4 && nota <= 9)
        nota = 2;
    else if(nota > 9 && nota <= 12)
        nota = 3;
    else if(nota > 12 && nota <= 17)
        nota = 4;
    else
        nota = 5;

    printf("A nota correspondente e: %d", nota);
}
