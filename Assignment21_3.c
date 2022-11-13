//Program to display product of all digits of all element from singly linear linked list

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

void DisplayProduct(PNODE head)
{
	while(head!=NULL)
	{
		int iDigit=0,iMult=1,iNo=0;
		iNo=head->data;
	
		while(iNo!=0)
		{
			iDigit=iNo%10;
			if(iDigit==0)
			{
				iDigit=1;
			}
			iMult=iMult*iDigit;
			iNo=iNo/10;
		}
		
		printf("%d\t",iMult);
		head=head->next;
	}
}

int main()
{
	PNODE first=NULL;
	int iRet=0;
	
	InsertFirst(&first,41);
	InsertFirst(&first,32);
	InsertFirst(&first,20);
	InsertFirst(&first,11);
	
	Display(first);
	DisplayProduct(first);

	return 0;
}