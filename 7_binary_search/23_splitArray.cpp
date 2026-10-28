#include <bits/stdc++.h>
using namespace std;
//we have to find minimum of maximum sum among all k subarrays

int checkForSubarraysWithMinSum(vector<int>&arr , int k , int i , int n){
   
    int currentSum=0;
    int subArrayCreatedSoFar=1;

    for (int i = 0; i < n; i++) {
        
     
        if(currentSum+arr[i] <=i){//we are already checking before adding arr[i] to current sum   
        currentSum+=arr[i];
        }

        else{
            subArrayCreatedSoFar++;
            currentSum=arr[i];//restarting the current sum from current elemnt
        }
       
    
    }

    return subArrayCreatedSoFar;

    
}
int splitArrayBf(vector<int>&arr , int k){
    int n=arr.size();
    int maxx=INT_MIN;
    int sum=0;

    for(int i:arr){
        sum+=i;
        maxx=max(i , maxx);
    }

    if(n==k) return maxx;
    
    
   
  else{
    for (int i = maxx; i <= sum; i++) { //possiblke sums
      int subarrays=(checkForSubarraysWithMinSum(arr , k , i , n));
      if(subarrays<=k) return i;

      /*why <=k works
      ur doubt is  we can further break a array to create subarrays exact k
      then max sum will reuce and become less than k

      🔥 Final clarity (this is what you were missing)
    Splitting can reduce actual max sum
     BUT brute force will eventually test that smaller limit anyway

      */

    }
       
    }

    return -1;
  
 
}



bool canCreateRequiredSubarrayWithThisSUm(vector<int>&arr , int k , int mid , int n){
   
    int currentSum=0;
    int subArrayCreatedSoFar=1;

    for (int i = 0; i < n; i++) {
        if(currentSum+arr[i] <=mid){//we are already checking before adding arr[i] to current sum   
        currentSum+=arr[i];
        }
        else{
            subArrayCreatedSoFar++;
            currentSum=arr[i];//restarting the current sum with current elemnt
        }
    }

    return (subArrayCreatedSoFar<=k);

    
}

int splitArrayOpt(vector<int>&arr , int k){

    int n= arr.size();


    int maxx=INT_MIN;
    int sum=0;
    for(int i:arr){
        sum+=i;
        maxx=max(i , maxx);
    }

    if(n==k) return maxx;

    int low = maxx;
    int high=sum;


       while(low<=high){ 
        int mid=low+(high-low)/2; 

        if(canCreateRequiredSubarrayWithThisSUm(arr,k ,mid , n)){//if true then try for lesser load
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