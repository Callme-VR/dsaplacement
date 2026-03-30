#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t; // number of test cases

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        int target;
        cin >> target;

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        for (int i = 0; i < n - 3; i++)
        {

            // skip duplicates for i
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; j++)
            {

                // skip duplicates for j
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int p = j + 1;
                int q = n - 1;

                while (p < q)
                {
                    long long sum = (long long)nums[i] + nums[j] + nums[p] + nums[q];

                    if (sum < target)
                    {
                        p++;
                    }
                    else if (sum > target)
                    {
                        q--;
                    }
                    else
                    {
                        res.push_back({nums[i], nums[j], nums[p], nums[q]});

                        p++;
                        q--;

                        // skip duplicates for p and q
                        while (p < q && nums[p] == nums[p - 1])
                            p++;
                        while (p < q && nums[q] == nums[q + 1])
                            q--;
                    }
                }
            }
        }

        // print result
        if (res.empty())
        {
            cout << "No quadruplets found\n";
        }
        else
        {
            for (auto &quad : res)
            {
                for (auto x : quad)
                    cout << x << " ";
                cout << endl;
            }
        }
    }

    return 0;
}