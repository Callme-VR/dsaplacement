#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> resultArray(n);
        vector<int> prefix(n);
        vector<int> suffix(n);

        prefix[0] = 1;
        suffix[n - 1] = 1;

        for (int i = 1; i < n; i++) {
            prefix[i] = nums[i - 1] * prefix[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = nums[i + 1] * suffix[i + 1];
        }

        for (int i = 0; i < n; i++) {
            resultArray[i] = prefix[i] * suffix[i];
        }

        return resultArray;
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    cin.ignore(); // clear newline

    vector<int> nums;
    cout << "Enter elements (comma separated): ";

    string line;
    getline(cin, line);

    stringstream ss(line);
    string temp;

    while (getline(ss, temp, ',')) {
        nums.push_back(stoi(temp));
    }

    vector<int> result = sol.productExceptSelf(nums);

    cout << "\nOutput array:\n";
    for (int x : result) {
        cout << x << " ";
    }
    return 0;
}
