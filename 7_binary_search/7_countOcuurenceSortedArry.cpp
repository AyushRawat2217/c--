#include <bits/stdc++.h>
using namespace std;

/*
we need to break it to first and last occurences
we will find index of first occurence then of last occurence then , use those indexes to find total elemnts
*/
int countingFirstOccBS(vector<int>&arr , int x){
    int low=0;
    int high=arr.size()-1;
    int mid;
    int firstOcc=0;
    while(low<=high){
         mid=low+(high-low)/2;

         if(arr[mid]=x){
            firstOcc=mid;
            high=mid-1;
         }
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
            
    }

    return firstOcc;


}

int countingLastOccBS(vector<int>&arr , int x){
    int low=0;
    int high=arr.size()-1;
    int mid;
    int lastOcc=0;
    while(low<=high){
         mid=low+(high-low)/2;

         if(arr[mid]=x){
            lastOcc=mid;
            low=mid+1;
         }
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
            
    }

    return lastOcc;

}


//at last do lastOcc-firstOcc+1;
int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return 0;
}