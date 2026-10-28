#include <bits/stdc++.h>
using namespace std;

vector <int> sortBF(vector <int>&arr , int n){
    //just sort it 
    sort(arr.begin(),arr.end());
    return arr;

    //tc onlogn
}

vector <int> sortCount(vector <int>&arr , int n){
   //count 0 , 1 ,2 then using loop insert them in arr
   //tc o n , sc o 1 , values are overwritten
}

vector <int> sortOpt3ptrs(vector <int>&arr , int n){

    //tc 0n
    int low=0;
    int mid=0;
    int high = n-1;
    /*
    logic is we have to keep 1 at middle ,
    the moving pointer is mid , if we find zero we swap it with low and 
    if we find 1 e keep it there and if we find 2 we send it to last
    we keep sending nr to position they should be at*/

    while(mid<=high){
        if (arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{//for 2
            swap(arr[mid],arr[high]);
            high--;
        }
    }

    return arr;
   
}


int main() {
     int n ;

    cin>>n;

    vector<int> arr(n); //either specify size of vector or use pushback  

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }


return 0;
}