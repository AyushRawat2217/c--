//The upper bound is the smallest index, ind, where arr[ind] > x.

/*

| Concept     | Condition Checked | Meaning                |
| ----------- | ----------------- | ---------------------- |
| Lower Bound | ≥ target          | First valid or equal   |
| Upper Bound | > target          | First strictly greater |


*/

#include <bits/stdc++.h>
using namespace std;

//bruteforce is easy just put condition n fuckoff

int upperBoundOpt(vector<int>&arr , int x){
    int n= arr.size();
    int low=0;
    int high=n-1;
    int mid;
    int ans=n;

    while(low<=high){
        mid=(low+high)/2;

        if(arr[mid]<=x){
            low=mid+1; // big leagues are ahead , and mid is not tuff
        }
        else{ //arr[mid]>x
            ans=mid;
            high=mid-1;
        }
    }
    return ans;
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