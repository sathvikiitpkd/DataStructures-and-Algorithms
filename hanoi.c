/*Recursive C program to implement the Tower of Hanoi game. The Poles are labelled as 0, 1 and 2 and the disks are labelled from 1 to n

in the increasing order of their diameters.

Input has a single line with the number of disks. The ith
line of the output shows the ith movement made in the game. */

#include <stdio.h>
//Function for moving n discs from source to target using interim as helper rod without disturbing the rules of hanoi game
void Tower( int n, int source, int target, int interim)
{	
	if(n<1)//not valid case
	{
		 return;
	}
	if(n==1)//base case
	{
	  	printf("Move Disk %d from Pole %d to Pole %d\n",n,source,target);
	}
	else
	{
		//call recursively till function hits base case
		//move (n-1)discs from source to helper rod
		Tower(n-1,source,interim,target);
		printf("Move Disk %d from Pole %d to Pole %d\n",n,source,target);
		//move largest(n'th) disc from source to target  
		Tower(n-1,interim,target,source);
		return;
	}
}

int main()
{
	//declare and read n from user
	int n;
	scanf("%d",&n);
	//call function Tower
	Tower(n,0,2,1);
	return 0;
}
	
