#include<stdio.h>
int main(){
    int arr[20],n=0,i,element,position,search,found,choice;

    do {
        printf("\nMENU: \n");
        printf("1.CREATE\n");
        printf("2.DISPLAY\n");
        printf("3.INSERT\n");
        printf("4.DELETE\n");
        printf("5.LINEAR SEARCH\n");
        printf("6.EXIT\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                printf("Enter no. of elements: ");
                scanf("%d",&n);
                for(i=0;i<n;i++){
                    printf("Enter %d element: ",i+1);
                    scanf("%d",&arr[i]);
                }
                break;

            case 2:
                if(n==0){
                    printf("Array is empty\n");
                }
                else{
                    printf("Array elements are: ");
                    for(i=0;i<n;i++){
                        printf("%d ",arr[i]);
                    }
                }
                break;

            case 3:
                printf("Enter the element you want to add: ");
                scanf("%d",&element);
                printf("Enter the position: ");
                scanf("%d",&position);
                if(position<1 || position>n+1){
                    printf("Invalid position\n");
                }
                else{
                    for(i=n;i>=position;i--){
                        arr[i]=arr[i-1];
                    }
                    arr[position-1]=element;
                    n++;
                    printf("Element inserted successfully\n");
                }
                break;

            case 4:
                if(n==0){
                    printf("Array is empty\n");
                }
                else{
                    printf("Enter the position to delete: ");
                    scanf("%d",&position);
                    if(position<1 || position>n){
                        printf("Invalid position\n");
                    }
                    else{
                        for(i=position-1;i<n-1;i++){
                            arr[i]=arr[i+1];
                        }
                        n--;
                        printf("Element deleted successfully\n");
                    }
                }
                break;

            case 5:
                printf("Enter element to be searched: ");
                scanf("%d",&search);
                found=0;
                for(i=0;i<n;i++){
                    if(arr[i]==search){
                        printf("At position %d",i+1);
                        found=1;
                        break;
                    }
                }
                if(found==0){
                    printf("Not found");
                }
                break;

            case 6:
                printf("Exiting program..\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice!=6);

    return 0;
}

