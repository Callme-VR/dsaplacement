#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;

    void push(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        int answer = s1.top();
        s1.pop();
        return answer;
    }

    int peek() {
        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }
};

int main() {
    MyQueue q;

    q.push(1);
    q.push(2);

    cout << "Peek: " << q.peek() << endl; // 1
    cout << "Pop: " << q.pop() << endl;   // 1
    cout << "Empty: " << q.empty() << endl; // false

    return 0;
}