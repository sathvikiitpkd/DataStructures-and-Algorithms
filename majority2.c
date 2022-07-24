/*C program that takes a positive integer n and an array A of n integers as input and does the following. If there is an element which appears more than n/2 times in the array A, the program prints that element as output. Otherwise, the program prints "No Majority". Make sure the number of comparisons of your program is linear with respect to n and the additional space used is bounded by a constant, independent of the input.*/

#include <stdio.h>

int main(){
	//declare variables
	int n;
	//initialising Freq and cf to zero
	int Freq=0;
	int cf=0;
	//read the size of array from the user
	scanf("%d",&n);
	int A[n],current,i;
	//read the values of array from user
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
}
	
	for(i=0;i<n;i++){
		//checking if Freq=0 set Freq=1 and current to A[i]
		if(Freq==0){
			Freq=1;
			current=A[i];
}
		//else if A[i]=current and increment Freq
		else if(A[i]==current){
			Freq++;
}
		//else decrement Freq
		else{Freq--;}
}
	//counting the no of times repeated by A[k]
	for(i=0;i<n;i++){
		if(A[i]==current){
			cf++;
}}
	//checking whether cf is greater than half of size of array
	if(cf>n/2){
		printf("%d\n",current);
}
	//else printing as No Majority
	else{ printf("No Majority\n");}
	//say everything went fine
	return 0;
}
