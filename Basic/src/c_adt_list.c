#include "c_adt_list.h"

// ************************************************************************
// LinkedList API
// ************************************************************************

/**
 * 
 * @brief: init_LL, init the linkedlist L and assign initial value to data fields
 * @param: L, LinkedList to be init, it must have a space assigned in memory prior to calling this function
 * 
 * */
void init_LL(LinkedList L) {
    if (L == NULL)
        return;
    else {
        L->head = NULL;
        L->tail = NULL;
        L->nodeCount = 0;
    }
}

/**
 * 
 * @brief: _free_LL, Recursively free a linkedlist
 * @param: L, LinkedList to be free
 * 
 * */
void _free_LL(PtrToLinkedListNode node) {
    if (node->next == NULL) {
        free(node);
    } else {
        _free_LL(node->next);
        free(node);
    }
    return;
}

/**
 * 
 * @brief: free_LL, Free the linkedlist nodes and return the LinkedList afterward
 * @param: L, LinkedList to be free
 * 
 * */
void free_LL(LinkedList L) {
    if (L != NULL && L->head != NULL) {
        _free_LL(L->head);
        L->nodeCount = 0;
        L->head = NULL;
        L->tail = NULL;
    }
}


/**
 * 
 * @brief: isEmpty_LL, Check if the linkedlist is empty (contains zero nodes)
 * @param: L, LinkedList to be checked
 * @return: int, 1 if the list is empty, 0 otherwise
 * 
 * */
int isEmpty_LL(LinkedList L) {
    if (L == NULL)
        return 1;
    else
        return L->nodeCount == 0;
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
    if (L == NULL || L->tail == NULL)
        return 0;
    else
        return L->tail->value == node->value;
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
    if (L == NULL)
        return NULL;

    PtrToLinkedListNode node = NULL;
    PtrToLinkedListNode head = L->head;
    while (head != NULL)
    {
        if (head->value == val) {
            node = head;
            break;
        } else if (head->next == NULL)
            break;
        else
            head = head->next;
    }
    return node;
}

/**
 * 
 * @brief: deleteNode_LL, delete the first node in LinkedList L with value val and update the head/tail and nodecount correspondingly
 * @param: val, ValueType, value to be removed from LinkedList L
 * @param: L, LinkedList
 * 
 * */
void deleteNode_LL(ValueType val, LinkedList L) {
    if (L == NULL || L->nodeCount == 0)
        return;

    PtrToLinkedListNode parent = L->head;

    // Node at head
    if (parent != NULL && parent->value == val) {
        L->head = parent->next;
        if (L->tail == parent)  // update tail pointer
            L->tail = NULL;
        L->nodeCount--;
        free(parent);
    } else {
        PtrToLinkedListNode node = parent->next;
        // Find the node that match
        while (node != NULL)
        {
            if (node->value == val) {
                // Found the match
                parent->next = node->next;
                if (L->tail == node)
                    L->tail = parent;
                L->nodeCount--;
                free(node);
                node = NULL;
            } else {
                // Traverse the list
                parent = node;
                node = node->next;
            }
        }
    }
    return;
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
    if (L == NULL)
        return NULL;

    PtrToLinkedListNode result = NULL;
    PtrToLinkedListNode parent = L->head;
    if (parent != NULL && parent->value != val) {
        PtrToLinkedListNode node = parent->next;
        // Find the node that match
        while (node != NULL)
        {
            if (node->value == val) {
                // Found the match
                result = parent;
                node = NULL;
            } else {
                // Traverse the list
                parent = node;
                node = node->next;
            }
        }
    }
    return result;
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
    if (L == NULL)
        return;
    else if (index == 0)
        insertHead_LL(val, L);
    else if (index >= L->nodeCount)
        insertTail_LL(val, L);
    else {
        PtrToLinkedListNode parent = L->head;
        PtrToLinkedListNode node = parent->next;    // Guarantee available
        for (uint32_t i = 0; i < index - 1; i++) {
            parent = node;
            node = node->next;
        }

        // Allocate space
        PtrToLinkedListNode tmp = (PtrToLinkedListNode) malloc(sizeof(struct LinkedListNode));
        tmp->value = val;
        parent->next = tmp;
        tmp->next = node;
        L->nodeCount++;
    }
}

/**
 * 
 * @brief: insertHead_LL, insert a node with value val to LinkedList L at head, update the node count correspondingly
 * @param: val, ValueType, value of the node to be inserted
 * @param: L, LinkedList
 * 
 * */
void insertHead_LL(ValueType val, LinkedList L) {
    if (L == NULL)
        return;
    else {
        // Allocate space
        PtrToLinkedListNode tmp = (PtrToLinkedListNode) malloc(sizeof(struct LinkedListNode));
        tmp->value = val;
        tmp->next = L->head;
        L->head = tmp;
        L->nodeCount++;
        if (L->nodeCount == 1) // initial insert
            L->tail = L->head;
    }
}

/**
 * 
 * @brief: insertTail_LL, insert a node with value val to LinkedList L at tail, update the node count correspondingly
 * @param: val, ValueType, value of the node to be inserted
 * @param: L, LinkedList
 * 
 * */
void insertTail_LL(ValueType val, LinkedList L) {
    if (L == NULL)
        return;
    else {
        // Allocate space
        PtrToLinkedListNode tmp = (PtrToLinkedListNode) malloc(sizeof(struct LinkedListNode));
        tmp->value = val;
        tmp->next = NULL;
        if (L->tail == NULL) {
            // initial insert
            L->head = tmp;
            L->tail = tmp;
        } else {
            L->tail->next = tmp;
            L->tail = tmp;
        }
        L->nodeCount++;
    }
}

