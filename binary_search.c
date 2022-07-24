#include <stdio.h>
//created function Depth to find recursive depth 
int Depth(int *arr,int left,int right,int item,int count)
{
//arr is the starting addressof array to search for
//item is to be search between index left and right
//count is defined as recursive depth
	int mid;
	//if left is right then it will return count and it is our base case
	if(left==right)//array with only one element
	{		
		return (count);	
	}
	else
	{	
		mid=(left+right)/2;
		//if item = arr[mid] and return count 
		if(item==arr[mid])
		{
			return(count);
		}
		//else if item <arr[mid] and mid is greater than left
		else if(item <arr[mid] && (left<mid))
		{
			//increment count
			count++;
			//call recursive according 
			return(Depth(arr,left,mid-1,item,count));
		}
		else if((item >arr[mid]) && (mid<right))
		{
			count++;
			//call recursive according 
			return(Depth(arr,mid+1,right,item,count));
		}
		else
		{
			return (count);
		}
	}
}
		
int binarySearch(int *arr,int left,int right,int item){
//arr is the starting addressof array to search for
//item is to be search between index left and right
//left is starting index and right is ending index to search for item
	int mid;
	if(left==right)//Base condition
	{		
		if(arr[left]==item)
		{
			return (left);
		}
		else
		{
			return (-1);
		}
	}
	else
	{	mid=(left+right)/2;
		if(item==arr[mid])
		{
			return(mid);
		}
		else if(item <arr[mid] && (left<mid))
		{
		//call recursive according i.e if item<arr[mid],then search the item from index left to mid-1
			return(binarySearch(arr,left,mid-1,item));
		}
		else if((item >arr[mid]) && (mid<right))
		{
		//call recursive according i.e if item>arr[mid],then search the item from index mid+1 to right
			return(binarySearch(arr,mid+1,right,item));
		}
		else
		{
			return (-1);
		}
	}
									}
		
int main()
{
	int answera,answerb,depth;
	int x,i,n;
	//read n,k,arr[n] from the user
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);}
	scanf("%d",&x);
	//call function binarysearch
	answera=binarySearch(arr,0,n-1,x);
	//call function Depth
	answerb=Depth(arr,0,n-1,x,1);
	//print answera,answerb
	printf("%d\n",answerb);	
	printf("%d\n",answera);
	return 0;
}
