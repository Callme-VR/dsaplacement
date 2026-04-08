#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isvalidparenthesis(string s)
    {
        stack<char> st;
        unordered_map<char, char> closeToOpen = {{')', '('}, {'}', '{'}, {']', '['}};

        for (char c : s)
        {
            if (closeToOpen.count(c))
            {
                if (!st.empty() && st.top() == closeToOpen[c])
                {
                    st.top();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                st.push(c);
            }
        }
        return st.empty();
    }
};


// time_complexity of this solution is O(n), where n is the length of the input string s. This is because we need to iterate through each character in the string once.
// space complexity of this solution is O(n) in the worst case, when all characters in the string are opening parentheses. In this case, we would push all characters onto the stack. However, in general, the space complexity can be considered O(1) if we assume that the number of different types of parentheses is constant (i.e., only '()', '{}', and '[]').