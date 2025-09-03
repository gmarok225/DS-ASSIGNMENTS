//addition of sparse
#include <iostream>
using namespace std;
#define MAX 100

// Function to convert sparse -> normal
void sparseToNormal(int sparse[][3], int normal[][MAX]) {
    int rows = sparse[0][0];
    int cols = sparse[0][1];
    int nz   = sparse[0][2];

    // initialize with 0
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            normal[i][j] = 0;

    // fill non-zero values
    for (int k = 1; k <= nz; k++) {
        int r = sparse[k][0];
        int c = sparse[k][1];
        int val = sparse[k][2];
        normal[r][c] = val;
    }
}

// Function to convert normal -> sparse
void normalToSparse(int normal[][MAX], int rows, int cols, int sparse[][3]) {
    int k = 1;
    sparse[0][0] = rows;
    sparse[0][1] = cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (normal[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = normal[i][j];
                k++;
            }
        }
    }
    sparse[0][2] = k - 1;  // store number of non-zero elements
}

// Function to display sparse
void displaySparse(int sparse[][3]) {
    int nz = sparse[0][2];
    for (int i = 0; i <= nz; i++) {
        cout << sparse[i][0] << " " << sparse[i][1] << " " << sparse[i][2] << endl;
    }
}

// Function to display normal
void displayNormal(int normal[][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << normal[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int rows, cols;
    cout << "Enter rows and cols of matrix: ";
    cin >> rows >> cols;

    int A[MAX][3], B[MAX][3], C[MAX][3];
    int normalA[MAX][MAX], normalB[MAX][MAX], normalC[MAX][MAX];

    // Input first sparse
    cout << "Enter number of non-zero elements in A: ";
    int nzA; cin >> nzA;
    A[0][0] = rows; A[0][1] = cols; A[0][2] = nzA;
    cout << "Enter row col value for A:\n";
    for (int i = 1; i <= nzA; i++)
        cin >> A[i][0] >> A[i][1] >> A[i][2];

    // Input second sparse
    cout << "Enter number of non-zero elements in B: ";
    int nzB; cin >> nzB;
    B[0][0] = rows; B[0][1] = cols; B[0][2] = nzB;
    cout << "Enter row col value for B:\n";
    for (int i = 1; i <= nzB; i++)
        cin >> B[i][0] >> B[i][1] >> B[i][2];

    // Convert to normal
    sparseToNormal(A, normalA);
    sparseToNormal(B, normalB);

    // Add index-wise
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            normalC[i][j] = normalA[i][j] + normalB[i][j];
        }
    }

    // Convert back to sparse
    normalToSparse(normalC, rows, cols, C);

    // Display
    cout << "\nMatrix A (sparse):\n";
    displaySparse(A);

    cout << "\nMatrix B (sparse):\n";
    displaySparse(B);

    cout << "\nMatrix A (normal):\n";
    displayNormal(normalA, rows, cols);

    cout << "\nMatrix B (normal):\n";
    displayNormal(normalB, rows, cols);

    cout << "\nResultant Matrix (normal):\n";
    displayNormal(normalC, rows, cols);

    cout << "\nResultant Matrix (sparse):\n";
    displaySparse(C);

    return 0;
}

