#include <iostream>
#include <vector>
#include <cstdlib>   // for std::abs
using namespace std;

int countPairs(vector<int>& arr, int k) {
    int n = arr.size();
    int cnt = 0;
    k = std::abs(k);   // ensure non-negative

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (std::abs(arr[i] - arr[j]) == k) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int temp[] = {1, 4, 1, 4, 5};          // fallback array
    vector<int> arr(temp, temp + 5);       // construct vector from array

    int k = 3;
    cout << countPairs(arr, k) << endl;    // should print 4
    return 0;
}

