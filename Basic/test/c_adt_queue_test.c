#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

#include "c_adt_queue.h"
#define ValueType int

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

}

void test_enqueue_q() {

}

void test_dequeue_q() {

}

void test_peek_q() {

}

void test_isEmpty_q() {

}

void test_free_q() {

}
