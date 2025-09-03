#include <iostream>
#include <cstring> 
using namespace std;

int main() {
    char s1[20] = "hello ";
    char s2[] = "world";
    strcat(s1, s2);
    cout << "new string is " << s1;
    return 0;
}

