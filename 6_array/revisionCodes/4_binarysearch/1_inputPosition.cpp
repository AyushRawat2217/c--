#include <bits/stdc++.h>
using namespace std;

//here we return the index at which we found the element
int indexOfTarget(vector<int>&arr , int target){
    int low=0;
    int high=arr.size()-1;
    int mid;

    while(low<=high){

        mid=low+(high-low)/2;
        if(arr[mid]==target)return mid;
        else if(target<arr[mid])high=mid-1;
        else low=mid+1;
        
    }
    return low;
}


int main() {
    
    return 0;
}