#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for (int num : nums) {
            if (num == target) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    int n;
    cin >> n; // size of array

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i]; // array elements
    }

    int target;
    cin >> target; // target element

    Solution obj;
    cout << (obj.search(nums, target) ? "true" : "false");

    return 0;
}



// class Solution {
// public:
//     bool search(vector<int>& nums, int target) {
//         int low = 0;
//         int high = nums.size() - 1;

//         while (low <= high) {
//             int mid = low + (high - low) / 2;
//             if (nums[mid] == target) return true;

//             // Handle the case where we can't tell which side is sorted due to duplicates
//             if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
//                 low++;
//                 high--;
//             }
//             // Left side is sorted
//             else if (nums[low] <= nums[mid]) {
//                 if (target >= nums[low] && target < nums[mid]) {
//                     high = mid - 1;
//                 } else {
//                     low = mid + 1;
//                 }
//             }
//             // Right side is sorted
//             else {
//                 if (target > nums[mid] && target <= nums[high]) {
//                     low = mid + 1;
//                 } else {
//                     high = mid - 1;
//                 }
//             }
//         }
//         return false;
//     }
// };