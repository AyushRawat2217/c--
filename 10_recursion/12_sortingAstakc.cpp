#include <bits/stdc++.h>
using namespace std;


# /*# SORT A STACK USING RECURSION

## INTUITION

We cannot use any extra data structure.

Idea:

1. Remove all elements using recursion.
2. While recursion returns, insert each element into its
   correct position in the already sorted stack.

Think of it as:

```
BREAK DOWN  -> createSortedStack()
BUILD BACK  -> insertInSortedStack()
```

---

## ROLE OF EACH FUNCTION

## sortStack()

Purpose:
Takes the stack to the smallest possible state
(empty stack).

Work:
- Pop top element.
- Recursively sort remaining stack.
- Insert popped element back in sorted position.

## insertSorted()

Purpose:
Insert one element into an already sorted stack.

Assumption:
Stack is already sorted.

Work:
- If current position is correct, push element.
- Otherwise pop larger elements.
- Recursively find correct position.
- Restore popped elements.

---

## ALGORITHM

sortStack(st)

1. If stack is empty:
   return

2. Store top element in temp.

3. Pop top element.

4. Recursively sort remaining stack.

5. Insert temp into its correct position using
   insertSorted().

---

insertSorted(st, x)

1. If stack is empty OR top <= x:
   push x
   return

2. Store top in temp.

3. Pop top.

4. Recursively insert x.

5. Push temp back.

---

## DRY RUN

Initial Stack:

Top
2
4
1
3

---

## PHASE 1 : BREAK DOWN

sortStack()

Pop 2

Top
4
1
3

↓

Pop 4

Top
1
3

↓

Pop 1

Top
3

↓

Pop 3

[]

↓

Base Case Reached
return

---

## PHASE 2 : BUILD BACK

Returning to call that removed 3

insertSorted([], 3)

[3]

---

Returning to call that removed 1

insertSorted([3], 1)

1 should be below 3

[1,3]

---

Returning to call that removed 4

insertSorted([1,3], 4)

4 belongs at top

[1,3,4]

---

Returning to call that removed 2

insertSorted([1,3,4], 2)

Pop 4
Pop 3

[1]

Push 2

[1,2]

Restore 3

[1,2,3]

Restore 4

[1,2,3,4]

---

## FINAL STACK

Top
4
3
2
1

(Stack sorted in ascending order from bottom to top)

---

## IMPORTANT RECURSION PATTERN

sortStack(smaller problem);

do work while returning;

This same pattern appears in:

1. Sort Stack
2. Reverse Stack
3. Delete Middle of Stack
4. Recursive Insertion Sort

Mental Model:

sortStack()
= Remove everything.

insertSorted()
= Rebuild in sorted order.
==========================

*/

void insertInSortedStack(stack<int>&st , int temp){
    if(st.empty()||st.top()<=temp){
        st.push(temp);
        return;
    }
    //otherwise
    int val=st.top();//if top elemnt come out as bigger than temp
    st.pop();
    insertInSortedStack(st , temp);//recursively  check which place suits the temp , if temp get the place it will return back at the call after inserting temp using base case

    st.push(val);//insert back the values
}

void createSortedStack(stack<int>&st){
    if(st.empty())return;

    int val=st.top();//to get the first elemnt in hand
    st.pop();
    createSortedStack(st);

    insertInSortedStack(st , val);
}


int main() {
    
    return 0;
}