#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

#include "c_adt_queue.h"
#define ValueType int

#define CONCAT(A, B) A##B

#define ARGUMENT_AMOUNT 7
const char* argumentName[] = {
    "help",

    "test_init_queue",
    "test_enqueue_q",
    "test_dequeue_q",
    "test_peek_q",
    "test_isEmpty_q",
    "test_free_q"
};

// ************************************************************************
// Queue test function declarations
// ************************************************************************
void test_init_queue();
void test_enqueue_q();
void test_dequeue_q();
void test_peek_q();
void test_isEmpty_q();
void test_free_q();

// ************************************************************************
// Helper functions for print
// ************************************************************************
#define MAX_SECTION_LENGTH "68"
void printSectionBlock(char * strings[], int rowCount) {
    printf("/************************************************************************/\n");
    for (int i = 0; i < rowCount; i++) {
        printf("/* %-"MAX_SECTION_LENGTH"s */\n", strings[i]);
    }
    printf("/************************************************************************/\n");
}

void printSectionSingle(char * string) {
    printf("/************************************************************************/\n");
    printf("/* %-"MAX_SECTION_LENGTH"s */\n", string);
    printf("/************************************************************************/\n");
}

#define MAX_SUB_SECTION_LENGTH "42"
void printSubSectionBlock(char * string) {
    printf("+--------------------------------------------+\n");
    printf("| %-"MAX_SUB_SECTION_LENGTH"s |\n", string);
    printf("+--------------------------------------------+\n");
}

void printDivider() {
    printf("\n");
    printf("----------------------------------------------\n");
    printf("\n");
}

void printNewLine() {
    printf("\n");
}

// ************************************************************************
// Main test program
// ************************************************************************
int main(int argc, char* argv[]) {
    dup2(1, 2); // Redirect stderr to stdout
    printNewLine();
    if (argc == 1) {
        // Run all test
        char * header[] = {
            "Begin all test functions for c_adt_queue"
        };
        char * footer[] = {
            "Test complete for all test functions of c_adt_queue"
        };
        printSectionBlock(header, 1);

        // LL test functions
        printSectionSingle("Begin testing for Queue");
        test_init_queue();
        test_enqueue_q();
        test_peek_q();
        test_dequeue_q();
        test_isEmpty_q();
        test_free_q();
        printSectionSingle("Test complete for Queue");

        printSectionBlock(footer, 1);
    } else {
        // Split the argument strings to run individual test
        char * header[] = {
            "Begin specific test functions for c_adt_queue"
        };
        char * footer[] = {
            "Test complete for all specific functions of c_adt_queue"
        };
        printSectionBlock(header, 1);
        for (int i = 1; i < argc; i++) {
            char * testname = argv[i];
            if (!strcmp(testname, "test_init_queue")) {
                test_init_queue();
            } else if (!strcmp(testname, "test_enqueue_q")) {
                test_enqueue_q();
            } else if (!strcmp(testname, "test_peek_q")) {
                test_peek_q();
            } else if (!strcmp(testname, "test_dequeue_q")) {
                test_dequeue_q();
            } else if (!strcmp(testname, "test_isEmpty_q")) {
                test_isEmpty_q();
            } else if (!strcmp(testname, "test_free_q")) {
                test_free_q();
            } else {
                // Print available arguments
                char * subheader[] = {
                    "Available arguments for testing c_adt_queue"
                };
                char * subfooter[] = {
                    "End of arguments list"
                };
                printSectionBlock(subheader, 1);
                for (int i = 0; i < ARGUMENT_AMOUNT; i++)
                    printf("%s\n", argumentName[i]);
                printSectionBlock(subfooter, 1);
            }
        }
        printSectionBlock(footer, 1);
    }
    printNewLine();
    return 0;
}

// ************************************************************************
// Test function definitions
// ************************************************************************
void test_init_queue() {
    // Preparing testing variables
    char * header[] = {"Testing: ", __func__};
    char * footer[] = {"End Testing", __func__};
    Queue test_queue = malloc(sizeof(struct Queue_s));
    printSectionBlock(header, sizeof(header) / sizeof(char *));

    // Test 1: Initialization of queue
    printSubSectionBlock("testing initialization of stack");
    init_queue(test_queue);
    printNewLine();
    assert(test_queue->arr != NULL);
    assert(test_queue->maxSize == MIN_QUEUE_SIZE);
    assert(test_queue->head == 0);
    assert(test_queue->tail == 0);
    assert(test_queue->size == 0);
    printf("%s complete\n", "testing initialization of stack");
    printDivider();

    free_q(test_queue);
    free(test_queue);
    printSectionBlock(footer, sizeof(footer) / sizeof(char *));
    printNewLine();
}

