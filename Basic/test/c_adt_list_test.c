#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

#include "c_adt_list.h"
#define ValueType int

#define ARGUMENT_AMOUNT 17
const char* argumentName[] = {
    "help",

    "test_init_LL",
    "test_free_LL",
    "test_isEmpty_LL",
    "test_find_LL",
    "test_deleteNode_LL",
    "test_findPrev_LL",
    "test_insert_LL",
    "test_insertHead_LL",
    "test_insertTail_LL",
    
    "test_init_DLL",
    "test_free_DLL",
    "test_isEmpty_DLL",
    "test_find_DLL",
    "test_deleteNode_DLL",
    "test_findPrev_DLL",
    "test_insert_DLL",
    "test_insertHead_DLL"
};

// ************************************************************************
// LinkedList test functions declaration
// ************************************************************************
void test_init_LL();
void test_free_LL();
void test_isEmpty_LL();
void test_find_LL();
void test_deleteNode_LL();
void test_findPrev_LL();
void test_insert_LL();
void test_insertHead_LL();
void test_insertTail_LL();

// ************************************************************************
// Double LinkedList test functions declaration
// ************************************************************************
void test_init_DLL();
void test_free_DLL();
void test_isEmpty_DLL();
void test_find_DLL();
void test_deleteNode_DLL();
void test_insert_DLL();
void test_insertHead_DLL();
void test_insertTail_DLL();

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

int main(int argc, char* argv[]) {
    dup2(1, 2); // Redirect stderr to stdout
    printNewLine();
    if (argc == 1) {
        // Run all test
        char * header[] = {
            "Begin all test functions for c_adt_list"
        };
        char * footer[] = {
            "Test complete for all test functions of c_adt_list"
        };
        printSectionBlock(header, 1);

        // LL test functions
        printSectionSingle("Begin testing for LinkedList");
        test_init_LL();
        test_insertHead_LL();
        test_insertTail_LL();
        test_insert_LL();
        test_find_LL();
        test_findPrev_LL();
        test_isEmpty_LL();
        test_deleteNode_LL();
        test_free_LL();
        printSectionSingle("Test complete for LinkedList");

        printNewLine();

        // DLL test functions
        printSectionSingle("Begin testing for Double LinkedList");
        test_init_DLL();
        test_insertHead_DLL();
        test_insertTail_DLL();
        test_insert_DLL();
        test_isEmpty_DLL();
        test_find_DLL();
        test_deleteNode_DLL();
        test_free_DLL();
        printSectionSingle("Test complete for Double LinkedList");

        printSectionBlock(footer, 1);
    } else {
        // Split the argument strings to run individual test
        char * header[] = {
            "Begin specific test functions for c_adt_list"
        };
        char * footer[] = {
            "Test complete for all specific functions of c_adt_list"
        };
        printSectionBlock(header, 1);
        for (int i = 1; i < argc; i++) {
            char * testname = argv[i];
            if (!strcmp(testname, "test_init_LL")) {
                test_init_LL();
            } else if (!strcmp(testname, "test_free_LL")) {
                test_free_LL();
            } else if (!strcmp(testname, "test_isEmpty_LL")) {
                test_isEmpty_LL();
            } else if (!strcmp(testname, "test_find_LL")) {
                test_find_LL();
            } else if (!strcmp(testname, "test_deleteNode_LL")) {
                test_deleteNode_LL();
            } else if (!strcmp(testname, "test_findPrev_LL")) {
                test_findPrev_LL();
            } else if (!strcmp(testname, "test_insert_LL")) {
                test_insert_LL();
            } else if (!strcmp(testname, "test_insertHead_LL")) {
                test_insertHead_LL();
            } else if (!strcmp(testname, "test_insertTail_LL")) {
                test_insertTail_LL();
            } 
            // DLL Test begin
            else if (!strcmp(testname, "test_init_DLL")) {
                test_init_DLL();
            } else if (!strcmp(testname, "test_free_DLL")) {
                test_free_DLL();
            } else if (!strcmp(testname, "test_isEmpty_DLL")) {
                test_isEmpty_DLL();
            } else if (!strcmp(testname, "test_find_DLL")) {
                test_find_DLL();
            } else if (!strcmp(testname, "test_deleteNode_DLL")) {
                test_deleteNode_DLL();
            } else if (!strcmp(testname, "test_insert_DLL")) {
                test_insert_DLL();
            } else if (!strcmp(testname, "test_insertHead_DLL")) {
                test_insertHead_DLL();
            } else if (!strcmp(testname, "test_insertTail_DLL")) {
                test_insertTail_DLL();
            } else {
                // Print available arguments
                char * header[] = {
                    "Available arguments for testing c_adt_list"
                };
                char * footer[] = {
                    "End of arguments list"
                };
                printSectionBlock(header, 1);
                for (int i = 0; i < ARGUMENT_AMOUNT; i++)
                    printf("%s\n", argumentName[i]);
                printSectionBlock(footer, 1);
            }
        }
        printSectionBlock(footer, 1);
    }
    printNewLine();
    return 0;
}

