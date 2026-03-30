#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0, r = 0;

        while (r < nums.size()) {
            nums[l] = nums[r];

            while (r < nums.size() && nums[r] == nums[l]) {
                r++;
            }
            l++;
        }
        return l;
    }
};

int main() {
    int t;
    cin >> t; // number of test cases

    while (t--) {
        int n;
        cin >> n; // size of array

        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        
        Solution obj;
        int k = obj.removeDuplicates(nums);

        // Output the length of unique elements
        cout << k << endl;

        // Output the modified array (only unique elements)
        for (int i = 0; i < k; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }

    return 0;
}