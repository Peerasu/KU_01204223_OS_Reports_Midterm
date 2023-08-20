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
        long thread_num = omp_get_num_threads();
        long thread_id = omp_get_thread_num();

        long first_index = (thread_id*input_size)/thread_num;
        long last_index = ((thread_id+1)*input_size)/thread_num - 1;

        for (long i=first_index; i<=last_index; i++) {
            sum_thread[first_index] += input[i];
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