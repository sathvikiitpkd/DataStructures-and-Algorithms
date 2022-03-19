#include <stdio.h>
#include <stdlib.h>

struct node
{
	int item;
	struct node * next;
	struct node * previous;
};
typedef struct node *nodeptr;
int main()
{
	int i,x,n,num;
	nodeptr head=NULL, lastptr=NULL;
	nodeptr newptr,curptr,tempptr,tempptr1;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{		
		newptr=(nodeptr ) malloc(sizeof(struct node));
		if(newptr !=NULL)
		{
			scanf("%d",&x);
			newptr->item=x;
			newptr->next=NULL;
			newptr->previous=NULL;
			
			if(i==0)
			{
				head=newptr;
				lastptr=head;
				tempptr1=head;
			}
			else
			{
				lastptr->next=newptr;
				newptr->previous=lastptr;
				lastptr=newptr;
				lastptr->next=NULL;
			}
		}
		else
		{
			printf("alloc failed\n");
			return -1;
		}
	}
	curptr=head;
	num=curptr->item;
	while(curptr!=NULL)
	{
		printf("%d\n",curptr->item);
		//tempptr=curptr;
		curptr=curptr->next;
		//curptr->previous=NULL;
		//free(tempptr);
	}
	curptr=lastptr;
	while(curptr!=NULL)
	{
		printf("%d\n",curptr->item);
		curptr=curptr->previous;
	}
	curptr=head;
	tempptr=curptr;
	curptr=curptr->next;
	curptr->previous=NULL;
	tempptr->next=NULL;
	head=curptr;
	
	curptr=lastptr;
	tempptr1=curptr;
	curptr=curptr->previous;
	curptr->next=NULL;
	tempptr->previous=NULL;
	lastptr=curptr;
	
	curptr=head;
	while(curptr!=NULL)
	{
		printf("%d\n",curptr->item);
		curptr=curptr->next;
	}
	
	curptr=lastptr;
	while(curptr!=NULL)
	{
		printf("%d\n",curptr->item);
		curptr=curptr->previous;
	}
	free(tempptr);
	free(tempptr1);	
	return 0;
}
