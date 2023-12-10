#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    struct ListNode* prev;
    struct ListNode* next;
    void* item;
} ListNode;

/** Creates a node with given item and inserts it after the given node */
void listInsertAfter(ListNode* node, void* item) {
    if (!node) return;
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (!newNode) {
        printf("Could not allocate memory for new list node!\n");
        return;
    }
    ListNode* temp = node->next;
    node->next = newNode;
    newNode->prev = node;
    newNode->next = temp;
    if (temp) temp->prev = newNode;
    newNode->item = item;
}
/** Creates a node with given item and inserts it before the given node */
void listInsertBefore(ListNode* node, void* item) {
    if (!node) return;
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (!newNode) {
        printf("Could not allocate memory for new list node!\n");
        return;
    }
    ListNode* temp = node->prev;
    node->prev = newNode;
    newNode->next = node;
    newNode->prev = temp;
    if (temp) temp->next = newNode;
    newNode->item = item;
}
/** Removes the given node from the list */
void* listRemove(ListNode* node) {
    if (!node) return NULL;
    if (node->prev)
        node->prev->next = node->next;
    if (node->next)
        node->next->prev = node->prev;
    void* result = node->item;
    free(node);
    return result;
}
/** Fetches the item that is at the given offset from the given node.
 * The offset is interpreted as follows:
 * - if the offset is positive it will get a next item
 * - if the offset is negative it will get a previous item
 * - if the offset is 0 it will get the value of the given node
 * 
 * If the node at the specified offset does not exist or the given node does
 * not exist, it will return NULL.
 */
void* listGet(ListNode* node, int offset) {
    if (!node) return NULL;
    ListNode* temp = node;
    if (offset >= 0) {
        int i;
        for (i = 0; i < offset; i++) {
            temp = temp->next;
            if (!temp) return NULL;
        }
    }
    else {
        offset = -offset;
        int i;
        for (i = 0; i < offset; i++) {
            temp = temp->prev;
            if (!temp) return NULL;
        }
    }
    return temp->item;
}

/*
int main() {
    int d = 2;
    ListNode* n1 = (ListNode*)malloc(sizeof(ListNode));
    n1->next = NULL;
    n1->prev = NULL;
    n1->item = &d;

    int a = 10;
    int b = 12;
    int c = 9;
    // 2
    listInsertAfter(n1, &a);
    // 2, 10
    listInsertAfter(n1, &b);
    // 2, 12, 10
    listInsertBefore(n1, &c);
    // 9, 2, 12, 10
    listRemove(n1->next);
    // 9, 2, 10

    int* x = (int*)listGet(n1, -1);
    int* y = (int*)listGet(n1, 0);
    int* z = (int*)listGet(n1, 1);
    
    printf("%d, %d, %d\n", *x, *y, *z);

    return 0;
}
*/

#endif