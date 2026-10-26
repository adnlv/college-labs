#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void)
{
    int stack_var;

    int *heap_arr = calloc(3, sizeof(*heap_arr));
    assert(heap_arr != NULL);

    printf("[STACK] stack_var address: %p\n", (void *)&stack_var);
    printf("[STACK] heap_arr address: %p\n", (void *)&heap_arr);
    printf("[HEAP] heap_arr points at: %p\n", (void *)heap_arr);

    heap_arr = realloc(heap_arr, 5 * sizeof(*heap_arr));
    assert(heap_arr != NULL);

    printf("[HEAP] heap_arr points at after realloc: %p\n", (void *)heap_arr);

    printf("[HEAP] heap_arr content:\n");
    for (size_t i = 0; i < 5; ++i)
    {
        printf("  heap_arr[%ld] = %d (%p)\n", i, heap_arr[i], (void *)&heap_arr[i]);
    }

    free(heap_arr);
    return 0;
}