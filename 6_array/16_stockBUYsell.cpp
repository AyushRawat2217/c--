#include <bits/stdc++.h>
using namespace std;

int stockBuySellBF(vector <int>&arr , int n ){
    int max1= INT_MIN;


    for (int i = 0; i < n; i++) {
        

      for (int j = i+1; j < n; j++) {
        max1 = max(arr[j]-arr[i],max1);


        
      } 
    }



if(max1>0) return max1;

else return 0;
}


int stockBuySellOpt(vector <int>&arr , int n ){
    /*We traverse the array once, keep track of the minimum price seen so far,
     and at each step compute the profit by selling at the current price after
      buying at that minimum.*/

  
      int profit=0;
      int mininvst=arr[0];

      for (int i = 1; i < n; i++) {
        profit=max(profit,arr[i]-mininvst);
        mininvst=min(mininvst,arr[i]);
       }


if(profit>0) return profit;

else return 0;
}


int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result =stockBuySellOpt(arr,n);
    cout<<result;
    return 0;
}