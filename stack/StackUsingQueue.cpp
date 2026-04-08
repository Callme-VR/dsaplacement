#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q;

    void push(int x) {
        q.push(x);
        int size = q.size();
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack st;
    int n;
    cin >> n;  // number of operations

    while (n--) {
        string op;
        cin >> op;

        if (op == "push") {
            int x;
            cin >> x;
            st.push(x);
        } 
        else if (op == "pop") {
            cout << st.pop() << endl;
        } 
        else if (op == "top") {
            cout << st.top() << endl;
        } 
        else if (op == "empty") {
            cout << (st.empty() ? "true" : "false") << endl;
        }
    }

    return 0;
}