// ************************************************************************
// Double LinkedList API
// ************************************************************************

/**
 * 
 * @brief: init_DLL, init the double linkedlist L and assign initial value to data fields
 * @param: L, DoubleLinkedList to be init, it must have a space assigned in memory prior to calling this function
 * 
 * */
void init_DLL(DoubleLinkedList L) {
    if (L == NULL)
        return;
    else {
        L->head = NULL;
        L->tail = NULL;
        L->nodeCount = 0;
    }
}

/**
 * 
 * @brief: _free_DLL, Recursively free a double linkedlist
 * @param: L, Double LinkedList to be free
 * 
 * */
void _free_LL(PtrToLinkedListNode node) {
    if (node->next == NULL) {
        free(node);
    } else {
        _free_LL(node->next);
        free(node);
    }
    return;
}

/**
 * 
 * @brief: free_DLL, Free the double linkedlist nodes and return the double LinkedList afterward
 * @param: L, DoubleLinkedList to be free
 * 
 * */
void free_DLL(DoubleLinkedList L) {
    if (L == NULL || L->nodeCount == 0)
        return;

    PtrToDoubleListNode node = L->tail;
    while (node != NULL && node->prev != NULL) {
        node = node->prev;
        free(node->next);
    }
    free(node); // Reach head

    L->head = NULL;
    L->tail = NULL;
    L->nodeCount = 0;
    return NULL;
}

/**
 * 
 * @brief: isEmpty_DLL, Check if the double linkedlist is empty (contains zero nodes)
 * @param: L, DoubleLinkedList to be checked
 * @return: int, 1 if the list is empty, 0 otherwise
 * 
 * */
int isEmpty_DLL(DoubleLinkedList L) {
    if (L == NULL)
        return 1;
    else
        return L->nodeCount == 0;
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
    if (L == NULL || L->tail == NULL)
        return 0;
    else
        return L->tail->value == node->value;
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
    if (L == NULL)
        return NULL;

    PtrToDoubleListNode node = NULL;
    PtrToDoubleListNode head = L->head;
    while (head != NULL)
    {
        if (head->value == val) {
            node = head;
            break;
        } else if (head->next == NULL)
            break;
        else
            head = head->next;
    }
    return node;
}

/**
 * 
 * @brief: deleteNode_DLL, delete the node in DoubleLinkedList L and update the head/tail and nodecount correspondingly
 * @param: val, ValueType, value to be removed from DoubleLinkedList L
 * @param: L, DoubleLinkedList
 * 
 * */
void deleteNode_DLL(ValueType val, DoubleLinkedList L) {
    if (L == NULL || L->nodeCount == 0)
        return;
    else {
        PtrToDoubleListNode node = find_DLL(val, L);
        node->prev->next = node->next;
        node->next = node->prev;
        free(node);
    }
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
    if (L == NULL)
        return;
    else if (index == 0)
        insertHead_DLL(val, L);
    else if (index >= L->nodeCount)
        insertTail_DLL(val, L);
    else {
        PtrToDoubleListNode parent = L->head;
        PtrToDoubleListNode node = parent->next;    // Guarantee available
        for (uint32_t i = 0; i < index - 1; i++) {
            parent = node;
            node = node->next;
        }

        // Allocate space
        PtrToDoubleListNode tmp = (PtrToDoubleListNode) malloc(sizeof(struct DoubleLinkedListNode));
        tmp->value = val;
        parent->next = tmp;
        tmp->prev = parent;
        tmp->next = node;
        node->prev = tmp;
        L->nodeCount++;
    }
}

/**
 * 
 * @brief: insertHead_DLL, insert a node with value val to DoubleLinkedList L at head, update the node count correspondingly
 * @param: val, ValueType, value of the node to be inserted
 * @param: L, DoubleLinkedList
 * 
 * */
void insertHead_DLL(ValueType val, DoubleLinkedList L) {
    if (L == NULL)
        return;
    else {
        // Allocate space
        PtrToDoubleListNode tmp = (PtrToDoubleListNode) malloc(sizeof(struct DoubleLinkedListNode));
        tmp->value = val;
        tmp->next = L->head;
        tmp->prev = NULL;
        L->head->prev = tmp;
        L->head = tmp;
        L->nodeCount++;
        if (L->nodeCount == 1)  // initial insert
            L->tail = L->head;
    }
}

/**
 * 
 * @brief: insertTail_DLL, insert a node with value val to DoubleLinkedList L at tail, update the node count correspondingly
 * @param: val, ValueType, value of the node to be inserted
 * @param: L, DoubleLinkedList
 * 
 * */
void insertTail_DLL(ValueType val, DoubleLinkedList L) {
    if (L == NULL)
        return;
    else {
        // Allocate space
        PtrToDoubleListNode tmp = (PtrToDoubleListNode) malloc(sizeof(struct DoubleLinkedListNode));
        tmp->value = val;
        tmp->next = NULL;
        tmp->prev = NULL;
        if (L->tail == NULL) {
            // initial insert
            L->head = tmp;
            L->tail = tmp;
        } else {
            L->tail->next = tmp;
            tmp->prev = L->tail;
            L->tail = tmp;
        }
        L->nodeCount++;
    }
}