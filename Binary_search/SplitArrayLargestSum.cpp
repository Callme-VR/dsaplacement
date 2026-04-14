#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        // The smallest possible 'largest sum' is the maximum element in the array
        int low = *max_element(nums.begin(), nums.end());
        // The largest possible 'largest sum' is the sum of the entire array
        int high = accumulate(nums.begin(), nums.end(), 0);

        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canSplit(nums, k, mid)) {
                result = mid;
                high = mid - 1; // Try to find a smaller valid maximum
            } else {
                low = mid + 1;  // Need a larger limit to fit within k subarrays
            }
        }
        return result;
    }

private:
    bool canSplit(const vector<int>& nums, int k, int largest) {
        int subarrayCount = 1;
        int currentSum = 0;

        for (int num : nums) {
            if (currentSum + num > largest) {
                // If adding this number exceeds the limit, start a new subarray
                subarrayCount++;
                currentSum = num;
                // If we need more than k subarrays, this 'largest' limit is too small
                if (subarrayCount > k) return false;
            } else {
                currentSum += num;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    int n, k;

    cout << "Enter number of elements in array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter k (number of subarrays): ";
    cin >> k;

    int result = sol.splitArray(nums, k);
    cout << "\nThe minimized largest sum is: " << result << endl;

    return 0;
}