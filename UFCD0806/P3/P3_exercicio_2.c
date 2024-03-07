#include <stdio.h>

int main()
{
    int idade;

    printf("Indique a idade:\n");
    scanf("%d", &idade);

    if(idade < 18)
        printf("Ainda nao pode tirar a carta");
    else if(idade > 65)
        printf("Ja nao pode tirar a carta");
    else
        printf("Pode tirar a carta");

    return 0;
}
