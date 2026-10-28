#include <bits/stdc++.h>
using namespace std;

/*We keep exactly k elements on the LEFT side.

Binary search decides how many of those k
should come from the smaller array.

For every split, we check partition validity:

l1 <= r2
l2 <= r1

If valid:
all left-side elements <= all right-side elements

So the kth smallest element becomes:
max(l1,l2)*/

int kthElemntOf2sortedArraysBinSearch(vector<int>&arr1,vector<int>&arr2 , int k){

int n1=arr1.size();
int n2=arr2.size();
int n3=n1+n2;

if(n1>n2) return (kthElemntOf2sortedArraysBinSearch(arr2 , arr1 , k));

int low=max(0 , k-n2);
/*itne elemnts to de ki
dusri array prr burden na pde
maan lo k=6 h , tumne low=0 rkha h and dusri array m elemnt hi 4 h 
toh bta left m 6 kese aayenge koi point ni h aisa low hone ka similarly h high ka explaination
maan lo k =6 h and and n1 hi 4 h , toh kbhi cut 1 =6 aaya
toh mathematically incorrect hojaega poora scene*/
int high=min(k , n1);

while(low<=high){
    int cut1=(low+high)/2;
    int cut2=k-cut1; //itne hi elemnts chiye ki left m k hojaein poore

    int left1=(cut1==0)?INT_MIN:arr1[cut1-1];
    int left2=(cut2==0)?INT_MIN:arr2[cut2-1];
    int right1=(cut1==n1)?INT_MAX:arr1[cut1];
    int right2=(cut2==n2)?INT_MAX:arr2[cut2];

     if(left1<=right2 && left2<=right1){

        return max(left1 , left2);

        /*Which are the biggest candidates on left side?

Only:

l1 and l2

Why?

Because arrays are sorted.

So:

biggest element from A-left = l1
biggest element from B-left = l2

Thus overall biggest left element is:

max(l1,l2)

That becomes kth smallest.

Visualize
LEFT SIDE:

A -> ... l1
B -> ... l2

Since arrays are sorted:

Nothing before l1 can be bigger than l1
Nothing before l2 can be bigger than l2

So kth element must be:

max(l1,l2)

That is the logic.*/
        
}


    if(left1>right2) high=cut1-1;
    else low=cut1+1;


}






}

int main() {
    
    return 0;
}