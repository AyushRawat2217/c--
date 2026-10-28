#include <bits/stdc++.h>
using namespace std;

int lowerBoundBf(vector<int>&arr , int x){
    int n= arr.size();
    for (int i = 0; i < n; i++) {
      if(arr[i]>=x){
        return i;
      }
    }

    return n;

}


//we will use binary search
/*
as the array is sorted we can reduce the search space 
as if the mid is smaller than x , then we can eleiminate 
all the elemnts left of mid
*/
int lowerBoundOpt(vector<int>&arr , int x){
    int n= arr.size();
    int low=0;
    
    int high=n;
    int ans=n; //default case

    while(low<=high){
        int mid=(low+high)/2; // calculating mid at start
        if(arr[mid]<x){
            low=mid+1;
        }
        else{ // when arr[mid]>=x
            ans =mid;
            high=mid-1; // we will check elemnts lesser than mid as they will have smaller index
        }
       

    }


   

    
    return n;

}

int main() {
    int n , x;
    cin >> n>>x;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout<<lowerBoundBf(arr , x);
    return 0;
}