void test_enqueue_q() {
    // Preparing testing variables
    char * header[] = {"Testing: ", __func__};
    char * footer[] = {"End Testing", __func__};
    Queue test_queue = malloc(sizeof(struct Queue_s));
    init_queue(test_queue);
    printSectionBlock(header, sizeof(header) / sizeof(char *));

    // Test 1: Empty queue
    printSubSectionBlock("testing enqueuing single element into empty queue");
    enqueue_q(1, test_queue);
    printNewLine();
    assert(test_queue->arr != NULL);
    assert(test_queue->maxSize == MIN_QUEUE_SIZE);
    assert(test_queue->head == 0);
    assert(test_queue->tail == 1);
    assert(test_queue->size == 1);
    assert(peek_q(test_queue) == 1);
    printf("%s complete\n", "testing enqueuing single element into empty queue");
    printDivider();

    // Test 2: Queue with single element
    printSubSectionBlock("testing enqueuing elements into queue with single element");
    enqueue_q(2, test_queue);
    printNewLine();
    assert(test_queue->arr != NULL);
    assert(test_queue->maxSize == MIN_QUEUE_SIZE);
    assert(test_queue->head == 0);
    assert(test_queue->tail == 2);
    assert(test_queue->size == 2);
    assert(peek_q(test_queue) == 1);
    printf("%s complete\n", "testing enqueuing elements into queue with single element");
    printDivider();

    // Test 3: Queue with multiple elements
    printSubSectionBlock("testing enqueuing multiple elements into queue");

    // Reset queue
    free_q(test_queue);
    init_queue(test_queue);

    // Begin enqueue
    enqueue_q(1, test_queue);
    enqueue_q(2, test_queue);
    enqueue_q(3, test_queue);
    enqueue_q(4, test_queue);
    enqueue_q(5, test_queue);
    printNewLine();
    assert(test_queue->arr != NULL);
    assert(test_queue->maxSize == MIN_QUEUE_SIZE);
    assert(test_queue->head == 0);
    assert(test_queue->tail == 5);
    assert(test_queue->size == 5);
    assert(peek_q(test_queue) == 1);
    printf("%s complete\n", "testing enqueuing multiple elements into queue");
    printDivider();

    // Test 4: Test automatic resizing
    printSubSectionBlock("testing automatic resizing");

    // Reset queue
    free_q(test_queue);
    init_queue(test_queue);

    // Begin enqueue
    for (int i = 0; i < MIN_QUEUE_SIZE * 2 - 1; i++) {
        enqueue_q(i, test_queue);
        assert(test_queue->arr != NULL);
        assert(test_queue->head == 0);
        assert(test_queue->tail == i + 1);
        assert(test_queue->size == i + 1);
        assert(peek_q(test_queue) == 0);
    }
    assert(test_queue->maxSize >= 2 * MIN_QUEUE_SIZE);
    printNewLine();
    
    printf("%s complete\n", "testing automatic resizing");
    printDivider();

    // Test 5: Circular enqueuing test
    printSubSectionBlock("testing circular enqueuing");

    // Reset queue
    free_q(test_queue);
    init_queue(test_queue);

    // Enqueuing (tail is move to the end)
    for (int i = 0; i < MIN_QUEUE_SIZE - 1; i++) {
        enqueue_q(i, test_queue);
    }

    // Dequeuing (head is move to the center)
    for (int i = 0; i < (MIN_QUEUE_SIZE - 1) / 2; i++) {
        assert(dequeue_q(test_queue) == i);
    }

    // Enqueuing (tail should be in front of head)
    for (int i = MIN_QUEUE_SIZE - 1; i < MIN_QUEUE_SIZE - 1 + (MIN_QUEUE_SIZE - 1) / 2; i++) {
        enqueue_q(i, test_queue);
    }

    assert(test_queue->maxSize == MIN_QUEUE_SIZE);
    assert(test_queue->head > test_queue->tail);
    printNewLine();
    printf("%s complete\n", "testing circular enqueuing");
    printDivider();

    // Test 5: Extensive test
    printSubSectionBlock("Extensive test");

    // Reset queue
    free_q(test_queue);
    init_queue(test_queue);
    
    // Initialize test array
    int test_arr[1000];
    for (int i = 0; i < 1000; i++)
        test_arr[i] = i;
    
    int read_index = 0;
    int write_index = 0;

    // enqueue 500 elements
    for(; write_index < write_index + 500; write_index++)
        enqueue_q(test_arr[write_index], test_arr);

    // read 200 times
    for (; read_index < read_index + 200; read_index++)
        assert(dequeue_q(test_queue) == test_arr[read_index]);
    
    // Enqueue another 300
    for(; write_index < write_index + 300; write_index++)
        enqueue_q(test_arr[write_index], test_arr);

    // Read another 400 elements
    for (; read_index < read_index + 400; read_index++)
        assert(dequeue_q(test_queue) == test_arr[read_index]);

    // Write all into the queue
    for(; write_index < 1000; write_index++)
        enqueue_q(test_arr[write_index], test_arr);
    
    // Read all
    for (; read_index < 1000; read_index++)
        assert(dequeue_q(test_queue) == test_arr[read_index]);

    printNewLine();
    printf("%s complete\n", "Extensive test");
    printDivider();

    free_q(test_queue);
    free(test_queue);
    printSectionBlock(footer, sizeof(footer) / sizeof(char *));
    printNewLine();
}

