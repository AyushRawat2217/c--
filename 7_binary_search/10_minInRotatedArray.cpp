#include <bits/stdc++.h>
using namespace std;
int minRotatedArray(vector<int>&arr , int x){
    int low=0;
    int high=arr.size()-1;
    int mid;
    int minn=INT_MAX;

    while(low<=high){
        mid=(low+high)/2;
        if(arr[low]<arr[high]){ //from low to high is sorted
            minn=min(minn,arr[low]);
            return minn;//iss point p left right krne ki jrurat ni h ek baar ye chl gya fir 
            //decide hojaega ki minn ki min value kya h 
            //fir arr low se chota kuch hai hi ni

        }
        else if (arr[mid]<arr[high])
        {
            minn=min(minn,arr[mid]);
            high=mid-1; //i already searched the right half ,  left might have good elemnts
        }

        else{//arr[low]<arr[mid]
             minn=min(minn,arr[low]);
             low=mid+1;
        }
        
    }
}


int minRotatedArray(vector<int>&arr , int x){
    int low=0;
    int high=arr.size()-1;
    int mid;
    int minn=INT_MAX;

    while(low<=high){
        mid=(low+high)/2;

        /*nums[mid] > nums[high]

Then:

mid is in the left rotated part
high is in the right sorted part

So structure looks like:

[ big values | small values ]
        mid        high

Example:

[30,40,50 | 5,10,20]
        mid     high

Now answer this:

👉 Can the minimum be on the left side (30,40,50)?

No.

Because:

Entire left side is greater than right side
Minimum must be in the right segment

segment
🔥 That’s why we do:
low = mid + 1;*/
       

/*
what if value on low side smaller than the one bw mid and high?
high ki last value k baad , ham low p aajaenge 
after nth value we move to 1st , wo toh obviouslly bdi hogi high se
kyuki sorted arrat h
7 8 0 1 2 , dekh 0mse break hua h

isliye low=mid+!; kiya h
*/
       if(arr[mid]>arr[high]){
            low=mid+1;
        }
        else{ //arr[mid]<=arr[high] , means 
            high=mid; //we move to high to mid, to check whether there are any smaller elemnt that side
            //we wont miss mid , as thats why we assigned  it high = mid
            //if arr new mid > high , then new mid was smaller
            //if not arr new mid > arr[high] , then we move low=mid+1;
            //at last low  mid high all will be at the asmallest elemnt
        } 
        
    }

    return arr[low];

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