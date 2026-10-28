#include <bits/stdc++.h>
using namespace std;

void powerSet(string s , int index ,vector<string>ps , string &subset )//&subset , passing it as refrence is imp , if i passs it as value than code significantly changes
{//s is the input , subset being the elemnt whih will be inside the powerset
    if(index==s.size()){
        ps.push_back(subset);
        return;
    }
    subset+=s[index];
    powerSet(s,index+1,ps,subset);//taking the occurences 
    //after taking all occurences once returned it move to last call , it will move to erase stament removing the last elemnt , then it goes to 
    //last line does the work return
    //it return back to 3rd line as that was last second call , remove last second elemnt
    subset.erase(s[index]);
    powerSet(s,index+1,ps,subset);
}
/*=========================================================
WHY NO erase() / pop_back() IS NEEDED (PASS BY VALUE)
=========================================================

In this solution, 'subset' is passed BY VALUE:

    void powerSet(..., string subset)

Every recursive call receives its OWN COPY of subset.

Example:

powerSet("ab", 0, ps, "")

Call 1:
    subset = ""

Take 'a':
    subset = "a"

    powerSet(..., "a")  <-- child gets a COPY

---------------------------------------------------------

Child Call:
    subset = "a"

Take 'b':
    subset = "ab"

    powerSet(..., "ab")

Child returns.

---------------------------------------------------------

After return:

Parent Call:
    subset = "a"

NOT "ab" !

Reason:
The child modified its own copy only.
The parent's subset was never changed.

---------------------------------------------------------

Because each recursive call has its own copy:

    ""
      └── "a"
             └── "ab"

When "ab" returns, that copy is destroyed.

Parent automatically goes back to:

    "a"

No erase() or pop_back() is required.

=========================================================
WHEN IS pop_back() NEEDED?
=========================================================

When subset is passed BY REFERENCE:

    void powerSet(..., string& subset)

Now all recursive calls share the SAME string.

Example:

    subset.push_back('a');   // subset = "a"

    recursive call

    subset.push_back('b');   // subset = "ab"

    return

After return:

    subset is STILL "ab"

To restore previous state:

    subset.pop_back();       // subset = "a"

This manual restoration step is called BACKTRACKING.

=========================================================
RULE
=========================================================

Pass By Value:
    -> Every call gets a copy
    -> State restores automatically
    -> No pop_back() needed

Pass By Reference:
    -> State is shared
    -> Must undo changes
    -> pop_back()/erase() required
=========================================================
*/

/*=========================================================
GENERATING SUBSEQUENCES USING BIT MASKING
=========================================================

Idea:

Every character has 2 choices:

    1. Take it
    2. Don't take it

For n characters:

    Total subsequences = 2^n

We represent each choice pattern using a binary number
(mask).

---------------------------------------------------------
Example:
---------------------------------------------------------

s = "abc"

Index:

    0 1 2
    a b c

Total subsequences:

    2^3 = 8

Masks:

    0 -> 000
    1 -> 001
    2 -> 010
    3 -> 011
    4 -> 100
    5 -> 101
    6 -> 110
    7 -> 111

---------------------------------------------------------
Meaning Of Bits
---------------------------------------------------------

1 = Take character
0 = Don't take character

Example:

    mask = 5

Binary:

    101

    a b c
    1 0 1

Take:
    a
    c

Skip:
    b

Subsequence:

    "ac"

---------------------------------------------------------
Algorithm
---------------------------------------------------------

For every mask from 0 to (2^n - 1):

    Create an empty subsequence.

    Check every bit position.

    If i-th bit is set:

        Take s[i]

    Else:

        Skip s[i]

    Store the formed subsequence.

---------------------------------------------------------
Code Meaning
---------------------------------------------------------

    (1 << n)

means:

    2^n

Example:

    1 << 3 = 8

---------------------------------------------------------

    mask & (1 << i)

checks whether the i-th bit is set.

If true:

    Include s[i]

If false:

    Skip s[i]

---------------------------------------------------------
Dry Run
---------------------------------------------------------

s = "abc"

mask = 6

Binary:

    110

    a b c
    0 1 1

Take:
    b
    c

Skip:
    a

Result:

    "bc"

---------------------------------------------------------
Complexity
---------------------------------------------------------

Outer Loop:
    2^n masks

Inner Loop:
    n bits checked per mask

Time Complexity:
    O(n * 2^n)

Space Complexity:
    O(1) extra
    (excluding answer storage)

---------------------------------------------------------
Recognition Pattern
---------------------------------------------------------

Use Bit Masking when:

    - n is small (typically <= 20)
    - Need all subsets/subsequences
    - Each element has:
          Take / Don't Take choice
    - Looking for iterative alternative to recursion
=========================================================
*/
void powerSetBitWay(vector<string>pS,string s , int n){

    for (int i = 0; i < (1<<n); i++) { //1<<n can be written as 2^n
      string subSq;

      for (int j = 0; j < n; i++) {//j is the index
        if(i&(1<<j)!=0)subSq+=s[i];
        /* How its done?
arr = {10, 20, 30, 40}
index  3  2  1  0

Suppose mask = 13

13 = 1101₂

Bit Position : 3  2  1  0
Mask Bits    : 1  1  0  1
Array Index  : 3  2  1  0

Decision:
bit 0 = 1 -> Take arr[0] = 10
bit 1 = 0 -> Skip arr[1] = 20
bit 2 = 1 -> Take arr[2] = 30
bit 3 = 1 -> Take arr[3] = 40

Subset formed = {10, 30, 40}

Check each bit using:

j = 0: mask & (1<<0) = 1101 & 0001 = 0001 -> Take
j = 1: mask & (1<<1) = 1101 & 0010 = 0000 -> Skip
j = 2: mask & (1<<2) = 1101 & 0100 = 0100 -> Take
j = 3: mask & (1<<3) = 1101 & 1000 = 1000 -> Take
*/
      }
      pS.push_back(subSq);
    }

}
int main() {
    
    return 0;
}