#include <stdio.h>
#include <stdlib.h>

//creating structure of node
struct node
{
	int item;
	struct node * next;
};
typedef struct node *nodeptr;
//created global variable nodeptr head
nodeptr head=NULL;

//creating function for isempty
void Isempty( )
{
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

//creating function for push
void Push (int num)
{
	nodeptr newnode;
	//dynamically allot a newnode
	newnode=(struct node *) malloc (sizeof(struct node));
	//linking newnode at top of stack
	newnode->item=num;
	newnode->next=head;
	head=newnode;
}

//creating function for top
void Top ()
{
	//printing top value of stack
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

//creating function for pop		
void Pop( )
{
	//create temp nodeptr
	nodeptr temp;
	//point head to temp
	temp=head;
	//pop the top element of stack
	if(head !=NULL)
	{
		printf("%d\n",head->item);
		head=head->next;
		free(temp);
	}
	else 
	{
		printf("Pop Failure\n");
	}
}


	
int main()
{
	int i,num,n;
	while(1)
	{
		nodeptr head=NULL;
		//depending on input function is menu driven
		scanf("%d",&n);
		if(n==0)
		{
			Isempty();
		}
		if(n==1)
		{
			scanf("%d",&num);
			Push(num);
		}
		if(n==2)
		{
			Pop( );
		}
		if(n==3)
		{
			Top( );
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
