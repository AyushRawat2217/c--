#include <bits/stdc++.h>
using namespace std;
/*
first task is merging both arrays
*/

int mediaOfTwoSortedArraysBf(vector<int>&arr1 , vector<int>arr2){
    int n1=arr1.size();
    int n2=arr2.size();
    vector<int>arr3(n1+n2);
    int median;
    for (int i = 0; i < n1+n2; i++) {

      if(i<n1)arr3[i]=arr1[i];
      else arr3[i]=arr2[i-n1];
    }

    sort(arr3.begin() , arr3.end());
    

    int n=n1+n2;
    if ((n)%2==0){
        median=(arr3[n/2] + arr3[n/2 - 1]) / 2.0;

    }
    else median = arr3[(n1+n2+1)/2];

    return median;


}


/*the ogic of approach is we dvide the two arrays in 2 partions eaxh and then recombine the 4 
components such a way that we get a sorted array and using binary search we
 regulate the sorted length*/

int mediaOfTwoSortedArraysOpt(vector<int>&arr1 , vector<int>arr2){

    int n1=arr1.size();
    int n2=arr2.size();

    int n3=n1+n2;

    //why we need smaller array for bin search
    /*
    while we do binary search me must do it from smaller array
    lets say we take bigger array
    A = [1 2 3 4 5 6 7 8]
    B = [9 10]

    now if need to keep a half of length 5 as total length is 10
    and low=0 , high=7
    if mid ever become high or more than half length during binary search
    lets say 7
    then program says 7 elemnts from A and to make it 5  , -2 elemnts from 
    smaller aaray mathematically incorrect thats why take smaller array and
    
    if n1 <= n2
    then n1 <= (n1+n2+1)/2
    
    */

    if(n1<n2){
        mediaOfTwoSortedArraysBf(arr2 , arr1);//swaps the array such a way that
        //smaller array is used as arr1
    }

    //from here we have arr1 as smaller array and n1 as smaller array length
    int low=0;
    int high=n1-1;

    while(low<=high){
        int cut1= (low+high)/2;
        int cut2=((n1+n2+1)/2)-cut1;
        //half of the final array - cut1

        int left1= (cut1==0)?INT_MIN:arr1[cut1-1];
        /*
        agr cut1 zero h mlb koi elemnt ni liya arr1 s
        toh baad m left1<=right2 m dikkat na ho isliye right se chota
        nr lere h same baaki k liye krenge
        */

        int right1= (cut1==n1)?INT_MAX:arr1[cut1];

        int left2= (cut2==0)?INT_MIN:arr1[cut2-1];

        int right2= (cut2==n2)?INT_MAX:arr1[cut2];


        //checking the components 
        //fitting which way they make the sorted array


        if(left1<=right2 && left2<=right1){ 
            /*This condition guarantees sorted order:

left1 <= right2
&&
left2 <= right1

Why only these two checks?

Because arrays are already individually sorted.

So if boundary elements satisfy order, entire partitions satisfy order.*/
            
            if(n3%2==0){
                return ((max(left1 , left2))+min(right1 , right2))/2;
                
            }

            else return max(left1 , left2);
        }


        else if( left1>right2) high=cut1-1; //equivalent of mid-1

        else low=cut1+1;

    }

    return 0;

    
}


int main() {
    
    return 0;
}



/*binary search helps with merging two sorted arrays because
Binary search is NOT searching for kth element.

It is searching for:
“How many elements should smaller array contribute
to the first k elements?”


we just need the boundary elemnts to fit the pieces


*/