//Program to display all elements which are prime from singly linear linked list

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

void DisplayPrime(PNODE head)
{
	
	while(head!=NULL)
	{
		int iCnt=0;
		bool check;
	
		for(iCnt=2;iCnt<(head->data);iCnt++)
		{
			if((head->data)%iCnt==0)
			{
				check=false;
				break;
			}
			else
			{
				check=true;
			}
		}
		
		if(check==true)
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
	DisplayPrime(first);

	return 0;
}