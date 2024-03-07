#include <stdio.h>

int main(){
    int i;

    for(i = 1; i <= 20; i++){
        if(i <= 10)  
            printf("%d ", i);    
        if(i >= 11)
            printf("%d ", i++);
    }
}