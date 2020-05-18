#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

#include "c_adt_dequeue.h"
#define ValueType int

#define ARGUMENT_AMOUNT 10
const char* argumentName[] = {
    "help",

    "test_init_dequeue",
    "test_insertHead_dq",
    "test_insertTail_dq",
    "test_removeHead_dq",
    "test_removeTail_dq",
    "test_peekHead_dq",
    "test_peekTail_dq",
    "test_isEmpty_dq",
    "test_free_dq"
};

// ************************************************************************
// Queue test function declarations
// ************************************************************************
void test_init_dequeue();
void test_insertHead_dq();
void test_insertTail_dq();
void test_removeHead_dq();
void test_removeTail_dq();
void test_peekHead_dq();
void test_peekTail_dq();
void test_isEmpty_dq();
void test_free_dq();

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
            "Begin all test functions for",
            (char *) __FILE__
        };
        char * footer[] = {
            "Test complete for all test functions of",
            (char *) __FILE__
        };

        printSectionBlock(header, sizeof(header) / sizeof(header[0]));

        // test functions
        printSectionSingle("Begin testing");
        test_init_dequeue();
        test_insertHead_dq();
        test_insertTail_dq();
        test_removeHead_dq();
        test_removeTail_dq();
        test_peekHead_dq();
        test_peekTail_dq();
        test_isEmpty_dq();
        test_free_dq();
        printSectionSingle("Test complete");

        printSectionBlock(footer, sizeof(footer) / sizeof(footer[0]));
    } else {
        // Split the argument strings to run individual test
        char * header[] = {
            "Begin specific test functions for",
            (char *) __FILE__
        };
        char * footer[] = {
            "Test complete for all specific functions of",
            (char *) __FILE__
        };
        
        printSectionBlock(header, sizeof(header) / sizeof(header[0]));
        for (int i = 1; i < argc; i++) {
            char * testname = argv[i];
            if (!strcmp(testname, "test_init_dequeue")) {
                test_init_dequeue();
            } else if (!strcmp(testname, "test_insertHead_dq")) {
                test_insertHead_dq();
            } else if (!strcmp(testname, "test_insertTail_dq")) {
                test_insertTail_dq();
            } else if (!strcmp(testname, "test_removeHead_dq")) {
                test_removeHead_dq();
            } else if (!strcmp(testname, "test_removeTail_dq")) {
                test_removeTail_dq();
            } else if (!strcmp(testname, "test_peekHead_dq")) {
                test_peekHead_dq();
            } else if (!strcmp(testname, "test_peekTail_dq")) {
                test_peekTail_dq();
            } else if (!strcmp(testname, "test_isEmpty_dq")) {
                test_isEmpty_dq();
            } else if (!strcmp(testname, "test_free_dq")) {
                test_free_dq();
            } else {
                // Print available arguments
                char * subheader[] = {
                    "Available arguments for testing",
                    (char *) __FILE__
                };
                char * subfooter[] = {
                    "End of arguments list"
                };
                printSectionBlock(subheader, sizeof(subheader) / sizeof(subheader[0]));
                for (int i = 0; i < ARGUMENT_AMOUNT; i++)
                    printf("%s\n", argumentName[i]);
                printSectionBlock(subfooter, sizeof(subfooter) / sizeof(subfooter[0]));
            }
        }        
        printSectionBlock(footer, sizeof(footer) / sizeof(footer[0]));
    }
    printNewLine();
    return 0;
}

// ************************************************************************
// Test function definitions
// ************************************************************************
void test_init_dequeue() {
    // Preparing testing variables
    char * header[] = {"Testing: ", (char *)__func__};
    char * footer[] = {"End Testing", (char *)__func__};
    Dequeue test_dequeue = malloc(sizeof(struct Dequeue_s));
    printSectionBlock(header, sizeof(header) / sizeof(char *));

    // Test 1: Initialization of dequeue
    printSubSectionBlock("testing initialization of dequeue");
    init_dequeue(test_dequeue);
    printNewLine();
    assert(test_dequeue->arr != NULL);
    assert(test_dequeue->maxSize == MIN_QUEUE_SIZE);
    assert(test_dequeue->head == 0);
    assert(test_dequeue->tail == 0);
    assert(test_dequeue->size == 0);
    printf("%s complete\n", "testing initialization of dequeue");
    printDivider();

    // Cleaning up
    free_dq(test_dequeue);
    free(test_dequeue);
    printSectionBlock(footer, sizeof(footer) / sizeof(char *));
    printNewLine();
}

