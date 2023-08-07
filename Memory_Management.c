#include<stdio.h>
#include<stdlib.h>

char global_1, global_2 = 'a', global_3 = 'b';

int stack_show(int n) {
    if (n == 4) {
        return 0;
    }

    printf("stack_%d: %d\n", n, &n);
    return stack_show(n+1);
}

void heap_show(int *heap_1, int *heap_2, int *heap_3) {
    printf("heap_1: %d\n", &(*heap_1));
    printf("heap_2: %d\n", &(*heap_2));
    printf("heap_3: %d\n", &(*heap_3));
}

void global_show(char* global_1_addr, char* global_2_addr, char* global_3_addr) {
    printf("global_1: %d\n", global_1_addr);
    printf("global_2: %d\n", global_2_addr);
    printf("global_3: %d\n", global_3_addr);
}


int main() {
    int stack_1, stack_2 = 0, stack_3 = 1;

    int *heap_1 = (int*)malloc(1*sizeof(int));
    int *heap_2 = (int*)malloc(1*sizeof(int));
    int *heap_3 = (int*)malloc(1*sizeof(int));

    stack_show(1);
    printf("\n");
    heap_show(heap_1, heap_2, heap_3);
    printf("\n");
    global_show(&global_1, &global_2, &global_3);

    free(heap_1);
    free(heap_2);
    free(heap_3);

    return 0;
}
