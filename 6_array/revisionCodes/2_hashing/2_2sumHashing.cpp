#include <bits/stdc++.h>
using namespace std;

//returning pairs which are equal to that target
// we will will using prefix sum technique , we will store elements , and check whether for currentelemnt suxh
//elemnt exist to mKE sum equal to targt

pair<int , int> twosum(vector<int>&arr , int target , int n){
    unordered_map< int , int>mpp;

    for (int i = 0; i < n; i++) {
        int diff= target-arr[i];
        if(mpp.find(diff)!=mpp.end()){
            return {arr[i] , diff};
        }
      mpp[arr[i]]=i;
    }

    return {-1 , -1};
}



int main() {
    
    return 0;
}