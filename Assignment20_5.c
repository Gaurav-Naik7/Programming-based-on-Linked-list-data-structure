//Program which displays addition of digits of elements from singly linear linked list 

#include<stdio.h>
#include<stdlib.h>

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

void SumDigit(PNODE head)
{
	while(head!=NULL)
	{
		int iDigit,iSum=0,iNo=0;
		iNo=head->data;
	
		while(iNo!=0)
		{
			iDigit=iNo%10;
			iSum=iSum+iDigit;
			iNo=iNo/10;
		}
		
		printf("%d\t",iSum);
		head=head->next;
	}
}

int main()
{
	PNODE first=NULL;
	int iRet=0;
	
	InsertFirst(&first,640);
	InsertFirst(&first,240);
	InsertFirst(&first,20);
	InsertFirst(&first,230);
	InsertFirst(&first,110);
	
	Display(first);
	
	SumDigit(first);

	return 0;
}