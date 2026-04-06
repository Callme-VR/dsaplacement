
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        long long start = 0;
        long long current_sum = 0;
        long long minLength = LLONG_MAX;

        for (long long end = 0; end < nums.size(); ++end)
        {
            current_sum += nums[end];

            while (current_sum >= target)
            {
                minLength = min(minLength, end - start + 1);
                current_sum -= nums[start];
                start++;
            }
        }
        return (minLength == LLONG_MAX) ? 0 : minLength;
    }
};