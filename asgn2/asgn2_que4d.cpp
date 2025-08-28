#include <iostream>
#include <string>
#include <algorithm>  
using namespace std;

int main() {
    string arr[] = {"sky", "cloud", "moon", "stars", "rain"};
    int n = 5;

    sort(arr, arr + n);  

    cout << "Sorted strings: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;

    return 0;
}

