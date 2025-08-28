#include<iostream>
using namespace std;
// Function to map (i,j) ? index in 1D array (row-major, 1-based indexing)
int indexLower(int i, int j) {
    return (i * (i - 1)) / 2 + (j - 1);  
    // Formula: i(i-1)/2 + (j-1)
}

int main() {
    int n;
    cout << "Enter size of symmetric matrix (n x n): ";
    cin >> n;

    int size = n * (n + 1) / 2;  // storage needed
    int sym[size];


    cout << "\nEnter elements of symmetric matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {  // only lower triangular including diagonal
            cout << "Enter A[" << i << "][" << j << "]: ";
            int val;
            cin >> val;
            sym[indexLower(i, j)] = val;
        }
    }

    cout << "\nStored 1D array representation:\n";
    for (int k = 0; k < size; k++)
        cout << sym[k] << " ";
    cout << endl;

    cout << "\nReconstructed full symmetric matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= j)
                cout << sym[indexLower(i, j)] << " ";
            else
                cout << sym[indexLower(j, i)] << " "; // mirror element
        }
        cout << endl;
    }

    return 0;
}

