
#include <bits/stdc++.h>
using namespace std;


bool partition(vector<int>&nums){
  int totalsum=0;

  for(int num:nums){
    totalsum+=num;
  }

  // then we can check the odd if odd not possible to partition equal

  if(totalsum%2!=0){
    return false;
  }

  // .partition the array aur total sum
  int target=totalsum/2;

  
}





int main() {

    int n;

    // Input size of array
    cin >> n;

    vector<int> nums(n);

    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;

    // Input target sum
    cin >> target;

    // Call subset sum function
    bool answer = subsetSum(nums, target);

    // Print result
    if (answer)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
