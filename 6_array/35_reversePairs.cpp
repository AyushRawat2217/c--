#include <bits/stdc++.h>
using namespace std;

// those pairs i<j and arr[i]>2*arr[j].
//brute force m simply ye condition lga deni h and done , on2 ki tc hogi iski

/*
optimal approach logic
*/



void mergeAndSort(vector<int>&arr ,int low , int mid , int high){

    vector<int>temp;

    int left= low;
    int right = mid+1;
    int count=0;

    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left++]);
        }
        else{
            temp.push_back(arr[right++]);
        }

    }

    while(left<=mid){
        temp.push_back(arr[left++]);
    }
    while(right<=high){
        temp.push_back(arr[right++]);
    }

    for (int i = low; i <= high; i++)arr[i] = temp[i - low];

    

}


int breakArray(vector<int>&arr , int low , int high){

    int leftCount=0;
    int rightCount=0;
    int cross=0;
    if(low>=high){
        return 0;
    }
    
    int mid = (low+high)/2;

   int leftCount= leftCount+breakArray(arr,low , mid);
    int rightCount=rightCount+breakArray(arr , mid+1 , high);
   int cross= cross + reversePairs(arr, low, mid, high); // get clear on here
   mergeAndSort(arr, low, mid, high);
    return leftCount+rightCount+cross;

}
   

int reversePairs(vector<int>&arr , int low ,int mid ,int high){
    int n =arr.size();
    int left=low;
    int right=mid+1;
    int count=0;

    for (int i = low; i <=mid; i++) {   //get clear on here
      while(right<=high && arr[i]>=2*arr[right]){
        right++;
      }
      count+=(right-1)-(mid+1)+1; //(end - start + 1)
    }
    return count;
    
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










