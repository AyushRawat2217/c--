#include <bits/stdc++.h>
using namespace std;

/*

h is number o hours alooted
we have to find k(nr of banana to be eaten per hour ) whihc is fixed
so we can take max hours and with minimum speeed
condn is he can eat k bananas per hour only , if the nr is greater and lesser than that 
he stops at<=k and eats next hr


we know the max banana per hour he can eat ir arr[n-1]/hr , but we need the speed which is the least
or speed which take max time but less than h
*/

int kokoBananaBf(vector<int>&arr , int h){
    int n=arr.size();
    int prevMaxTime=INT_MIN;
    int maxTime;
    int maxPile=INT_MIN;

    for (int x : arr) maxPile = max(maxPile, x);

    for(int i=1;i<=maxPile;i++){
        maxTime=0;
        for (int j = 0; j < n; j++) {
          maxTime+=ceil((double)arr[j]/i);

          //or
          // (arr[j]+i-1)/i) this also works a ceil function
        }
        if(maxTime<=h){
           return i; //first valid will be the least speed automatically

           /*Here, i = eating speed (bananas/hour).

For each i, you compute total time maxTime.

Key Battlefield Insight

As speed increases → time required decreases.

This is a monotonic decreasing relationship.

Small i → slow speed → high time
Large i → fast speed → low time*/
        }
    }

    return -1;

}





int kokoS(vector<int>&arr,int x){
    int n=arr.size();
    long long  maxTime=0;
    for (int i = 0; i < n; i++) {
      maxTime+=((arr[i]+x-1)/x);
      if (maxTime > x) return maxTime;//to stop extra computation once maxtime exceeds 
      //deadline  
    }
    return maxTime;
}

int kokoBananaOpt(vector<int>&arr , int h){
    int n=arr.size();
    int low=1;
    //int minSpeed=INT_MAX;

    int maxPile=INT_MIN;

    for (int x : arr) maxPile = max(maxPile, x);
    int high=maxPile;

    while(low<=high){
        int mid= low+(high-low)/2;

        if(kokoS(arr,mid)<=h){
           // minSpeed=min(minSpeed , mid);
           /*
            we actuallly dont need this min speed , because 
            when we r checking condn then we are moving toward the smaller value
            where the condn is satisfied so at the end we can just return low
            */
            
            high=mid-1;
        }
        else{
            low=mid+1;
        }

    }

    return low;

}



int main() {
    int n , h;
    cin >> n>>h;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout<<kokoBananaOpt(arr ,h);
    return 0;
}