#include "queue.h"

/*
 *   Creates the queue. Allocates the memory
 *
 *   returns:  queue pointer if memory allocation was successfull
 *             NULL if memory allocation failed
 */
queue_t *queue_init() {
    queue_t *queue = malloc(sizeof(struct queue_s));
    // memory allocation for queue failed
    if (queue == NULL) {
        return NULL;
    }
     // memory allocation successfull
    queue->front = queue->back = NULL;
    return queue;
}

/*
 *   Destroys the queue. Deallocates the memory
 *
 *   *queue: queue pointer
 *
 *   returns: 1 if the queue memory was never allocated
 *            0 if the queue memory was successfully deallocated
 */
int queue_destroy(queue_t *queue) {
    // queue was never allocated
    if (queue == NULL) {
        return 1;
    }
    // iterate over all nodes and deallocate memory
    while (queue->front != NULL) {
        struct queue_node_s *node = queue->front;
        queue->front = node->next;
        free(node);
    }
    free(queue);
    return 0;
}

/*
 *   Counts the number of elements in the queue
 *
 *   *queue: queue pointer
 *
 *   returns: the number of elements in the queue
 *            0 if the queue is empty
 *            -1 if the queue was never allocated
 */
int queue_count(queue_t *queue) {
    if (queue == NULL) {
        return -1;
    }
    if (queue->front == NULL) {
        return 0;
    }
	unsigned int i;
    struct queue_node_s *n;
	for (i = 1, n = queue->front; n->next; i++, n = n->next);
	return i;
}

/*
 *   Checks if the queue is empty
 *
 *   *queue: queue pointer
 *
 *   returns: 1 if the queue is empty or NULL
 *            0 otherwise
 */
int queue_empty(queue_t *queue) {
    if (queue == NULL || queue->front == NULL) {
        return 1;
    } else {
        return 0;
    }
}

/*
 *   Pushes a new element into the queue. 
 *
 *   *queue: stack pointer
 *   *data: void data pointer
 *
 *   returns: 0 if successfull
 *            1 if the queue was never allocated
 *            2 if memory allocation for the new element failed
 */
int queue_push(queue_t *queue, void *data) {
    if (queue == NULL) {
        return 1;
    }
    struct queue_node_s *node = malloc(sizeof(*node));
    if (node == NULL) {
        return 2;
    }
    node->data = data;
    node->next = NULL;
    // first element that is added is both "front" and "back"
    if (queue->back == NULL) {
        queue->front = queue->back = node;
    } else {
        queue->back->next = node;
        queue->back = node;
    }
    return 0;
}

/*
 *   Removes and returns the "front" element from the queue.
 *
 *   *queue: queue pointer
 *
 *   returns: front queue element if queue is not empty and was allocated
 *            NULL if stack is empty or wasn't allocated
 */
void *queue_pop(queue_t *queue) {
    if (queue == NULL || queue->front == NULL) {
        return NULL;
    }
    // pop "front". next node is new "front"
    struct queue_node_s *node = queue->front;
    void *data = node->data;
    queue->front = node->next;
    // if there was only one element in queue
    if (queue->front == NULL) {
        queue->back = NULL;
    }
    free(node);
    return data;
}

/*
 *   Returns the "front" element from the queue without removing it.
 *
 *   *queue: queue pointer
 *
 *   returns: front queue element
 */
void *queue_peek(queue_t *queue) {
    if (queue == NULL || queue->front == NULL) {
        return NULL;
    }
    return queue->front->data;
}

/*
 *   Prints the elements in the queue and their index front to back.
 *
 *   *queue: queue pointer
 * 
 *   returns: 0 if the queue was printed
 *           -1 if queue is NULL or empty
 */
int queue_print(queue_t *queue) {
    if(queue == NULL || queue->front == NULL){
        return -1;
    }
    unsigned int i;
    struct queue_node_s *n;
    for (i = 0, n = queue->front; n->data; i++, n = n->next) {
        printf("[%d]: %d\n", i, *((int*)(n->data)));
        if(!n->next){
            break;
        }
    }
    return 0;
}