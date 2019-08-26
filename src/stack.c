#include "stack.h"

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
    // memory allocation for initial stack elements failed
    if ((stack->bottom = malloc(STACK_INIT_SIZE*sizeof(*(stack->bottom)))) == NULL) {
        free(stack);
        return NULL;
    }
    // memory allocation successfull
    stack->size = STACK_INIT_SIZE;
    stack->len = 0;
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
    free(stack->bottom);
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
	return stack->len;
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
    if (stack == NULL || stack->len == 0) {
        return 1;
    } else {
        return 0;
    }
}

/*
 *   Pushes a new element onto the stack. 
 *   Increases the stack size if full. The amount is specified by #define parameters
 *   If the size is increased, the memory is re-allocated.
 *
 *   *stack: stack pointer
 *   *data: void data pointer
 *
 *   returns: 0 if successfull
 *            1 if the stack was never allocated
 *            2 if memory allocation for increasing the stack size failed
 */
int stack_push(stack_t *stack, void *data) {
    if (stack == NULL) {
        return 1;
    }
    // stack is full. increase size
    if (stack->len == stack->size) {
        size_t new_size = stack->size + STACK_INCR_SIZE;
        void **new_bottom = realloc(stack->bottom, new_size*sizeof(*(stack->bottom)));
        if (new_bottom == NULL) {
            return 2;
        }
        stack->bottom = new_bottom;
        stack->size = new_size;
    }
    stack->bottom[(stack->len)++] = data;
    return 0;
}

/*
 *   Removes and returns the top element from the stack.
 *   Decreases the stack size if necessary as defined by #define parameters.
 *   If the size is decreased, the memory is re-allocated.
 *
 *   *stack: stack pointer
 *
 *   returns: top stack element if stack is not empty and was allocated
 *            NULL if stack is empty or wasn't allocated
 */
void *stack_pop(stack_t *stack) {
    if (stack == NULL || stack->len == 0) {
        return NULL;
    }
    void *data = stack->bottom[--(stack->len)];
    // shrink stack if necessary
    if ((stack->size - stack->len) >= STACK_DIFF_SIZE) {
        size_t new_size = stack->len + (stack->len + STACK_INCR_SIZE) % STACK_INCR_SIZE;
        stack->bottom = realloc(stack->bottom, new_size*sizeof(*(stack->bottom)));
        stack->size = new_size;
    }
    return data;
}

/*
 *   Returns the top element from the stack without removing it.
 *
 *   *stack: stack pointer
 *
 *   returns: top stack element
 */
void *stack_peek(stack_t *stack) {
    if (stack == NULL || stack->len == 0) {
        return NULL;
    }
    return stack->bottom[(stack->len)-1];
}

/*
 *   Prints the elements on the stack and their index bottom to top
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
    for(int i=0; i < stack->len; i++){
        printf("[%d]: %d\n", i, *((int*)stack->bottom[i]));
    }
    return 0;
}