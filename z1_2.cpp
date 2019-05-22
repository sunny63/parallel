#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[])
{
    int count, num, sum;
    printf("Последовательная область 1\n");
    #pragma omp parallel
        {
            count = omp_get_num_threads();
            num = omp_get_thread_num();
            if (num == 0) printf("Всего нитей: %d\n", count);
            else {
                printf("Параллельная область №%d\n", num);
                sum++;
            }
        }
    printf("Последовательная область 2\n");
    printf("Сумма параллельних областей: %d\n", sum);
    return 0;
}