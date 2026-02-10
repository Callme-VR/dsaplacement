#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];

            if (hashmap.count(diff)) {
                return {hashmap[diff], i};
            }

            hashmap[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cin.ignore(); // clear buffer

    string input;
    cout << "Enter elements (comma separated): ";
    getline(cin, input);

    vector<int> nums;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, ',')) {
        nums.push_back(stoi(temp));
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    Solution obj;
    vector<int> result = obj.twoSum(nums, target);

    if (result.empty()) {
        cout << "No two sum solution found";
    } else {
        cout << "Indices: " << result[0] << " " << result[1];
    }   

    return 0;
}
