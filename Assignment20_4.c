//Program which returns second largerst element from singly linear linked list

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


int Maximum(PNODE head)
{
	int iMax=0;
	
	PNODE temp=head;
	
	iMax=head->data;
	
	while(head!=NULL)
	{
		if((head->data)>iMax)
		{
			iMax=head->data;
		}
		head=head->next;
	}
	
	head=temp;
	
	while(head!=NULL)
	{
		if((head->data)==iMax)
		{
			head->data=0;
		}
		head=head->next;
	}
	
	iMax=0;
	head=temp;
	
	while(head!=NULL)
	{
		if((head->data)>iMax)
		{
			iMax=head->data;
		}			
		head=head->next;
	}
	return iMax;
}


int main()
{
	PNODE first=NULL;
	int iRet=0;
	
	InsertFirst(&first,240);
	InsertFirst(&first,320);
	InsertFirst(&first,230);
	InsertFirst(&first,110);
	Display(first);
	
	iRet=Maximum(first);
	printf("Second Maximum of all elements is %d ",iRet);
	
	
	return 0;
}