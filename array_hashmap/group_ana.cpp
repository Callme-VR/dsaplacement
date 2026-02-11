#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;

        for (const auto& s : strs) {
            vector<int> count(26, 0);

            for (char c : s) {
                count[c - 'a']++;
            }

            // build unique key from character counts
            string key = to_string(count[0]);
            for (int i = 1; i < 26; i++) {
                key += "," + to_string(count[i]);
            }

            res[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& p : res) {
            result.push_back(p.second);
        }

        return result;
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);
    cout << "Enter strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    vector<vector<string>> ans = sol.groupAnagrams(strs);

    cout << "\nGrouped Anagrams:\n";
    for (auto& group : ans) {
        cout << "[ ";
        for (auto& word : group) {
            cout << word << " ";
        }
        cout << "]\n";
    }

    return 0;
}
