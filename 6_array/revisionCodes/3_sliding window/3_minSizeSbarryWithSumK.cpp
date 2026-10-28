#include <bits/stdc++.h>
using namespace std;

//314
//k sum given hai hame krna ye hai ki min subarray find krni hai jiska sum k ho
int fun(vector<int>&arr  , int k , int n ){

    int i=0;
    int j=0;
    int sum=0;
    int ans=arr.size()+1;

    while(j<n){
        sum+=arr[j];

        while(sum>=k){//jis point pe sum , k se jyada ya barabar jaaega uss time shrink krna start krdo window ko
            ans=min(ans , j-i+1);
            sum-=arr[i];
            i++;
        }   
    }
    
    /*   
while (sum >= target) {
    // Current window is valid (sum >= target),
    // so record its length BEFORE shrinking.
    ans = min(ans, right - left + 1);

    // Try to make the window smaller while it
    // still satisfies the condition.
    sum -= nums[left];
    left++;
}

*/
    
   
   return ans;
}

int main() {
    


    return 0;
}