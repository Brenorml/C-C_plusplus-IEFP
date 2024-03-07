#include <stdio.h>

int main(){
    int box = 13, count6 = 0, count10 = 0, pen = 110, total;

    for (count6 = 0; count6 <= box; count6++){
        count10 = box - count6;
        total = count6 * 6 + count10 * 10;
        if(pen == total)
            printf("Caixas 6: %d, Caixas 10: %d", count6, count10);
    }
}