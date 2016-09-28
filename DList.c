#include "DList.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
///////////////////////////////////////////////////////////////For print function check in test file how an empty list is printed

// Create a new node with next set to NULL
DNode* dnode_new( int data)
{
	DNode *new1;
	new1=(DNode*) malloc(sizeof(DNode));

	new1->data=data;

	new1->prev=NULL;	//Setting both th pointers to NULL
	new1->next=NULL;

	return new1;
}


// Create an empty list (head shall be NULL)
DList* dlist_new()
{
	DList *start;
	start=(DList*) malloc(sizeof(DList));
	start->head=NULL;	//Setting head as NULL

	return start;
}


// Traverse the linked list and return its size
int dlist_size( DList* lst )
{
	DNode *temp;
	int size=0;

	temp=lst->head;

	while(temp!=NULL)	//Keep traversing the linked list till NULL is encountered
	{
		temp=temp->next;
		size++;
	}


	return size;

}




// Traverse the linked list and print each element
void dlist_print( DList* lst )
{
	DNode *temp;
    temp=lst->head;

    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }

    printf("\n");	//Inserting new line in the end
    return;
}




//get the element at position @idx
int dlist_get( DList* lst, int idx )
{
	DNode *temp;
    int index=0;
    temp=lst->head;


    while(temp!=NULL)
    {
        if(index==idx)
        {
            return temp->data;
        }
        index++;
        temp=temp->next;
    }

    return -1;
}





// Add a new element at the end of the list
void dlist_append( DList* lst, int data )
{
	DNode *temp,*new1;


	new1=dnode_new(data);

	temp=lst->head;

	if(temp==NULL)	//Writing seperate code if the list is empty initially
	{
		lst->head=new1;
		new1->next=NULL;
		new1->prev=NULL;
		return;
	}

	while(temp->next!=NULL)
	{
		temp=temp->next;
	}

	temp->next=new1;
	new1->prev=temp;
	new1->next=NULL;
	return;

}




// Add a new element at the beginning of the list
void dlist_prepend( DList* lst, int data )
{
	DNode *temp,*new1;

	new1=dnode_new(data);
	temp=lst->head;

	if(temp==NULL)
	{
		lst->head=new1;
		new1->next=NULL;
		new1->prev=NULL;
		return;	
	}

	new1->next=lst->head;
	new1->prev=NULL;
	(lst->head)->prev=new1;	//Added the node
	lst->head=new1;		//Changing the start pointer

	return;


}





// Add a new element at the @idx index
void dlist_insert( DList* lst, int idx, int data )
{
	DNode *temp,*new1;
	int i;	//Loop variable
	int size;

	size=dlist_size(lst);
	if(idx==size)
	{
		dlist_append(lst,data);
		return;
	}

	if(idx>size)
	{
		return;
	}



	if(idx==0)
	{
		dlist_prepend(lst,data);
		return;
	}

	new1=dnode_new(data);
	temp=lst->head;


	for(i=0;i<idx;++i)
	{
		temp=temp->next;
	}

	(temp->prev)->next=new1;	//Inserting the node in the correct position
	new1->next=temp;
	new1->prev=temp->prev;
	temp->prev=new1;

	return;


}




// Remove an element from the end of the list
void dlist_remove_last( DList* lst )
{
	DNode *temp;
	temp=lst->head;

	if(temp==NULL)
	{
		return;
	}

	if(temp->next==NULL)
	{
		free(temp);
		lst->head=NULL;
		return;
	}

	while(temp->next!=NULL)
	{
		temp=temp->next;
	}

	(temp->prev)->next=NULL;
	temp->prev=NULL;
	free(temp);

	return;


}





// Remove an element from the beginning of the list
void dlist_remove_first( DList* lst )
{
	DNode *temp;
	temp=lst->head;

	if(temp==NULL)
	{
		return;
	}


	if(temp->next==NULL)
	{
		free(temp);
		lst->head=NULL;
		return;
	}


	lst->head=(lst->head)->next;
	(lst->head)->prev=NULL;

	return;

}




// Remove an element from an arbitrary @idx position in the list
void dlist_remove( DList* lst, int idx )
{
	DNode *temp;
	int i;	//Loop variable

	temp=lst->head;

	if(temp==NULL)
	{
		return;
	}

	if(idx==0)
	{
		dlist_remove_first(lst);
		return;
	}

	for(i=0;i<idx;++i)
	{
		temp=temp->next;
	}

	(temp->prev)->next=temp->next;
	if(temp->next!=NULL)
	{
		(temp->next)->prev=temp->prev;	
	}
	
	free(temp);
	return;

}




// Reverse the doubly linked list
void dlist_reverse(DList* lst)
{
	DNode *temp,*swap;
	temp=lst->head;

	if(temp==NULL)
	{
		return;
	}

	while(temp->next!=NULL)
	{
		swap=temp->next;		//Swapping the next and prev pointers
		temp->next=temp->prev;
		temp->prev=swap;

		temp=temp->prev;
	}

	lst->head=temp;

	swap=temp->next;		//Writing seperately for the last node
	temp->next=temp->prev;
	temp->prev=swap;

	return;


}











