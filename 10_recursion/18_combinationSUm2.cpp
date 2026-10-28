#include <bits/stdc++.h>
using namespace std;

// iss combintn sum , m combinations unique honi chiye
//ek elemnt ko do baar use ni krna 

void combinatnSum2(int index , vector<int>&arr , vector<int>result , int target){

    //base case
    if(index>=arr.size()){
        if(target==0){
            //print krdo result k andr k elemnts
        }
        return;
    }

    for (int i = index; i < arr.size(); i++) {
      if(i>index && arr[i]==arr[i-1])continue;//skip if duplicate
      //because of this skip statement i will be having only unque combinsations

      /*WHY DO WE SKIP DUPLICATES?

Example:

arr = [1,1,2]
target = 3

Without:

    if(i > ind && arr[i] == arr[i-1]) continue;

We can generate the same combination twice.

--------------------------------------------------

Branch 1:

Start with first 1

    [1]
      ↓
    [1,2]

Answer:
    [1,2]

--------------------------------------------------

Branch 2:

Start with second 1

    [1]
      ↓
    [1,2]

Answer:
    [1,2]

AGAIN!

--------------------------------------------------

Output becomes:

    [1,2]
    [1,2]

Duplicate answer.

--------------------------------------------------

To prevent this, after sorting:

    [1,1,2]

we allow only the FIRST 1 to start a branch
at a particular recursion level.

The second identical 1 is skipped because it
would generate exactly the same combinations.

IMPORTANT:

We are NOT skipping duplicates everywhere.

Example:

    [1,1]

is still allowed because the second 1 is chosen
at a DEEPER recursion level, not as another
starting branch at the same level.

Rule:

Skip duplicate STARTING choices at the same level
to avoid duplicate combinations in the output.
*/
    
      if(arr[i]>target)break;//no use

      result.push_back(arr[i]);

      combinatnSum2(i+1 , arr , result , target-arr[i]);
      //the i=0 , because of recusion creates a combination from i=0 till end
      //then after combo is made we return back to , i=0 to i<n , but now i=1 , n then skipping happens
      //koi bhi doubt aaya recusion m basic funda is to dry run

      //after returning it will come back again here from index+1 to index because the pervios call was not completed , it would only get comoleted once
      //the ith oteration gets over
      //and i dont need to do pop back because im passing it a value 

    }
}


int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin() , arr.end());//sort it so i can skip the elemnts

    return 0;
}