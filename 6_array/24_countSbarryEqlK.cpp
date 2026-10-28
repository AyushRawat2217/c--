#include <bits/stdc++.h>
using namespace std;

int countSbarrysBf1(vector<int>&arr , int sum){
    int n=arr.size();
    int arrSum=0;
    int count=0;

    for (int i = 0; i < n; i++) {

        for (int j = i; j < n; j++) {

            for (int k = i; k<=j; k++) {
                arrSum+=arr[k];
            }
            if(arrSum==sum){
                count++;
            }
            arrSum=0;
           
                
        }
    }

    return count;
}

int countSbarrysBr(vector<int>&arr , int sum){
    int n=arr.size();
    int arrSum=0;
    int count=0;

    for (int i = 0; i < n; i++) {

        for (int j = i; j < n; j++) {
             arrSum+=arr[j];
            if(arrSum==sum){
            count++;
             }
        
        }
        arrSum=0;
        
    }

    return count;
}

int countSbarrysOpt(vector<int>&arr , int sum){
    int n=arr.size();
  
    int count=0;
   
    int sum1=0;
    map<int , int>mpp;
  

  
    for (int i = 0; i < n; i++) {
        sum1+=arr[i];
        mpp[sum1]=i;
        int findSbarry=sum1-sum;


        
        if(mpp.find(findSbarry)!=mpp.end()){
        
            count++;
        }


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
    int result = countSbarrysOpt(arr,k);
    cout<<result;
    return 0;
}