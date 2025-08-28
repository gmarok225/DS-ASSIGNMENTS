#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter size of square matrix (n x n): ";
    cin>>n;
    int size =3*n-2;
    int tri[size];   
    int k=0;      

    cout<<"Enter elements for Tri-diagonal Matrix:\n";
    // Loop through matrix positions
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || i == j + 1 || i == j - 1) {
                // valid tri-diagonal position
                cout << "Enter A[" << i << "][" << j << "]: ";
                cin >> tri[k++];
            }
        }
    }

    cout << "\nStored 1D array (tri-diagonal form): ";
    for (int i = 0; i < size; i++)
        cout << tri[i] << " ";

    cout << "\n\nReconstructed full matrix:\n";
    k = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || i == j + 1 || i == j - 1)
                cout << tri[k++] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    return 0;
}