void test_insertHead_dq() {
    // Preparing testing variables
    char * header[] = {"Testing: ", (char *)__func__};
    char * footer[] = {"End Testing", (char *)__func__};
    Dequeue test_dequeue = malloc(sizeof(struct Dequeue_s));
    init_dequeue(test_dequeue);
    printSectionBlock(header, sizeof(header) / sizeof(char *));

    // Test 1: Empty Dequeue
    printSubSectionBlock("testing insertHead for single element into empty dequeue");
    printNewLine();
    insertHead_dq(1, test_dequeue);
    assert(test_dequeue->arr != NULL);
    assert(test_dequeue->maxSize == MIN_QUEUE_SIZE);
    assert(test_dequeue->head == MIN_QUEUE_SIZE - 1);
    assert(test_dequeue->tail == 0);
    assert(test_dequeue->size == 1);
    assert(peekHead_dq(test_dequeue) == 1);
    assert(peekTail_dq(test_dequeue) == 1);
    printf("%s complete\n", "testing insertHead for single element into empty dequeue");
    printDivider();

    // Test 2: Dequeue with single element
    printSubSectionBlock("testing insertHead for single element into single element dequeue");
    printNewLine();
    insertHead_dq(2, test_dequeue);
    assert(test_dequeue->arr != NULL);
    assert(test_dequeue->maxSize == MIN_QUEUE_SIZE);
    assert(test_dequeue->head == MIN_QUEUE_SIZE - 2);
    assert(test_dequeue->tail == 0);
    assert(test_dequeue->size == 2);
    assert(peekHead_dq(test_dequeue) == 2);
    assert(peekTail_dq(test_dequeue) == 1);
    printf("%s complete\n", "testing insertHead for single element into single element dequeue");
    printDivider();

    // Test 3: Dequeue with multiple elements
    printSubSectionBlock("testing insertHead element into multiple elements dequeue");
    printNewLine();
    free_dq(test_dequeue);
    init_dequeue(test_dequeue);
    insertHead_dq(1, test_dequeue);
    insertHead_dq(2, test_dequeue);
    insertHead_dq(3, test_dequeue);
    insertHead_dq(4, test_dequeue);
    assert(test_dequeue->arr != NULL);
    assert(test_dequeue->maxSize == MIN_QUEUE_SIZE);
    assert(test_dequeue->head == MIN_QUEUE_SIZE - 4);
    assert(test_dequeue->tail == 0);
    assert(test_dequeue->size == 4);
    assert(peekHead_dq(test_dequeue) == 4);
    assert(peekTail_dq(test_dequeue) == 1);
    printf("%s complete\n", "testing insertHead element into multiple elements queue");
    printDivider();

    // Test 4: Test automatic resizing
    printSubSectionBlock("testing automatic resizing");
    printNewLine();
    free_dq(test_dequeue);
    init_dequeue(test_dequeue);
    for (int i = 1; i < 2 * MIN_QUEUE_SIZE; i++)
        insertHead_dq(i, test_dequeue);
    assert(test_dequeue->arr != NULL);
    assert(test_dequeue->maxSize >= 2 * MIN_QUEUE_SIZE);
    assert(test_dequeue->size == 2 * MIN_QUEUE_SIZE - 1);
    assert(peekHead_dq(test_dequeue) == 2 * MIN_QUEUE_SIZE - 1);
    assert(peekTail_dq(test_dequeue) == 1);
    printf("%s complete\n", "testing automatic resizing");
    printDivider();

    // Test 5: Circular insertion and deletion test
    printSubSectionBlock("testing circular insertHead");

    // Reset queue
    free_dq(test_dequeue);
    init_dequeue(test_dequeue);

    // Enqueuing (tail is move to the end)
    for (int i = 0; i < MIN_QUEUE_SIZE - 1; i++) {
        insertHead_dq(i, test_dequeue);
    }

    // Dequeuing (head is move to the center)
    for (int i = 0; i < (MIN_QUEUE_SIZE - 1) / 2; i++) {
        assert(removeTail_dq(test_dequeue) == i);
    }

    // Enqueuing (tail should be in front of head)
    for (int i = MIN_QUEUE_SIZE - 1; i < MIN_QUEUE_SIZE - 1 + (MIN_QUEUE_SIZE - 1) / 2; i++) {
        insertHead_dq(i, test_dequeue);
    }

    assert(test_dequeue->maxSize == MIN_QUEUE_SIZE);
    assert(test_dequeue->head > test_dequeue->tail);
    printNewLine();
    printf("%s complete\n", "testing circular insertHead");
    printDivider();

    // Test 6: Extensive test
    printSubSectionBlock("Extensive mixture test");

    // Reset queue
    free_dq(test_dequeue);
    init_dequeue(test_dequeue);
    
    // Initialize test array
    int test_arr[1000];
    for (int i = 0; i < 1000; i++)
        test_arr[i] = i;
    
    int read_index = 0;
    int write_index = 0;
    int tmp = write_index;

    // Mix insertHead and insertTail
    // Mix removeHead and removeTail

    // Insert 500 elements at tail
    for (; write_index < tmp + 500; write_index++)
        insertTail_dq(test_arr[write_index], test_dequeue);
    
    // Remove 200 elements from head
    tmp = read_index;
    for (; read_index < tmp + 200; read_index++)
        assert(removeHead_dq(test_dequeue) == test_arr[read_index]);
    
    // Insert another 200 element at head
    tmp = write_index;
    for(; write_index < tmp + 200; write_index++)
        insertHead_dq(test_arr[write_index], test_dequeue);
    
    // Remove the rest 300 first elements from tail
    tmp = read_index;
    for(read_index = 499; read_index >= 200; read_index--)
        assert(removeTail_dq(test_dequeue) == test_arr[read_index]);

    read_index = 699;
    // Remove the 200 elements from Head
    for (; read_index >= 500; read_index--)
        assert(removeHead_dq(test_dequeue) == test_arr[read_index]);

    printNewLine();
    printf("%s complete\n", "Extensive mixture test");
    printDivider();

    // Cleaning up
    free_dq(test_dequeue);
    free(test_dequeue);
    printSectionBlock(footer, sizeof(footer) / sizeof(char *));
    printNewLine();
}

