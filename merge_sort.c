/*Write a recursive C program to perform a top-down merge sort algorithm to sort a list of n integers given in an array A. You may use additional space proportional to the size of the input array A.*/

#include <stdio.h>
//function for merging 
void merge(int *arr,int left,int mid,int right)
{
	int i,j,k;
	//merge two subarrays of array
	//declare and initialise num1,num2
	int num1=mid-left+1;
	int num2=right-mid;
	//arr1 is from index left to mid
	int arr1[num1];
	//arr2 is from index mid+1 to right
	int arr2[num2];
	//copy data to created sub-arrays from main array
	for(i=0;i<num1;i++)
	{
		arr1[i]=arr[left+i];
	}
	for(j=0;j<num2;j++)		
	{
		arr2[j]=arr[1+mid+j];
	}
	//initialise i,j to 0 and k to left
	i=0;
	j=0,
	k=left;
	//sorting
	while(i<num1 && j<num2)
	{
		if(arr1[i]<=arr2[j])
		{
			arr[k]=arr1[i];
			i++;
		}
		
		else 
		{
			arr[k]=arr2[j];
			j++;
		}
		k++;
	}
	//copying remaining elements of arr1,if elements are remaining 
	while(i<num1)
	{
		arr[k]=arr1[i];
		k++;
		i++;
	}
	//copying remaining elements of arr2,if elements are remaining 
	while(j<num2)
	{
		arr[k]=arr2[j];
		k++;
		j++;
	}
}
//sort function for recursive calls
void sort(int *A,int left,int right)
{
	int mid;
	if(left<right)
	{
		
		mid=(left+right)/2;
		sort(A,left,mid);
		sort(A,mid+1,right);
		merge(A,left,mid,right);//call merge function
	}
} 
int main()
{
	int n,i;
	scanf("%d",&n);
	int A[n];
	//scan the array from user
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	//sort function call
	sort(A,0,n-1);
	//print the array from user
	for(i=0;i<n;i++)
	{
		printf("%d\n",A[i]);
	}
	return 0;
}