void test_init_LL() {
    char * header[] = {"Testing: test_init_LL"};
    char * footer[] = {"End Testing: test_init_LL"};

    // Preparing testing variables
    char* testcase_tags = "testing initialization of linkedlist";
    LinkedList test_list = malloc(sizeof(struct LinkedList_s));
    printSectionBlock(header, 1);

    // Test 1: initialization of linkedlist
    printSubSectionBlock(testcase_tags);
    init_LL(test_list);
    printNewLine();
    assert(test_list != NULL);
    assert(test_list->head == NULL);
    assert(test_list->tail == NULL);
    assert(test_list->nodeCount == 0);
    printf("Test complete\n");
   
    free_LL(test_list);
    free(test_list);
    printSectionBlock(footer, 1);
    printNewLine();
}

void test_free_LL() {
    // NOTE: This function cannot fully test the free process and
    // Must rely on memcheck tool like valgrind to determine
    char * header[] = {"Testing: test_free_LL"};
    char * footer[] = {"End Testing: test_free_LL"};

    // Preparing testing variables
    LinkedList test_list = malloc(sizeof(struct LinkedList_s));
    init_LL(test_list);
    printSectionBlock(header, 1);

    // Test 1: Free empty list
    printSubSectionBlock("testing freeing empty linked list");
    free_LL(test_list);
    assert(test_list->head == NULL);
    assert(test_list->tail == NULL);
    assert(test_list->nodeCount == 0);
    printf("%s complete\n", "testing freeing empty linked list");
    printDivider();


    // Test 2: Free list with single node
    printSubSectionBlock("testing freeing linked list with single node");
    insertHead_LL(1, test_list);
    free_LL(test_list);
    assert(test_list->head == NULL);
    assert(test_list->tail == NULL);
    assert(test_list->nodeCount == 0);
    printf("%s complete\n", "testing freeing linked list with single node");
    printDivider();


    // Test 3: Free list with multiple nodes
    printSubSectionBlock("testing freeing linked list with multiple nodes");
    insertHead_LL(1, test_list);
    insertHead_LL(3, test_list);
    insertTail_LL(2, test_list);
    free_LL(test_list);
    assert(test_list->head == NULL);
    assert(test_list->tail == NULL);
    assert(test_list->nodeCount == 0);
    printf("%s complete\n", "testing freeing linked list with multiple nodes");
    printDivider();

    // Clean up
    free_LL(test_list);
    free(test_list);
    printSectionBlock(footer, 1);
    printNewLine();
}

void test_isEmpty_LL() {
    // Preparing testing variables
    char * header[] = {"Testing: test_isEmpty_LL"};
    char * footer[] = {"End Testing: test_isEmpty_LL"};
    LinkedList test_list = malloc(sizeof(struct LinkedList_s));
    init_LL(test_list);
    printSectionBlock(header, 1);

    // Test 1: Test empty list
    printSubSectionBlock("testing empty linked list");
    init_LL(test_list);
    assert(isEmpty_LL(test_list) == 1);
    printf("%s complete\n", "testing empty linked list");
    printDivider();


    // Test 2: Test list with single node
    printSubSectionBlock("testing list with single node");
    insertHead_LL(1, test_list);
    assert(isEmpty_LL(test_list) == 0);
    printf("%s complete\n", "testing list with single node");
    printDivider();


    // Test 3: Test list with multiple node
    printSubSectionBlock("testing list with multiple node");
    insertHead_LL(2, test_list);
    assert(isEmpty_LL(test_list) == 0);
    printf("%s complete\n", "testing list with multiple node");
    printDivider();


    // Test 4: Test list after removing all nodes
    printSubSectionBlock("testing list after removing all nodes");
    deleteNode_LL(2, test_list);
    deleteNode_LL(1, test_list);
    assert(isEmpty_LL(test_list) == 1);
    printf("%s complete\n", "testing list after removing all nodes");
    printDivider();

    free_LL(test_list);
    free(test_list);
    printSectionBlock(footer, 1);
    printNewLine();
}

