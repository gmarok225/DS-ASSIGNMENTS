#include <iostream>
#include <string>
using namespace std;

// helper function to check if x is substring of y
bool isSubstring(const string& x, const string& y) {
    return y.find(x) != string::npos;
}

bool canSplit(string s) {
    int n = s.size();
    // try all split points
    for (int i = 1; i < n - 1; i++) {          // first cut
        for (int j = i + 1; j < n; j++) {      // second cut
            string A = s.substr(0, i);
            string B = s.substr(i, j - i);
            string C = s.substr(j);

            // check all possibilities
            if ((isSubstring(A, B) && isSubstring(A, C)) ||
                (isSubstring(B, A) && isSubstring(B, C)) ||
                (isSubstring(C, A) && isSubstring(C, B))) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    if (canSplit(s))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}

