#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;

        for (int num : st) {

            // Only start if it's the beginning of a sequence
            if (st.find(num - 1) == st.end()) {

                int current = num;
                int length = 1;

                while (st.find(current + 1) != st.end()) {
                    current++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements (space separated): ";

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int ans = sol.longestConsecutive(nums);

    cout << "\nLongest Consecutive Length: " << ans << endl;

    return 0;
}  

// is this code is correct or not and explain me it approaches
// Approach:
// 1. Convert the input vector into an unordered set for O(1) lookups.
// 2. Iterate through each number in the set.
// 3. Check if the number is the start of a sequence (i.e., num - 1 is not in the set).
// 4. If it is, count the length of the consecutive sequence by incrementally checking num + 1, num + 2, etc., until the end of the sequence is reached.
// 5. Update the longest sequence length found so far.
// 6. Return the longest sequence length after iterating through all numbers in the set.
