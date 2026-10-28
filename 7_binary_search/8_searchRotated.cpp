#include <bits/stdc++.h>
using namespace std;

//search elemnt in a rotated array , using binary search
//rotated array is unsorted by a pivot point

int searchELeInRotatedArr(vector<int>&arr , int x){
    int low=0;
    int high=arr.size()-1;
    int mid;
    

    while(low<=high){
        mid=(low+high)/2;

        if(arr[mid]==x){
            return mid; //search space will be minimised til that point that we get mid if present
        }

       
        else if(arr[low]<=arr[mid]){//left half is sorted
            if(arr[low]<x && arr[mid]>x){ //means x is in left half
                high=mid-1;
            }
            else{ //though it sorted its possible that x is not in this search space
                low=mid+1; //if not in left half then in right half
            }
        }

        else{ //right half sorted
            if(arr[mid]<x && arr[high]>x){ //means x is in right half
                low=mid+1;
            }
            else{ //though it sorted its possible that x is not in this search space
                high=mid-1; //if not in right then in left
            }
        }

        
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