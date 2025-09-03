#include <iostream>
#include <vector>
using namespace std;

void duplicateTwos(vector<int>& arr) {
    int n = arr.size();
    int possibleDups = 0;
    int last = n - 1;

    // Count how many duplications are possible
    for (int i = 0; i <= last - possibleDups; i++) {
        if (arr[i] == 2) {
            // Edge case: last element is 2 and no room to duplicate
            if (i == last - possibleDups) {
                arr[last] = 2;   // put one 2 at the end
                last--;
                break;
            }
            possibleDups++;
        }
    }

    // Start from the last element to be copied
    int i = last - possibleDups;
    for (; i >= 0; i--) {
        if (arr[i] == 2) {
            arr[i + possibleDups] = 2;   // duplicate
            possibleDups--;
            arr[i + possibleDups] = 2;   // write the second copy
        } else {
            arr[i + possibleDups] = arr[i];
        }
    }
}

int main() {
    int temp[] = {1, 2, 3, 4, 5};
    vector<int> arr(temp, temp + 5);

    duplicateTwos(arr);

    cout << "Modified array: ";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