void test_dequeue_q() {
    // Preparing testing variables
    char * header[] = {"Testing: ", __func__};
    char * footer[] = {"End Testing", __func__};
    Queue test_queue = malloc(sizeof(struct Queue_s));
    init_queue(test_queue);
    printSectionBlock(header, sizeof(header) / sizeof(char *));


    // Test 1: Empty queue
    printSubSectionBlock("testing dequeuing with empty queue");
    printNewLine();
    assert(dequeue_q(test_queue) == 0);
    assert(test_queue->arr != NULL);
    assert(test_queue->maxSize == MIN_QUEUE_SIZE);
    assert(test_queue->head == 0);
    assert(test_queue->tail == 0);
    assert(test_queue->size == 0);
    printf("%s complete\n", "testing dequeuing with empty queue");
    printDivider();

    // Test 2: Queue with single element
    printSubSectionBlock("testing dequeuing with single element queue");
    printNewLine();
    enqueue_q(1, test_queue);
    assert(dequeue_q(test_queue) == 1);
    assert(test_queue->arr != NULL);
    assert(test_queue->maxSize == MIN_QUEUE_SIZE);
    assert(test_queue->head == 0);
    assert(test_queue->tail == 0);
    assert(test_queue->size == 0);
    printf("%s complete\n", "testing dequeuing with single element queue");
    printDivider();

    // Test 3: Queue with multiple elements
    printSubSectionBlock("testing dequeuing with multiple element queue");
    printNewLine();
    for (int i = 1; i < 4; i++)
        enqueue_q(i, test_queue);

    uint32_t head_pos = test_queue->head;
    uint32_t tail_pos = test_queue->tail;
    uint32_t size_orig = test_queue->size;

    for (int i = 1; i < 4; i++) {
        assert(dequeue_q(test_queue) == i);
        assert(test_queue->arr != NULL);
        assert(test_queue->maxSize == MIN_QUEUE_SIZE);
        assert(test_queue->head == i - 1);
        assert(test_queue->tail == tail_pos);
        assert(test_queue->size == size_orig - i);
    }
    printf("%s complete\n", "testing dequeuing with multiple element queue");
    printDivider();

    // Test 4: Test automatic resizing
    printSubSectionBlock("testing automatic resizing");
    printNewLine();
    for (int i = 1; i < MIN_QUEUE_SIZE * 2; i++)
        enqueue_q(i, test_queue);

    assert(test_queue->maxSize >=  2 * MIN_QUEUE_SIZE); // At least expand to twice as the size
        
    uint32_t head_pos = test_queue->head;
    uint32_t tail_pos = test_queue->tail;
    uint32_t size_orig = test_queue->size;

    for (int i = 1; i < MIN_QUEUE_SIZE * 2; i++) {
        assert(dequeue_q(test_queue) == i);
        assert(test_queue->arr != NULL);
        assert(test_queue->size == size_orig - i);
    }
    
    assert(test_queue->maxSize == MIN_QUEUE_SIZE);  // Size should return to MIN_QUEUE_SIZE and not less than it

    printf("%s complete\n", "testing automatic resizing");
    printDivider();

    free_q(test_queue);
    free(test_queue);
    printSectionBlock(footer, sizeof(footer) / sizeof(char *));
    printNewLine();
}

void test_peek_q() {
    // Preparing testing variables
    char * header[] = {"Testing: ", __func__};
    char * footer[] = {"End Testing", __func__};
    Queue test_queue = malloc(sizeof(struct Queue_s));
    init_queue(test_queue);
    printSectionBlock(header, sizeof(header) / sizeof(char *));


    // Test 1: Empty queue
    // Test 2: Queue with single element
    // Test 3: Queue with multiple elements
    // Test 4: Test automatic resizing
    
    free_q(test_queue);
    free(test_queue);
    printSectionBlock(footer, sizeof(footer) / sizeof(char *));
    printNewLine();
}

void test_isEmpty_q() {
    // Preparing testing variables
    char * header[] = {"Testing: ", __func__};
    char * footer[] = {"End Testing", __func__};
    Queue test_queue = malloc(sizeof(struct Queue_s));
    init_queue(test_queue);
    printSectionBlock(header, sizeof(header) / sizeof(char *));


    // Test 1: Empty queue
    // Test 2: Queue with single element
    // Test 3: Queue with multiple elements
    // Test 4: Test automatic resizing
    
    free_q(test_queue);
    free(test_queue);
    printSectionBlock(footer, sizeof(footer) / sizeof(char *));
    printNewLine();
}

void test_free_q() {
    // Preparing testing variables
    char * header[] = {"Testing: ", __func__};
    char * footer[] = {"End Testing", __func__};
    Queue test_queue = malloc(sizeof(struct Queue_s));
    init_queue(test_queue);
    printSectionBlock(header, sizeof(header) / sizeof(char *));


    // Test 1: Empty queue
    // Test 2: Queue with single element
    // Test 3: Queue with multiple elements
    // Test 4: Test automatic resizing
    
    free_q(test_queue);
    free(test_queue);
    printSectionBlock(footer, sizeof(footer) / sizeof(char *));
    printNewLine();
}
