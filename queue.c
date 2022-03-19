#include <stdio.h>
#include <stdlib.h>

//creating structure of node
struct node
{
	int item;
	struct node * next;
};
typedef struct node *nodeptr;
//created global variable nodeptr head,tail
nodeptr head=NULL;
nodeptr tail=NULL;

//creating function for isempty
void Isempty( )
{
	//if head is null then print empty else print non empty
	if(head==NULL)
	{
		printf("Empty\n");
	}
	else
	{
		printf("Non Empty\n");
	}
	return;
}

//creating function for Enqueue
void Enqueue (int num)
{
	nodeptr newnode,current;
	//dynamically allot a newnode
	newnode=(struct node *) malloc (sizeof(struct node));
	//initialise newnode
	newnode->item=num;
	newnode->next=NULL;
	//linking newnode at tail of queue
	if(head==NULL) //enqueuing first element
	{
		head=newnode;
		tail=newnode;
	}
	else
	{	
	tail->next=newnode;
	tail=newnode;
	}
}

//creating function for Peek
void Peek ()
{
	//printing top value of squeue
	printf("%d\n",head->item);

}

//creating function for Display
void Display()
{
	int i;
	nodeptr temp;
	temp=head;
	//if head is null print null
	if(head ==NULL)
	{
		printf("Empty List\n");
	}
	//else printing elements till head is null
	else
	{
		
		while(temp !=NULL)
		{	
			printf("%d\n",(temp)->item);
			temp=temp->next;
		}
	}
	return;
}

//creating function for Dequeue	
void Dequeue( )
{
	//create temp nodeptr
	nodeptr temp;
	//point head to temp
	temp=head;
	//pop the top element of queue
	if(head !=NULL)
	{
		printf("%d\n",head->item);
		head=head->next;
		free(temp);
		
	}
	else 
	{
		printf("Dequeue Failure\n");
	}
}


	
int main()
{
	int i,num,n;
	nodeptr head=NULL;
	nodeptr tail=NULL;
	while(1)
	{
		//depending on input function is menu driven
		scanf("%d",&n);
		if(n==0)
		{
			Isempty();
		}
		if(n==1)
		{
			scanf("%d",&num);
			Enqueue(num);
		}
		if(n==2)
		{
			Dequeue( );
		}
		if(n==3)
		{
			Peek( );
		}
		if(n==4)
		{
			Display( );
		}
		if(n==5)
		{
			//freeing space and exit 
			free(head);
			return 0;
		}
	}
}
