#include <bits/stdc++.h>
using namespace std;


//in third loop we face every subarray
//in this in every traversal we get a subarray

int lngSubArry2ptr3loop(vector<int>&arr, int n , int k){

    //3loop approach checks every possible subarray
    int sum;
    int len=0;
    for (int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            //3rd loop works as extension for 1st and 2nd loop
            sum=0;
             for(int k=i;k<j;k++){ // this 3rd loop can be eliminated in the next approach

                sum+=arr[k];
               
               
}
  //it traverses the whole subarrays in the array , then it takes the length of maximum  subarray
       //after sum of elemnts of subarray are counted
  if(sum==k) len=max(len , j-1+1);
            
            }
        
    }


return len;

}




// 2 ptrs we dont need to mov again ang again we can continue from the progress
//we left from 
/*for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
        cout << arr[j] << " ";
        cout << endl;
    }
}
⚔️ Output (Dry Run)

For:

[1,2,3]

You get:

1
2
3
2
3
3*/
//here in every traversal we face a extension
int lngSubArry2ptr2loop(vector<int>&arr, int n , int k){
    int sum;
    int len=0;
    for (int i=0;i<n;i++){
        sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==k) len=max(len,j-1+1);
    }
        }
return len;
}


int lngSubArryBr(vector<int>&arr, int n , int k){
      map<int ,int> mp;

      int sum =0;
      int len=0;

      for(int i=0;i<n;i++){
        sum+=arr[i]; //we will do sum of elements

        if(sum==k){//👉 If total sum from start = k → longest subarray from index 0 → i
            len=i+1;
        }
    // we will check when sum-k is coming before current sum , if its there then we check the elemnts comin in between , if there len is max we store them
        if(mp.find(sum-k)!=mp.end()){ 
            len=max(len , i-mp[sum-k]);

        }

        if(mp.find(sum)==mp.end()){ // inserting the key and value if its the first one to occur
            mp[sum]=i;
        }


      }

      return len;
}

int lngSubArryOpt(vector<int>&arr, int n , int k){
    int sum =0;
    int i=0;
    int j=0;
    int Len=0;
    while(i<n){
        sum+=arr[i]; //start from left

        while(sum>k && j<=i){ //if sum gets more than k then decrease from left , area from where we started doing sum
            sum-=arr[j];
            j++;
        }
        if(sum == k) {
                Len = max(Len, i - j + 1);
            }
              i++;
    }


return Len;
}



int main() {
    int n,k;
    cin >> n>>k;

    vector<int> arr(n); //either specify size of vector or use pushback  

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout<<lngSubArry2ptr3loop(arr, n , k);

return 0;
}