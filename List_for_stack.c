#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



Node* node_new( int data)	//To create first element
{
    Node *temp;
    temp=(Node*) malloc(sizeof(Node));
    temp->data=data;
    temp->next=NULL;
    return temp;	//Setting next pointer to NULL
}



LList* llist_new()	//To create a head pointer
{
    LList *start;
    start=(LList *) malloc(sizeof(LList));
    start->head=NULL;
    return start;
}


int llist_size( LList* lst )	//Returning the number of elements
{
    int count=0;
    Node *temp;
    temp=lst->head;

    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }

    return count;
}



void llist_print( LList* lst )	//To print all the elements of a linked list
{
    Node *temp;
    temp=lst->head;

    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }

    //printf("\n");	//Inserting new line in the end //already inserted in driver function
}



int llist_get( LList* lst, int idx )	//To print the element at the given index
{
    Node *temp;
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

    return INT_MIN;

}




void llist_append( LList* lst, int data )	//Adding a new element at the end of the list
{
    Node *temp,*new1;

    new1=node_new(data);

    if(lst->head==NULL)
    {
        lst->head=new1;
        return;
    }

    temp=lst->head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=new1;
    (temp->next)->next=NULL;	//Setting last pointer as null


}





void llist_prepend( LList* lst, int data )	//Adding element at the beginning of the list
{
    Node *temp,*new1;
    new1=node_new(data);

    temp=lst->head;

    lst->head=new1;
    (lst->head)->next=temp;	//Connecting the link back

}


void llist_insert( LList* lst, int idx, int data )	//Adding element at random index
{
    int index=0;
    Node *temp,*temp1,*new1;
    temp=lst->head;

    if(idx==0)
    {
        llist_prepend(lst,data);
        return;
    }

    new1=node_new(data);

    while(temp->next!=NULL)
    {
        index++;
        if(index==idx)
        {
            break;
        }
        temp=temp->next;
    }

    temp1=temp->next;
    temp->next=new1;
    (temp->next)->next=temp1;

}



void llist_remove_last( LList* lst )	//Remove an element from the end of the list
{
    Node *temp,*temp1;
    temp=lst->head;
    if(temp==NULL)
    {
        return;
    }

    if(temp->next==NULL)
    {
        lst->head=NULL;
        free(temp);
    }


    while((temp->next)->next!=NULL)
    {
        temp=temp->next;
    }


    temp1=temp->next;
    free(temp1);
    temp->next=NULL;

}





void llist_remove_first( LList* lst )	//Remove an element from the beginning of the list
{
    Node *temp;
    temp=lst->head;

    if(temp==NULL)
    {
        return;
    }

    lst->head=temp->next;
    free(temp);
}



void llist_remove( LList* lst, int idx )	//Remove an element from an arbitrary @idx position in the list
{
    Node *temp,*temp1;
    int index=0;
    temp=lst->head; //Initialising temp

    index=llist_size(lst);

    if(idx>=index)
    {
        return;
    }

    if(idx==0)
    {
    llist_remove_first(lst);
    return; 
    }

    if(idx==index-1)
    {
        llist_remove_last(lst);
        return;
    }

    index=0;



    while(temp->next!=NULL)
    {
        index++;
        if(index==idx)
        {
            temp1=temp->next;
            temp->next=temp1->next;
            free(temp1);
            break;
        }
        temp=temp->next;
    }

}



























