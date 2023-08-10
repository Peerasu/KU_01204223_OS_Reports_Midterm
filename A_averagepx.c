#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main() {
    int n=0, m=0, sum=0;
    scanf("%d", &n);

    int *input = (int*)malloc(sizeof(int)*n);
    for (int i=0; i<n; i++) {
        scanf("%d", &m);
        input[i] = m;
    }

    int *sub_sum = (int*)malloc(sizeof(int)*n);
    for (int i=0; i<n; i++) {
        sub_sum[i] = 0;
    }

    #pragma omp parallel
    {
        int num=omp_get_num_threads();
        int id=omp_get_thread_num();
        int s=0;

        for (int i=id/num*n; i<(id+1)/num*n; i++) {
            if (i == n) {
                break;
            }
            s += input[i];
        }

        sub_sum[id] = s;
    }

    for (int i=0; i<n; i++) {
        sum += sub_sum[i];
    }

    printf("%d\n", sum/n);

    free(input);
    free(sub_sum);

    return 0;
}