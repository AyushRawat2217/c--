#include <bits/stdc++.h>
using namespace std;

/*
in this question duplicates are there and point is how 
the logic wil be different because of it

for ex-:

if 3 , 1 ,2 ,3 ,3 3 3
here low is 3 , mid is 3 , and mid and low are 
equal but we cant determine its sorted or not

and mid=high too , similarly we cant determine wherther elemnts in it are sorted or not

so what we do is
 if arr low== arr mid ==arr high
 then we trim the search space from low and high
 that is we do low++ and high-- , because low n high elemnt dont hold
 any value of fiding x until ther are x , we can trim the space and continue 
 with our prev logic of finding unique elemnt


 whener ques like duplicate comes , first think it as unique then later
 modify it accoding to the edge case of duoplicate

*/

int searchELeInRotatedArr(vector<int>&arr , int x){
    int low=0;
    int high=arr.size()-1;
    int mid;
    

    while(low<=high){
        mid=(low+high)/2;

        if(arr[low]==arr[mid] && arr[high]==arr[mid]){
            low++; //trimmimg the search space
            high--;

            continue; //repeating the same thing until we have unique elemnt at all three places
            //now we can continue with normal code

        }

        if(arr[mid]==x){
            return mid; //search space will be minimised til that point that we get mid if present
        }

       
        else if(arr[low]<=arr[mid]){//left half is sorted
            if(arr[low]<=x && arr[mid]>x){ //means x is in left half
                high=mid-1;
            }
            else{ //though it sorted its possible that x is not in this search space
                low=mid+1; //if not in left half then in right half
            }
        }

        else{ //right half sorted
            if(arr[mid]<x && arr[high]>=x){ //means x is in right half
                low=mid+1;
            }
            else{ //though it sorted its possible that x is not in this search space
                high=mid-1; //if not in right then in left
            }
        }

        //= didnt come with < &> mid because , we are handling arr[mid]==x already

        
    }

    return -1;
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