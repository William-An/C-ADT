#ifndef __C_ADT_LIST_H__
#define __C_ADT_LIST_H__

#include <stdint.h>
#include <stdlib.h>

#ifndef ValueType
#define ValueType int
#endif

// Data Structure Definition
struct LinkedListNode;
typedef struct LinkedListNode* PtrToLinkedListNode;

struct LinkedList_s;
typedef struct LinkedList_s* LinkedList;

struct DoubleLinkedListNode;
typedef struct DoubleLinkedListNode* PtrToDoubleListNode;

struct DoubleLinkedList_s;
typedef struct DoubleLinkedList_s* DoubleLinkedList;

// LinkedList API
LinkedList free_LL(LinkedList L);
int isEmpty_LL(LinkedList L);
int isLast_LL(PtrToLinkedListNode node, LinkedList L);
PtrToLinkedListNode find_LL(ValueType val, LinkedList L);
void deleteNode_LL(ValueType val, LinkedList L);
PtrToLinkedListNode findPrev_LL(ValueType val, LinkedList L);
void insert_LL(ValueType val, LinkedList L, uint32_t index);
void insertAtHead_LL(ValueType val, LinkedList L);
void insertAtTail_LL(ValueType val, LinkedList L);

// Double LinkedList API
LinkedList free_DLL(DoubleLinkedList L);
int isEmpty_DLL(DoubleLinkedList L);
int isLast_DLL(PtrToDoubleListNode node, DoubleLinkedList L);
PtrToDoubleListNode find_DLL(ValueType val, DoubleLinkedList L);
void deleteNodeVal_DLL(ValueType val, DoubleLinkedList L);
void deleteNode_DLL(PtrToDoubleListNode node, DoubleLinkedList L);
void insert_DLL(ValueType val, DoubleLinkedList L, uint32_t index);
void insertAtHead_DLL(ValueType val, DoubleLinkedList L);
void insertAtTail_DLL(ValueType val, DoubleLinkedList L);

#endif