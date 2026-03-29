#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int N = word1.size(), M = word2.size();
        string StoringList;
        int i = 0, j = 0;

        while (i < N || j < M) {
            if (i < N) StoringList += word1[i++];
            if (j < M) StoringList += word2[j++];
        }
        return StoringList;
    }
};

int main() {
    Solution obj;

    string word1, word2;

    cout << "Enter first string: ";
    cin >> word1;

    cout << "Enter second string: ";
    cin >> word2;

    string result = obj.mergeAlternately(word1, word2);

    cout << "Merged String: " << result << endl;

    return 0;
}