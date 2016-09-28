/*
This program converts the given infix expression to postfix expression

Ameet S Deshpande
CS15B001
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "List.h"
#include <limits.h>

int precedence(char a)	//Returns the precedence value of the operator
{
	if(a=='|')
	{
		return 0;
	}

	else if(a=='^')
	{
		return 1;
	}

	else if(a=='&')
	{
		return 2;
	}

	else if(a=='+')
	{
		return 3;
	}

	else if(a=='-')
	{
		return 4;
	}

	else if(a=='*')
	{
		return 5;
	}

	else if(a=='/')
	{
		return 6;
	}

	else if(a=='%')
	{
		return 7;
	}

	return INT_MIN;
} 


int main()
{	
	char a[1000];
	stack *s;	//The stack being used for the conversion
	char c = ' ';		//Used for storing the characters required
	int popped;	//Stores the value of the popped element
	int count=0;
	int flag=0;

	s = stack_new();	//Making a new stack

	int i=0;	//Loop variable



	for(i=0;i<10;++i)
	{

	count=0;
	c=' ';	//Initialising

	//scanf("%[^\n]s",a);
	fgets (a, 999, stdin);

	while(c!='\0')
	{	
		//c = getchar();
		c=a[count];
		count++;
		

		if(c=='(')
		{
			stack_push(s,(int)(c));
		}
		else if(c==')')
		{
			popped = stack_pop(s);
			while((char)(popped)!='(')
			{
				printf("%c ",popped);	//Space after every operand
				popped = stack_pop(s);
			}
		}
		else if(((c>='A')&&(c<='Z'))||((c>='a')&&(c<='z'))||((c>='0')&&(c<='9')))
		{	
			//flag=0;
			while(((c>='A')&&(c<='Z'))||((c>='a')&&(c<='z'))||((c>='0')&&(c<='9')))
			{
				printf("%c",c);
				//c = getchar();
				if(a[count]=='\0')
				{	c=a[count];
					break;
				}
				else
				{
					c=a[count];
					count++;
				}
			}
			printf(" ");
		}
		else if(c == ' ')
		{
			continue;	//Ignore spaces
		}

		else	//For operators
		{	
			if(stack_is_empty(s))		//If the stack is empty, just push the operator in
			{	
				stack_push(s,(int)(c));
				continue;
			}

			popped = stack_pop(s);

			while(((popped!='(')&&(popped!=')'))&&(precedence((char)(popped)) >= precedence(c)))	//If the popped operator has higher 
			{																						//precedence		
				printf("%c ",popped);
				if(stack_is_empty(s))
				{	flag=1;
					break;
				}	

				popped = stack_pop(s);
			}

			if((char)(popped) == '(')
			{
				stack_push(s,popped);
				stack_push(s,(int)(c));
			}
			else if((stack_is_empty(s))&&(flag==1))
			{	
				//stack_push(s,popped);
				stack_push(s,(int)(c));
				flag=0;
			}
			else
			{	
				stack_push(s,popped);
				stack_push(s,(int)(c));
			}
		}

	}

	while(!stack_is_empty(s))
	{
		popped = stack_pop(s);
		printf("%c ",popped);
	}

	printf("\n");


	}

return 0;

}