void test_insertTail_dq() {
    // Preparing testing variables
    char * header[] = {"Testing: ", (char *)__func__};
    char * footer[] = {"End Testing", (char *)__func__};
    Dequeue test_dequeue = malloc(sizeof(struct Dequeue_s));
    init_dequeue(test_dequeue);
    printSectionBlock(header, sizeof(header) / sizeof(char *));

    // Test 1: Empty Dequeue
    printSubSectionBlock("testing insertTail for single element into empty dequeue");
    printNewLine();
    insertTail_dq(1, test_dequeue);
    assert(test_dequeue->arr != NULL);
    assert(test_dequeue->maxSize == MIN_QUEUE_SIZE);
    assert(test_dequeue->head == 0);
    assert(test_dequeue->tail == 1);
    assert(test_dequeue->size == 1);
    assert(peekHead_dq(test_dequeue) == 1);
    assert(peekTail_dq(test_dequeue) == 1);
    printf("%s complete\n", "testing insertTail for single element into empty dequeue");
    printDivider();

    // Test 2: Dequeue with single element
    printSubSectionBlock("testing insertTail for single element into single element dequeue");
    printNewLine();
    insertTail_dq(2, test_dequeue);
    assert(test_dequeue->arr != NULL);
    assert(test_dequeue->maxSize == MIN_QUEUE_SIZE);
    assert(test_dequeue->head == 0);
    assert(test_dequeue->tail == 2);
    assert(test_dequeue->size == 2);
    assert(peekHead_dq(test_dequeue) == 1);
    assert(peekTail_dq(test_dequeue) == 2);
    printf("%s complete\n", "testing insertTail for single element into single element dequeue");
    printDivider();

    // Test 3: Dequeue with multiple elements
    printSubSectionBlock("testing insertTail element into multiple elements dequeue");
    printNewLine();
    free_dq(test_dequeue);
    init_dequeue(test_dequeue);
    insertTail_dq(1, test_dequeue);
    insertTail_dq(2, test_dequeue);
    insertTail_dq(3, test_dequeue);
    insertTail_dq(4, test_dequeue);
    assert(test_dequeue->arr != NULL);
    assert(test_dequeue->maxSize == MIN_QUEUE_SIZE);
    assert(test_dequeue->head == 0);
    assert(test_dequeue->tail == 4);
    assert(test_dequeue->size == 4);
    assert(peekHead_dq(test_dequeue) == 1);
    assert(peekTail_dq(test_dequeue) == 4);
    printf("%s complete\n", "testing insertTail element into multiple elements queue");
    printDivider();

    // Test 4: Test automatic resizing
    printSubSectionBlock("testing automatic resizing");
    printNewLine();
    free_dq(test_dequeue);
    init_dequeue(test_dequeue);
    for (int i = 1; i < 2 * MIN_QUEUE_SIZE; i++)
        insertTail_dq(i, test_dequeue);
    assert(test_dequeue->arr != NULL);
    assert(test_dequeue->maxSize >= 2 * MIN_QUEUE_SIZE);
    assert(test_dequeue->size == 2 * MIN_QUEUE_SIZE - 1);
    assert(peekHead_dq(test_dequeue) == 1);
    assert(peekTail_dq(test_dequeue) == 2 * MIN_QUEUE_SIZE - 1);
    printf("%s complete\n", "testing automatic resizing");
    printDivider();

    // Cleaning up
    free_dq(test_dequeue);
    free(test_dequeue);
    printSectionBlock(footer, sizeof(footer) / sizeof(char *));
    printNewLine();
}

