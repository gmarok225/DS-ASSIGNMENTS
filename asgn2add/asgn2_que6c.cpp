#include <iostream>
using namespace std;
#define MAX 100

// Convert sparse -> normal
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

// Convert normal -> sparse
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

// Display sparse
void displaySparse(int sparse[][3]) {
    int nz = sparse[0][2];
    for (int i = 0; i <= nz; i++) {
        cout << sparse[i][0] << " " << sparse[i][1] << " " << sparse[i][2] << endl;
    }
}

// Display normal
void displayNormal(int normal[][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << normal[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int r1, c1, r2, c2;
    cout << "Enter rows and cols of Matrix A: ";
    cin >> r1 >> c1;
    cout << "Enter rows and cols of Matrix B: ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Matrix multiplication not possible (c1 != r2)." << endl;
        return 0;
    }

    int A[MAX][3], B[MAX][3], C[MAX][3];
    int normalA[MAX][MAX], normalB[MAX][MAX], normalC[MAX][MAX];

    // Input first sparse
    cout << "Enter number of non-zero elements in A: ";
    int nzA; cin >> nzA;
    A[0][0] = r1; A[0][1] = c1; A[0][2] = nzA;
    cout << "Enter row col value for A:\n";
    for (int i = 1; i <= nzA; i++)
        cin >> A[i][0] >> A[i][1] >> A[i][2];

    // Input second sparse
    cout << "Enter number of non-zero elements in B: ";
    int nzB; cin >> nzB;
    B[0][0] = r2; B[0][1] = c2; B[0][2] = nzB;
    cout << "Enter row col value for B:\n";
    for (int i = 1; i <= nzB; i++)
        cin >> B[i][0] >> B[i][1] >> B[i][2];

    // Convert to normal
    sparseToNormal(A, normalA);
    sparseToNormal(B, normalB);

    // Initialize C with 0
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            normalC[i][j] = 0;

    // Multiply
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                normalC[i][j] += normalA[i][k] * normalB[k][j];
            }
        }
    }

    // Convert result to sparse
    normalToSparse(normalC, r1, c2, C);

    // Display results
    cout << "\nMatrix A (sparse):\n";
    displaySparse(A);

    cout << "\nMatrix B (sparse):\n";
    displaySparse(B);

    cout << "\nMatrix A (normal):\n";
    displayNormal(normalA, r1, c1);

    cout << "\nMatrix B (normal):\n";
    displayNormal(normalB, r2, c2);

    cout << "\nResultant Matrix (normal):\n";
    displayNormal(normalC, r1, c2);

    cout << "\nResultant Matrix (sparse):\n";
    displaySparse(C);

    return 0;
}

