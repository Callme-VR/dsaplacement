#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string S) {

        // this varible is used for storing the temporary variable for char string
        string temperary = "";

        // for the convert the alpha numric value to loweer case 

        for (char c : S) {
            if (isalnum(c)) {
                temperary += tolower(c);
            }
        }

                // them compare the string with its reverse and check if they are equal or not

        return equal(temperary.begin(), temperary.end(), temperary.rbegin());
    }
};

int main() {
    Solution obj;

    string input;

    cout << "Enter a string: ";
    getline(cin, input);   // takes full sentence with spaces

    bool result = obj.isPalindrome(input);

    if (result)
        cout << "Palindrome ✅" << endl;
    else
        cout << "Not Palindrome ❌" << endl;

    return 0;
}