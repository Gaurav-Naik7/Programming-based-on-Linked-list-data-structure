//Program to display all palindrome elements of singly linked list

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

void Palindrome(PNODE head)
{
	while(head!=NULL)
	{
		int iDigit=0,iRev=0,iTemp=0;
		
		iTemp=head->data;
	
		while((head->data) > 0)
		{
			iDigit = (head->data) % 10;
			iRev = iRev * 10 + iDigit;
			(head->data) = (head->data) / 10;
		}
		
		if(iTemp==iRev)
		{
			printf("%d ",iTemp);
		}
		
		head=head->next;
	}
}

int main()
{
	PNODE first=NULL;
	int iRet=0;
	
	InsertFirst(&first,89);
	InsertFirst(&first,6);
	InsertFirst(&first,414);
	InsertFirst(&first,17);
	InsertFirst(&first,28);
	InsertFirst(&first,11);
	
	Display(first);
	Palindrome(first);

	return 0;
}