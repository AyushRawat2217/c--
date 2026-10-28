#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

// brute force m pow inbuilt function ka use krenge


int multNtimes(int x , int n){
    long long num=1;
    for (int i = 1; i <=n; i++) {
      num*=x;
    }
    return num;
}

float nThsqrtOpt(int n , int x){
    int low=2;
    int high=x;
    int mid;
    int ans=0;

    if(x==1 || x==0) return x;


    while(low<=high){
        mid=low+(high-low)/2;

        if(multNtimes(mid,n)<=x){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }

    return ans;
    
}

int main() {
    int n , x;
    cin >> n>>x;

    cout<<nThsqrtOpt(n , x);
    

    return 0;
}