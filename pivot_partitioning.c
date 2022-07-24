#include <stdio.h>
	
int main()
{
	//declare variables
	int pivot,n,k,j,i,temp;
	int r=0;
	//read n,A[n],k from user
	scanf("%d",&n);
	int A[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	scanf("%d",&k);
	//pivot=A[k]
	pivot=A[k];
	//sort pivot to its correct position 
	for(i=0;i<n;i++)
	{
		if(pivot>A[i])
		{
			r++;
		}
	}
	//swap A[k] and A[r]
	temp=A[k];
	A[k]=A[r];
	A[r]=temp;
	//initialise i to 0 and j to r+1
	i=0;
	j=r+1;
	//run while loop till i<r and j<n
	while(i<r && j<n)
	{
		//run while loop till i<r and A[i]<A[r] and increment i accordingly
		while(i<r && A[i]<A[r])
		{
				i++;
		}
		//run while loop till j<n and A[j]>=A[r] and increment j accordingly
		while(j<n && A[j]>=A[r])
		{
				j++;
		}
		//if i<r and j<n swap A[i] and A[j] and increment i and j accordingly
		if(i<r && j<n)
		{
			temp=A[i];
			A[i]=A[j];
			A[j]=temp;
			i++;
			j++;
		}
	}
	//print array 
	for(i=0;i<n;i++)
	{
		printf("%d\n",A[i]);
	}
	return 0;
}
