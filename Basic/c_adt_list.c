#include "c_adt_list.h"

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

// ************************************************************************
// LinkedList API
// ************************************************************************

/**
 * 
 * @brief: free_LL, Free the linkedlist nodes and return the LinkedList afterward
 * @param: L, LinkedList to be free
 * @return: LinkedList
 * 
 * */
LinkedList free_LL(LinkedList L) {

}

/**
 * 
 * @brief: isEmpty_LL, Check if the linkedlist is empty (contains zero nodes)
 * @param: L, LinkedList to be checked
 * @return: int, 1 if the list is empty, 0 otherwise
 * 
 * */
int isEmpty_LL(LinkedList L) {

}

/**
 * 
 * @brief: isLast_LL, Check if the given node is truly the last/tail node of the LinkedList L
 * @param: node, PtrToLinkedListNode, node to be checked if is the last node of the LinkedList
 * @param: L, LinkedList
 * @return: int, 1 if the node is the last node in the list, 0 otherwise
 * 
 * */
int isLast_LL(PtrToLinkedListNode node, LinkedList L) {

}

/**
 * 
 * @brief: find_LL, find the node with the value val in LinkedList L; NULL if not found
 * @param: val, ValueType, value to be found in LinkedList L
 * @param: L, LinkedList
 * @return: PtrToLinkedListNode, node with parameter val as value, NULL if not found
 * 
 * */
PtrToLinkedListNode find_LL(ValueType val, LinkedList L) {

}

/**
 * 
 * @brief: deleteNode_LL, delete the node in LinkedList L with value val and update the head/tail and nodecount correspondingly
 * @param: val, ValueType, value to be removed from LinkedList L
 * @param: L, LinkedList
 * 
 * */
void deleteNode_LL(ValueType val, LinkedList L) {

}

/**
 * 
 * @brief: findPrev_LL, find the previous node of the node with value val in LinkedList L
 * @param: val, ValueType, value of the node to be found previous node
 * @param: L, LinkedList
 * @return: The previous node of the node with value val; NULL if unable to found such node
 * 
 * */
PtrToLinkedListNode findPrev_LL(ValueType val, LinkedList L) {

}

/**
 * 
 * @brief: insert_LL, insert a node with value val to LinkedList L at index, update the node count correspondingly
 * @param: val, ValueType, value of the node to be inserted
 * @param: L, LinkedList
 * @param: index, uint32_t, index to be inserted to, starts from 0
 * 
 * */
void insert_LL(ValueType val, LinkedList L, uint32_t index) {

}

/**
 * 
 * @brief: insertHead_LL, insert a node with value val to LinkedList L at head, update the node count correspondingly
 * @param: val, ValueType, value of the node to be inserted
 * @param: L, LinkedList
 * 
 * */
void insertHead_LL(ValueType val, LinkedList L) {

}

/**
 * 
 * @brief: insertTail_LL, insert a node with value val to LinkedList L at tail, update the node count correspondingly
 * @param: val, ValueType, value of the node to be inserted
 * @param: L, LinkedList
 * 
 * */
void insertTail_LL(ValueType val, LinkedList L) {

}

// ************************************************************************
// Double LinkedList API
// ************************************************************************

/**
 * 
 * @brief: free_DLL, Free the double linkedlist nodes and return the double LinkedList afterward
 * @param: L, DoubleLinkedList to be free
 * @return: DoubleLinkedList
 * 
 * */
LinkedList free_DLL(DoubleLinkedList L) {

}

/**
 * 
 * @brief: isEmpty_DLL, Check if the double linkedlist is empty (contains zero nodes)
 * @param: L, DoubleLinkedList to be checked
 * @return: int, 1 if the list is empty, 0 otherwise
 * 
 * */
int isEmpty_DLL(DoubleLinkedList L) {

}

/**
 * 
 * @brief: isLast_DLL, Check if the given node is the last/tail node of the DoubleLinkedList L
 * @param: node, PtrToDoubleListNode, node to be checked if is the last node of the DoubleLinkedList
 * @param: L, DoubleLinkedList
 * @return: int, 1 if the node is the last node in the list, 0 otherwise
 * 
 * */
int isLast_DLL(PtrToDoubleListNode node, DoubleLinkedList L) {

}

/**
 * 
 * @brief: find_DLL, find the node with the value val in DoubleLinkedList L; NULL if not found
 * @param: val, ValueType, value to be found in DoubleLinkedList L
 * @param: L, DoubleLinkedList
 * @return: PtrToDoubleListNode, node with parameter val as value, NULL if not found
 * 
 * */
PtrToDoubleListNode find_DLL(ValueType val, DoubleLinkedList L) {

}

/**
 * 
 * @brief: deleteNodeVal_DLL, delete the node in DoubleLinkedList L with value val and update the head/tail and nodecount correspondingly
 * @param: val, ValueType, value to be removed from DoubleLinkedList L
 * @param: L, DoubleLinkedList
 * 
 * */
void deleteNodeVal_DLL(ValueType val, DoubleLinkedList L) {

}

/**
 * 
 * @brief: deleteNode_DLL, delete the node in DoubleLinkedList L and update the head/tail and nodecount correspondingly
 * @param: node, PtrToDoubleListNode, node to be removed from DoubleLinkedList L
 * @param: L, DoubleLinkedList
 * 
 * */
void deleteNode_DLL(PtrToDoubleListNode node, DoubleLinkedList L) {

}


/**
 * 
 * @brief: insert_DLL, insert a node with value val to DoubleLinkedList L at index, update the node count correspondingly
 * @param: val, ValueType, value of the node to be inserted
 * @param: L, DoubleLinkedList
 * @param: index, uint32_t, index to be inserted to, starts from 0
 * 
 * */
void insert_DLL(ValueType val, DoubleLinkedList L, uint32_t index) {

}

/**
 * 
 * @brief: insertHead_DLL, insert a node with value val to DoubleLinkedList L at head, update the node count correspondingly
 * @param: val, ValueType, value of the node to be inserted
 * @param: L, DoubleLinkedList
 * 
 * */
void insertHead_DLL(ValueType val, DoubleLinkedList L) {

}

/**
 * 
 * @brief: insertTail_DLL, insert a node with value val to DoubleLinkedList L at tail, update the node count correspondingly
 * @param: val, ValueType, value of the node to be inserted
 * @param: L, DoubleLinkedList
 * 
 * */
void insertTail_DLL(ValueType val, DoubleLinkedList L) {

}