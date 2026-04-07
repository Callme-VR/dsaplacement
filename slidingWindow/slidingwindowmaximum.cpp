#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cin >> k;

    deque<int> store;
    vector<int> result;

    for (int i = 0; i < n; i++)
    {
        // remove indices out of current window
        if (!store.empty() && store.front() == i - k)
        {
            store.pop_front();
        }

        // remove smaller elements from back
        while (!store.empty() && nums[store.back()] < nums[i])
        {
            store.pop_back();
        }

        // push current index
        store.push_back(i);

        // store answer when window is valid
        if (i >= k - 1)
        {
            result.push_back(nums[store.front()]);
        }
    }

    // print output
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}