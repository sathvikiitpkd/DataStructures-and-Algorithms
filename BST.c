#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//created structure for nodeptr
struct node
{
	int item;
	struct node * left;
	struct node * right;
	struct node * parent;
};
typedef struct node *nodeptr;

nodeptr temp=NULL;
void wrapper1(nodeptr current,int num)
{
	if(current==NULL)
	{
	 printf("No predecessor\n");
	}
	else
	{
	 printf("%d\n",current->item);
	}
}

void wrapper2(nodeptr current,int num)
{
		//check whether num is greater than prev->item or not
           if(current==NULL)
	{
	 printf("No successor\n");
	}
	else
	{
	 printf("%d\n",current->item);
	}
	
}

void wrapper(nodeptr temp)
{
	if(temp==NULL)
	{
		printf("Not Found\n");
	}
	else
	{
		printf("Found\n");
	}
}

//created function for insert
nodeptr insert(nodeptr root, int key)
{  
	if (root == NULL)
	{
	   nodeptr temp = (nodeptr)malloc(sizeof(struct node));
	   if(temp==NULL)
	   {
	     printf("Insert Fail\n");
	   }
	   temp->item = key;
	   temp->left =NULL;
	   temp->right = NULL;
	   temp->parent=NULL;
	   return temp;
	}

	if (key <= root->item)
	{   
	     nodeptr tempptr=NULL;
	     tempptr = insert(root->left, key);
	     tempptr->parent=root;
                 root->left=tempptr;
	     return root;
    	}		
	else if (key > root->item)
	{
	    nodeptr tempptr=NULL;
	    tempptr = insert(root->right, key);
	    tempptr->parent=root;
	    root->right=tempptr;
	    return root;
    	}
	return root;
}

//function to search an element in BST and returning nodeptr of that position
nodeptr search(nodeptr root,int x)
{

	if(root ==NULL || x== root->item)
	{
		return root;
	}
	//call recursively till root->right and root->left becomes null
	//It is similar to insert function,but here just search is enough

	else if(x < (root->item))
	{
		root=root->left;
		search(root,x);
	}
	
	else if(x > (root->item))
	{
		root=root->right;
		search(root,x);
	}
	
}
	
//function for finding predecessor		
nodeptr Predecessor(nodeptr p,int num)
{
	nodeptr current,prev;
	//if num is not present in BST
	//general case 
	 if(p->left !=NULL)
	{
		current=p->left;
		if(current!=NULL)
		{
		while(current->right !=NULL)
		{
			current=current->right;
		}
		return current;
		}
	}
	//special case if num doesnot has left children 
	//here we need to traverse back i.e via parental tranversing
	else
	{
		current=p;
		prev=current->parent;
		while(prev !=NULL && prev->left==current)
		{
			current=prev;
			prev=current->parent;
		}
		return prev;
	}
}

//function for finding successor
nodeptr successor(nodeptr p,int num)
{
	nodeptr current,temp,prev;
	//if num is not present in BST
	if(p->right !=NULL)
	{
		current=p->right;
		if(current!=NULL)
		{
		while(current->left !=NULL)
		{
			current=current->left;
		}
		return current;
		}
	}
	//special case if num doesnot has right children 
	//here we need to traverse back i.e via parental tranversing
	else
	{
		current=p;
		prev=current->parent;
		while(prev !=NULL && current==prev->right )
		{
			current=prev;
			prev=current->parent;
		}
		return prev;
	}
}

//function for inorder traversal
void inorder(nodeptr root)	
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\n",root->item);
		inorder(root->right);
	}
	else
	{
		return;
	}
}

//function for preorder traversal
void preorder(nodeptr root)	
{
	if(root!=NULL)
	{
		printf("%d\n",root->item);
		preorder(root->left);
		preorder(root->right);
	}
	else
	{
		return;
	}
}

//function for postorder traversal
void postorder(nodeptr root)	
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\n",root->item);
	}
	else
	{
		return;
	}
}

int main()
{
	int i,num,n;
	nodeptr root=NULL,ret,temp1,temp2,searc;
	int answer;
	while(1)
	{
		//depending on input function is menu driven
		scanf("%d",&n);
		if(n==1)
		{
			scanf("%d",&num);
			root=insert(root,num);
		}
		if(n==2)
		{
			scanf("%d",&num);
			search(root,num);
			wrapper(search(root,num));
		}
		if(n==3)
		{
			inorder(root);
		}
		if(n==4)
		{
			preorder(root);
		}
		if(n==5)
		{
			postorder(root);
		}
		if(n==6)
		{
			scanf("%d\n",&num);
			searc=search(root,num);
			if(searc==NULL)
			{			
				printf("Invalid Input\n");
			}
			else
			{
				temp1=Predecessor(searc,num);
			            wrapper1(temp1,num);
				
			}	
		}
		if(n==7)
		{
			scanf("%d\n",&num);
			searc=search(root,num);
			if(searc==NULL)
			{			
				printf("Invalid Input\n");
			}
			else
			{
				temp2=successor(searc,num);
				if(searc != NULL)
				{
					wrapper2(temp2,num);
				}
			}	
		}
		if(n==8)
		{
			return 0;
		}
	}
}