void test_removeHead_dq() {
    // Preparing testing variables
    char * header[] = {"Testing: ", (char *)__func__};
    char * footer[] = {"End Testing", (char *)__func__};
    Dequeue test_dequeue = malloc(sizeof(struct Dequeue_s));
    init_dequeue(test_dequeue);
    printSectionBlock(header, sizeof(header) / sizeof(char *));

    // Test 1: Empty queue
    printSubSectionBlock("testing removeHead with empty dequeue");
    printNewLine();
    assert(removeHead_dq(test_dequeue) == 0);
    assert(test_dequeue->arr != NULL);
    assert(test_dequeue->maxSize == MIN_QUEUE_SIZE);
    assert(test_dequeue->head == 0);
    assert(test_dequeue->tail == 0);
    assert(test_dequeue->size == 0);
    printf("%s complete\n", "testing removeHead with empty dequeue");
    printDivider();

    // Test 2: Queue with single element
    printSubSectionBlock("testing removeHead with single element dequeue");
    printNewLine();
    insertTail_dq(1, test_dequeue);
    assert(removeHead_dq(test_dequeue) == 1);
    assert(test_dequeue->arr != NULL);
    assert(test_dequeue->maxSize == MIN_QUEUE_SIZE);
    assert(test_dequeue->head == 1);
    assert(test_dequeue->tail == 1);
    assert(test_dequeue->size == 0);
    printf("%s complete\n", "testing removeHead with single element dequeue");
    printDivider();

    // Test 3: Queue with multiple elements
    printSubSectionBlock("testing removeHead with multiple element dequeue");
    printNewLine();
    free_dq(test_dequeue);
    init_dequeue(test_dequeue);
    for (int i = 1; i < 4; i++)
        insertTail_dq(i, test_dequeue);

    uint32_t head_pos = test_dequeue->head;
    uint32_t tail_pos = test_dequeue->tail;
    uint32_t size_orig = test_dequeue->size;

    for (int i = 1; i < 4; i++) {
        assert(removeHead_dq(test_dequeue) == i);
        assert(test_dequeue->arr != NULL);
        assert(test_dequeue->maxSize == MIN_QUEUE_SIZE);
        assert(test_dequeue->head == i);
        assert(test_dequeue->tail == tail_pos);
        assert(test_dequeue->size == size_orig - i);
    }
    printf("%s complete\n", "testing removeHead with multiple element dequeue");
    printDivider();

    // Test 4: Test automatic resizing
    printSubSectionBlock("testing automatic resizing");
    printNewLine();
    for (int i = 1; i < MIN_QUEUE_SIZE * 2; i++)
        insertTail_dq(i, test_dequeue);

    assert(test_dequeue->maxSize >=  2 * MIN_QUEUE_SIZE); // At least expand to twice as the size
        
    head_pos = test_dequeue->head;
    tail_pos = test_dequeue->tail;
    size_orig = test_dequeue->size;

    for (int i = 1; i < MIN_QUEUE_SIZE * 2; i++) {
        assert(removeHead_dq(test_dequeue) == i);
        assert(test_dequeue->arr != NULL);
        assert(test_dequeue->size == size_orig - i);
    }

    assert(test_dequeue->maxSize == MIN_QUEUE_SIZE);  // Size should return to MIN_QUEUE_SIZE and not less than it

    printf("%s complete\n", "testing automatic resizing");
    printDivider();

    // Cleaning up
    free_dq(test_dequeue);
    free(test_dequeue);
    printSectionBlock(footer, sizeof(footer) / sizeof(char *));
    printNewLine();
}

