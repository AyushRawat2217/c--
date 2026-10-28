#include <bits/stdc++.h>
using namespace std;


int find_NrBF(vector<int>&arr,int n){
    for(int i= arr[0];i<=arr[n-1];i++){
        int flag=1;
        for(int j=0;j<n;j++){
            if(i==arr[j]){
                flag=0;
                break; //not want to continue further when element is found

            }
        
        }
        if(flag==1){
                return i;

            }
    } 
 return 0 ;
}


void  find_NrHash(vector<int>&arr,int n){
   int hsh[n]={0}; //using hashing

   for(int i=0;i<n;i++){
    hsh[arr[i]]=1;
   }

   for(int i=1;i<n;i++){
     if(hsh[i]==0){
        cout<<i;
        break;
     }
   }







}


void  find_NrSum(vector<int>&arr,int n){
    /*find the sum of array elemnts s2 and then 
    find the sum of nrs 1-n s1 , at the end 
    missing number is s1-s2
    it reduces space complexity only a 2 constants
    required
    
    */ 
}


/*
xor of same number is 0 

*/ 

void  find_NrXor(vector<int>&arr,int n){ 
    int x1=0;
    int x2=0;
  for(int i=1;i<=n;i++){
    x1=x1^i;
   }

for(int i=0;i<n;i++){
    x2=x2^arr[i];
   }

   cout<<(x2^x1);


}



int main() {
    int n;
    cin >> n;
  
    vector<int> arr(n); //either specify size of vector or use pushback  

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

 find_NrXor(arr,n);


return 0;
}