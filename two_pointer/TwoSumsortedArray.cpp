#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, target;
        cin >> n;

        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];

        cin >> target;

        int i = 0, j = n - 1;
        bool found = false;

        while (i < j) {
            int sum = nums[i] + nums[j];

            if (sum > target) j--;
            else if (sum < target) i++;
            else {
                cout << i + 1 << " " << j + 1 << endl; // 1-based index
                found = true;
                break;
            }
        }

        if (!found) cout << "No solution\n";
    }

    return 0;
}