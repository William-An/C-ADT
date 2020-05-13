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

See `c_adt_stack.h` and `c_adt_stack.c` for APIs

## Queue

See `c_adt_queue.h` and `c_adt_queue.c` for APIs

## Dequeue

See `c_adt_dequeue.h` and `c_adt_dequeue.c` for APIs
