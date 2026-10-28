#include <bits/stdc++.h>
using namespace std;
int lastOccBf(vector<int>&arr , int x){
  
    for (int i = arr.size()-1; i>=0; i++) {//exploiting the property that last occurence willl come at last due to sort
      if(arr[i]==x){
        return i;
      }
    }

    return -1;
    
}

int lastOccBinary(vector<int>&arr,int x){
    int low=0;
    int high=arr.size()-1;
    int mid;
    int ind=-1;

    while(low<=high){
        mid=low+(high-low)/2;

        if(arr[mid]<x){
            low=mid+1;
        }
        else if(arr[mid]>x){ //arr[mid]>x;
            high=mid-1;
        }
        else{
            ind = mid;
            low=mid+1;
        }
    }
    return ind;
}
int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return 0;
}