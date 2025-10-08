/*
//nearest smaller element

#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int A[100];      // Array to store input elements (assuming n <= 100)
    int result[100]; // Array to store nearest smaller elements
    stack<int> st;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }



    // Find nearest smaller element for each element
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= A[i]) {
            st.pop();
        }

        if (st.empty()) {
            result[i] = -1;
        } else {
            result[i] = st.top();
        }

        st.push(A[i]);
    }

    cout << "Nearest smaller elements: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}




//getMin() 

#include <iostream>
#include <stack>
using namespace std;

stack<long long> st;   // to handle encoded values safely
long long minElement;

void push(long long x) {
    if (st.empty()) {
        st.push(x);
        minElement = x;
    } else if (x >= minElement) {
        st.push(x);
    } else {
        // store encoded value
        st.push(2*x - minElement);
        minElement = x;
    }
}

void pop() {
    if (st.empty()) {
        cout << "Stack Underflow\n";
        return;
    }

    long long topVal = st.top();
    st.pop();

    if (topVal < minElement) {
        // encoded value found
        minElement = 2*minElement - topVal;
    }
}

long long top() {
    if (st.empty()) {
        cout << "Stack is empty\n";
        return -1;
    }

    long long topVal = st.top();
    if (topVal >= minElement)
        return topVal;
    else
        return minElement;
}

long long getMin() {
    if (st.empty()) {
        cout << "Stack is empty\n";
        return -1;
    }
    return minElement;
}

int main() {
    int n;
    cout << "Enter number of elements to push: ";
    cin >> n;
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        push(x);
        cout << "Pushed " << x << ", Current Min: " << getMin() << endl;
    }
    cout << "\nPopping elements...\n";
    while (!st.empty()) {
        cout << "Top: " << top() << ", Min: " << getMin() << endl;
        pop();
    }
    return 0;
}





//next greater element

#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n], ans[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) st.pop();
        ans[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }

    cout << "Next Greater Elements: ";
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}





//daily temperatures

#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    int temp[n], ans[n];
    cout << "Enter temperatures: ";
    for (int i = 0; i < n; i++) cin >> temp[i];

    stack<int> st;  // store indices

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && temp[st.top()] <= temp[i])
            st.pop();

        ans[i] = st.empty() ? 0 : st.top() - i;
        st.push(i);
    }

    cout << "Answer array: ";
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}
*/











