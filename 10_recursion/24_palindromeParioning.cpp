#include <bits/stdc++.h>
using namespace std;

bool isItPalndrm(string &s){

}

/*Gneric templatate from problem include words like all possible chices atc
solve(start)
{
    if(start reached end)
    {
        store answer;
        return;
    }

    for(each possible choice from start)
    {
        if(choice is valid)
        {
            take choice;

            solve(next position);

            undo choice;
        }
    }
}*/

void palindromePartioning(vector<string>palndromes , vector<vector<string>>&result , string &s ,int index  ){
    if(index==s.size()){//base case
        result.push_back(palndromes);
        return;
    }

    for (int partitionPoint = index; partitionPoint < s.size(); partitionPoint++) {
      string substring = s.substr(index , partitionPoint-index+1);

      if(isItPalndrm(substring)){

        palndromes.push_back(substring);

        palindromePartioning(palndromes ,result , s , partitionPoint+1 );

      }
    }
}

/* recursion tree
solve(0)
│
├── "a"
│   │
│   └── solve(1)
│       │
│       ├── "a"
│       │   │
│       │   └── solve(2)
│       │       │
│       │       └── "b"
│       │           │
│       │           └── solve(3)
│       │               │
│       │               ├── "a"
│       │               │   │
│       │               │   └── "a"
│       │               │       │
│       │               │       └── ✓ ["a","a","b","a","a"]
│       │               │
│       │               └── "aa"
│       │                   │
│       │                   └── ✓ ["a","a","b","aa"]
│       │
│       └── "aba"
│           │
│           └── solve(4)
│               │
│               └── "a"
│                   │
│                   └── ✓ ["a","aba","a"]
│
├── "aa"
│   │
│   └── solve(2)
│       │
│       └── "b"
│           │
│           └── solve(3)
│               │
│               ├── "a"
│               │   │
│               │   └── "a"
│               │       │
│               │       └── ✓ ["aa","b","a","a"]
│               │
│               └── "aa"
│                   │
│                   └── ✓ ["aa","b","aa"]
│
└── "aabaa"
    │
    └── ✓ ["aabaa"]
    
*/

int main() {
    
    return 0;
}