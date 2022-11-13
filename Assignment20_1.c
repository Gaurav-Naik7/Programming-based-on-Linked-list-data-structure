//Program to display all elements which are perfect from singly linear linked list

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

int SumOfFactors(int iNo)
{
	int iCnt=0,iSum=0;
	
	for(iCnt=1;iCnt<iNo;iCnt++)
	{
		if(iNo%iCnt==0)
		{
			iSum=iSum+iCnt;
		}
	}
	return iSum;
}

void DisplayPerfect(PNODE head)
{

	while(head!=NULL)
	{
		if(SumOfFactors(head->data)==head->data)
		{
			printf("%d\t",head->data);
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
	InsertFirst(&first,41);
	InsertFirst(&first,17);
	InsertFirst(&first,28);
	InsertFirst(&first,11);
	
	Display(first);
	DisplayPerfect(first);

	return 0;
}