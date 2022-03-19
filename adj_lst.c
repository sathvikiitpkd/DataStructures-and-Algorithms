#include <stdio.h>
#include <stdlib.h>

//structure for linked list
struct node
{
	int item;
	struct node* next;
};
typedef struct node* nodeptr;

//creating function for Enqueue
void Enqueue(nodeptr *head,nodeptr *tail,int num)
{
	nodeptr newnode;
	newnode=(struct node *) malloc (sizeof(struct node));
	newnode->item=num;
	newnode->next=NULL;
	//linking newnode at tail of queue
	if(*head==NULL) //enqueuing first element
	{
		(*head)=newnode;
		(*tail)=newnode;
	}
	else
	{	
		(*tail)->next=newnode;
		(*tail)=newnode;
	}
}

//function for displaying adjacent elements
void Display(nodeptr head,nodeptr tail)
{
	nodeptr temp,prev;
	temp=head;
	//if head is null print null
	if(head ==NULL)
	{
		printf("Nil");
	}
	//else printing elements till head is null
	else
	{
		while(temp!=NULL)
		{			
			if(temp==tail)
			{
				printf("%d",(temp)->item);
				temp=temp->next;
			}
			else
			{	
				printf("%d ",(temp)->item);
				temp=temp->next;	
			}
		}
	}
	return;
}
	
int main()
{
	int n,m,i,x,y;
	scanf("%d%d",&n,&m);
	//define array of linked lists
	nodeptr head[n],tail[n];
	//initialise it to NULL
	for(i=0;i<n;i++)
	{
		head[i]=NULL;
		tail[i]=NULL;
	}
	//read m lines of edges
	i=0;
	while(i<m)
	{
		scanf("%d%d",&x,&y);
		//enqueue x in head[y] and y in tail[x]
		Enqueue(&head[x],&tail[x],y);
		Enqueue(&head[y],&tail[y],x);
		i++;
	}
	for(i=0;i<n;i++)
	{
		Display(head[i],tail[i]);
		printf("\n");
	}
	return 0;
}

		
