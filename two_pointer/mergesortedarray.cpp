#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;          // pointer for nums1
        int j = n - 1;          // pointer for nums2
        int k = m + n - 1;      // position to fill

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        // If nums2 still has elements
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

int main() {
    Solution obj;

    int m, n;

    cout << "Enter m (size of nums1 valid elements): ";
    cin >> m;

    cout << "Enter n (size of nums2): ";
    cin >> n;

    vector<int> nums1(m + n);
    vector<int> nums2(n);

    cout << "Enter elements of nums1 (" << m << " sorted elements): ";
    for (int i = 0; i < m; i++) {
        cin >> nums1[i];
    }

    cout << "Enter elements of nums2 (" << n << " sorted elements): ";
    for (int i = 0; i < n; i++) {
        cin >> nums2[i];
    }

    obj.merge(nums1, m, nums2, n);

    cout << "Merged Array: ";
    for (int x : nums1) {
        cout << x << " ";
    }

    return 0;
}