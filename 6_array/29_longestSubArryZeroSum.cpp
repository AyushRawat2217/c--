#include <bits/stdc++.h>
using namespace std;

int lenSbaryBF(vector<int>&arr){

    int n=arr.size();
    int max1=INT_MIN;
    int sum=0;
    for (int i = 0; i < n; i++) {
        

        for (int j = i; j< n; j++) {

            sum+=arr[j];
           

            if(sum==0){
                //j-i+1 gives length of elemnts traversed so far 
                //earlier i was creating an array storing the arr[j] , then calculation size of array , incearing sc
                max1=max(max1,j-i+1);// this arr size give me long int so i need to make both data types same
                break;
            } 

           
        }
    }
    return max1;
}

int lenSbaryOpt(vector<int>&arr){

    int n=arr.size();
    int max1=INT_MIN;

    unordered_map<int ,int>mapp;

    int sum=0;

    for (int i = 0; i < n; i++) {
       

        sum+=arr[i];


        sum+=arr[i];

        if(sum==0){
            max1=i+1;
        }

        if(mapp.find(sum)!=mapp.end()){
            max1= max(max1 ,( i-mapp[sum]));
          
        }

        else{
        mapp[sum]=i;
        }


      
    }


    return max1;




    
    
}


int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int res=lenSbaryOpt(arr);

    cout<<res;

    return 0;
}


