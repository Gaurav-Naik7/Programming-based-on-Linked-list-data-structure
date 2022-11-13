//Program to display smallest digits of all element from singly linear linked list

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
	int data;
	struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE head,int no)
{
	PNODE newn=NULL;
	
	newn=(PNODE)malloc(sizeof(NODE));
	
	newn->data=no;
	newn->next=NULL;
	
	if(*head==NULL)
	{
		*head=newn;
	}
	else
	{
		newn->next=*head;
		*head=newn;
	}
}

void Display(PNODE head)
{

	while(head!=NULL)
	{
		printf("|%d|->",head->data);
		head=head->next;
	}
	printf("NULL\n");
}

void DisplaySmall(PNODE head)
{
	while(head!=NULL)
	{
		int iDigit,iMin=0,iNo=0;
		iNo=head->data;
		
		iMin=9;
		
		while(iNo!=0)
		{
			iDigit=iNo%10;
			if(iDigit<iMin)
			{
				iMin=iDigit;
			}
			iNo=iNo/10;
		}
		printf("%d\t",iMin);
		head=head->next;
	}
}

int main()
{
	PNODE first=NULL;
	int iRet=0;
	
	InsertFirst(&first,415);
	InsertFirst(&first,532);
	InsertFirst(&first,250);
	InsertFirst(&first,11);
	
	Display(first);
	DisplaySmall(first);

	return 0;
}