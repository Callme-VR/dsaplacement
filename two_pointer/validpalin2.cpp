#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindromeRange(string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                // Try removing one character (left OR right)
                return isPalindromeRange(s, left + 1, right) ||
                       isPalindromeRange(s, left, right - 1);
            }
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    Solution obj;

    string input;
    cout << "Enter string: ";
    cin >> input;

    if (obj.validPalindrome(input))
        cout << "True ✅" << endl;
    else
        cout << "False ❌" << endl;

    return 0;
}