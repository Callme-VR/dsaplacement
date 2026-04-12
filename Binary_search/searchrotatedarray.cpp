#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;                      // Start index
        int high = nums.size() - 1;       // End index

        // Binary Search loop
        while (low <= high) {
            int mid = low + (high - low) / 2;  // Middle index

            // Case 1: Target found
            if (nums[mid] == target)
                return mid;

            // Case 2: Left half is sorted
            if (nums[low] <= nums[mid]) {

                // Check if target lies in left sorted half
                if (target >= nums[low] && target < nums[mid]) {
                    high = mid - 1;  // Move to left side
                } else {
                    low = mid + 1;   // Move to right side
                }
            }
            // Case 3: Right half is sorted
            else {

                // Check if target lies in right sorted half
                if (target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;   // Move to right side
                } else {
                    high = mid - 1;  // Move to left side
                }
            }
        }

        return -1;  // Target not found
    }
};

int main() {
    /*
    ================= INPUT FORMAT =================
    First line  : n (size of array)
    Second line : n integers (rotated sorted array)
    Third line  : target element to search
    =================================================
    */

    int n;
    cin >> n;  // Read size of array

    vector<int> nums(n);
    
    // Read array elements
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cin >> target;  // Read target value

    Solution obj;

    // Call search function
    int result = obj.search(nums, target);

    // Output result
    if (result != -1)
        cout << "Target found at index: " << result << endl;
    else
        cout << "Target not found" << endl;

    return 0;
}