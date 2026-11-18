#include<stdio.h>
int main(){
  int a[100],n,i,j,temp,k;
  printf("enter the no of element:");
  scanf("%d",&n);
  if(n==100){
  	printf("invalid size!" );
  	return 0;}
  printf("enter the elements:\n");
  for(i=0;i<n;i++){
  scanf("%d",&a[i]);
  }
   for(i=0;i<n-2;i++){
    for(j=0;i<n-i-2;i++){
    if (a[j]>a[j+1])
    {temp=a[j];
    a[j]=a[j+1];
    a[j+1]=temp;
    }}}
    printf("print sorted array");
    for(i=0;i<n;i++){
    printf("%d",a[i]);}
if a[i]!=a[j]{
	j=j+1
	if a[i]=a[k]{
	k=j
	}
	
}
