#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

/*
 * Data node in the queue with reference to the next node
 */
struct queue_node_s {
  struct queue_node_s *next;
  void *data;
};

/*
 * Queue (FIFO) with references to "front" and "back" nodes
 */
struct queue_s {
  struct queue_node_s *front;
  struct queue_node_s *back;
};

typedef struct queue_s queue_t;

/*
 * Allocates the queue in memory
 */
queue_t *queue_init();
/*
 * Deallocates the queue in memory
 */
int queue_destroy(queue_t *queue);
/*
 * Returns the number of elements in the queue
 */
int queue_count(queue_t *queue);
/*
 * Returns 1 if the queue is empty
 */
int queue_empty(queue_t *queue);
/*
 * Pushes the given element into the queue
 */
int queue_push(queue_t *queue, void *data);
/*
 * Returns the front element from the queue and removes it
 */
void *queue_pop(queue_t *queue);
/*
 * Returns the front element from the queue
 */
void *queue_peek(queue_t *queue);
/*
 * Prints the queue contents front to back
 * --- INTEGER ONLY ---
 */
int queue_print(queue_t *queue);

#endif