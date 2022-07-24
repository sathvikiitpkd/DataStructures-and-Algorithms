/*Write a C program that takes a positive integer n and an array A of n integers as input and does the following. If there is an element which appears more than n/2 times in the array A, the program prints that element as output. Otherwise, the program prints "No Majority". Make sure the number of comparisons of your program is at most quadratic with respect to n and the additional space used is bounded by a constant, independent of the input.*/

#include <stdio.h>

int main(){
	//declare variables
	int n,f=0,cf=0;
	int i,j;
	//scan for size of array
	scanf("%d",&n);
	//initialise maxf and k to zero
	int A[n],maxf=0,k=0;
	//read the values of array from user
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
}
	//set maxf=maximum of maxf and f and k to i and again after comparing each element to all other elements,we need to make f=0.
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(A[j]==A[i]){
		        	f++;}}
		if(f>maxf){
			maxf=f;
			k=i;}
		f=0;}
	//counting the no of times repeated by A[k]
	for(i=0;i<n;i++){
		if(A[i]==A[k]){
			cf++;
}}
	//checking whether cf is greater than half of size of array
	if(cf>n/2){
		printf("%d\n",A[k]);
}
	//else printing as No Majority
	else{ printf("No Majority\n");}	

	//say everything went fine
	return 0;
}
	   	
