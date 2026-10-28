#include <bits/stdc++.h>
using namespace std;

/* problem explained
Part 1 — Maximum Consecutive Ones (LeetCode 485)

You are given only a binary array.

Find the longest consecutive sequence of 1s.

Example:

nums = [1,1,0,1,1,1]

Answer = 3

You are not allowed to change anything.

Just count the longest run of 1s.




Part 2 — Maximum Consecutive Ones II (LeetCode 487)

Now you're allowed to flip exactly one 0 to 1 (or at most one, depending on the interpretation).

Example:

nums = [1,0,1,1]

Flip the 0:

1 1 1 1

Answer = 4

Here:

Allowed flips = 1
This is equivalent to saying k = 1.





Part 3 — Maximum Consecutive Ones III (LeetCode 1004)

Now the problem becomes more general.

Instead of always allowing 1 flip, you're given a variable k.

Example:

nums = [1,0,1,0,1]
k = 2

You may flip 2 zeros.

After flipping both:

1 1 1 1 1

Answer = 5.


| Problem | Allowed flips |
| ------- | ------------- |
| Part 1  | 0 flips       |
| Part 2  | 1 flip        |
| Part 3  | `k` flips     |


*/
//this problem is part 3

int nrOf1AfterFLippingKzeroes(vector<int>&arr , int k , int n){
    int left=0;
    int right=0;
    int zeroeSoFar=0;
    int len=0;

    while(right<n){
        
        if(arr[right]==0)zeroeSoFar++;

        //once zero excedes the k limit then shrink the window until it goes back in the limit
        while(zeroeSoFar>k){
            if(arr[left]==0){
                zeroeSoFar--;
            }
            left++;
        }
        len=max(len , right-left+1);

    }
    
}


int main() {
    
    return 0;
}