void test_find_LL() {
    // Preparing testing variables
    char * header[] = {"Testing: test_find_LL"};
    char * footer[] = {"End Testing: test_find_LL"};
    LinkedList test_list = malloc(sizeof(struct LinkedList_s));
    init_LL(test_list);
    printSectionBlock(header, 1);

    // Test 1: Test empty list
    printSubSectionBlock("testing empty list");
    assert(find_LL(1, test_list) == NULL);
    printf("%s complete\n", "testing empty list");
    printDivider();

    // Test 2: Test list with single node
    printSubSectionBlock("test list with single node");
    insertHead_LL(1, test_list);
    assert(find_LL(1, test_list)->value == 1);
    printf("%s complete\n", "test list with single node");
    printDivider();

    // Test 3: Test list with multiple node
    printSubSectionBlock("test list with multiple nodes");
    insertHead_LL(2, test_list);
    insertHead_LL(3, test_list);
    assert(find_LL(1, test_list)->value == 1);
    assert(find_LL(2, test_list)->value == 2);
    assert(find_LL(3, test_list)->value == 3);
    printf("%s complete\n", "test list with multiple nodes");
    printDivider();

    // Test 4: Test list with multiple node after removing one
    printSubSectionBlock("test list with multiple nodes after removing one");
    deleteNode_LL(1, test_list);
    assert(find_LL(1, test_list) == NULL);
    assert(find_LL(2, test_list)->value == 2);
    assert(find_LL(3, test_list)->value == 3);
    printf("%s complete\n", "test list with multiple nodes after removing one");
    printDivider();

    free_LL(test_list);
    free(test_list);
    printSectionBlock(footer, 1);
    printNewLine();
}

void test_deleteNode_LL() {
    // Preparing testing variables
    char * header[] = {"Testing: test_deleteNode_LL"};
    char * footer[] = {"End Testing: test_deleteNode_LL"};
    LinkedList test_list = malloc(sizeof(struct LinkedList_s));
    init_LL(test_list);
    printSectionBlock(header, 1);

    // Test 1: Test with empty list
    printSubSectionBlock("test with empty list");
    deleteNode_LL(1, test_list);
    assert(test_list->head == NULL);
    assert(test_list->tail == NULL);
    assert(test_list->nodeCount == 0);
    printf("%s complete\n", "test with empty list");
    printDivider();

    // Test 2: Test list with single node
    printSubSectionBlock("test list with single node");
    insertHead_LL(1, test_list);
    deleteNode_LL(1, test_list);
    assert(test_list->head == NULL);
    assert(test_list->tail == NULL);
    assert(test_list->nodeCount == 0);
    printf("%s complete\n", "test list with single node");
    printDivider();

    // Test 3: Test list with multiple nodes
    printSubSectionBlock("test list with multiple nodes at head");
    insertHead_LL(1, test_list);
    insertHead_LL(2, test_list);
    insertHead_LL(3, test_list);
    deleteNode_LL(1, test_list);
    assert(test_list->head->value == 3);
    assert(test_list->tail->value == 2);
    assert(test_list->nodeCount == 2);
    printf("%s complete\n", "test list with multiple nodes at head");
    printDivider();

    // Test 4: Test list with multiple nodes
    printSubSectionBlock("test list with multiple nodes at middle");
    free_LL(test_list);
    insertHead_LL(1, test_list);
    insertHead_LL(2, test_list);
    insertHead_LL(3, test_list);
    deleteNode_LL(2, test_list);
    assert(test_list->head->value == 3);
    assert(test_list->tail->value == 1);
    assert(test_list->nodeCount == 2);
    printf("%s complete\n", "test list with multiple nodes at middle");
    printDivider();

    // Test 5: Test list with multiple nodes
    printSubSectionBlock("test list with multiple nodes at tail");
    free_LL(test_list);
    insertHead_LL(1, test_list);
    insertHead_LL(2, test_list);
    insertHead_LL(3, test_list);
    deleteNode_LL(3, test_list);
    assert(test_list->head->value == 2);
    assert(test_list->tail->value == 1);
    assert(test_list->nodeCount == 2);
    printf("%s complete\n", "test list with multiple nodes at tail");
    printDivider();

    free_LL(test_list);
    free(test_list);
    printSectionBlock(footer, 1);
    printNewLine();
}

