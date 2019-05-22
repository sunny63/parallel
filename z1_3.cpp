#include <stdio.h>
#include <omp.h>

int array[8];
int i;

int main(int argc, char *argv[]) {
    int count, num, n;
    printf("Последовательная область 1\n");

#pragma omp parallel
    {
        count = omp_get_num_threads();
        num = omp_get_thread_num();
        if (num == 0) printf("Всего нитей: %d\n", count);
        #pragma omp critical
        {
            n = omp_get_thread_num();
            array[i] = n;
            i++;
        }
    }
    for (i = 7; i >= 0; i--)
    {
        if (i == 0) printf("%d\n", array[i]);
        else
            printf("%d ", array[i]);
    }

    printf("Последовательная область 2\n");
}