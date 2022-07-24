/*Write a C program that takes as input an integer n and an integer array A of length n, and sorts the array in the non-decreasing order using Insertion Sort algorithm. Make sure your program has two functions other than the main function. One function which performs insertion sort and the other for insertion which takes the starting address of an array A and an index i as parameters (assuming A[0,⋯,i−1] is in non-decreasing order) and inserts A[i] into its appropriate position so that A[0,⋯,i] are now in non-decreasing order of the corresponding elements in A, while elements of A after index i are unaffected.*/

#include <stdio.h>
//declare insertion function
void insertion(int*,int);
void insertion_sort (int *arr,int n)
{
	//base case
	if(n==1)
	{
		return;
	}
	//call insertion sort and insertion
	else
	{
		insertion_sort(arr,n-1);
		insertion(arr,n-1);
	}
}

//function for insertion
void insertion(int *arr,int n)
{
	int i,j;
	int last=arr[n];
	//for loop from n-1 to 0
	for(j=n-1;j>=0;j--)
	{
		//if arr[j] is greater than last
		if(arr[j]>last)
		{
			//move all elements 1 position rightwards
				arr[j+1]=arr[j];
			//finally arr[j]=last
			arr[j]=last;
		}
	}
}		
int main()
{	
	//initialise and declare variables
	int n,i;
	scanf("%d",&n);
	int arr[n];
	//read array values
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	//call for function
	insertion_sort(arr,n);
	//print array
	for(i=0;i<n;i++)
	{
		printf("%d\n",arr[i]);
	}
	return 0;
}	  


