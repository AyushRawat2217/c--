#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntrvlsBf(vector<vector<int>>&arr){
   int  n=arr.size();
   sort(arr.begin(),arr.end());
   
   vector<vector<int>> arr2;

    for (int i = 0; i < n-1; i++) {

        int start = arr[i][0];
        int end = arr[i][1];
        if(!arr2.empty()&&arr2.back()[1]>=end){ // checks whether arr2 is empty or not
            continue;  // and to skips those elemnts which are already incorporated

        }

        for (int j = i+1; j< n; j++) { 

            /*
            [1,10]
[2,3]

Overlap still exists.

But:

max(10,3) = 10

So the merged interval remains:

[1,10]

Because the second interval is fully inside the first.

Without max, you'd incorrectly shrink the interval.*/
            if(arr[j][0]<=end){
                end= max(end , arr[j][1]);
            }
            else{
                /*if current
                condition is false then next elemnts will also be false
                as they are only bigger so continuing loop will be pointless
                */
                break;
            }
        }
        
    }
    return arr2;

}


vector<vector<int>> mergeIntrvlsOpt(vector<vector<int>>&arr){
   int  n=arr.size();
   sort(arr.begin(),arr.end());
   
   vector<vector<int>> arr2;

   for (int i = 0; i < n; i++) {
    // int start=arr[i][0];
    // int end=arr[i][1];

    if(arr2.empty() || arr2.back()[1]<arr[i][0]){

        //agr empty h ya lie ni krta toh daal do element , wo next wale step
        //mai change hojaege agr condition of merge follow hogi
        //uske peeche wala index change hojaega
        arr2.push_back(arr[i]);
                    
    }

    else{ //changing the last index of the elemnet only
        arr2.back()[1]=max(arr2.back()[1],arr[i][1]);
    }

     
   }

    
        
    
    return arr2;

}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> arr(n , vector<int>(2));
    for (int i = 0; i < n; i++) {
        for(int j=0;j<2;j++){
            cin>>arr[i][j];
        }
    }

    vector<vector<int>>result=mergeIntrvlsOpt(arr);
    for(auto &it:result){
        cout<<it[0]<<" "<<it[1]<<endl;
    }
    return 0;
}