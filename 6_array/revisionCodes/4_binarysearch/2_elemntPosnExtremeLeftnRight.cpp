#include <bits/stdc++.h>
using namespace std;

pair<int , int>fun(vector<int>&arr , int target){

    int low=0;
    int high=arr.size()-1;
    int mid;
    int extremeLeft , extremeRight;
    int couldBeExtreme;

    //to find exterme right
    while(low<=high){
        mid=low+(high-low)/2;
        if(target<arr[mid])high=mid-1;
        else if(target>arr[mid])low=mid+1;
        else{//when arr[mid]==target then move towards right
            couldBeExtreme=mid;
            low=mid+1;
        }
    }
    extremeRight=couldBeExtreme;



    int low1=0;
    int high1=arr.size()-1;
   

    //to find exterme right
    while(low1<=high1){
        mid=low1+(high1-low1)/2;
        if(target<arr[mid])high1=mid-1;
        else if(target>arr[mid])low1=mid+1;
        else{//when arr[mid]==target then move towards left
            couldBeExtreme=mid;//store it then move
            high=mid-1;
        }
    }

     extremeLeft=couldBeExtreme;

     return {extremeLeft , extremeRight};


}

int main() {
    
    return 0;
}