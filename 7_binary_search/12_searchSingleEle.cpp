#include <bits/stdc++.h>
using namespace std;



/*
logic ye hai ki , jbtk sirf pairs exist krre h toh , repeating elemnt odd index p aata h
jese 
1 1 2 2 3 3 
dusra 1 ara index 1 p , vese hi , dusra 2 aara inddex 3 p 

prr jese hi , different elemnt aata h toh ye order break hojata h
jese 
1 1 2 2 3 4 4 
dusra 4 6 th index p aara h
toh iska mtlb ye h ki , agr dusra repeated elemnt ki index even hogyi toh mlb
distinct elemnt left side h , agr aise nhi h toh right
*/

int searchSIngleELe (vector<int>&arr ){
    int low=0;
    int high=arr.size()-1;
    int mid;

    while(low<high){ // to avoid mid+1 when mid=n-1;
        mid= low+(high-low)/2;



        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]){
            return arr[mid];
        }

        if(mid%2==1) mid--; // if mid=0 , then it doesnt do mid-1;


        // after this mid is always at a odd index so we can assume
        
        // Check pair validity
        if (arr[mid] == arr[mid + 1]) {
            // Pair is correct → single element is on right
            low = mid + 2;
        } else {
            // Pair is broken → single is here or on left
            high = mid;
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