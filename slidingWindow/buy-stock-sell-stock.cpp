#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;  // number of test cases

    while (t--) {
        int n;
        cin >> n;

        vector<int> prices(n);
        for (int i = 0; i < n; i++) {
            cin >> prices[i];
        }

        long long minprofit = LLONG_MAX;
        long long maxprofit = 0;

        for (int price : prices) {
            if (price < minprofit) {
                minprofit = price;
            } else {
                long long profit = price - minprofit;
                maxprofit = max(maxprofit, profit);
            }
        }

        cout << maxprofit << "\n";
    }

    return 0;
}