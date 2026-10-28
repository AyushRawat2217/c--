#include <bits/stdc++.h>
using namespace std;

void floorAndCeilBinaryS (vector<int>&arr , int x){
    int low=0;
    int high=arr.size();
    int floor , ceil;
    int mid;


    //dry run is the revision
    while(low<=high){ // ceiling , smallest arr elemnt greater than x
        mid=low+(high-low)/2; //to avoid overflow

        if (arr[mid] == x) { // applies for both ceil and floor
        floor = ceil = arr[mid];
        break;
        }
        else if(arr[mid]>x){
            ceil=arr[mid];//arr mid is potential canditate for ceil
            high=mid-1; //but there could be smaller elemnts who could be bigger
        }
        else{ //arr[mid]<x
            floor=arr[mid]; //potential for floor 
            low=mid+1; //ther could be elemnts bigger arr elemnts but smaller than floor
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return 0;
}