#include<stdio.h> 
#include<stdlib.h> 
  
struct node 
{ 
    int item; 
    struct node* next; 
}; 
typedef struct node * nodeptr; 

void print( nodeptr sortedlist)
{
	while(sortedlist != NULL) 
    	{	 
        		printf("%d\n", sortedlist->item); 
        		sortedlist = sortedlist->next; 
    	} 
}

void Insert(nodeptr *, nodeptr); 
  
void insertionSort(nodeptr *head) 
{  
    nodeptr sortedlist = NULL;  
    nodeptr current = *head; 
    while (current != NULL) 
    { 
        nodeptr temp = current->next; 
        Insert(&sortedlist, current);  
        print(sortedlist);
        current=temp;
    } 
    *head = sortedlist; 
} 

void Insert(nodeptr * head, nodeptr newnode)
{
	nodeptr current;
	if(*head==NULL || (*head)->item >=newnode->item)
	{
		newnode->next =*head;
		*head=newnode;
	}
	else
	{
		current=*head;
		while(current->next !=NULL && current->next->item < newnode->item)
		{
			current=current->next;
		}
		newnode->next=current->next;
		current->next=newnode;
	}
	
}
int main()
{
	int x1,x2,x3,x4,x5,i;
	struct node a,b,c,d,e;
	scanf("%d%d%d%d%d",&x1,&x2,&x3,&x4,&x5);
	nodeptr head=NULL;
	
	a.item=x1;
	a.next=NULL;
	
	b.item=x2;
	b.next=NULL;
	
	c.item=x3;
	c.next=NULL;
	
	d.item=x4;
	d.next=NULL;
	
	e.item=x5;
	e.next=NULL;
	
	head=&a;
	a.next=&b;
	b.next=&c;
	c.next=&d;
	d.next=&e;
	
	insertionSort(&head);
    	return 0;
}
	
