#include <bits/stdc++.h>
using namespace std;


int binSearchRecursion(vector<int>&arr , int target ,int low , int high){
    if(low>high){
        return -1;
    }
    int mid=(low+high)/2;

    /* 
    its important to return the function as it stored the value of arr[mid ]which
    is equal to target
   */
    if(target<arr[mid]){
        return binSearchRecursion(arr , target ,low , mid-1);
    }
    else if(target==arr[mid]){
        return mid;
    }
    else{
    return binSearchRecursion(arr , target ,mid+1 , high);
    }

}
int binSearch(vector<int>&arr , int target){
    int n=arr.size();

    int low=0;
    int high=n-1;
    
    //we tryna put target in arr[mid] , at one time if it exist it will be
    //till then we keep shrinking search space
    
    while(low<=high){
        int mid=(low+high)/2;

        if(target==arr[mid]){ 
            return mid;
        }
        else if(target<arr[mid]){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    cout<<"Not Found"<<endl;
    return 0;
}

int main() {
    int n;
    cin >> n;
    int target;
    cin>>target;

    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout<<binSearch(arr , target);
    return 0;
}

