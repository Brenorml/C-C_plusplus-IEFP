#include <stdio.h>
#include <string.h>

int main(){
    int base = 10, count = 0, i = 0;
    int list[4];

    while(i < 5){
        printf("Indique a nota %d: ", i + 1);
        scanf("%d", &list[i]);
        getchar();
        if(list[i] >= base)
            count++;
        i++;
    }
    printf("%d notas sao superiores que 10", count);
}