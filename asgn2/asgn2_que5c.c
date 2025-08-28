//triangular matrix
#include<stdio.h>
#define MAX 4 
int main() {
int i,j,k=0, size = (MAX*(MAX+1))/2, a[size]; //non zero elements
printf("\nEnter elements (row major):\n"); 
for(i = 0; i < size; i++) 
scanf("%d",&a[i]); 
printf("\nThe upper triangular matrix is...\n");
for(i = 0; i < MAX; i++) { //4x4 matrix
 for(j = 0; j < MAX; j++) {
  if(i <= j) {
   printf("%d ", a[k]); k++; // elements are stored in linear array so no loop
   } 
   else 
   printf("0 "); 
   } 
    printf("\n"); // after each j loop proceed to next line
	} 
k = 0; 
printf("\nThe lower triangular matrix is...\n");
for(i = 0; i < MAX; i++) 
 { for(j = 0; j < MAX; j++)  //4x4 matrix
 { if(i >= j) 
       { printf("%d ", a[k]); k++; } 
 else 
 printf("0 "); } 
 printf("\n"); } 
 return 0; }

