#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue size should be even for proper interleaving.\n";
        return;
    }

    stack<int> s;
    int half = n / 2;

    // Step 1: Push first half into stack
    for (int i = 0; i < half; i++) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Enqueue back the stack elements (reverses first half)
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Step 3: Move first half to back of queue
    for (int i = 0; i < half; i++) {
        q.push(q.front());
        q.pop();
    }

    // Step 4: Push first half into stack again
    for (int i = 0; i < half; i++) {
        s.push(q.front());
        q.pop();
    }

    // Step 5: Interleave stack and queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    int n, x;
    cout << "Enter number of elements (even number): ";
    cin >> n;
    if (n % 2 != 0) {
        cout << "Please enter an even number of elements.\n";
        return 0;
    }

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.push(x);
    }

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}

