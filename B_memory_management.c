#include<stdio.h>
#include<stdlib.h>

char global_1, global_2 = 'a', global_3 = 'b';

int stack_show(int n) {
    if (n == 4) {
        return 0;
    }

    printf("stack_%d: %p\n", n, &n);
    return stack_show(n+1);
}

int main() {
    int *heap_1 = (int*)malloc(1*sizeof(int));
    int *heap_2 = (int*)malloc(1*sizeof(int));
    int *heap_3 = (int*)malloc(1*sizeof(int));

    stack_show(1);
    printf("\n");
    
    printf("heap_3: %p\n", &(*heap_3));
    printf("heap_2: %p\n", &(*heap_2));
    printf("heap_1: %p\n", &(*heap_1));
    printf("\n");

    printf("global_1: %p\n", &global_1);
    printf("global_3: %p\n", &global_3);
    printf("global_2: %p\n", &global_2);

    free(heap_1);
    free(heap_2);
    free(heap_3);

    return 0;
}
