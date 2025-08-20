#include<stdio.h>
int main(){
	int i,n;
	printf("Enter a digit n: ");
	scanf("%d",&n);
	int arr[n],brr[n];
	for(i=0;i<n;i++) {
	printf("Enter %d element: ",i+1);
	scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++){
    	brr[i]=arr[n-1-i];
	}
	for(i=0;i<n;i++){
		printf("%d ",brr[i]);
	}
	return 0;
}
