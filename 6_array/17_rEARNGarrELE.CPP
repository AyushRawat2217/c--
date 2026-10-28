#include <bits/stdc++.h>
using namespace std;
vector <int> rearngVecBF(vector<int>&arr , int n){
   vector< int> arr1;
    vector <int>arr2;
    

    for (int i = 0; i < n; i++) {
        if(arr[i]>0){
            arr1.push_back(arr1[i]);
        }
        else{
            arr2.push_back(arr2[i]);
        }
      
    }
    for (int i = 0; i < n; i++) {
        if(i%2==0){
            arr[i]=arr1[i/2];
        }

      else{
        arr[i]=arr2[(i-1)/2];
      }

      //+ve nrs are at even locations and negative are at odd


      
    }

    return arr;
}
vector <int> rearngVecOPT(vector<int>&arr , int n){
    vector <int>arr1(n);
    arr1[0]=arr[0];
    
    //find elemnt and shift it to the index
    //instead of finding index and putting wlemnt in it
    //smart ass approach

    int pos=0 ,neg=1; //when we want index to change according traversal we can use variable
    
  for (int i = 1; i < n; i++) {
    if(arr[i]>0){
        arr1[pos]=arr[i];
        pos+=2;
    }

    if(arr[i]>0){
        arr1[neg]=arr[i];
        neg+=2;
    }
    
  }
}



int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int>result=rearngVecBF(arr,n);
    for(auto &i:result){
        cout<<i;
    }
    return 0;
}