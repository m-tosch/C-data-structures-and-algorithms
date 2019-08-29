#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 8
#define STACK_INCR_SIZE 8
#define STACK_DIFF_SIZE 16 

/*
 * Stack implemented as linked list
 */
struct stack_node_s {
    struct stack_node_s *next;
    void *data;
};

struct stack_s {
    struct stack_node_s *top;
};

typedef struct stack_s stack_t;

/*
 * Allocates the stack in memory
 */
stack_t* stack_init();
/*
 * Deallocates the stack in memory
 */
int stack_destroy(stack_t *stack);
/*
 * Returns the number of elements on the stack
 */
int stack_count(stack_t *stack);
/*
 * Returns 1 if the stack is empty
 */
int stack_empty(stack_t *stack);
/*
 * Pushes the given element onto the stack
 */
int stack_push(stack_t *stack, void *data);
/*
 * Returns the top element from the stack and removes it
 */
void *stack_pop(stack_t *stack);
/*
 * Returns the top element from the stack
 */
void *stack_peek(stack_t *stack);
/*
 * Prints the stack contents bottom to top
 * --- INTEGER ONLY ---
 */
int stack_print(stack_t *stack);

#endif