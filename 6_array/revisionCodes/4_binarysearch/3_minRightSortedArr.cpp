#include <bits/stdc++.h>
using namespace std;

//3 4 5 1 2
int breakingPtIndex(vector<int>&arr){
    for (int i = 0; i < arr.size()-1; i++) {
      if(arr[i+1]<arr[i])return i+1;
    }
}

int minInRotatedArr(vector<int>&arr ){
    int low =0;
    int high=arr.size()-1;
    int mid;


    while(low<high){
        mid=low+(high-low)/2;
     if(arr[mid]>arr[high]){//iska mlb right side ki trf hai min elemnt , kyuki mid tkk elemnt increae hai fir high pe jaakr decrease hore hai
        //mlb dip mid se high ke beech hai
        low=mid+1;
     }

     else {//arr[mid]<arr[low] , it means there was a dip going towards mid
        high=mid;
     }

        }

        return arr[low];
    }

int main() {
    
    return 0;
}