/*A) Write a function that takes an integer n and an array A of size n as arguments, to find the index of the largest element from A
and exchange the element in that position with the element in the last position. 
The selection sort algorithm is a well known algorithm for sorting. It works by repeatedly calling the function in the step (A). After the first iteration, the largest element will be in the last position. After the second iteration, the second largest element will be in the second last position.  After n−1
iteration, the input array becomes sorted.
B) Write a C program to implement selection sort using this function.*/

#include <stdio.h>
//function for sorting from last element of array
void select(int n,int *A)
{
	//declare and initialise variables
	int max=-100000;
	int k,temp,i;
	//base case
	if(n==1)
	{
		return;
	}
	//loop to find maximum of the elements and noting its index
	for(i=0;i<n;i++)
	{
		if(A[i]>max)
		{	max=A[i];
			k=i;
		}
	}
	//swapping A[k] with A[n-1]
	temp=A[n-1];
	A[n-1]=A[k];
	A[k]=temp;
	//returning select(n-1,A)
	return select(n-1,A);
}
		
int main()
{
	//declare and initialise variables
	int n,i;
	//read value of n from user
	scanf("%d",&n);
	int A[n];
	//read values of A[n] from user
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	// call select function
	select(n,A);
	//print sorted array
	for(i=0;i<n;i++)
	{
		printf("%d\n",A[i]);
	}
	//say everything went well
	return 0;
}
	

