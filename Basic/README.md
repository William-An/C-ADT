# Basic Data Structure

## LinkedList

![Example Figure](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2013/03/Linkedlist.png) image from GeeksforGeeks

LinkedList is simply nodes connected together via the `next` pointer from the previous node to the next node. In addition, each node also has a data field `value` to store data.

In this implementatioin, we will be using a meta data structure `LinkedList` to hold the nodes, where it will have certain meta information like `head` node, `tail` node, and `nodecount`.

For more information, seek for online materials like [GeeksforGeeks](https://www.geeksforgeeks.org/data-structures/linked-list/)

See `c_adt_list.h` and `c_adt_list.c` for APIs

## Double LinkedList

![Example Figure](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2014/03/DLL1.png) image from GeeksforGeeks

Double LinkedList is basically the same as the LinkedList, except for each node, besides the pointer to the next node, it will also have the pointer to the previous node.

See `c_adt_list.h` and `c_adt_list.c` for APIs

## Stack

![Example Figure](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2013/03/stack.png) image from GeeksforGeeks

[Stack](https://www.geeksforgeeks.org/stack-data-structure/) is a LIFO (last in, first out) linear data structure that supports `pop` and `push` operations. Data store in the stack will be removed based on the time they are added or push into the stack. The newer data will be removed first. Example of stack can be the way browser stores the visited tab. In addition, in terms of C program, the local variables of a subroutine will be store onto the stack for CPU to fetch.

In our version of Stack, we will try two different ways to implement the Stack: 1) use an array with dynamic resizing based on current size of stack and 2) use a linkedlist.

See `c_adt_stack_arr.h`, `c_adt_stack_list.h` and `c_adt_stack_arr.c`, `c_adt_stack_list.c` for APIs

## Queue

See `c_adt_queue.h` and `c_adt_queue.c` for APIs

## Dequeue

See `c_adt_dequeue.h` and `c_adt_dequeue.c` for APIs
