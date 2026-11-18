/*
i. Insert an element to a particular location
*/
#include<stdio.h>
int main(){
 int arr[50],n,ele,i,pos;
 printf("enter no of elements:\n");
 scanf("%d",&n);
 
 for(i=1;i<=n;i++){
 	printf("enter the element %d:",i);
 	scanf("%d",&ele);
 	arr[i]=ele;
 }
 for(i=1;i<=n;i++){
 	//printf("enter the element %d:",i);
 	//scanf("%d",&ele);
 	printf("%d \n",arr[i]);
 } 
 
 printf("enter the position:");
 scanf("%d",&pos);
 printf("enter the element:");
 scanf("%d",&ele);
 for(i=n;i>=pos;i--){//backwards
 	arr[i]=arr[i-1];
 }
 arr[pos]=ele;//for position of ARRAY
 n++;
 
 for(i=1;i<n;i++){
 	//printf("enter the element %d:",i);
 	//scanf("%d",&ele);
 	printf("%d ",arr[i]);
 } 
 
 

 return 0;
 
 
 
 
 }

