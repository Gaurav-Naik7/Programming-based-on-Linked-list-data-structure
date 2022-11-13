//Program to display largest digits of all element from singly linear linked list

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

void DisplayMax(PNODE head)
{
	while(head!=NULL)
	{
		int iDigit,iMax=0,iNo=0;
		iNo=head->data;
	
		while(iNo!=0)
		{
			iDigit=iNo%10;
			if(iDigit>iMax)
			{
				iMax=iDigit;
			}
			iNo=iNo/10;
		}
		printf("%d\t",iMax);
		head=head->next;
	}
}

int main()
{
	PNODE first=NULL;
	int iRet=0;
	
	InsertFirst(&first,419);
	InsertFirst(&first,532);
	InsertFirst(&first,250);
	InsertFirst(&first,11);
	
	Display(first);
	DisplayMax(first);

	return 0;
}