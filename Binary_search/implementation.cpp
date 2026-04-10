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
            else if (arr[midElement] > target)
            {
                high = midElement - 1;
            }
            else
            {
                low = midElement + 1;
            }
        }
        return -1;
    };
};

int main()
{
    Solution s;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 5;
    int result = s.binarySearch(arr, target);
    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found in the array." << endl;
    }
    return 0;
}