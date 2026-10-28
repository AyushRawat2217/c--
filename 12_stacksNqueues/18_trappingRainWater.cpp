#include <bits/stdc++.h>
using namespace std;


/*paani tbhi andr jaaega jbh uske agl bagal
uss se badi buldings hongi , notebkook mai dry run krr

fir ek ith bulding ke pass jaakr dekhna hai ki uske left mai sbse badi and right and sbse
badi building kon hai , wo dono hi dip create krr rhi hai kyuki
fir rigtMax and left max mai se min jo hai usko choose krlo  usko  ith buidling ki height se
substract krdo , iska mlb uss building ke upr utna paani hai*/



int leftMax(vector<int>&arr , int index){//index wrt we have to checkleft max
}
int rightMax(vector<int>&arr , int index){
}


int waterTrappedBwDipsBf(vector<int>&arr){
    int sum=0;
    for (int i = 1; i < arr.size(); i++) {
            if(leftMax(arr,i)>arr[i]  &&  rightMax(arr,i)>arr[i]){
                sum+=(min(leftMax(arr , i) , rightMax(arr , i))-arr[i]);
            }
    }
    return sum;
}
//tc is  O n2 ,  sc is O1





//better approach

void prefixArr(vector<int>&arr , vector<int>&pfxArr){//prefix arr is used to store 
    pfxArr[0]=arr[0];
        for (int i = 1; i < arr.size(); i++) {
            pfxArr[i]=max(arr[i] , pfxArr[i-1]);//i will keep accumulating the biggest elemnt to right of
            //elemnt at ith index in the pfxArr
        }
}

void suffixArr(vector<int>&arr , vector<int>&sfxArr){//prefix arr is used to store whichver elemnt is rightmax wrt to an index
      sfxArr[arr.size()-1]=arr[arr.size()-1];
        for (int i = arr.size()-1;i>=0; i--) {
            sfxArr[i]=max(arr[i] , sfxArr[i+1]);
        }

}


int waterTrappedBwDipsBr(vector<int>&arr){

    int sum=0;

    vector<int>pfxArr;
    vector<int>sfxArr;

    prefixArr(arr , pfxArr);
    suffixArr(arr , sfxArr);

    for (int i = 0; i < arr.size(); i++) {
        if(arr[i]<pfxArr[i] && arr[i]<sfxArr[i]) sum+=(max(pfxArr[i] , sfxArr[i]))-arr[i];
    }

    return sum;
  
}//tc is oN , sc is 0n



                //OPTIMAL APPROACH

 /* we use two po'inters logic to do it
from one left side we keep a track of leftmax
and from right we keep a track rightmax .
like we increase the pointer when the nr in  it
is lesser than the other
if right index nr is smaller we move the right 
*/

int waterTrappedBwDipsOpt(vector<int>&arr){
    int leftMax=arr[0];
    int rightMax=arr[arr.size()-1];

    int left=0;
    int right= arr.size()-1;
    int sum=0;
    
    while(left<right){
        if(arr[left]<arr[right]){
            left++;
            if(arr[left]<leftMax)sum+=(leftMax-arr[left]);
            else leftMax=arr[left];
        }
        else{
            right--;
            if(arr[left]<rightMax)sum+=(rightMax-arr[right]);
            else rightMax=arr[right];
        }
    }
    /*what if we are considering a left and we leave a right which could be minimum

    dekh jese hmne left and right ko 0 and n-1 bnaya hai
    fir jo minimum hoga ham usi line mai move krenge , abh if left for now minimum hai and
    uska next element is smaller than it , and right obviously is bigger tbhi ham left pointer move krre hai
    so simply iska mlb hai ki left is the limiting value(jo ki water ko rokegi) and right toh bada hai hi wo uss left wall tkk ke
    paani ko paar ni jaane degaa , chahe beech mai kuch bhi aajein



    
    // We start with two pointers at the extreme ends of the array.
// At every step, we compare the current left and right heights.
// We move the pointer pointing to the smaller height.
//
// Why do we move the smaller side?
// Suppose left is smaller than right:
//
//      left                    right
//        ↓                       ↓
//        3                       6
//
// Here, left = 3 is the limiting boundary because:
//
//      min(leftMax, rightMax) = 3
//
// The right side is already taller (6), so it is tall enough
// to hold water up to the height of the left boundary.
// We don't care what walls exist in between.
//
// Even if there is a smaller wall somewhere in the middle,
// that wall is not the boundary for the current position.
// It is just an internal wall.
//
// Therefore, the current left position can be safely processed,
// and we move the left pointer.
//
// Similarly, if right is smaller:
//
//      left                    right
//        ↓                       ↓
//        6                       3
//
// right becomes the limiting boundary, so we process the
// current right position and move the right pointer.
//
// In short:
//
//      smaller side = limiting boundary
//      larger side  = already tall enough
//
// This is how the two-pointer approach effectively resolves
// min(leftMax, rightMax) without scanning both sides repeatedly.
    */
    
    return sum;
}



int main() {
    
    return 0;
}