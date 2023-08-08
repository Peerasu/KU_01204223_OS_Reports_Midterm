#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<math.h>

int main() {
    int n=0, m=0, sum=0;
    scanf("%d", &n);

    int *input = (int*)malloc(sizeof(int)*n);
    for (int i=0; i<n; i++) {
        scanf("%d", &m);
        input[i] = m;
    }

    int thread_num = omp_get_num_threads();
    int thread_size = (int)ceil(n/thread_num);

    int *sub_sum = (int*)malloc(sizeof(int)*thread_num);


    #pragma omp parallel 
    {
        int id=omp_get_thread_num();
        int s=0;

        for (int i=id*thread_size; i<(id+1)*thread_size; i++) {
            if (i == n) {
                break;
            }
            s += input[i];
        }

        sub_sum[id] = s;
    }

    for (int i=0; i<thread_num; i++) {
        sum += sub_sum[i];
    }

    printf("%d\n", (int)floor(sum/n));

    free(input);
    free(sub_sum);

    return 0;
}