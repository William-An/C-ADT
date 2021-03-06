#ifndef __C_ADT_LIST_H__
#define __C_ADT_LIST_H__

#include <stdint.h>
#include <stdlib.h>

#ifndef ValueType
#define ValueType int
#endif

/**
 * 
 * Data Structure Declaration for LinkedList and Double LinkedList
 * 
 * */
struct LinkedListNode;
typedef struct LinkedListNode* PtrToLinkedListNode;

struct LinkedList_s;
typedef struct LinkedList_s* LinkedList;

struct DoubleLinkedListNode;
typedef struct DoubleLinkedListNode* PtrToDoubleListNode;

struct DoubleLinkedList_s;
typedef struct DoubleLinkedList_s* DoubleLinkedList;

/**
 * 
 * Data Structure definition for LinkedList and Double LinkedList
 * 
 * */

struct LinkedListNode {
    ValueType value;
    PtrToLinkedListNode next;
};

struct LinkedList_s {
    PtrToLinkedListNode head;
    PtrToLinkedListNode tail;
    uint32_t nodeCount;
};

struct DoubleLinkedListNode {
    ValueType value;
    PtrToDoubleListNode next;
    PtrToDoubleListNode prev;
};

struct DoubleLinkedList_s {
    PtrToDoubleListNode head;
    PtrToDoubleListNode tail;
    uint32_t nodeCount;
};

// LinkedList API
void init_LL(LinkedList L);
void free_LL(LinkedList L);
int isEmpty_LL(LinkedList L);
int isLast_LL(PtrToLinkedListNode node, LinkedList L);
PtrToLinkedListNode find_LL(ValueType val, LinkedList L);
void deleteNode_LL(ValueType val, LinkedList L);
PtrToLinkedListNode findPrev_LL(ValueType val, LinkedList L);
void insert_LL(ValueType val, LinkedList L, uint32_t index);
void insertHead_LL(ValueType val, LinkedList L);
void insertTail_LL(ValueType val, LinkedList L);

// Double LinkedList API
void init_DLL(DoubleLinkedList L);
void free_DLL(DoubleLinkedList L);
int isEmpty_DLL(DoubleLinkedList L);
int isLast_DLL(PtrToDoubleListNode node, DoubleLinkedList L);
PtrToDoubleListNode find_DLL(ValueType val, DoubleLinkedList L);
void deleteNode_DLL(ValueType val, DoubleLinkedList L);
void insert_DLL(ValueType val, DoubleLinkedList L, uint32_t index);
void insertHead_DLL(ValueType val, DoubleLinkedList L);
void insertTail_DLL(ValueType val, DoubleLinkedList L);

#endif