#include<bits/stdc++.h>
using namespace std;
class Solution {
     public:
         int hammingWeight(uint32_t N) {
             int setBitCount = 0;
             while(N!=0){
                 N &=(N-1);
                 ++setBitCount;
             }
             return setBitCount;
         }
     };
int main(){
     Solution s;
     uint32_t n=90;
     cout<<s.hammingWeight(n);
     return 0;
}