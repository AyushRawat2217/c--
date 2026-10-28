#include <bits/stdc++.h>
using namespace std;

/* we have to assume that wwe have an array having elements 1 to 9
we are given k ,k is number of elemnts whuch should be insidethe subset
, and n 
n refers to target sum */

//504
void combination3(vector<int>&arr , int index , vector<int>&subsetArray , vector<vector<int>>&resultArr  , int n , int k){
    if(n<0)return;
    if(n==0){
        if(subsetArray.size()==k)resultArr.push_back(subsetArray);
        return;
    }
    subsetArray.push_back(arr[index]);
    combination3(arr , index+1 , subsetArray , resultArr ,  n-arr[index] , k);
    subsetArray.pop_back();
    combination3(arr , index+1 , subsetArray , resultArr ,  n+arr[index] , k);

}

int main() {
    
    return 0;
}