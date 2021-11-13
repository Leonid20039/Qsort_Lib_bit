//112-Чудновский-Леонид
//Сортировка с помощью библиотечной функции qsort в по количеству единичных битов числа
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"qsort.h"
#define N 25000

int main(void)
{
    FILE*fin;
    char filename[120];
    time_t start, end;
    int Low = -1000;
    int High = 1000;
    int mass[N];
    int a, mass_bit[N], b;
    printf("Enter file name:");
    scanf("%s", filename);
    fin = fopen(filename, "w");

    if(!fin){
        printf("Unable to open %s\n", filename);
        return 1;
    }

    for(int i = 0; i < N; i++){
        mass[i] = random(Low, High);
        fprintf(fin, "%d  ", mass[i]);
    }

    //Сортируем
    start = clock();
    qsort(mass, N, sizeof(int), q_sort);
    end = clock();
    check_sort(mass);

    //Выводим
    fprintf(fin, "Sort mass:\n");
    for(int i = 0; i < N; i++){
        a = count_bit(mass[i]);
        fprintf(fin, "%d   ", mass[i]);
         
        for(int j = 1; j < 32; j++){
            mass_bit[32-j] = mass[i]&1;
            fprintf(fin, "%d", mass_bit[32-j]);
            mass[i] >>= 1;
        }
        fprintf(fin, "    %d\n", a);
    }

    printf("Time: %lf", (double)((end - start))/CLOCKS_PER_SEC);
}