//Find the Majority Element that occurs more than N/2 times

#include <bits/stdc++.h>
using namespace std;

int cntBF(vector<int>&arr,int n){
    // we will use 2 loops , take one element at a time count its freuency 
    //then store that elemnt if its frew is gretaer than that of prev elemnt
    //and at last return the elemnt with greatest cnt
    int cnt2=INT_MIN;
    int maxEle;
    for(int i=0;i<n;i++){
        int count1=0;


        for(int j=0;j<n;j++){
            if(arr[i]==arr[j]){
                count1++;
            }

        }
        if(count1>(n/2)) return arr[i];//break computational maths here
        
    }

    return -1;


    
}

int cntHsh(vector<int>&arr,int n){
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    int maxEle=mpp[arr[0]];

    for(auto &it:mpp){
        if(it.second>(n/2)){//its given in question
            return it.first;
        }

    }

    return -1;



    
   
    
}

int cntMooreVtng(vector<int>&arr,int n){

    int cnt=0;
    int ele;
   
    //finding the contender for majority elemnt
    //If an element occurs more than n/2 times, it cannot be eliminated by pairwise cancellation.
    for(int i=0;i<n;i++){
        
        if(cnt==0){
            ele=arr[i];
        }

        if(ele=arr[i]){
            cnt++;
        }

        else{
            cnt--;
        }
//ek na ek baar toh majority elemnt aaega dubara and wo toh n/2 times se jyada h , milkr bhi saare nr cancel ni krpayenge
    }

    //checking if its maj elemnt for true or not
    //Moore’s Voting Algorithm always returns an element — but that element is only a candidate.
    //{1,2,3,4} example

    //we need to verify only when question dosnt specify that maj elemnt is present
    //else no need to specify like in this case
    //we didnt need to specify
    int cnt2=0;
    for(auto &it:arr){
        if(it=ele){
            cnt2++;
        }

    } 
    if(cnt2<(n/2))   {
        return -1;

    }
    else{
        return ele;
    }

}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int res=cntMooreVtng(arr,n);
    cout<<res;
return 0;
}