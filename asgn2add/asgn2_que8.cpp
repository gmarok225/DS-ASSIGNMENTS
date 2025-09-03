#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter elements of array: ";
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }

    int distinctCount = 0;

    for (int i = 0; i < n; i++) {
        int flag = 0;

        // check if arr[i] appeared before
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                flag = 1;  // found duplicate
                break;
            }
        }

        if (flag == 0) {
            distinctCount++;
        }
    }

    cout << "Total distinct elements: " << distinctCount << endl;
    return 0;
}

