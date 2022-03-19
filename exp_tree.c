#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// creating node for tree
struct node
{
    char item;
    struct node *left;
    struct node *right;
};
typedef struct node* nodeptr;

// node for stack which can store address of tree node
struct stack
{
    nodeptr item;
    struct stack *next;
};
typedef struct stack Stack;

//function for pushing into stack
Stack *push(Stack *node, nodeptr item)
{
    Stack *newnode = (Stack *)malloc(sizeof(Stack));
    if (newnode == NULL) //checking main stack is full or not
    {
        printf("Stack is FULL\n");
        return node;
    }
    newnode->item = item;
    newnode->next = node;
    return newnode;
}

//function for poping top element of stack
Stack *pop(Stack *node)
{
    Stack *head = node;
    node = node->next;
    free(head); //free space
    return node;
}

//Function to show top element of the stack 
nodeptr top(Stack *root)
{
    return root->item;
}

//function for inorder traversal
void inorder(nodeptr head)
{
    if (head  == NULL) //base condition
        return;

    //for parthesis before head->left
    if (head ->left != NULL && head ->right != NULL)
    {
        printf("(");
    }
    inorder(head->left);
    printf("%c", head->item);
    inorder(head->right);
    //parthensis after head=>right
    if (head ->left != NULL && head ->right != NULL)
    {
        printf(")");
    }
}

//function for preorder transversal
void preorder(nodeptr head)
{
    if (head  == NULL)
        return;

    printf("%c", head->item);
    preorder(head->left);
    preorder(head->right);
}

//function for making Expression tree 
void Tree(char str[])
{
	Stack *root = NULL; 
    	nodeptr head  = NULL;  
	int i=0;
    
    while( i < strlen(str))
    {
        char c = str[i];
        i++;
        // if c is operand then we need to create newnode and push to existing stack
        if (c >= 97 && c <= 122)
        {
            nodeptr newnode = (nodeptr)malloc(sizeof(struct node));
            newnode->left = NULL;
            newnode->right = NULL;
            newnode->item = c;
            root = push(root, newnode);
        }
        //On reading an operator 'op', pop the top two elements from the stack. (If we are not able to do this, the tree was invalid and we can exit with an error.)  Create a new node whose opertor is 'op'. Push the new tree into the stack and continue.
        else
        {
            nodeptr newnode = (nodeptr)malloc(sizeof(struct node));

            if (root == NULL) //check whether it is valid 
            {
                printf("Error\n");
                exit(1);
            }
            newnode->item = c;
            newnode->right = top(root);
            root = pop(root);
            if (root == NULL) //check whether it is valid 
            {
                printf("Error\n");
                exit(1);
            }
            newnode->left = top(root);
            root = pop(root);
            root = push(root, newnode);
        }
    }

    /* creating head  for the tree */
    head  = top(root);
    inorder(head); //result 1
    printf("\n");
    preorder(head); //result 2
}

int main()
{
    char str[500];
    gets(str);
    Tree(str);
    return 0;
}
