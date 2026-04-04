#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) return false;

    vector<int> count1(26, 0);
    vector<int> count2(26, 0);

    // count s1
    for (char c : s1) {
        count1[c - 'a']++;
    }

    int k = s1.size();

    // first window
    for (int i = 0; i < k; i++) {
        count2[s2[i] - 'a']++;
    }

    if (count1 == count2) return true;

    // sliding window
    for (int i = k; i < s2.size(); i++) {
        count2[s2[i] - 'a']++;        // add new char
        count2[s2[i - k] - 'a']--;    // remove old char

        if (count1 == count2) return true;
    }

    return false;
}

int main() {
    string s1, s2;
    
    cin >> s1 >> s2;

    if (checkInclusion(s1, s2)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}