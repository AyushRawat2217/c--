#include <bits/stdc++.h>
using namespace std;
/*we are given nr of painters and we have to divide the work such a way that
maimum time taken by painter is minimum of all possible combinaton
*/

int returnPainterUsed(vector<int>&arr ,  int maxArea , int n){
    int ptrUsed=1;
    int areaPaintedSoFar=0;

    for (int i = 0; i < n; i++) {
      if(areaPaintedSoFar+arr[i]<=maxArea){
        areaPaintedSoFar+=arr[i];
      }
      else{
        ptrUsed++;
        areaPaintedSoFar=arr[i];
      }
    }

    return ptrUsed;
}

int painterPartitionBF(vector<int>&arr , int nrOfPtrs){
    int minn=INT_MIN;
    int maxx=0;

    for(int i:arr){
        minn=max(i , minn);
        maxx+=i;
    }

    for (int i = minn; i <=maxx; i++) {

        if(returnPainterUsed(arr ,  i , arr.size())<=nrOfPtrs) return i;

    }

    return -1;
}





bool canWeTryForLesserTimeTaken(vector<int>&arr ,  int maxArea , int n){
   int ptrUsed=1;
    int areaPaintedSoFar=0;

    for (int i = 0; i < n; i++) {
      if(areaPaintedSoFar+arr[i]<=maxArea){
        areaPaintedSoFar+=arr[i];
      }
      else{
        ptrUsed++;
        areaPaintedSoFar=arr[i];
      }

      if(ptrUsed>maxArea) return false;
    }


    return true;

   
}

int bookAllocationOpt(vector<int>&arr , int students){

    

    int n= arr.size();
    int minn=INT_MIN;
    int maxx=0;

    for(int i:arr){
        minn=max(i , minn);
        maxx+=i;
    }

    int low = minn;
    int high=maxx;
    

    while(low<=high){ 
        int mid=low+(high-low)/2; 

        if(canWeTryForLesserTimeTaken(arr , mid , n)){//if true then try for lesser max time
            high=mid-1;
        }
        else low=mid+1;
    }
    return low;

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