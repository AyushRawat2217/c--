#include <bits/stdc++.h>
using namespace std;

/*WORD BREAK - RECURSION

PROBLEM:
Can the string be completely divided into dictionary words?

CORE IDEA:
At every index, try forming all possible substrings starting from that index.

If a substring exists in the dictionary:
    -> Treat it as one chosen word.
    -> Recursively check whether the remaining string can also be segmented.

WHY RECURSION IS NEEDED?
Because multiple valid words may start from the same index.

Example:
s = "cars"
dict = {ca, car, rs}

At index 0:
    "ca"  -> valid
    "car" -> valid

Choosing "car" leaves "s"     -> fails
Choosing "ca" leaves "rs"     -> succeeds

Therefore we cannot greedily choose the first valid word.
We must explore all valid choices.

RECURSIVE MEANING:

solve(index)

returns:

"Can the substring starting from index
be completely segmented into dictionary words?"

BASE CASE:
index == s.size()

Means entire string has been consumed successfully.
Return true.

CHOICE:
Form all substrings:

s[index...index]
s[index...index+1]
s[index...index+2]
...

Whenever a substring exists in dictionary:
    solve(next_index)

If any recursive call returns true:
    return true

Otherwise:
    return false

RECURSION FLOW:

takeuforward

take ✓
|
v
u ✓
|
v
forward ✓
|
v
end reached -> true

PATTERN RECOGNITION:

Use this pattern when:
"String must be divided into valid pieces"
and
"Multiple valid partitions may exist"

Similar Problems:
- Palindrome Partitioning
- Restore IP Addresses
- Expression Add Operators
- String Segmentation Problems

TEMPLATE:

for(all possible partition points)
{
    if(current substring is valid)
    {
        recurse on remaining string
    }
}

TIME COMPLEXITY (PURE RECURSION):
Exponential (~2^n)

OPTIMIZATION:
Memoize on index because the same index
gets solved repeatedly.
*/


bool recWrdBrk(unordered_set<string>&dict , string &result , string combo , int newStart){
    if(newStart==result.size()){
        return true;
    }
for (int i = newStart; i < dict.size(); i++) {
  combo+=result[i];
  if(dict.find(combo)!=dict.end()){//if found then 
       if(recWrdBrk(dict , result , "", i+1 )){
        return true;
       }//everytime combo gather charcter of result and then check whether that string is in dict or not
        //if yes acknolegge it and move towards base case
  }

  return false; //if it rreaches the end
}
    
}

int main() {
    
    return 0;
}