#include <bits/stdc++.h>
using namespace std;

pair<int ,int> twoSumBF(vector<int>&arr,int n , int sum){

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i]+arr[j]==sum){
                cout<<i<<" "<<j;
                return {i,j};
            }
        }
    }

    
    return {-1,-1};
}

pair<int ,int> twoSumHash(vector<int>&arr,int n , int sum){
    unordered_map<int , int>mpp;
    for (int i=0;i<n;i++){
        int a =arr[i];
        

        int value=sum-a;
        if(mpp.find(value)!=mpp.end()){
            return {mpp[value],i}; //i is after the mpp value , i is actually j
        }
        mpp[a]=i;

    
    }
    return {-1,-1};
}

string twoSum2ptr(vector<int>arr,int n , int sum){
 sort(arr.begin(), arr.end());// first sort the array
 int left=0;
 int right=n-1;
 while(left>right){
    int sum2=arr[left]+arr[right];
    if(sum2==sum){
        return "yes";
    }
    else if (sum2<sum){//check sum if its less than sum increa the sum by increasing left side ptr
        left++;
    }
    else{//do opposite
        right--;
    }

    //it became possible because of sorting
 }

 return "NO";
}




       
    
int main() {
    int n , k;

    cin>>n>>k;

    vector<int> arr(n); //either specify size of vector or use pushback  

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    pair<int, int> result = twoSumHash(arr,n,k);


    if(result.first==-1 &&result.second==-1){
        cout<<"no";
    }

    else{
        cout<<"yes";
    }

 

return 0;
}