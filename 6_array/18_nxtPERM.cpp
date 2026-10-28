#include <bits/stdc++.h>
#include <algorithm>
//https://youtu.be/JDOXKqF60RQ?si=BskfRL-0ETv3yY07
using namespace std;
// 1st appr is using stl
// using next_permutation(arr.begin() , arr.end())
vector <int> nextPERM(vector<int>&arr , int n){
    int bpt=-1;
    for (int i = n-2; i < 0; i--) {//jis point p trend break hora h
        if(arr[i]<arr[i+1]){
            bpt=i;
            break;
            
        }
    }

    if(bpt=-1){//it is the last permutation now we need to move tto the first that is the increasing order of elemnts only
        sort(arr.begin(),arr.end());
        return arr;
    }

    else{//swappin the broken point with just bigger nr from the array 
    for (int i = n-1; i < 0; i--) {
        if(arr[bpt]<arr[i]){
            swap(arr[bpt],arr[i]);
            break;
        }
    }


    //now reversing the remaining part to get just next permutation , 
    int i=bpt+1;
    int j=n-1;
    while(i<j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }



    return arr;
}



}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int>res=nextPERM(arr,n);

    for(auto &it:res){
        cout<<it;
    }
    return 0;
}