#ifndef __C_ADT_QUEUE_H__
#define __C_ADT_QUEUE_H__

/**
 * 
 * Array implementation of queue
 * 
 * */

#include <stdint.h>
#include <stdlib.h>

#ifndef ValueType
#define ValueType int
#endif

// Minimum queue size used to initialize queue
#ifndef MIN_QUEUE_SIZE
#define MIN_QUEUE_SIZE 10
#endif // MIN_QUEUE_SIZE

/**
 * 
 * Data Structure definition for array implementation of Queue
 * 
 * */

struct Queue_s {
    ValueType* arr;
    uint32_t size;      // Current element count in the queue
    uint32_t maxSize;   // Current array size
    uint32_t head;      // Current queue head index in the array (next element to be dequeue)
    uint32_t tail;      // Current queue tail index in the array (next location to be enqueue)
};

// Data Structure Definition
struct Queue_s;
typedef struct Queue_s* Queue;

// Queue API
void init_queue(Queue q);
void enqueue_q(ValueType val, Queue q);
ValueType dequeue_q(Queue q);
ValueType peek_q(Queue q);
int isEmpty_q(Queue q);
void free_q(Queue q);

#endif