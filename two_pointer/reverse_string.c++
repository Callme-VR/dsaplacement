#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int firstindex = 0, lastindex = s.size() - 1;
        while (firstindex < lastindex)
        {
            swap(s[firstindex], s[lastindex]);
            firstindex++;
            lastindex--;
        }
    }
};

int main()
{
    Solution obj;

    // -------- Test Case 1 --------
    vector<char> s1 = {'h', 'e', 'l', 'l', 'o'};
    obj.reverseString(s1);

    cout << "Reversed String 1: ";
    for (char c : s1)
        cout << c;
    cout << endl;

    // -------- Test Case 2 --------
    vector<char> s2 = {'H', 'a', 'c', 'k', 'e', 'r'};
    obj.reverseString(s2);

    cout << "Reversed String 2: ";
    for (char c : s2)
        cout << c;
    cout << endl;

    // -------- Test Case 3 --------
    vector<char> s3 = {'A'};
    obj.reverseString(s3);

    cout << "Reversed String 3: ";
    for (char c : s3)
        cout << c;
    cout << endl;

    return 0;
}