void test_removeTail_dq() {
    // Preparing testing variables
    char * header[] = {"Testing: ", (char *)__func__};
    char * footer[] = {"End Testing", (char *)__func__};
    Dequeue test_dequeue = malloc(sizeof(struct Dequeue_s));
    init_dequeue(test_dequeue);
    printSectionBlock(header, sizeof(header) / sizeof(char *));

    // Test 1: Empty queue
    printSubSectionBlock("testing removeTail with empty dequeue");
    printNewLine();
    assert(removeTail_dq(test_dequeue) == 0);
    assert(test_dequeue->arr != NULL);
    assert(test_dequeue->maxSize == MIN_QUEUE_SIZE);
    assert(test_dequeue->head == 0);
    assert(test_dequeue->tail == 0);
    assert(test_dequeue->size == 0);
    printf("%s complete\n", "testing removeTail with empty dequeue");
    printDivider();

    // Test 2: Queue with single element
    printSubSectionBlock("testing removeTail with single element dequeue");
    printNewLine();
    insertHead_dq(1, test_dequeue);
    assert(removeTail_dq(test_dequeue) == 1);
    assert(test_dequeue->arr != NULL);
    assert(test_dequeue->maxSize == MIN_QUEUE_SIZE);
    assert(test_dequeue->head == MIN_QUEUE_SIZE - 1);
    assert(test_dequeue->tail == MIN_QUEUE_SIZE - 1);
    assert(test_dequeue->size == 0);
    printf("%s complete\n", "testing removeTail with single element dequeue");
    printDivider();

    // Test 3: Queue with multiple elements
    printSubSectionBlock("testing removeTail with multiple element dequeue");
    printNewLine();
    free_dq(test_dequeue);
    init_dequeue(test_dequeue);
    for (int i = 1; i < 4; i++)
        insertHead_dq(i, test_dequeue);

    uint32_t head_pos = test_dequeue->head;
    uint32_t tail_pos = test_dequeue->tail;
    if (tail_pos == 0)
        tail_pos = test_dequeue->maxSize;
    uint32_t size_orig = test_dequeue->size;

    for (int i = 1; i < 4; i++) {
        assert(removeTail_dq(test_dequeue) == i);
        assert(test_dequeue->arr != NULL);
        assert(test_dequeue->maxSize == MIN_QUEUE_SIZE);
        assert(test_dequeue->head == head_pos);
        assert(test_dequeue->tail == tail_pos - i);
        assert(test_dequeue->size == size_orig - i);
    }
    printf("%s complete\n", "testing removeTail with multiple element dequeue");
    printDivider();

    // Test 4: Test automatic resizing
    printSubSectionBlock("testing automatic resizing");
    printNewLine();
    for (int i = 1; i < MIN_QUEUE_SIZE * 2; i++)
        insertHead_dq(i, test_dequeue);

    assert(test_dequeue->maxSize >=  2 * MIN_QUEUE_SIZE); // At least expand to twice as the size
        
    head_pos = test_dequeue->head;
    tail_pos = test_dequeue->tail;
    size_orig = test_dequeue->size;

    for (int i = 1; i < MIN_QUEUE_SIZE * 2; i++) {
        assert(removeTail_dq(test_dequeue) == i);
        assert(test_dequeue->arr != NULL);
        assert(test_dequeue->size == size_orig - i);
    }

    assert(test_dequeue->maxSize == MIN_QUEUE_SIZE);  // Size should return to MIN_QUEUE_SIZE and not less than it

    printf("%s complete\n", "testing automatic resizing");
    printDivider();

    // Cleaning up
    free_dq(test_dequeue);
    free(test_dequeue);
    printSectionBlock(footer, sizeof(footer) / sizeof(char *));
    printNewLine();
}

