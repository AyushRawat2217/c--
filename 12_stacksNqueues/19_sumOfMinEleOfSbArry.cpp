#include <bits/stdc++.h>
using namespace std;

int sumOfMInNrOfSbarryBf(vector<int>&arr){
    
    int sum=0;
    int mod=10e7;
     int minn;

    for (int i = 0; i < arr.size(); i++) {
        minn=arr[i];

      for (int j = i; j < arr.size(); j++) {
            minn=min(minn,arr[j]);

            sum+=minn;// we keep gettting subarrays


      }
        
    }
    
    return (minn % mod);
}


            //OPTIMAL APPROACH

/*logic
uss elemt ke right and left dono ke smallest lemnt tkk jana hai and
unn dono ke beech jitne bhi element aare hai unka minimjm hoga arr[i]*/


/*PSEE — Previous Smaller or Equal(we take equal elemnts as well)

For every index i:

Find the closest index to the left whose value is <= arr[i].

Example:

arr = [3, 1, 2, 5]

index:  0  1  2  3
value:  3  1  2  5

PSEE = [-1, -1, 1, 2]

*/


/*ALGORITHM

Sum of Subarray Minimums — Algorithm
For every element arr[i], find its PSEE:
Previous Smaller or Equal element.
Store its index.
If none exists, store -1.
For every element arr[i], find its NSE:
Next Smaller element.
Store its index.
If none exists, store n.

For each index i:

left  = i - PSEE[i]
right = NSE[i] - i
left × right gives the number of subarrays in which arr[i] acts as the minimum.

Calculate its contribution:

contribution = arr[i] × left × right
Add the contribution of every element.
Take modulo 1e9 + 7.
Stack rules

PSEE:

Traverse left → right
Pop while arr[stack.top()] > arr[i]

NSE:

Traverse right → left
Pop while arr[stack.top()] >= arr[i]

The difference in > vs >= handles duplicate values without counting the same subarray twice.
*/

int indexOfPrevSmallerOrEqualEle(vector<int>&arr , vector<int>&psee){

    stack<int>indStack;//stores index of the smallest elemnt at top

    for (int i = 0; i<arr.size()-1; i++) {


        while(!indStack.empty() && arr[indStack.top()]>arr[i]){
            indStack.pop();
        }

        psee[i]=!indStack.empty()?indStack.top():-1;

        indStack.push(i);
        
    }
}


void indexOfNextSmallerlEle(vector<int>&arr , vector<int>&nse){

    stack<int>indStack;

    for (int i =arr.size()-1; i>=0; i--) {

        while(!indStack.empty() && arr[indStack.top()]>=arr[i]){
            indStack.pop();
        }

        nse[i]=!indStack.empty()?indStack.top():-1;

        indStack.push(i);
        
    }
}




int sumOfMInNrOfSbarryOpt(vector<int>&arr){

    vector<int>nse;
    vector<int>psee;
    indexOfPrevSmallerOrEqualEle(arr , psee);
    indexOfNextSmallerlEle(arr , nse);

    int mod=10e9;

    int left;
    int right;
    int sum=0;
    for (int i = 0; i < arr.size(); i++) {
      left=i-psee[i];
      right=nse[i]-i;

      long long freq = left*right*1LL;
            
            // Contribution due to current element 
            int val = (freq*arr[i]*1LL) % mod;
            
            // Updating the sum
            sum = (sum + val) % mod;


    }


    return sum;
}



int main() {
    
    return 0;
}