void test_findPrev_LL() {
    // Preparing testing variables
    char * header[] = {"Testing: test_findPrev_LL"};
    char * footer[] = {"End Testing: test_findPrev_LL"};
    LinkedList test_list = malloc(sizeof(struct LinkedList_s));
    init_LL(test_list);
    printSectionBlock(header, 1);

    // Test 1: Test with empty list
    printSubSectionBlock("test with empty list");
    assert(findPrev_LL(1, test_list) == NULL);
    printf("%s complete\n", "test with empty list");
    printDivider();

    // Test 2: List with single node
    printSubSectionBlock("test with single node list");
    insertHead_LL(1, test_list);
    assert(findPrev_LL(1, test_list) == NULL);
    printf("%s complete\n", "test with single node list");
    printDivider();

    // Test 3: List with multiple nodes, find at head
    printSubSectionBlock("test with single node list");
    free_LL(test_list);
    insertHead_LL(1, test_list);
    insertHead_LL(2, test_list);
    insertHead_LL(3, test_list);
    assert(findPrev_LL(3, test_list) == NULL);
    assert((findPrev_LL(2, test_list))->value == 3);
    assert((findPrev_LL(1, test_list))->value == 2);
    printf("%s complete\n", "test with single node list");
    printDivider();

    // Clean up
    free_LL(test_list);
    free(test_list);
    printSectionBlock(footer, 1);
    printNewLine();
}

void test_insert_LL() {
    // Preparing testing variables
    char * header[] = {"Testing: test_insert_LL"};
    char * footer[] = {"End Testing: test_insert_LL"};
    LinkedList test_list = malloc(sizeof(struct LinkedList_s));
    init_LL(test_list);
    printSectionBlock(header, 1);

    // Test 1: Test with empty list
    printSubSectionBlock("test with empty list at head");
    insert_LL(1, test_list, 0);
    assert(test_list->head->value == 1);
    assert(test_list->tail->value == 1);
    assert(test_list->nodeCount == 1);
    printf("%s complete\n", "test with empty list at head");
    printDivider();

    // Test 2: Test with empty list at tail
    printSubSectionBlock("test with empty list at tail");
    free_LL(test_list);
    insert_LL(1, test_list, 2);
    assert(test_list->head->value == 1);
    assert(test_list->tail->value == 1);
    assert(test_list->nodeCount == 1);
    printf("%s complete\n", "test with empty list at tail");
    printDivider();

    // Test 3: Test with list with multiple nodes
    printSubSectionBlock("test with multiple node insert");
    free_LL(test_list);
    
    // List construction
    insert_LL(1, test_list, 0);
    insert_LL(2, test_list, 0);
    insert_LL(3, test_list, 0);
    assert(test_list->head->value == 3);
    assert(test_list->tail->value == 1);
    assert(test_list->nodeCount == 3);

    // Insert node at middle
    insert_LL(4, test_list, 1);
    insert_LL(5, test_list, 3);
    assert(test_list->nodeCount == 5);
    assert(test_list->head->next->value == 4);
    assert((findPrev_LL(test_list->tail->value, test_list))->value == 5);
    printf("%s complete\n", "test with multiple node insert");
    printDivider();

    // Clean up
    free_LL(test_list);
    free(test_list);
    printSectionBlock(footer, 1);
    printNewLine();
}

void test_insertHead_LL() {
    // Preparing testing variables
    char * header[] = {"Testing: test_insertHead_LL"};
    char * footer[] = {"End Testing: test_insertHead_LL"};
    LinkedList test_list = malloc(sizeof(struct LinkedList_s));
    init_LL(test_list);
    printSectionBlock(header, 1);

    // Test 1: Test with empty list
    printSubSectionBlock("test with empty list");
    insertHead_LL(1, test_list);
    assert(test_list->head->value == 1);
    assert(test_list->tail->value == 1);
    assert(test_list->nodeCount == 1);
    printf("%s complete\n", "test with empty list");
    printDivider();

    // Test 2: Multiple insertion
    printSubSectionBlock("test with multiple insertion");
    free_LL(test_list);
    insertHead_LL(1, test_list);
    insertHead_LL(2, test_list);
    insertHead_LL(3, test_list);
    insertHead_LL(4, test_list);
    insertHead_LL(5, test_list);
    insertHead_LL(6, test_list);
    assert(test_list->head->value == 6);
    assert(test_list->head->next->value == 5);
    assert(test_list->head->next->next->value == 4);
    assert(test_list->head->next->next->next->value == 3);
    assert(test_list->head->next->next->next->next->value == 2);
    assert(test_list->head->next->next->next->next->next->value == 1);
    assert(test_list->head->next->next->next->next->next->next == NULL);
    assert(test_list->tail->value == 1);
    assert(test_list->nodeCount == 6);
    printf("%s complete\n", "test with multiple insertion");
    printDivider();

    // Clean up
    free_LL(test_list);
    free(test_list);
    printSectionBlock(footer, 1);
    printNewLine();
}

