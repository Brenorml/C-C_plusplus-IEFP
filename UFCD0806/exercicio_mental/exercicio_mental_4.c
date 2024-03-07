#include <stdio.h>

int main(){
    int box = 13, count6 = 0, count10 = 0, pen = 100, total, totalComb = 0;

    for (count6 = 0; count6 <= box; count6++){
        for (count10 = 0; count10 <= box - count6; count10++){        
            total = count6 * 6 + count10 * 10;
            if(pen > total){
                printf("Caixas 6: %2d, Caixas 10: %2d\n", count6, count10);
                totalComb++;
            }                
        }
    }
    printf("Total de combinacoes: %d\n", totalComb);
}