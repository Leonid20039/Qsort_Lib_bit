//112-Чудновский-Леонид
#include"qsort.h"
int q_sort(const void *a, const void *b)
{
    double arg1 =*(const int*)a;
    double arg2 =*(const int*)b;
    int count1 = count_bit(arg1);
    int count2 = count_bit(arg2);

    if (count1 < count2) return -1;
    if (count1 > count2) return 1;
    return 0;
}