#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Method 1: Using sorting
bool areAnagramsSort(string str1, string str2) {
    if (str1.size() != str2.size()) return false;

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    return str1 == str2;
}

// Method 2: Using character frequency
bool areAnagramsCount(const string &str1, const string &str2) {
    if (str1.size() != str2.size()) return false;

    int count[26] = {0};

    for (size_t i = 0; i < str1.size(); i++) {
        count[str1[i] - 'a']++;
        count[str2[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) return false;
    }

    return true;
}

int main() {
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    if (areAnagramsCount(str1, str2))
        cout << "YES - They are Anagrams\n";
    else
        cout << "NO - Not Anagrams\n";

    return 0;
}

