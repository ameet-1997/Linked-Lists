#include "CList.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


/*
Ameet S Deshpande
CS15B001
*/

// Create a new node with next set to NULL
CNode* cnode_new( int data)
{
	CNode *temp;	//Creating a temporary pointer
    temp=(CNode*) malloc(sizeof(CNode));	//Allocating memory
    temp->data=data;
    temp->next=NULL;
    return temp;	//Setting next pointer to NULL
}



// Create an empty list (head shall be NULL)
CList* clist_new()
{
	CList *temp;	//Creating a temporary pointer
	temp=(CList*) malloc(sizeof(CList));	//Allocating memory
	temp->head=NULL;
	return temp;
}


// Traverse the linked list and return its size
int clist_size( CList* lst )
{
	CNode *temp1,*temp2;
	int size=0;	//Contains the size of the linked list
	
	temp1=lst->head;	//Initially both the pointers are pointing to the same location
	temp2=lst->head;
	
	if(temp1==NULL)
	{
		return size;
	}

	else
	{
		temp2=temp2->next;
		size++;

		while(temp2!=temp1)	//Keep traversing the linked list till both the pointers become equal again
		{
			temp2=temp2->next;
			size++;
		}

		return size;
	}



}




// Traverse the linked list and print each element
void clist_print( CList* lst )
{
	CNode *temp1,*temp2;
	int value;	//Contains the value of the current
	
	temp1=lst->head;	//Initially both the pointers are pointing to the same location
	temp2=lst->head;
	
	if(temp1==NULL)
	{
		return;				//Check later if newline is to be added if list is empty-----------------
	}

	else
	{	value=temp2->data;
		printf("%d ",value);

		temp2=temp2->next;

		while(temp2!=temp1)	//Keep traversing the linked list till both the pointers become equal again
		{	
			value=temp2->data;
			printf("%d ",value);
			temp2=temp2->next;

		}

		printf("\n");

	}

}







//get the element at position @idx
int clist_get( CList* lst, int idx )
{
	int i;	//Loop variable
	CNode *temp;
	temp=lst->head;

	if(temp==NULL)
	{
		return INT_MIN;
	}

	for(i=0;i<idx;++i)
	{
		temp=temp->next;
	}

	return temp->data;
}



// Add a new element at the end of the list
void clist_append( CList* lst, int data )
{
	CNode *temp1,*temp2,*new1;

	temp1=lst->head;
	temp2=lst->head;

	new1=cnode_new(data);	//Creating a new node

	if(temp1==NULL)
	{
		
		lst->head=new1;
		(lst->head)->next=new1;	//Making the node point to itself
		return;
	}

	else
	{
		while(temp2->next!=temp1)
		{
			temp2=temp2->next;
		}

		temp2->next=new1;
		new1->next=temp1;
		return;

	}


}



// Add a new element at the beginning of the list
void clist_prepend( CList* lst, int data )
{
	CNode *temp1,*temp2,*new1;

	new1=cnode_new(data);	//Creating a new node

	temp1=lst->head;
	temp2=lst->head;

	if(lst->head==NULL)
	{
		lst->head=new1;
		(lst->head)->next=new1;	//Making the node point to itself
		return;	
	}

	else
	{
		while(temp2->next!=temp1)
		{
			temp2=temp2->next;

		}	

		temp2->next=new1;
		new1->next=lst->head;
		lst->head=new1;

		return;
	}
}




// Add a new element at the @idx index
void clist_insert( CList* lst, int idx, int data )
{
	CNode *temp,*new1,*temp2;
	int i;		//Loop variable
	temp=lst->head;

	if(idx==0)
	{
		clist_prepend(lst,data);
		return;
	}

	new1=cnode_new(data);	//Creating a new node	

	for(i=0;i<idx-1;++i)
	{
		temp=temp->next;
	}

	temp2=temp->next;
	temp->next=new1;
	new1->next=temp2;
	return;

}




// Remove an element from the end of the list
void clist_remove_last( CList* lst )
{	
	CNode *temp1,*temp;
	int size;
	int i;	//Loop variable

	temp1=lst->head;

	if(temp1==NULL)
	{
		return;
	}

	size=clist_size(lst);


	if(size==1)
	{
		lst->head=NULL;
		free(temp1);
		return;
	}
	else
	{
		for(i=0;i<size-2;++i)
		{
			temp1=temp1->next;
		}

		temp=temp1->next;
		temp1->next=lst->head;	//Setting temp to be the next to next node
		free(temp);
		return;
	}
}


// Remove an element from the beginning of the list
void clist_remove_first( CList* lst )
{
	CNode *temp1,*temp;
	int size;
	int i;	//Loop variable

	temp1=lst->head;

	if(temp1==NULL)
	{
		return;
	}

	size=clist_size(lst);


	if(size==1)
	{	
		lst->head=NULL;
		free(temp1);
		return;
	}
	else
	{
		for(i=0;i<size-1;++i)
		{
			temp1=temp1->next;
		}

		temp=lst->head;
		temp1->next=(lst->head)->next;
		lst->head=temp1->next;
		free(temp);
	}
}



// Remove an element from an arbitrary @idx position in the list
void clist_remove( CList* lst, int idx )
{
	CNode *temp1,*temp;
	int i;	//Loop variable
	temp1=lst->head;

	if(temp1==NULL)
	{
		return;
	}

	if(idx==0)
	{
		clist_remove_first(lst);
	}
	else
	{
		for(i=0;i<idx-1;++i)
		{
			temp1=temp1->next;
		}

		temp=temp1->next;
		temp1->next=temp->next;
		free(temp);
		return;

	}

}


// reverse the list
void clist_reverse(CList* lst)
{
	int *a;
	int size;
	CNode *temp;
	int i;	//Loop variable

	size=clist_size(lst);

	if(lst->head==NULL)
	{
		return;
	}

	temp=(lst->head);

	if(size==1)
	{
		return;
	}

	a=(int *) malloc(sizeof(int)*(size));

	for(i=0;i<size;++i)	//Storing the values and then setting them in the reverse order
	{
		a[i]=temp->data;
		temp=temp->next;
	}

	temp=(lst->head);

	for(i=0;i<size;++i)
	{
		temp->data=a[size-1-i];
		temp=temp->next;
	}

	free(a);

	return;


}