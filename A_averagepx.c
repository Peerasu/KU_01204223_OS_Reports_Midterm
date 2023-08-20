#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

// N = MAX_input_size
long N = 500000;

int main() {
    long input_size = 0;
    long n = 0;
    long long sum = 0;

    scanf("%ld", &input_size);

    long *input = (long*)calloc(input_size, sizeof(long));
    for (long i=0; i<input_size; i++) {
        scanf("%ld", &n);
        input[i] = n;
    }

    long long *sum_thread = (long long*)calloc(N, sizeof(long long));

    #pragma omp parallel
    {
        long num = omp_get_num_threads();
        long id = omp_get_thread_num();

        for (long i=(id*input_size)/num; i<((id+1)*input_size)/num; i++) {
            sum_thread[(id*input_size)/num] += input[i];
        }
    }

    for (long i=0; i<N; i++) {
        sum += sum_thread[i];
    }

    printf("%lld\n", sum/input_size);

    free(input);
    free(sum_thread);

    return 0;
}