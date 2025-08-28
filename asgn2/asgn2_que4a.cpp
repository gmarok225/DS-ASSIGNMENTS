#include <iostream>
#include <cstring>  // for strcat
using namespace std;

int main() {
    char s1[20] = "hello "; // extra space for concatenation
    char s2[] = "world";
    strcat(s1, s2);
    cout << "new string is " << s1;
    return 0;
}

