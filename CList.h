/*
 * Author:Abhishek Yadav
 * Linked list data structure
 */

#ifndef CLIST_H
#define CLIST_H

// CNode for the link list
typedef struct Node_ CNode;
struct Node_ {
    int data;
    CNode* next;
};

// Create a new node with next set to NULL
CNode* cnode_new( int data);

// Link list structure
typedef struct LList_ {
    CNode* head;
} CList;

// Create an empty list (head shall be NULL)
CList* clist_new();

// Traverse the linked list and return its size
int clist_size( CList* lst );

// Traverse the linked list and print each element
void clist_print( CList* lst );

//get the element at position @idx
int clist_get( CList* lst, int idx );

// Add a new element at the end of the list
void clist_append( CList* lst, int data );

// Add a new element at the beginning of the list
void clist_prepend( CList* lst, int data );

// Add a new element at the @idx index
void clist_insert( CList* lst, int idx, int data );

// Remove an element from the end of the list
void clist_remove_last( CList* lst );

// Remove an element from the beginning of the list
void clist_remove_first( CList* lst );

// Remove an element from an arbitrary @idx position in the list
void clist_remove( CList* lst, int idx );

// reverse the list
void clist_reverse(CList* lst);
#endif

