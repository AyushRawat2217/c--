#include <bits/stdc++.h>
using namespace std;

float sqrtOpt(int n){
    int low=1;
    int high=n;
    int mid;
    int ans;

    if(n==1 || n==0) return n;

    while(low<=high){
        mid=low+(high-low)/2;


        if(mid*mid<=n) {
            ans=mid; //storing the  best canditate
            low=mid+1;
        }
        else high=mid-1; // at a point high will be less than low

    }

    return ans;
    
}

int main() {
    int n;
    cin >> n;

    cout<<sqrtOpt(n);
    
    
    return 0;
}