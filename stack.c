/*
Stack implementation using linked list

Ameet S Deshpande
CS15B001
*/

//See if print function giving extra new line is creating a problem

#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


// create a new stack
stack* stack_new()
{
	stack *temp;
	temp= (stack*) malloc(sizeof(stack));
	temp->top = llist_new();
	(temp->top)->head=NULL;
	return temp;
}



// push an element on the stack
void stack_push(stack* a, int data)
{
	llist_prepend(a->top,data);
}


// pop the top element from the stack
int stack_pop(stack* a)
{
	Node *temp;
	LList *lst = a->top;
	int value;
    temp=(a->top)->head;

    if(temp==NULL)
    {
        return INT_MIN;
    }

    lst->head=temp->next;
    (a->top)->head = lst->head;

    value=temp->data;
    free(temp);
    return value;
}



// Check if stack is empty
bool stack_is_empty(stack* a)
{
	int ans=llist_size(a->top);

	if(ans>0)
	{
		return 0;
	}

	return 1;
}



// find the size of the stack
int stack_size(stack* a)
{
	return llist_size(a->top);
}



// print stack element
void stack_print(stack* a)
{
	llist_print(a->top);
}


