#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    unordered_set<char> st;
    int l = 0;
    int maxLength = 0;

    for (int r = 0; r < s.size(); r++) {
        // remove characters until no duplicate
        while (st.find(s[r]) != st.end()) {
            st.erase(s[l]);
            l++;
        }

        st.insert(s[r]);
        maxLength = max(maxLength, r - l + 1);
    }

    cout << maxLength;

    return 0;
}