#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

#include "c_adt_stack_arr.h"
#define ValueType int

#define ARGUMENT_AMOUNT 7
const char* argumentName[] = {
    "help",

    "test_init_stack",
    "test_push_stack",
    "test_pop_stack",
    "test_peek_stack",
    "test_isEmpty_stack",
    "test_free_stack"
};

// ************************************************************************
// Stack test function declarations
// ************************************************************************
void test_init_stack();
void test_push_stack();
void test_pop_stack();
void test_peek_stack();
void test_isEmpty_stack();
void test_free_stack();

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
            "Begin all test functions for c_adt_stack_arr"
        };
        char * footer[] = {
            "Test complete for all test functions of c_adt_stack_arr"
        };
        printSectionBlock(header, 1);

        // LL test functions
        printSectionSingle("Begin testing for Stack");
        test_init_stack();
        test_push_stack();
        test_peek_stack();
        test_pop_stack();
        test_isEmpty_stack();
        test_free_stack();
        printSectionSingle("Test complete for Stack");

        printSectionBlock(footer, 1);
    } else {
        // Split the argument strings to run individual test
        char * header[] = {
            "Begin specific test functions for c_adt_stack_arr"
        };
        char * footer[] = {
            "Test complete for all specific functions of c_adt_stack_arr"
        };
        printSectionBlock(header, 1);
        for (int i = 1; i < argc; i++) {
            char * testname = argv[i];
            if (!strcmp(testname, "test_init_stack")) {
                test_init_stack();
            } else if (!strcmp(testname, "test_push_stack")) {
                test_push_stack();
            } else if (!strcmp(testname, "test_pop_stack")) {
                test_pop_stack();
            } else if (!strcmp(testname, "test_peek_stack")) {
                test_peek_stack();
            } else if (!strcmp(testname, "test_isEmpty_stack")) {
                test_isEmpty_stack();
            } else if (!strcmp(testname, "test_free_stack")) {
                test_free_stack();
            } else {
                // Print available arguments
                char * subheader[] = {
                    "Available arguments for testing c_adt_stack_arr"
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
void test_init_stack() {
    // Preparing testing variables
    char * header[] = {"Testing: test_init_stack"};
    char * footer[] = {"End Testing: test_init_stack"};
    Stack test_stack = malloc(sizeof(struct Stack_s));
    printSectionBlock(header, 1);


    // Test 1: initialization of stack
    printSubSectionBlock("testing initialization of stack");
    init_stack(test_stack);
    printNewLine();
    assert(test_stack->arr != NULL);
    assert(test_stack->maxSize == MIN_STACK_SIZE);
    assert(test_stack->size == 0);
    printf("%s complete\n", "testing initialization of stack");
    printDivider();

    free_stack(test_stack);
    free(test_stack);
    printSectionBlock(footer, 1);
    printNewLine();
}

void test_push_stack() {
    // Preparing testing variables
    char * header[] = {"Testing: test_push_stack"};
    char * footer[] = {"End Testing: test_push_stack"};
    Stack test_stack = malloc(sizeof(struct Stack_s));
    init_stack(test_stack);
    printSectionBlock(header, 1);


    // Test 1: single push
    printSubSectionBlock("testing single push");
    printNewLine();
    push_stack(1, test_stack);
    assert(test_stack->arr != NULL);
    assert(peek_stack(test_stack) == 1);
    assert(test_stack->maxSize == MIN_STACK_SIZE);
    assert(test_stack->size == 1);
    printf("%s complete\n", "testing single push");
    printDivider();

    // Test 2: Multiple push
    printSubSectionBlock("testing multiple push");
    printNewLine();
    free_stack(test_stack);
    init_stack(test_stack);
    push_stack(1, test_stack);
    assert(test_stack->arr != NULL);
    assert(peek_stack(test_stack) == 1);
    assert(test_stack->maxSize == MIN_STACK_SIZE);
    assert(test_stack->size == 1);

    push_stack(2, test_stack);
    assert(test_stack->arr != NULL);
    assert(peek_stack(test_stack) == 2);
    assert(test_stack->maxSize == MIN_STACK_SIZE);
    assert(test_stack->size == 2);

    push_stack(3, test_stack);
    assert(test_stack->arr != NULL);
    assert(peek_stack(test_stack) == 3);
    assert(test_stack->maxSize == MIN_STACK_SIZE);
    assert(test_stack->size == 3);

    printf("%s complete\n", "testing multiple push");
    printDivider();

    // Test 3: Resizing push
    printSubSectionBlock("testing auto resizing push");
    printNewLine();
    free_stack(test_stack);
    init_stack(test_stack);
    
    for (int i = 0; i < MIN_STACK_SIZE * 2 - 1; i++) {
        push_stack(i, test_stack); 
        assert(test_stack->arr != NULL);
        assert(peek_stack(test_stack) == i);
        assert(test_stack->size == i + 1);
    }

    assert(test_stack->maxSize >= 2 * MIN_STACK_SIZE);  // test if properly resized (minimum twice as original size to achieve constant time access)
    printf("%s complete\n", "testing auto resizing push");
    printDivider();

    free_stack(test_stack);
    free(test_stack);
    printSectionBlock(footer, 1);
    printNewLine();
}

void test_pop_stack() {
    // Preparing testing variables
    char * header[] = {"Testing: test_pop_stack"};
    char * footer[] = {"End Testing: test_pop_stack"};
    Stack test_stack = malloc(sizeof(struct Stack_s));
    init_stack(test_stack);
    printSectionBlock(header, 1);

    // Test 1: pop with empty stack
    printSubSectionBlock("testing single pop");
    printNewLine();
    pop_stack(test_stack);
    assert(test_stack->arr != NULL);
    assert(test_stack->maxSize == MIN_STACK_SIZE);
    assert(test_stack->size == 0);
    printf("%s complete\n", "testing single pop");
    printDivider();

    // Test 2: pop single element in stack
    printSubSectionBlock("testing pop stack with single element");
    printNewLine();
    
    // Reinit stack
    free_stack(test_stack);
    init_stack(test_stack);

    push_stack(1, test_stack);
    assert(pop_stack(test_stack) == 1);
    assert(test_stack->arr != NULL);
    assert(test_stack->maxSize == MIN_STACK_SIZE);
    assert(test_stack->size == 0);

    pop_stack(test_stack);
    assert(test_stack->arr != NULL);
    assert(test_stack->maxSize == MIN_STACK_SIZE);
    assert(test_stack->size == 0);

    printf("%s complete\n", "testing pop stack with single element");
    printDivider();

    // Test 3: Multiple pop
    printSubSectionBlock("testing multiple pops");
    printNewLine();
    
    // Reinit stack
    free_stack(test_stack);
    init_stack(test_stack);

    push_stack(1, test_stack);
    push_stack(2, test_stack);
    push_stack(3, test_stack);
    assert(pop_stack(test_stack) == 3);
    assert(pop_stack(test_stack) == 2);
    assert(pop_stack(test_stack) == 1);
    assert(test_stack->arr != NULL);
    assert(test_stack->maxSize == MIN_STACK_SIZE);
    assert(test_stack->size == 0);

    printf("%s complete\n", "testing multiple pops");
    printDivider();

    // Test 4: Resizing pop
    printSubSectionBlock("testing resizing pops");
    printNewLine();
    
    // Reinit stack
    free_stack(test_stack);
    init_stack(test_stack);

    for (int i = 0; i < MIN_STACK_SIZE * 2 - 1; i++) {
        push_stack(i, test_stack);
    }

    for (int i = MIN_STACK_SIZE * 2 - 2; i >= 0; i--) {
        assert(pop_stack(test_stack) == i);
    }

    assert(test_stack->arr != NULL);
    assert(test_stack->maxSize == MIN_STACK_SIZE);

    printf("%s complete\n", "testing resizing pops");
    printDivider();

    // Cleaning up
    free_stack(test_stack);
    free(test_stack);
    printSectionBlock(footer, 1);
    printNewLine();
}

void test_peek_stack() {
    // Preparing testing variables
    char * header[] = {"Testing: test_peek_stack"};
    char * footer[] = {"End Testing: test_peek_stack"};
    Stack test_stack = malloc(sizeof(struct Stack_s));
    init_stack(test_stack);
    printSectionBlock(header, 1);

    // Test 1: peek with empty stack
    printSubSectionBlock("testing peek with empty stack");
    printNewLine();
    peek_stack(test_stack);
    assert(test_stack->arr != NULL);
    assert(test_stack->maxSize == MIN_STACK_SIZE);
    assert(test_stack->size == 0);
    printf("%s complete\n", "testing peek with empty stack");
    printDivider();

    // Test 2: multiple peeks
    printSubSectionBlock("testing multiple stack peeks");
    printNewLine();
    
    // Reinit stack
    free_stack(test_stack);
    init_stack(test_stack);

    for (int i = 0; i < MIN_STACK_SIZE * 2 - 1; i++) {
        push_stack(i, test_stack);
        assert(peek_stack(test_stack) == i);
    }

    printf("%s complete\n", "testing multiple stack peeks");
    printDivider();

    // Cleaning up
    free_stack(test_stack);
    free(test_stack);
    printSectionBlock(footer, 1);
    printNewLine();
}

void test_isEmpty_stack() {
    // Preparing testing variables
    char * header[] = {"Testing: test_isEmpty_stack"};
    char * footer[] = {"End Testing: test_isEmpty_stack"};
    Stack test_stack = malloc(sizeof(struct Stack_s));
    init_stack(test_stack);
    printSectionBlock(header, 1);

    // Test 1: empty stack
    printSubSectionBlock("testing isEmpty with empty stack");
    printNewLine();
    assert(isEmpty_stack(test_stack));
    printf("%s complete\n", "testing isEmpty with empty stack");
    printDivider();

    // Test 2: nonempty stack
    printSubSectionBlock("testing isEmpty with nonempty stack");
    printNewLine();
    push_stack(1, test_stack);
    assert(isEmpty_stack(test_stack) == 0);
    pop_stack(test_stack);
    assert(isEmpty_stack(test_stack));
    printf("%s complete\n", "testing isEmpty with nonempty stack");
    printDivider();

    // Cleaning up
    free_stack(test_stack);
    free(test_stack);
    printSectionBlock(footer, 1);
    printNewLine();
}

void test_free_stack() {
    // Preparing testing variables
    char * header[] = {"Testing: test_free_stack"};
    char * footer[] = {"End Testing: test_free_stack"};
    Stack test_stack = malloc(sizeof(struct Stack_s));
    init_stack(test_stack);
    printSectionBlock(header, 1);

    // Test 1: Free empty stack
    printSubSectionBlock("testing free_stack with empty stack");
    printNewLine();
    free_stack(test_stack);
    assert(test_stack->arr == NULL);
    assert(test_stack->maxSize == MIN_STACK_SIZE);
    assert(test_stack->size == 0);
    printf("%s complete\n", "testing free_stack with empty stack");
    printDivider();

    // Test 2: Free non resized stack
    printSubSectionBlock("testing free_stack with stack without resizing");
    printNewLine();
    init_stack(test_stack);
    push_stack(1, test_stack);
    push_stack(2, test_stack);
    push_stack(3, test_stack);
    push_stack(4, test_stack);
    free_stack(test_stack);
    assert(test_stack->arr == NULL);
    assert(test_stack->maxSize == MIN_STACK_SIZE);
    assert(test_stack->size == 0);
    printf("%s complete\n", "testing free_stack with stack without resizing");
    printDivider();

    // Test 3: Free on resized stack
    printSubSectionBlock("testing free_stack with stack with resizing");
    printNewLine();
    init_stack(test_stack);
    for (int i = 0; i < MIN_STACK_SIZE * 2 - 1; i++)
        push_stack(i, test_stack);
    free_stack(test_stack);
    assert(test_stack->arr == NULL);
    assert(test_stack->maxSize == MIN_STACK_SIZE);
    assert(test_stack->size == 0);
    printf("%s complete\n", "testing free_stack with stack with resizing");
    printDivider();

    // Cleaning up
    free_stack(test_stack);
    free(test_stack);
    printSectionBlock(footer, 1);
    printNewLine();
}