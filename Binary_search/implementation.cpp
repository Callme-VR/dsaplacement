#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int binarySearch(vector<int> arr, int target)
    {
        int low = 0;
        int high = arr.size() - 1;
        while (low <= high)
        {
            int midElement = high - (high - low) / 2;
            if (arr[midElement] == target)
            {
                return midElement;
            }
            else if (arr[midElement > target])
            {
                high = midElement - 1;
            }
            else
            {
                low = midElement + 1;
            }
            return -1;
        }
    };
};