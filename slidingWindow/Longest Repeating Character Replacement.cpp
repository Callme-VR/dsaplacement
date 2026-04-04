#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        vector<long long> count(26, 0);
        long long l = 0;
        long long maxf = 0;
        long long result = 0;

        for (long long r = 0; r < s.size(); r++)
        {
            count[s[r] - 'A']++;
            maxf = max(maxf, count[s[r] - 'A']);

            while ((r - l + 1) - maxf > k)
            {
                count[s[l] - 'A']--;
                l++;
            }
            result = max(result, r - l + 1);
        }
        return result;
    }
};
