#include <stdio.h>

int main(){
    int i;

    for (i = 2; i <= 60; i++){
        if(!(i % 2) && i < 40)
            printf("%d ", i);
        if(!(i % 2) && i > 50)
            printf("%d ", i);
    }    
}