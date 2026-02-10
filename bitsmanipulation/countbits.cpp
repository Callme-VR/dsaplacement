#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> countBits(int n){
        vector<int> ans(n+1, 0);
        for(int i = 1; i <= n; i++){
            // Brian Kernighan's algorithm: i & (i-1) removes the rightmost set bit
            ans[i] = ans[i & (i-1)] + 1;
        }
        return ans;
    }
};

int main(){
    Solution s;
    int n = 6;
    vector<int> res = s.countBits(n);
    cout << "Number of 1-bits for numbers 0 to " << n << ": ";
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    return 0;
}