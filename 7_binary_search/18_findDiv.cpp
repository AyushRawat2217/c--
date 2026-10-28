#include <bits/stdc++.h>
using namespace std;

//simply we have to do ceil division
/*
ek integer 1- n lenge aur us se array k harr elemnts ko
ceil divide krenge and add up krte jaayenge agr aakhri m
wo value thres hold se kam ya barabar ho toh use return krdenge
*/

int smllstDiv(vector<int>&arr,int x){
    int n=arr.size();
    int maxx=INT_MIN;
    for(int i:arr) maxx=max(maxx,i);

    for (int i = 1; i <= maxx; i++) {
        int divSum=0;
      for (int j = 0; j < n; j++) {
        divSum+=((arr[j]+i-1)/i);
      }
      if(divSum<=x){
        return i; // we will automatically get the least one
      }
    }
    return -1;

}



int sumOfCeilDivBy(vector<int>&arr,int x , int thres){
    int n=arr.size();
    int divSum=0;
    for (int i = 0; i < n; i++) {
        divSum+=((arr[i]+x-1)/x);
        if(divSum>thres) return divSum; // reducing extra computataional efforts

    }
    return divSum;

}
int smllstDivOpt(vector<int>&arr , int thres){
    int n= arr.size();
    int low = 1;
    int maxx=INT_MIN;
    for(int i:arr) maxx=max(i , maxx);
    int high=maxx;
    int ans=-1;


    while(low<=high){

        //these low mid high are divisors
        //bigger divisor lesser the divsum
        int mid=low+(high-low)/2;

        if(sumOfCeilDivBy(arr , mid , thres)<=thres){
            ans=mid;
            //we are trying to find the smallest divisor
            
            high=mid-1; //trying smaller answers
        }
        else{ //sumofceildiv(mid)>thres
           low=mid+1;// we need bigger divisor then to reduce value below thres
        }

    }

    return ans;
    


}










int main() {
    int n ,x;
    cin >> n>>x;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout<<smllstDiv(arr ,x );
    return 0;
}