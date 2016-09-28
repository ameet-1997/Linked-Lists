#ifndef DLIST_H
#define DLIST_H

// DNode for the link list
typedef struct Node_ DNode;
struct Node_ {
	int data;
    DNode* prev; 
    DNode* next;
};

// Create a new node with next set to NULL
DNode* dnode_new( int data);

// Link list structure
typedef struct LList_ {
    DNode* head;
} DList;

// Create an empty list (head shall be NULL)
DList* dlist_new();

// Traverse the linked list and return its size
int dlist_size( DList* lst );

// Traverse the linked list and print each element
void dlist_print( DList* lst );

//get the element at position @idx
int dlist_get( DList* lst, int idx );

// Add a new element at the end of the list
void dlist_append( DList* lst, int data );

// Add a new element at the beginning of the list
void dlist_prepend( DList* lst, int data );

// Add a new element at the @idx index
void dlist_insert( DList* lst, int idx, int data );

// Remove an element from the end of the list
void dlist_remove_last( DList* lst );

// Remove an element from the beginning of the list
void dlist_remove_first( DList* lst );

// Remove an element from an arbitrary @idx position in the list
void dlist_remove( DList* lst, int idx );

void dlist_reverse(DList* lst);
#endif

