#include <bits/stdc++.h>
using namespace std;

bool isItValidParenthesis(string result){
if(result[0]==')' || result.size()&1)return false;

int open=0;

for(auto it:result){
    if(it=='(')open++;
    else if(it==')')open--;
    if(open<0)return false;//At no point can we have more ')' than '('.
}

return(open==0);

}

void generatingParanthesis(int n ,int index, string result , vector<string>&arr){
    if(index==2*n){//as n=3 means 3 pairs of bracket that makes it 6
        if(isItValidParenthesis(result)){
            arr.push_back(result);
        }
        return;
    }

    //to build combination of paranthesis
    generatingParanthesis(n , index+1 , result+"(" , arr);
    generatingParanthesis(n , index+1 , result+")", arr);
}
//in this approach we are genrating then validatind

//in the otimal approach we are going to , validate while genrating


void generatingParanthesisOpt(int n ,int open , int index, string result ,int close , vector<string>&arr){
    if(index==n){
        arr.push_back(result);
        return;
    }

    if(open<n)generatingParanthesisOpt(n,open+1,index+1,result+'(',close ,arr );
    if(close<open)generatingParanthesisOpt(n,open,index+1,result+')',close+1 ,arr );
}

/*GENERATE PARENTHESES (n = 3) — COMPLETE DRY RUN

Function State:

curr  = string built so far
open  = number of '(' used
close = number of ')' used

Rules:

1. If open < n, we can add '('.
2. If close < open, we can add ')'.
3. When curr.length() == 2*n, store the answer.

---

## START

solve("", 0, 0)

curr=""
open=0
close=0

Can add '(' ?
0 < 3 → YES

Can add ')' ?
0 < 0 → NO

Only one branch exists.

---

## LEVEL 1

solve("(", 1, 0)

curr="("
open=1
close=0

Can add '(' ?
1 < 3 → YES

Can add ')' ?
0 < 1 → YES

Tree splits into two branches.

---

## BRANCH A

solve("((", 2, 0)

curr="(("
open=2
close=0

Can add '(' ?
2 < 3 → YES

Can add ')' ?
0 < 2 → YES

---

## BRANCH A1

solve("(((", 3, 0)

curr="((("
open=3
close=0

Can add '(' ?
3 < 3 → NO

Can add ')' ?
0 < 3 → YES

Only ')' is allowed.

---

solve("((()", 3, 1)

curr="((()"
open=3
close=1

Can add '(' ?
3 < 3 → NO

Can add ')' ?
1 < 3 → YES

---

solve("((())", 3, 2)

curr="((())"
open=3
close=2

Can add '(' ?
3 < 3 → NO

Can add ')' ?
2 < 3 → YES

---

solve("((()))", 3, 3)

curr="((()))"
length = 6

Base Case Reached

Store:
((()))

Return to previous call.

---

## BACKTRACK TO "(("

We already explored:

(((
↓
((()))

Now explore the second choice from:

curr="(("
open=2
close=0

---

## BRANCH A2

solve("(()", 2, 1)

curr="(()"
open=2
close=1

Can add '(' ?
2 < 3 → YES

Can add ')' ?
1 < 2 → YES

Again two branches.

---

## BRANCH A2.1

solve("(()(", 3, 1)

curr="(()("
open=3
close=1

Can add '(' ?
3 < 3 → NO

Can add ')' ?
1 < 3 → YES

---

solve("(()()", 3, 2)

curr="(()()"
open=3
close=2

Only ')' allowed.

---

solve("(()())", 3, 3)

Base Case

Store:
(()())

Return.

---

## BACKTRACK TO "(()"

Now explore second choice.

---

## BRANCH A2.2

solve("(())", 2, 2)

curr="(())"
open=2
close=2

Can add '(' ?
2 < 3 → YES

Can add ')' ?
2 < 2 → NO

Only '(' allowed.

---

solve("(())(", 3, 2)

curr="(())("
open=3
close=2

Only ')' allowed.

---

solve("(())()", 3, 3)

Base Case

Store:
(())()

Return.

---

## BACKTRACK TO "("

Finished entire "((" subtree.

Now explore second choice from:

curr="("
open=1
close=0

---

## BRANCH B

solve("()", 1, 1)

curr="()"
open=1
close=1

Can add '(' ?
1 < 3 → YES

Can add ')' ?
1 < 1 → NO

Only '(' allowed.

---

solve("()(", 2, 1)

curr="()("
open=2
close=1

Can add '(' ?
2 < 3 → YES

Can add ')' ?
1 < 2 → YES

---

## BRANCH B1

solve("()((", 3, 1)

Only ')' allowed.

---

solve("()(()", 3, 2)

Only ')' allowed.

---

solve("()(())", 3, 3)

Base Case

Store:
()(())

Return.

---

## BACKTRACK TO "()("

Explore second choice.

---

## BRANCH B2

solve("()()", 2, 2)

curr="()()"
open=2
close=2

Can add '(' ?
2 < 3 → YES

Can add ')' ?
2 < 2 → NO

---

solve("()()(", 3, 2)

Only ')' allowed.

---

solve("()()()", 3, 3)

Base Case

Store:
()()()

Return.

---

## FINAL ANSWERS

1. ((()))
2. (()())
3. (())()
4. ()(())
5. ()()()

IMPORTANT BACKTRACKING IDEA

At every call:

1. Choose a valid character.
2. Recurse completely down that branch.
3. Return to the current call.
4. Explore the next valid choice.

The function never "jumps" to another answer.

It reaches one answer completely, returns, and then explores the next unexplored branch of the recursion tree.

*/


int main() {
    
    return 0;
}