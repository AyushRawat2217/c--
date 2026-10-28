#include <bits/stdc++.h>
using namespace std;

/*
hme ek array di h , jisme i th rose , a[i]th day tkk bloom hoga
aur hmse pucha ki agr hme m boquet bnane h k rose each
toh hme min kitne din legenge thing is we have to take alternative roses
i.e 0th rose and 1th rose can be in a boquet but 2 nd and 5th cant be
*/
int minDaysBf(vector<int>&arr , int m , int k){
    int n= arr.size();
    int maxx=INT_MIN;
  

    for(int i:arr) maxx=max(i , maxx);


    for (int i = 1; i<=maxx; i++) { // i is the days
        int boquet=0;
        int roses=0;
      for (int j = 0; j < n; j++) {
        if(arr[j]<=i){//if blooming day is less than i day then we increase nr of roses by 1
             roses++;
             if(roses=k){
                boquet++;
                roses=0; //reset after forming the boquet
             }
        }
        else{
            roses=0; // breaking the streak as we need adjacent elemnts only
        }

    }

    if(boquet>=m){ // we got out desired number of buckets
        return i;
int minDaysBf(vector<int>&arr , int m , int k){
    int n= arr.size();
    int maxx=INT_MIN;
  
    }

    }

    return -1;

}




//opt approach

bool isItGudCndtt(vector<int>&arr,int x , int m , int k , int maxx){
/*x is the the day and using this function we have to check
whether using this we can get m boquet each with k adjacent flowers
*/
    int n=arr.size();
    int boquet=0;
    int roses=0;
    for (int i = 0; i < n; i++) {
      if(arr[i]<=x){
        roses++;

        if(roses==k){
            boquet++;//agr k djacent roses mil gye toh ek boquet fill hojaegi
            roses=0;//resetting the streak
        }

      }

      else{
        roses=0;
      }

      
    }

    if(boquet>=m) return true;
    else return false;
}
int minDaysBf(vector<int>&arr , int m , int k){
    int n= arr.size();
    int low = *min_element(arr.begin(), arr.end()); // the least elemnt need not to be one
    int maxx=INT_MIN;
    for(int i:arr) maxx=max(i , maxx);
    int high=maxx;


    while(low<=high){
        int mid=low+(high-low)/2;

        if(isItGudCndtt(arr,mid ,m , k,maxx)){
            high=mid-1;
        }
        else{
            low=mid+1;
        }

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