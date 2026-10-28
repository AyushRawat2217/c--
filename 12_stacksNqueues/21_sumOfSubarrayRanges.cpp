#include <bits/stdc++.h>
using namespace std;


int sumOfSBarryRangesBf(vector<int>&arr){

    int sum=0;

    int minn=INT_MAX;
    int maxx=INT_MIN;


    for (int i = 0; i < arr.size(); i++) {

        for (int j= i; j < arr.size(); j++) {
            minn=min(minn , arr[j]);
            maxx=max(maxx , arr[j]);

            sum+= (maxx-minn);//as subarray keep growing righgt at that time do the maxx - minn

        }
    }
    return sum;
}


            //OPTIMAL APPROACH USING STACKS


int sumOfSbarryRangesOpt(vector<int>&arr){
    int maxSum=sumOfSbarryMax(arr);
    int minSum=sumOfSbarryMin(arr);

    return maxSum-minSum;

}


int sumOfSbarryMax(vector<int>&arr){
    
     vector<int>resultNse(arr.size() , -1);
     vector<int>resultPsee(arr.size() , -1);

     nextGreaterELe(arr , resultNse);
     GreaterPsee(arr , resultPsee);

     int leftEleArrIisMaxFrom;
     int rightEleArrIisMaxFrom;
     int subArraysWhichArrIisMaxIn;
     int maXsum=0;

     for (int i = 0; i < arr.size(); i++) {
       leftEleArrIisMaxFrom=i-resultPsee[i];
       rightEleArrIisMaxFrom=resultNse[i]-i;

       subArraysWhichArrIisMaxIn=leftEleArrIisMaxFrom*rightEleArrIisMaxFrom;

        maXsum+=subArraysWhichArrIisMaxIn*arr[i];


     }

     return maXsum;


}



void nextGreaterELe(vector<int>&arr , vector<int>&resultNse){

    stack<int>stIndex;//store indexes
    stIndex.push(arr.size()-1);
    

    for (int i = arr.size()-2; i >=0; i++) {
        //agr barabar bhi ho toh bhi hata do use
        while(!stIndex.empty() && arr[stIndex.top()]<=arr[i]){//jbtk top bada hai , kyuki we need the smaller element and jis point pe
            //stack is not empty  and we know that uss index wala elemnt is smaller so we store that in result index
            stIndex.pop();
        }
        if(!stIndex.empty())resultNse[i]=stIndex.top();

        stIndex.push(i);
        
    }
}

void GreaterPsee(vector<int>&arr , vector<int>&resultPsee){//previous smaller or equal elemnt

    stack<int>stIndex;//store indexes
    stIndex.push(arr.size()-1);
    

    for (int i = arr.size()-2; i >=0; i++) {
    
        while(!stIndex.empty() && arr[stIndex.top()]<arr[i]){//jbtk top bada hai , kyuki we need the smaller element and jis point pe
            //stack is not empty  and we know that uss index wala elemnt is smaller so we store that in result index
            stIndex.pop();
        }
        if(!stIndex.empty())resultPsee[i]=stIndex.top();

        stIndex.push(i);

    }

}


int sumOfSbarryMin(vector<int>&arr){
      
     vector<int>resultNse(arr.size() , -1);
     vector<int>resultPsee(arr.size() , -1);

     nextSmallestELe(arr , resultNse);
     SmallestPsee(arr , resultPsee);

     int leftEleArrIisMinFrom;
     int rightEleArrIisMinFrom;
     int subArraysWhichArrIisMaxIn;
     int miNsum=0;

     for (int i = 0; i < arr.size(); i++) {
       leftEleArrIisMinFrom=i-resultPsee[i];
       rightEleArrIisMinFrom=resultNse[i]-i;

       subArraysWhichArrIisMaxIn=leftEleArrIisMinFrom*rightEleArrIisMinFrom;

        miNsum+=subArraysWhichArrIisMaxIn*arr[i];


     }

     return miNsum;

}
void SmallestPsee(vector<int>&arr ,vector<int>&resultPsee ){//previous smaller or equal elemnt

    stack<int>stIndex;//store indexes
    stIndex.push(arr.size()-1);
    vector<int>resultPsee(arr.size() , -1);

    for (int i = arr.size()-2; i >=0; i++) {
    
        while(!stIndex.empty() && arr[stIndex.top()]>arr[i]){//jbtk top bada hai , kyuki we need the smaller element and jis point pe
            //stack is not empty  and we know that uss index wala elemnt is smaller so we store that in result index
            stIndex.pop();
        }
        if(!stIndex.empty())resultPsee[i]=stIndex.top();

        stIndex.push(i);

    }


}


void nextSmallestELe(vector<int>&arr , vector<int>&resultNse){

    stack<int>stIndex;//store indexes
    stIndex.push(arr.size()-1);
  

    for (int i = arr.size()-2; i >=0; i++) {
        //agr barabar bhi ho toh bhi hata do use
        while(!stIndex.empty() && arr[stIndex.top()]>=arr[i]){//jbtk top bada hai , kyuki we need the smaller element and jis point pe
            //stack is not empty  and we know that uss index wala elemnt is smaller so we store that in result index
            stIndex.pop();
        }
        if(!stIndex.empty())resultNse[i]=stIndex.top();

        stIndex.push(i);
        
    }

}



/*Sum of Subarray Ranges — Logic for Revision

Main formula:

Sum of Subarray Ranges
= Sum of all Subarray Maximums − Sum of all Subarray Minimums

Instead of generating every subarray, find the contribution of every element.

For an element arr[i]:

Contribution = arr[i] × number of choices on the left × number of choices on the right

1. Finding contribution as a Maximum

For every element, find:

Previous Greater or Equal → tells how far we can extend to the left.
Next Greater → tells how far we can extend to the right.

If:

previous greater/equal is at P
next greater is at N

then:

Left choices = i − P
Right choices = N − i

Therefore:

Number of subarrays where arr[i] is maximum:

(i − P) × (N − i)

So its maximum contribution is:

arr[i] × (i − P) × (N − i)

Add the contribution of every element → sum of all subarray maximums.

2. Finding contribution as a Minimum

Same idea, but now find:

Previous Smaller or Equal → left boundary.
Next Smaller → right boundary.

If:

previous smaller/equal is at P
next smaller is at N

then:

Left choices = i − P
Right choices = N − i

Number of subarrays where arr[i] is minimum:

(i − P) × (N − i)

Minimum contribution:

arr[i] × (i − P) × (N − i)

Add every element's contribution → sum of all subarray minimums.

3. Why use different equality conditions?

For maximum:

Previous ≥ and Next >

For minimum:

Previous ≤ and Next <

This is important when there are duplicate elements.

It gives each subarray a unique element responsible for its maximum/minimum and prevents double counting.

4. Monotonic Stack Pattern

Remember:

Previous → traverse Left to Right

Because we are searching toward the left.

Next → traverse Right to Left

Because we are searching toward the right.

Final Mental Model

Think:

“For every element, how many subarrays consider this element the maximum? How many consider it the minimum?”

Count those subarrays using:

left choices × right choices

Then:

Total Range = Total Maximum Contribution − Total Minimum Contribution

Time complexity: O(n)
Space complexity: O(n)
*/







int main() {
    
    return 0;
}