void test_peekHead_dq() {
    // Preparing testing variables
    char * header[] = {"Testing: ", (char *)__func__};
    char * footer[] = {"End Testing", (char *)__func__};
    Dequeue test_dequeue = malloc(sizeof(struct Dequeue_s));
    init_dequeue(test_dequeue);
    printSectionBlock(header, sizeof(header) / sizeof(char *));

    // Test 1: Empty queue
    printSubSectionBlock("testing peekHead_dq with empty queue");
    printNewLine();
    assert(peekHead_dq(test_dequeue) == 0);
    printf("%s complete\n", "testing peekHead_dq with empty queue");
    printDivider();

    // Test 2: Queue with single element
    printSubSectionBlock("testing peekHead_dq with single elment queue");
    printNewLine();
    insertTail_dq(1, test_dequeue);
    assert(peekHead_dq(test_dequeue) == 1);
    printf("%s complete\n", "testing peekHead_dq with single elment queue");
    printDivider();

    // Test 3: Queue with multiple elements
    printSubSectionBlock("testing peekHead_dq with multiple elments queue");
    printNewLine();
    free_dq(test_dequeue);
    init_dequeue(test_dequeue);
    insertTail_dq(1, test_dequeue);
    insertTail_dq(2, test_dequeue);
    insertTail_dq(3, test_dequeue);
    assert(peekHead_dq(test_dequeue) == 1);
    removeHead_dq(test_dequeue);
    assert(peekHead_dq(test_dequeue) == 2);
    printf("%s complete\n", "testing peekHead_dq with multiple elments queue");
    printDivider();

    // Clean up
    free_dq(test_dequeue);
    free(test_dequeue);
    printSectionBlock(footer, sizeof(footer) / sizeof(char *));
    printNewLine();
}

void test_peekTail_dq() {
    // Preparing testing variables
    char * header[] = {"Testing: ", (char *)__func__};
    char * footer[] = {"End Testing", (char *)__func__};
    Dequeue test_dequeue = malloc(sizeof(struct Dequeue_s));
    init_dequeue(test_dequeue);
    printSectionBlock(header, sizeof(header) / sizeof(char *));

    // Test 1: Empty queue
    printSubSectionBlock("testing peekTail_dq with empty queue");
    printNewLine();
    assert(peekTail_dq(test_dequeue) == 0);
    printf("%s complete\n", "testing peekTail_dq with empty queue");
    printDivider();

    // Test 2: Queue with single element
    printSubSectionBlock("testing peekTail_dq with single elment queue");
    printNewLine();
    insertHead_dq(1, test_dequeue);
    assert(peekTail_dq(test_dequeue) == 1);
    printf("%s complete\n", "testing peekTail_dq with single elment queue");
    printDivider();

    // Test 3: Queue with multiple elements
    printSubSectionBlock("testing peekTail_dq with multiple elments queue");
    printNewLine();
    free_dq(test_dequeue);
    init_dequeue(test_dequeue);
    insertHead_dq(1, test_dequeue);
    insertHead_dq(2, test_dequeue);
    insertHead_dq(3, test_dequeue);
    assert(peekTail_dq(test_dequeue) == 1);
    removeTail_dq(test_dequeue);
    assert(peekTail_dq(test_dequeue) == 2);
    printf("%s complete\n", "testing peekTail_dq with multiple elments queue");
    printDivider();

    // Clean up
    free_dq(test_dequeue);
    free(test_dequeue);
    printSectionBlock(footer, sizeof(footer) / sizeof(char *));
    printNewLine();
}

