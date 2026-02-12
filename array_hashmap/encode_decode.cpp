#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for (const string& s : strs) {
            res += to_string(s.size()) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;

        while (i < s.size()) {
            int j = i;

            while (s[j] != '#') {
                j++;
            }

            int length = stoi(s.substr(i, j - i));
            i = j + 1;
            j = i + length;

            res.push_back(s.substr(i, length));
            i = j;
        }

        return res;
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs;
    cin.ignore();  // ignore newline after number input

    cout << "Enter the strings:\n";
    for (int i = 0; i < n; i++) {
        string input;
        getline(cin, input);  // allows spaces inside string
        strs.push_back(input);
    }

    // Encode
    string encoded = sol.encode(strs);
    cout << "\nEncoded string:\n" << encoded << endl;

    // Decode
    vector<string> decoded = sol.decode(encoded);

    cout << "\nDecoded strings:\n";
    for (string &s : decoded) {
        cout << s << endl;
    }

    return 0;
}
