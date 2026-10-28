#include <bits/stdc++.h>
using namespace std;

//bf approach is 2-n check kro

//opt approach ye hai ki n or n/i check kro agr n or n/i distinct hai toh n/i ko bhi add kr
void allDivisorsOpt(int num , vector<int>&arr){
    for (int i = 0; i*i< num; i++) {
      if(num%i==0){
        arr.push_back(i);
        if(num!=(num/i))arr.push_back(num/i);
      }
    }
}

int main() {
    
    return 0;
}