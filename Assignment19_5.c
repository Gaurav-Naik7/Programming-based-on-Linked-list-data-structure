//Program which returns smallest element from singly linear linked list

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


int Minimum(PNODE head)
{
	int iMin=0;
	
	iMin=head->data;
	
	while(head!=NULL)
	{
		if((head->data)<iMin)
		{
			iMin=head->data;
		}			
		head=head->next;
	}
	return iMin;
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
	
	iRet=Minimum(first);
	printf("Minimum of all elements is %d ",iRet);
	
	
	return 0;
}