void test_isEmpty_dq() {
    // Preparing testing variables
    char * header[] = {"Testing: ", (char *)__func__};
    char * footer[] = {"End Testing", (char *)__func__};
    Dequeue test_dequeue = malloc(sizeof(struct Dequeue_s));
    init_dequeue(test_dequeue);
    printSectionBlock(header, sizeof(header) / sizeof(char *));

    // Test 1: Empty queue
    printSubSectionBlock("testing isEmpty_dq with empty queue");
    printNewLine();
    assert(isEmpty_dq(test_dequeue));
    printf("%s complete\n", "testing isEmpty_dq with empty queue");
    printDivider();

    // Test 2: Queue with single element
    printSubSectionBlock("testing isEmpty_dq with single elment queue");
    printNewLine();
    insertHead_dq(1, test_dequeue);
    assert(!isEmpty_dq(test_dequeue));
    printf("%s complete\n", "testing isEmpty_dq with single elment queue");
    printDivider();

    // Test 3: Queue with multiple elements
    printSubSectionBlock("testing isEmpty_dq with multiple elments queue");
    printNewLine();
    free_dq(test_dequeue);
    init_dequeue(test_dequeue);
    insertHead_dq(1, test_dequeue);
    insertHead_dq(2, test_dequeue);
    insertHead_dq(3, test_dequeue);
    assert(!isEmpty_dq(test_dequeue));
    removeHead_dq(test_dequeue);
    assert(!isEmpty_dq(test_dequeue));
    removeHead_dq(test_dequeue);
    assert(!isEmpty_dq(test_dequeue));
    removeHead_dq(test_dequeue);
    assert(isEmpty_dq(test_dequeue));
    printf("%s complete\n", "testing isEmpty_dq with multiple elments queue");
    printDivider();
    
    // Clean up
    free_dq(test_dequeue);
    free(test_dequeue);
    printSectionBlock(footer, sizeof(footer) / sizeof(char *));
    printNewLine();
}

void test_free_dq() {
        // Preparing testing variables
    char * header[] = {"Testing: ", (char *)__func__};
    char * footer[] = {"End Testing", (char *)__func__};
    Dequeue test_dequeue = malloc(sizeof(struct Dequeue_s));
    init_dequeue(test_dequeue);
    printSectionBlock(header, sizeof(header) / sizeof(char *));

    // Test 1: Free empty queue
    printSubSectionBlock("testing freeing empty dequeue");
    printNewLine();
    free_dq(test_dequeue);
    assert(test_dequeue->arr == NULL);
    assert(test_dequeue->maxSize == MIN_QUEUE_SIZE);
    assert(test_dequeue->head == 0);
    assert(test_dequeue->tail == 0);
    assert(test_dequeue->size == 0);
    printf("%s complete\n", "testing freeing empty dequeue");
    printDivider();

    // Test 2: Free non resized queue
    printSubSectionBlock("testing freeing non resized dequeue");
    printNewLine();
    init_dequeue(test_dequeue);
    insertTail_dq(1, test_dequeue);
    insertTail_dq(2, test_dequeue);
    insertTail_dq(3, test_dequeue);
    free_dq(test_dequeue);
    assert(test_dequeue->arr == NULL);
    assert(test_dequeue->maxSize == MIN_QUEUE_SIZE);
    assert(test_dequeue->head == 0);
    assert(test_dequeue->tail == 0);
    assert(test_dequeue->size == 0);
    printf("%s complete\n", "testing freeing non resized dequeue");
    printDivider();

    // Test 3: Free resizedd queue
    printSubSectionBlock("testing freeing non resized dequeue");
    printNewLine();
    init_dequeue(test_dequeue);
    for (int i = 0; i < MIN_QUEUE_SIZE * 2 - 1; i++)
        insertTail_dq(i, test_dequeue);
    free_dq(test_dequeue);
    assert(test_dequeue->arr == NULL);
    assert(test_dequeue->maxSize == MIN_QUEUE_SIZE);
    assert(test_dequeue->head == 0);
    assert(test_dequeue->tail == 0);
    assert(test_dequeue->size == 0);
    printf("%s complete\n", "testing freeing non resized dequeue");
    printDivider();
    
    free_dq(test_dequeue);
    free(test_dequeue);
    printSectionBlock(footer, sizeof(footer) / sizeof(char *));
    printNewLine();
}
