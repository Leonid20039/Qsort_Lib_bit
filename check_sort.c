//112-Чудновский-Леонид
#include<stdio.h>
#include"qsort.h"
#define N 25000
void check_sort(int *mass){
    int a, b, c;
    for(int i = 0; i < N - 1; i++){
        b = count_bit(mass[i]);
        c = count_bit(mass[i + 1]);
        if(b > c){
            a = 1;
        }
    }
        if (a == 0){
            printf("The mass is correctly sorted\n");
        }
        if (a == 1){
            printf("The mass is not correctly sorted\n");
        } 
}