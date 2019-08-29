#include "../header/stack.h"

/*
 *   Creates the stack. Allocates the memory for initial size
 *
 *   returns:  stack pointer if memory allocation was successfull
 *             NULL if memory allocation failed
 */
stack_t* stack_init(){
    stack_t *stack = malloc(sizeof(struct stack_s));
    // memory allocation for stack failed
    if (stack == NULL) {
        return NULL;
    }
    stack->top = NULL;
    return stack;
}

/*
 *   Destroys the stack. Deallocates the memory
 *
 *   *stack: stack pointer
 *
 *   returns: 1 if the stack memory was never allocated
 *            0 if the stack memory was successfully deallocated
 */
int stack_destroy(stack_t *stack) {
    if (stack == NULL) {
        return 1;
    }
    while(stack->top != NULL) {
        struct stack_node_s *node = stack->top;
        stack->top = node->next;
        free(node);
    }
    free(stack);
    return 0;
}

/*
 *   Counts the number of elements on the stack
 *
 *   *stack: stack pointer
 *
 *   returns: the number of elements on the stack
 *            -1 if the stack was never allocated
 */
int stack_count(stack_t *stack) {
    if (stack == NULL) {
        return -1;
    }
    unsigned int i;
    struct stack_node_s *n;
    for(i=1, n=stack->top; n->next; i++, n=n->next);
	return i;
}

/*
 *   Checks if the stack is empty
 *
 *   *stack: stack pointer
 *
 *   returns: 1 if the stack is empty or NULL
 *            0 otherwise
 */
int stack_empty(stack_t *stack) {
    if (stack == NULL || stack->top == NULL) {
        return 1;
    } else {
        return 0;
    }
}

/*
 *   Pushes a new element onto the stack
 *
 *   *stack: stack pointer
 *   *data: void data pointer
 *
 *   returns: 0 if successfull
 *            1 if the stack was never allocated
 *            2 if memory allocation for new stack element failed
 */
int stack_push(stack_t *stack, void *data) {
    if (stack == NULL) {
        return 1;
    }
    struct stack_node_s *node = malloc(sizeof(struct stack_node_s));
    if(node == NULL){
        return 2;
    }
    node->data = data;
    node->next = stack->top;
    stack->top = node;
    return 0;
}

/*
 *   Removes and returns the top element from the stack
 *
 *   *stack: stack pointer
 *
 *   returns: top stack element if stack is not empty and was allocated
 *            NULL if stack is empty or wasn't allocated
 */
void *stack_pop(stack_t *stack) {
    if (stack == NULL || stack->top == NULL) {
        return NULL;
    }
    struct stack_node_s *node = stack->top;
    void *data = node->data;
    stack->top = node->next;
    free(node);
    return data;
}

/*
 *   Returns the top element from the stack without removing it
 *
 *   *stack: stack pointer
 *
 *   returns: top stack element
 */
void *stack_peek(stack_t *stack) {
    if (stack == NULL || stack->top == NULL) {
        return NULL;
    }
    return stack->top->data;
}

/*
 *   Prints the elements on the stack and their index bottom to top
 *   --- INTEGER ONLY ---
 *
 *   *stack: stack pointer
 * 
 *   returns: 0 if the stack was printed
 *           -1 if stack is NULL
 */
int stack_print(stack_t *stack) {
    if (stack == NULL) {
        return -1;
    }
    unsigned int i;
    struct stack_node_s *n;
    for(i=0, n=stack->top; n->data; i++, n=n->next){
        printf("[%d]: %d\n", i, *((int*)n->data));
        if(!n->next){
            break;
        }
    }
    return 0;
}