#include <stdio.h>

int main()
{
    int valor[4], i, media, count;
    media = count = 0;

    for (i = 0; i < 5; i++){
        printf("Indique o valor %d: ", i + 1);
        scanf("%d", &valor[i]);
        getchar();
        media += valor[i];
    }
    printf("\nA media e: %d\n\n", (media /= i - 1));

    for (i = 0; i < 5; i++){
        if(valor[i] > media){
            printf("%d ", valor[i]);
            count++;
        }
    }
    if(!count)
        printf("Nao ha valores maiores que a media");

    return 0;
}
