#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"


void test_stack();
void test_queue();


int main(){
    /*
     * stack (LIFO)
     */
    printf("----- stack -----\n");
    test_stack();
    /*
     * queue (FIFO)
     */
    printf("----- queue -----\n");
    test_queue();
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

void test_queue() {
    // allocate
    queue_t *queue = queue_init();
    // push
    int arr_queue[5] = {44,55,66,77,88};
    for(int i=0; i<sizeof(arr_queue)/sizeof(int); i++){
        queue_push(queue, &arr_queue[i]);
    }
    printf("count: %d\n", queue_count(queue));
    queue_print(queue);
    // peek
    int g = *((int*) queue_peek(queue));
    printf("peek.. %d\n", g);
    queue_print(queue);
    // pop
    int h = *((int*) queue_pop(queue));
    printf("pop.. %d\n", h);
    queue_print(queue);
    // deallocate
    queue_destroy(queue);
}