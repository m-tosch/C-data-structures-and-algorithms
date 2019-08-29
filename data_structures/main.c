#include <stdio.h>
#include <stdlib.h>
#include "header/stack.h"
#include "header/queue.h"
#include "header/bintree.h"

void test_stack();
void test_queue();
void test_bintree();

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
    /*
     * bintree (Binary Search Tree)data_structures
     */
    printf("----- bintree -----\n");
    test_bintree();
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

void test_bintree() {
    int arr_bintree[7] = {60,40,30,50,80,70,90};
    // root node
    tree_node_t* root = NULL;
    root = bintree_insert(root, arr_bintree[0]);
    printf("root: %d\n", root->value);
    // insert
    for(int i=1; i<sizeof(arr_bintree)/sizeof(int); i++) {
        bintree_insert(root, arr_bintree[i]);
    }
    // search
    int search = 70;
    printf("search for %d: %d\n", search, bintree_search(root, search));
    // depth
    printf("depth: %d\n", bintree_depth(root));
    // print
    /*    60
        /    \ 
       40     80 
      /  \   /  \ 
     30  50 70  90 */
    printf("-- inorder\n");
    bintree_inorder(root);
    printf("-- preorder\n");
    bintree_preorder(root);
    printf("-- postorder\n");
    bintree_postorder(root);
    // deallocate
    bintree_destroy(root);
}