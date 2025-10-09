#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter string: ";
    getline(cin, str);

    int freq[256] = {0};   // frequency of characters
    queue<char> q;

    cout << "Output: ";
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if (ch == ' ') continue; 

        freq[(unsigned char)ch]++;
        q.push(ch);

        // remove all characters from front that are repeating
        while (!q.empty() && freq[(unsigned char)q.front()] > 1) {
            q.pop();
        }

        if (q.empty())
            cout << "-1 ";
        else
            cout << q.front() << " ";
    }

    cout << endl;
    return 0;
}


