#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.empty() || t.empty())
            return "";

        vector<int> targetcount(128, 0);
        for (char c : t)
            targetcount[c]++;

        int left = 0;
        int right = 0;
        int startIndex = 0;
        int required = t.length();
        int minLen = INT_MAX;

        while (right < s.length())
        {
            if (targetcount[s[right]] > 0)
            {
                required--;
            }
            targetcount[s[right]]--;
            right++;

            // when is valid
            while (required == 0)
            {
                if (right - left < minLen)
                {
                    minLen = right - left;
                    startIndex = left;
                }
                targetcount[s[left]]++;
                if (targetcount[s[left]] > 0)
                {
                    required++;
                }
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};