#include<stdio.h> 
#include<stdlib.h> 
  
  //structure for node  
struct node 
{ 
    int item; 
    struct node* next; 
}; 
typedef struct node * nodeptr; 

//function for print values in head
void print( nodeptr head)
{
	while(head != NULL) 
    	{	 
        		printf("%d\n", head->item); 
        		head = head->next; 
    	} 
}

void Insert(nodeptr *, nodeptr); 
 
 // function to insert all elements 
void insertionSort(nodeptr *head) 
{  
    nodeptr sortedlist = NULL;  
    nodeptr current = *head; 
     //traverse current from start and insert it into sorted list
    while (current != NULL) 
    { 
        nodeptr temp = current->next; 
        // insert current in sorted list
        Insert(&sortedlist, current);  
        current=temp;
    } 
     //copy back sorted list to head
    *head = sortedlist; 
} 

//function to insert single element into sorted linked list
void Insert(nodeptr * head, nodeptr newnode)
{
	nodeptr current;
	//case if head is null 
	if(*head==NULL || (*head)->item >=newnode->item)
	{
		newnode->next =*head;
		*head=newnode;
	}
	else
	{
		current=*head;
		// Locate node before the point of insertion and insert it
		while(current->next !=NULL && current->next->item < newnode->item)
		{
			current=current->next;
		}
		newnode->next = current->next; 
       		current->next = newnode; 
	}
	
}

int main()
{
	//Function to read a number n followed by n integers from the user 
	int i,x,n;
	nodeptr head=NULL,lastptr=NULL;
	nodeptr newptr,curptr;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{		
		newptr=(nodeptr) malloc(sizeof(struct node));
		if(newptr !=NULL)
		{
			scanf("%d",&x);
			newptr->item=x;
			newptr->next=NULL;
			
			if(i==1)
			{
				head=newptr;
				lastptr=head;
			}
			else
			{
				lastptr->next=newptr;
				lastptr=newptr;
			}
		}
		else
		{
			printf("alloc failed\n");
			return -1;
		}
	}
	
	insertionSort(&head);
	print(head);
	free(head);
	return 0;
}	
