#include<iostream>
using namespace std;

int main(){
    int i, j, row, col, rsum, csum;
    cout << "Enter number of rows: ";
    cin >> row;
    cout << "Enter number of columns: ";
    cin >> col;
    int arr[50][50];

    cout << "Enter elements of array:\n";
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            cout << "Element (" << i << "," << j << "): ";
            cin >> arr[i][j];
        }
    } 

    cout << "Matrix:\n";
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Row sums:\n";
    for(i=0;i<row;i++){
        rsum=0;
        for(j=0;j<col;j++){
            rsum += arr[i][j];
        }
        cout << "Row " << i + 1 << " sum = " << rsum << endl;
    }

    cout << "\nColumn sums:\n";
    for(j=0;j<col;j++){
        csum=0;
        for(i=0;i<row;i++){
            csum += arr[i][j];
        }
        cout << "Column " << j + 1 << " sum = " << csum << endl;
    }
    return 0;
}

