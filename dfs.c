#include <stdio.h>
#include <stdlib.h>

//structure for linked list
struct node
{
	int item;
	struct node* next;
};
typedef struct node* nodeptr;

//define visited,entry and exi,initially clock=0;
int visited[100000],entry[100000],exi[100000],clock=0;

//function for exploring adjacent vertices of v 
void Dfsexplore(nodeptr *head,int v)
{
	//Take a note of entry times of v using global clock
	visited[v]=1;
	entry[v]=clock;
	clock=clock+1;
	//declare temp and set head[v] to temp
	nodeptr temp;
	temp=head[v];
	//Check whether adjacent vertices are visited or not if not visit it via recursively calling Dfsexplore
	while(temp != NULL)
	{
		if(visited[(temp->item)] ==0)
		{
			Dfsexplore(head,(temp->item));
		}
		temp=temp->next;
	}
	//Take a note of exit times of v using global clock
	exi[v]=clock;
	clock=clock+1;
}

//Check whether vertice is visited or not if not visit it by calling dfsexplore
void DepthFirstSearch(nodeptr *head,int n,int start)
{
	int i;
	//initialise visited,entry time,exit times such that no vertice is visited first
	clock=0;
	for(i=start;i<n;i++)
	{
		visited[i]=0;
		entry[i]=-1;
		exi[i]=-1;
	}
	//check start index's vertice whether is visited or not
	if(visited[start]==0)
	{
		Dfsexplore(head,start);
	}
	//Then check for all vertices
	for(i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			Dfsexplore(head,i);
		}
	}
}

//creating function for Enqueue
void Enqueue(nodeptr *head,nodeptr *tail,int num)
{
	nodeptr newnode;
	newnode=(struct node *) malloc (sizeof(struct node));
	newnode->item=num;
	newnode->next=NULL;
	//linking newnode at tail of queue
	if(*head==NULL) //enqueuing first vertice
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
	
int main()
{
	int n,m,i,x,y,start;
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
	scanf("%d",&start);
	DepthFirstSearch(head,n,start);
	for(i=0;i<n;i++)
	{
		printf("%d %d\n",entry[i],exi[i]);
	}
	return 0;
}

