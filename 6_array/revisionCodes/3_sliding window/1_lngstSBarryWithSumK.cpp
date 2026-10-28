#include <bits/stdc++.h>
using namespace std;

/* sliding window vs 2 ptr
2 ptr mai ham sirf 2 elemnts ki baat krte hai jinko
wo dono pointer point krre hote hai but in case of 
sliding window we talk about */

void longestSubArrySumK(vector<int>&arr , int k){
    
    int n=arr.size();
    int i=0;
    int j=0;
    int sum=0;
    int len=0;

    /* pehle i ka use krke elemnt sum mai daala  aur window badi ki
    fir j ka use krke uss window ko dynamically chota kiya taaki
    sum k ke upr naa jaayein*/

    while(i<n){
        sum+=arr[i];

        while(sum>k && i>=j){
            sum-=arr[j];//remove from the left 
            j++;
        }
        if(sum==k){
            len=max(len , i-j+1);
        }
        i++;
    }
}





int main() {
    
    return 0;
}