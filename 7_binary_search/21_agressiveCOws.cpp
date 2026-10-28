#include <bits/stdc++.h>
using namespace std;
/*
hame k cows di hai and ek array di h jisme elemnt are poistions of shed
abh hame cows ko place krna h and ye krne k boht saare combo h 
find the combo whre the min distance(that is the dist bw any adjacent cow)
wo max ho

brute appraoch is  we assume the distance bw any two adj cows
then we check whether cow can come or not

binary search will be eliminatig the sample space 


ek or point h ki brute frce m jo ham distances assume krenge uski range kya hogi
dekh the least dist can be 1 and the max distance can be max elemnt - min element
*/

int arrangingAcowsBF(vector<int>&arr , int cows){
    sort(arr.begin() , arr.end());
    int n=arr.size();
    int maxx=arr[n-1];
    int minn=arr[0];
    


    for (int i = (maxx-minn); i>=1; i--) { // i represent the distances which are possible
        int cow=1;//cows so far put counter
        int last=arr[0];//the first cow will be places at first index

        for (int j = 1; j < n; j++) {
            if((arr[j]-last)>=i){//here we check whether we can put the nextt cow in it or not
                cow++;//we put the cow  so increase cow so far put counter
                last=arr[j];//this represent we already put the cow
            } 
            else continue;
        }
        if(cow>=cows) return i; //as we get the max min distance first
      
    }
    return -1;
}



bool canPlaceOrNot(int mid , vector<int>&arr , int n , int cows){
    int cow=1;
    int last=arr[0]; //last cow thats first cow is put at arr[0]
    for (int i = 0; i < n; i++) {
      if((arr[i]-last)>=mid){
        cow++;
        last=arr[i];//next cow position

        if(cow>=cows) return true;
      }
      
    }

    return false;
   
}
int aggrCOwsOpt(vector<int>&arr , int cows){
    int n= arr.size();
    sort(arr.begin(),arr.end());
    
    int low = 1;
    int high=arr[n-1]-arr[0];
    

       while(low<=high){ 
        int mid=low+(high-low)/2; 

        if(canPlaceOrNot(mid , arr , n , cows)){//if true then try for bigger
            low=mid+1;
        }
        else high=mid-1;  
    }
    return high;//as after low= high condn of loop high will be the right contender

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