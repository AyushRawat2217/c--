#include <bits/stdc++.h>
using namespace std;

pair<int,int>returnPairWithSumK(vector<int>arr , int k){

    sort(arr.begin() , arr.end());
    int left=0;
    int right=arr.size()-1;

    while(left<right){
        int sum=arr[left]+arr[right];
        if(sum==k)return {arr[left] .arr[right]};
        else if(sum<k)left++;
        else right--;
    }
    return {-1 , -1};
}

int main() {
    int n , k;
    cin >> n>>k;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout<<returnPairWithSumK(arr , k).first<<" "<<returnPairWithSumK(arr , k).second;
    return 0;
}