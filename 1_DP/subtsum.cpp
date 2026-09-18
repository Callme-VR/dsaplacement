
#include <bits/stdc++.h>
using namespace std;

bool subsetSum(vector<int>& nums, int target) {

    // dp[sum] = can we make this sum?
    vector<bool> dp(target + 1, false);

    // Sum 0 is always possible by taking no elements
    dp[0] = true;

    // Process every number
    for (int num : nums) {

        // Go backwards so each number is used only once
        for (int sum = target; sum >= num; sum--) {

            // Take num OR don't take num
            dp[sum] = dp[sum] || dp[sum - num];
        }
    }

    // Check whether target sum can be formed
    return dp[target];
}

int main() {

    int n;

    // Input size of array
    cin >> n;

    vector<int> nums(n);

    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;

    // Input target sum
    cin >> target;

    // Call subset sum function
    bool answer = subsetSum(nums, target);

    // Print result
    if (answer)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
