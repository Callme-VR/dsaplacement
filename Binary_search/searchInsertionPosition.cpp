#include <bits/stdc++.h>
using namespace std;

class Solution { // Fixed spelling: Solution
public:
    int insertionposition(vector<int>& nums, int target) { // Added & to pass by reference (faster)
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int midElement = low + (high - low) / 2;

            if (nums[midElement] == target) {
                return midElement; // Found the target, return index
            } 
            else if (nums[midElement] < target) {
                low = midElement + 1; // Move the low pointer (no return)
            } 
            else {
                high = midElement - 1; // Move the high pointer (no return)
            }
        }
        return low; // If not found, 'low' is the correct insertion position
    }
};