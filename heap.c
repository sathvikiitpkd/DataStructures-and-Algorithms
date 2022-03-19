#include <stdio.h>
#include <limits.h>

//return left child of i
int left(int i)
{
	return 2*i+1;
}

//return right child of i
int right(int i)
{
	return 2*i+2;
}

//return parent of i
int parent(int i)
{
	return (i-1)/2;
}

//function for shiftdown the H[posn] to its actual position
void minheapify(int *H,int posn, int n)
{
	int l,r,small,temp;
	l=left(posn);
	r=right(posn);
	small=posn;
	//checking H[posn] and H[left] if H[posn] is larger then we need to swap it or either the index of left
	if(l<n && H[l] <H[posn])
	{
		small=l;
	}
	//checking H[posn] and H[right] if H[posn] is larger then we need to swap it or either the index of right
	if(r<n && H[r] < H[small])
	{
		small=r;
	}
	//if small is not equal to posn then swap element of index posn and small
	if(small != posn)
	{
		temp=H[posn];
		H[posn]=H[small];
		H[small]=temp;
		minheapify(H,small,n);
	}	
}

//function for building heap
void Build_heap(int *arr,int n)
{
	int i=parent(n);
	//we need to run while loop from parent(n) to 0
	while(i>=0)
	{
		minheapify(arr,i,n);
		i--;
	}
}

//function for shift siftup
void siftup(int *H,int pos)
{
	int temp;
	//if H[parent(pos)] is greater than H[pos] then swap its elements
	while(pos>0 && H[pos] <= H[parent(pos)])
	{
		temp=H[pos];
		H[pos]=H[parent(pos)];
		H[parent(pos)]=temp;
		pos=parent(pos);
	}
	return;
}

//Function for inserting element to existing heap
void Insert(int *H,int x,int *n)
{
	//increament the position,set last position to element to get inserted,Then siftup until it reaches correct posn
	(*n)=(*n) + 1;
	H[(*n)-1]=x;
	siftup(H,*n-1);
}	 

//Function for decreasing key
void Decreasekey(int *H,int posn,int newval)
{
	//if newval is greater than H[pos],we need not do anything
	if(H[posn] <= newval)
	{	
		printf("Operation Fail\n");
		return;
	}
	//else siftup until it reaches correct posn
	else 
	{
		H[posn]=newval;
		siftup(H,posn);
	}
}

//function for removing H[0] without disturbing sematics of heap
int ExtractMin(int *H,int *n) 		
{
	int temp;
	temp=H[0];
	//printf("%d\n",temp);
	H[0]=H[*n-1];
	*n=*n-1;
	minheapify(H,0,*n);
	return temp;
}

//return H[0]
int FindMin(int *H,int n)
{
	if(n>=1)
	{
		return H[0];
	}
}

//print the elements of the array
void Printheap(int *H,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\n",H[i]);
	}
}	
//function to delete element at given index
void delete (int *H, int index, int n)
{	
	int last,temp;
	last=n-1;
	if(last==-1)//H has no element
	{
		printf("Operation Fail\n");
		return;
	}
	    if (index == last) //base
	    {
	        H[last] = INT_MIN;
	        return;
	    };
	    //swap H[index] and H[last]
	    //now set H[last] to int min
	    H[index]=H[last];
	    H[last]= INT_MIN;
	   // remove last element from array
	    last--;
	    minheapify(H, index, last+1);
}
int main()
{
	int n,i,input,num,posn,newval,index,temp;
	scanf("%d",&n);
	int heap[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&heap[i]);
	}
	Build_heap(heap,n);
	
	while(1)
	{
		//depending on input function is menu driven
		scanf("%d",&input);
		if(input==1)
		{
			scanf("%d",&num);
			Insert(heap,num,&n);
		}
		if(input==2)
		{
			scanf("%d",&index);
			//check whether index is lesser than n
			if(n>index)
			{
				delete(heap,index,n);
				n--;
			}
			else
			{
				printf("Operation Fail\n");
			}
		}
		if(input==3)
		{
			temp=ExtractMin(heap,&n);
			printf("%d\n",temp);
			
		}
		if(input==4)
		{
			Printheap(heap,n);
		}
		if(input==5)
		{
			scanf("%d",&posn);
			scanf("%d",&newval);
			//check whether posn is lesser than n
			if(n>posn)
			{
				Decreasekey(heap,posn,newval);
			}
			else
			{
				printf("Operation Fail\n");
			}
		}
		if(input==6)
		{
			//print minimum value of heap
			i=FindMin(heap,n);
			printf("%d\n",i);
		}
		if(input==7)
		{
			return 0;
		}
	}
	return 0;
}
	
