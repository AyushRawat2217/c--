#include <bits/stdc++.h>
using namespace std;

//we will need an extra array
vector<int>unionArr (vector<int>&arr1 , vector<int>&arr2){
    vector<int>unionArr;
    int left=0;
    int right=0;

    while(left<arr1.size() && right<arr2.size()){

        //we also have to take care of elemnt not being same , so one more condition inside comparision
        if(arr1[left]<arr2[right]){
            if(unionArr.size()==0||unionArr.back()!=arr1[left]){
            unionArr.push_back(arr1[left]);
            left++;
            }
        }
        else{
            if(unionArr.size()==0||unionArr.back()!=arr2[right]){
            unionArr.push_back(arr2[right]);
            right++;
            }
        }
    }
    while(left<arr1.size()){
         unionArr.push_back(arr1[left]);
            left++;
    }
    while(right<arr2.size()){
        unionArr.push_back(arr2[right]);
            right++;
    }

    return unionArr;

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