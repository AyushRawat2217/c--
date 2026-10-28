#include <bits/stdc++.h>
using namespace std;

int findOnesBF(vector<int>&arr, int n){

    int count;
    for(int i=0;i<n;i++){
        count=0;
         for(int j=0;j<n;j++){
            if(arr[i]==arr[j]){
               
                count++;
               
            }        
    }
    if (count==1) 
    {
        cout<<arr[i]<<endl;
    return arr[i];
        }
    
    }

    return 0;

}


int findOnesHash(vector<int>&arr, int n){//map wali bakchodi h bss array bna di and size specify krdiya
    int maxi = arr[0]; // finding max elemnt fpr hash array
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, arr[i]); //we find max so that array size is optimal
        } 

    int hsh[maxi+1]={0}; //created a array every elemnt zero , 

    for(int i=0;i<n;i++){ // hash arrray should have index till max elemnent
        hsh[arr[i]]++;
    }


     for (int i = 0; i < n; i++) {
            if (hsh[arr[i]] == 1)
                return arr[i];
        }

    return 0;

}

int findOnesMap(vector<int>&arr, int n){

    map <int , int > mp;

    for(auto x:arr){
        mp[x]++;
    }

    for(auto it :mp){
if(it.second==1){
    return it.first;
}
    }



    return 0;


}

int main() {

    int n;
    cin >> n;
  
    vector<int> arr(n); //either specify size of vector or use pushback  

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout<<findOnesBF(arr,n);


return 0;
}