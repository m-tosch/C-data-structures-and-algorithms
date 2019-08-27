#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


void test_stack();


int main(){
    /*
     * stack (LIFO)
     */
    printf("----- stack -----\n");
    test_stack();
}


void test_stack() {
    // allocate
    stack_t *stack = stack_init();
    // push
    int arr_stack[5] = {44,55,66,77,88};
    for(int i=0; i<sizeof(arr_stack)/sizeof(int); i++){
        stack_push(stack, &arr_stack[i]);
    }
    printf("len: %d\n", stack_count(stack));
    stack_print(stack);
    // peek
    int e = *((int*) stack_peek(stack));
    printf("peek.. %d\n", e);
    printf("len: %d\n", stack_count(stack));
    stack_print(stack);
    // pop
    int f = *((int*) stack_pop(stack));
    printf("pop.. %d\n", f);
    printf("len: %d\n", stack_count(stack));
    stack_print(stack);
    // deallocate
    stack_destroy(stack);
}