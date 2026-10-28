#include <bits/stdc++.h>
using namespace std;

void moveZeroToend(vector<int>&arr , int n){
    int goingaToBeZeroPtr=0; //j
/*This invariant is exactly what proves correctness: every time a non-zero element is found, it is placed at position j,
 the next available slot in the non-zero prefix. Thus, all non-zero elements end 
up compacted at the front while preserving order, and all zeros naturally move to the end.*/

    for (int nonZero = 0; nonZero < n; nonZero++) {//i
      if(arr[nonZero]!=0){
        swap(arr[goingaToBeZeroPtr], arr[nonZero]);
        goingaToBeZeroPtr++;
      } 
       }
       /*logic
       jbh bhi non zero aaega starting me  , nonzero n going2bzero same elemnt
       ko point krenge , jbh bhi ek zero aaega , usme alredy going2bezero pt krra hoga kyuki
       previous iteration m hmne usko increment kiya h , and jo nonzeroptr hoga wo move krega
       prr kuch swap ni hoga , nonzero and going2bezero 0 ko point krre honge , fir next iteration m jbh non zero elemnt aaega toh
       nonzero and o jisko going to be zero point krra h wo swap hoajega
       this keep happening
       */

       /*Dry Run Idea:

j points to the position where the next non-zero element should go.

Initially, if we keep seeing non-zero elements,
i and j point to the same element, so swapping changes nothing.
We simply increment j.

When a zero is encountered, j stops on that zero.

Now i continues moving forward.
When i finds the next non-zero element,
it swaps with arr[j] (the zero).

As a result:
- the non-zero element moves forward,
- the zero moves back.

Then j is incremented and again points to the next position
where a non-zero element should be placed.

This process repeats until all non-zero elements are grouped
at the front and all zeros are pushed to the end.

1 2 3 0 5 0 7

      j
1 2 3 0 5 0 7

i finds 5
swap(5, 0)

1 2 3 5 0 0 7
        j

i finds 7
swap(7, 0)

1 2 3 5 7 0 0
          j
*/
    
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    moveZeroToend(arr , arr.size());

    for(int i:arr)cout<<i<<" ";
    return 0;
}