#include <iostream>
using namespace std;
#define MAX 100

int main() {
    int rows, cols;
    int mat[20][20];

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    // Input matrix
    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }

    // Convert to sparse matrix (3-tuple form)
    int sparse[MAX][3];
    int k = 1; // index for non-zero entries

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                sparse[k][0] = i;      // row index
                sparse[k][1] = j;      // col index
                sparse[k][2] = mat[i][j]; // value
                k++;
            }
        }
    }

    // Store header
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = k - 1; // number of non-zero

    cout << "\nSparse Matrix (3-tuple form):\n";
    for (int i = 0; i < k; i++) {
        cout << sparse[i][0] << " " << sparse[i][1] << " " << sparse[i][2] << endl;
    }

    // Transpose
    int trans[MAX][3];
    trans[0][0] = cols;
    trans[0][1] = rows;
    trans[0][2] = sparse[0][2];

    int z = 1;
    for (int i = 0; i < cols; i++) {          // for each column in original
        for (int j = 1; j <= sparse[0][2]; j++) { // check all non-zero
            if (sparse[j][1] == i) {          // if element is in this column
                trans[z][0] = sparse[j][1];   // row = old col+
                trans[z][1] = sparse[j][0];   // col = old row
                trans[z][2] = sparse[j][2];   // value
                z++;
            }
        }
    }

    cout << "\nTranspose in Sparse Form:\n";
    for (int i = 0; i < z; i++) {
        cout << trans[i][0] << " " << trans[i][1] << " " << trans[i][2] << endl;
    }

    return 0;
}

