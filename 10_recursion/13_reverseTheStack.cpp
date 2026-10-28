#include <bits/stdc++.h>
using namespace std;

# /*# REVERSE STACK USING RECURSION

## FUNCTION 1 : reachTheBottom()

Purpose:
Remove every element from the stack.

While recursion returns:
Place each removed element at the bottom.

## FUNCTION 2 : insertInStack()

Purpose:
Insert one element at the bottom of a stack.

Idea:
Keep removing elements until stack becomes empty.
Push the required value.
Restore all removed elements.

=========================================================
DRY RUN
=======

Initial Stack

Top
3
2
1

=========================================================
PHASE 1 : REMOVE EVERYTHING
===========================

reachTheBottom()

---

## Call 1

val = 3
pop 3

Stack:

Top
2
1

reachTheBottom()

---

## Call 2

val = 2
pop 2

Stack:

Top
1

reachTheBottom()

---

## Call 3

val = 1
pop 1

Stack:

[]

reachTheBottom()

---

## Base Case

Stack empty

return

At this point every element has been removed.

=========================================================
PHASE 2 : REBUILD IN REVERSE ORDER
==================================

Now recursion starts returning.

---

## Returning to Call 3

val = 1

insertInStack([], 1)

Stack is empty

push 1

Stack:

[1]

Call 3 finished.

---

## Returning to Call 2

val = 2

Current Stack:

[1]

insertInStack([1], 2)

Top = 1

Pop 1

Stack:

[]

Call insertInStack([], 2)

Stack empty

Push 2

Stack:

[2]

Return

Restore 1

Stack:

Top
1
2

Meaning:
2 has successfully reached the bottom.

Call 2 finished.

---

## Returning to Call 1

val = 3

Current Stack:

Top
1
2

insertInStack([1,2], 3)

Top = 1

Pop 1

Stack:

[2]

Call insertInStack([2], 3)

Top = 2

Pop 2

Stack:

[]

Call insertInStack([], 3)

Stack empty

Push 3

Stack:

[3]

Return

Restore 2

Stack:

Top
2
3

Return

Restore 1

Stack:

Top
1
2
3

Call 1 finished.

=========================================================
FINAL STACK
===========

Top
1
2
3

Original:

Top
3
2
1

Reversed:

Top
1
2
3

=========================================================
MENTAL MODEL
============

## reachTheBottom()

Remove everything.

## insertInStack()

Insert removed element at the bottom.

Pattern:

1. Break down stack completely.
2. While returning, keep inserting each element
   at the bottom.
3. First removed element becomes the last element.
4. Last removed element becomes the first element.

This automatically reverses the stack.

=========================================================
*/

void insertInStack(stack<int>&st , int val){
  if(st.empty()){
    st.push(val);
    return;
  }
  int topp=st.top();
  st.pop();
  insertInStack(st , val);// i will keep popping until i can placethe value at bottom
  st.push(topp);
}

void reachTheBottom(stack<int>&st){
    if(st.empty())return;
    int val=st.top();
    st.pop();
    reachTheBottom(st);//i will reach the first element

    insertInStack(st , val);
}

int main() {
    
    return 0;
}