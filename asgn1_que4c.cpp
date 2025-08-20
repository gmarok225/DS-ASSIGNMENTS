#include<stdio.h>
int main() {
    int i,j,m,n;

    printf("Enter m and n for matrix: ");
    scanf("%d %d", &m, &n);

    int arr[m][n],trans[n][m];

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("Enter %d,%d: ", i,j);
            scanf("%d", &arr[i][j]);
        }
    }

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            trans[j][i]=arr[i][j];
        }
    }

    printf("\nTranspose of the matrix:\n");
    for(i=0;i<n;i++){   
        for(j=0;j<m;j++){ 
            printf("%d ", trans[i][j]);
        }
        printf("\n");
    }

    return 0;
}

