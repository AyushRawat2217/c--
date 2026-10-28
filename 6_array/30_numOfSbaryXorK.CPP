#include <bits/stdc++.h>
using namespace std;

int nrSbaryXorKBF(vector<int>&arr , int k){
    int n =arr.size();
    int a;
    int count=0;

    for (int i = 0; i < n; i++) {

      a=0;
      for (int j =i; j < n; j++) {
        a^=arr[j];

        if(a==k){
            count++;
            
        }
      }
    }

    return count;

}




int nrSbaryXorKOpt(vector<int>&arr , int k){
    int n =arr.size();
    int x=0;
    int count=0;
    map<int , int >mpp;
    mpp[0]=1; //if subarray star from index 0
    /*
    x[l-1]=x[i]^k; this is the concept
    if subarray is staring frox l to i
    */

    for (int i = 0; i < n; i++) {
       x^=arr[i];

       if(mpp.find(x^k)!=mpp.end()){
        count+=mpp[x^k];
       }

       mpp[x]++;
      
    }
    return count;
}

int main() {
    int n ,k;
    cin >> n>>k;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    

    int res = nrSbaryXorKOpt(arr ,k);
    cout<<res;

    return 0;


}