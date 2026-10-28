#include <bits/stdc++.h>
using namespace std;
//brute force taking a non zero elemnt stacking them first then stacking the 0 elemnts at last
//two traverals , one extra data structure it will need 


//optimal approach
// keep a pointer at y =0 and i =0 , then move the
//pointer first zero , then i also moves , then i checks
//which elemnt is non zero and waps with j

void zeroAtend(vector<int>&arr , int n){
    int j=0;


   while (j < n && arr[j] != 0) {
    j++;
}





for(int i=j+1;i<n;i++){
    if(arr[i]!=0){
        swap(arr[i],arr[j]);
        j++;
        

        //dry run krio
      
    }

}

    
   

}

/*
⚔️ Scenario

You’re asking:

What if the second zero is at index 3?

Example:

[1, 2, 0, 0, 3, 4]
         ↑  ↑
        j   second zero
🧠 Step-by-Step Execution
Phase 1 — Find first zero
j = 2
🔍 Now the loop begins
i = 3 → arr[3] = 0 (second zero)
if(arr[i] != 0) ❌ false

👉 Nothing happens.
👉 No swap.
👉 j stays at 2.

i = 4 → arr[4] = 3 (non-zero)
swap(arr[4], arr[2])

Array becomes:

[1, 2, 3, 0, 0, 4]

Then:

j = 3
i = 5 → arr[5] = 4 (non-zero)
swap(arr[5], arr[3])

Array becomes:

[1, 2, 3, 4, 0, 0]

Then:

j = 4
🎯 Final Output
[1, 2, 3, 4, 0, 0]
⚔️ Key Insight

Multiple zeros don’t matter.

Why?

Because:

You only care about filling the earliest zero (j)
Extra zeros are just empty slots waiting to be filled later*/






int main() {
   int n;
    cin >> n;
  
    vector<int> arr(n); //either specify size of vector or use pushback  

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }


     


    zeroAtend(arr,n);

      for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }


return 0;
}