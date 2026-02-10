#include<bits/stdc++.h>
using namespace std;

int sum(int a,int b){
     while(b!=0){
          int carry=(a&b)<<1;
          // update the a without carry
          a=a^b;
          // update the b with carry 
          b=carry;
     }
     return a;
}
int main(){
     int a=6,b=3;
     cout<<sum(a,b);
     return 0;
}