void test_insertTail_LL() {
    // Preparing testing variables
    char * header[] = {"Testing: test_insertTail_LL"};
    char * footer[] = {"End Testing: test_insertTail_LL"};
    LinkedList test_list = malloc(sizeof(struct LinkedList_s));
    init_LL(test_list);
    printSectionBlock(header, 1);

    // Test 1: Test with empty list
    printSubSectionBlock("test with empty list");
    insertTail_LL(1, test_list);
    assert(test_list->head->value == 1);
    assert(test_list->tail->value == 1);
    assert(test_list->nodeCount == 1);
    printf("%s complete\n", "test with empty list");
    printDivider();

    // Test 2: Multiple insertion
    printSubSectionBlock("test with multiple insertion");
    free_LL(test_list);
    insertTail_LL(1, test_list);
    insertTail_LL(2, test_list);
    insertTail_LL(3, test_list);
    insertTail_LL(4, test_list);
    insertTail_LL(5, test_list);
    insertTail_LL(6, test_list);
    assert(test_list->head->value == 1);
    assert(test_list->head->next->value == 2);
    assert(test_list->head->next->next->value == 3);
    assert(test_list->head->next->next->next->value == 4);
    assert(test_list->head->next->next->next->next->value == 5);
    assert(test_list->head->next->next->next->next->next->value == 6);
    assert(test_list->head->next->next->next->next->next->next == NULL);
    assert(test_list->tail->value == 6);
    assert(test_list->nodeCount == 6);
    printf("%s complete\n", "test with multiple insertion");
    printDivider();

    // Clean up
    free_LL(test_list);
    free(test_list);
    printSectionBlock(footer, 1);
    printNewLine();
}

// ************************************************************************
// DLL Test Functions
// ************************************************************************

void test_init_DLL() {
// Preparing testing variables
    char* testcase_tags = "testing freeing of linkedlist";
    LinkedList test_list = malloc(sizeof(struct LinkedList_s));

    // Test
    printSubSectionBlock(testcase_tags);

    printf("Test complete\n");
    printDivider();
}

void test_free_DLL() {
// Preparing testing variables
    char* testcase_tags = "testing freeing of linkedlist";
    LinkedList test_list = malloc(sizeof(struct LinkedList_s));

    // Test
    printSubSectionBlock(testcase_tags);

    printf("Test complete\n");
    printDivider();
}

void test_isEmpty_DLL() {
// Preparing testing variables
    char* testcase_tags = "testing freeing of linkedlist";
    LinkedList test_list = malloc(sizeof(struct LinkedList_s));

    // Test
    printSubSectionBlock(testcase_tags);

    printf("Test complete\n");
    printDivider();
}

void test_find_DLL() {
// Preparing testing variables
    char* testcase_tags = "testing freeing of linkedlist";
    LinkedList test_list = malloc(sizeof(struct LinkedList_s));

    // Test
    printSubSectionBlock(testcase_tags);

    printf("Test complete\n");
    printDivider();
}

void test_deleteNode_DLL() {
// Preparing testing variables
    char* testcase_tags = "testing freeing of linkedlist";
    LinkedList test_list = malloc(sizeof(struct LinkedList_s));

    // Test
    printSubSectionBlock(testcase_tags);

    printf("Test complete\n");
    printDivider();
}

void test_insert_DLL() {
// Preparing testing variables
    char* testcase_tags = "testing freeing of linkedlist";
    LinkedList test_list = malloc(sizeof(struct LinkedList_s));

    // Test
    printSubSectionBlock(testcase_tags);

    printf("Test complete\n");
    printDivider();
}

void test_insertHead_DLL() {
// Preparing testing variables
    char* testcase_tags = "testing freeing of linkedlist";
    LinkedList test_list = malloc(sizeof(struct LinkedList_s));

    // Test
    printSubSectionBlock(testcase_tags);

    printf("Test complete\n");
    printDivider();
}
 
void test_insertTail_DLL() {
// Preparing testing variables
    char* testcase_tags = "testing freeing of linkedlist";
    LinkedList test_list = malloc(sizeof(struct LinkedList_s));

    // Test
    printSubSectionBlock(testcase_tags);

    printf("Test complete\n");
    printDivider();
}