#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node*next;
        Node*bottom;
    
        Node(int val , Node*ptr=NULL , Node*bottm=NULL){
            data=val;
            next=ptr;
            bottom=bottm;
        }
    
};
# /*FLATTEN A LINKED LIST - PROBLEM STATEMENT

Each node contains:

```
int data;
Node* next;
Node* bottom;
```

Meaning:

```
next   -> points to the head of the next linked list
bottom -> points to the next node within the same linked list
```

Example Structure:

```
5 ------> 10 ------> 19 ------> 28
|          |          |          |
v          v          v          v
7          20         22         35
|                     |          |
v                     v          v
8                     50         40
|                                |
v                                v
30                               45
```

The horizontal chain is formed using 'next':

```
5 -> 10 -> 19 -> 28
```

The vertical chains are formed using 'bottom':

```
5 -> 7 -> 8 -> 30
10 -> 20
19 -> 22 -> 50
28 -> 35 -> 40 -> 45
```

Important Notes:

1. Each vertical list is already sorted.
2. The head nodes of these lists are connected using 'next'.
3. Nodes inside a vertical list usually have next = NULL.
4. We must flatten all these sorted lists into one sorted linked list.
5. The final flattened list should be connected using
   'bottom' pointers only.
6. After flattening, 'next' pointers are typically ignored
   or set to NULL.

Expected Output:

```
5
|
v
7
|
v
8
|
v
10
|
v
19
|
v
20
|
v
22
|
v
28
|
v
30
|
v
35
|
v
40
|
v
45
|
v
50
```

or simply:

```
5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22
-> 28 -> 30 -> 35 -> 40 -> 45 -> 50
```

(where the actual connections are through 'bottom',
not through 'next').

Goal:
Return the head of this single sorted flattened list.
*/

Node*arrToLL(vector<int>&arr){
    Node*head=new Node(arr[0]);
    Node*mover=head;
    for(int i=1;i<arr.size();i++){
        Node*newNode= new Node(arr[i]);
        mover->bottom=newNode;
        mover=newNode;
    }
    return head;
}

/*In the Flatten Linked List problem, every node contains:

    data
    next    -> horizontal connection
    bottom  -> vertical connection

Example:

    5 ------> 10 ------> 19 ------> 28
    |          |          |          |
    v          v          v          v
    7          20         22         35
    |                     |          |
    v                     v          v
    8                     50         40
    |                                |
    v                                v
    30                               45

Important observation:

Only the head nodes of each vertical list are connected using
the 'next' pointer.

    5->next  = 10
    10->next = 19
    19->next = 28

Nodes inside a vertical chain usually have next = NULL.

For example:

    7->next  = NULL
    8->next  = NULL
    30->next = NULL

and

    7->bottom  = 8
    8->bottom  = 30

So even though every node has both 'next' and 'bottom' fields,
most non-head nodes only use the 'bottom' pointer.

When traversing a vertical list, we follow only the bottom pointers:

    5 -> 7 -> 8 -> 30

The fact that a node has a 'bottom' pointer does NOT mean that
its 'next' pointer must exist. In the standard representation,
nodes like 7, 8, 20, 22, 35, etc. generally have next = NULL.

Flattening works by repeatedly merging these sorted bottom chains
into one final sorted list.
*/

/*im give a ll which has a node and node ha 3 pooin*/

Node*flatteningTheLLBf(Node*head){
    if(head==NULL)return NULL;
    vector<int>arr;
    Node*topLayer=head;
    while(topLayer){
        Node*childNode=topLayer;
        while(childNode){
            arr.push_back(childNode->data);
            childNode=childNode->bottom;
        }
        topLayer=topLayer->next;
    }
    sort(arr.begin(),arr.end());
    head=arrToLL(arr);
    return head;

}


Node*mergeTheLists(Node*l1 , Node*l2){
    //creating a dummy head
    Node*dummy=new Node(-1);
    Node*tail=dummy;

    while(l1 && l2){
        if(l1->data < l2->data){
            tail->bottom=l1;
            tail=l1;
            l1=l1->bottom;
        }
        else{
            tail->bottom=l2;
            tail=l2;
            l2=l2->bottom;
        }
        tail->next=NULL;
    }
    if(l1)tail->bottom=l1;
    if(l2)tail->bottom=l2;

    return dummy->bottom;
}
# /*
# OPTIMAL APPROACH : FLATTEN A LINKED LIST USING RECURSION + MERGE OF SORTED LISTS

## Observation:

Each vertical list (connected using 'bottom') is already sorted.

Example:

```
5 ------> 10 ------> 19 ------> 28
|          |          |          |
v          v          v          v
7          20         22         35
|                     |          |
v                     v          v
8                     50         40
|                                |
v                                v
30                               45
```

Vertical Lists:

```
L1 = 5 -> 7 -> 8 -> 30
L2 = 10 -> 20
L3 = 19 -> 22 -> 50
L4 = 28 -> 35 -> 40 -> 45
```

Notice that:

```
L1 is sorted
L2 is sorted
L3 is sorted
L4 is sorted
```

The lists are NOT sorted together:

```
30 > 10
20 > 19
50 > 28
```

Therefore we cannot simply connect them.

However, since every individual list is already sorted,
we can repeatedly MERGE sorted lists just like Merge Sort.

---

## MAIN IDEA

Instead of:

```
Collect all elements
-> Sort them again
-> Build a new list
```

we do:

```
Merge already-sorted bottom lists.
```

This avoids destroying the sorted information that already exists.

---

## RECURSIVE THINKING

Suppose the top-level list is:

```
5 -> 10 -> 19 -> 28
```

Start from the LAST list and move backwards.

Recursion Flow:

```
flatten(5)
    |
    +-- flatten(10)
            |
            +-- flatten(19)
                    |
                    +-- flatten(28)
```

Base Case:

```
If head is NULL
OR
If head->next is NULL

return head
```

Why?

Because a single bottom list is already sorted and
does not need any processing.

---

## STEP-BY-STEP DRY RUN

1. flatten(28)

   Only one list exists.

   28 -> 35 -> 40 -> 45

   Return it as it is.

---

2. flatten(19)

   We already have:

   ```
    flattenedRest =
    28 -> 35 -> 40 -> 45
   ```

   Now merge:

   ```
    19 -> 22 -> 50
   ```

   with

   ```
    28 -> 35 -> 40 -> 45
   ```

   Result:

   ```
    19 -> 22 -> 28 -> 35 -> 40 -> 45 -> 50
   ```

   Return this merged list.

---

3. flatten(10)

   We already have:

   ```
    19 -> 22 -> 28 -> 35 -> 40 -> 45 -> 50
   ```

   Merge it with:

   ```
    10 -> 20
   ```

   Result:

   ```
    10 -> 19 -> 20 -> 22 -> 28 -> 35 -> 40 -> 45 -> 50
   ```

   Return this merged list.

---

4. flatten(5)

   We already have:

   ```
    10 -> 19 -> 20 -> 22 -> 28 -> 35 -> 40 -> 45 -> 50
   ```

   Merge it with:

   ```
    5 -> 7 -> 8 -> 30
   ```

   Result:

   ```
    5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22
    -> 28 -> 30 -> 35 -> 40 -> 45 -> 50
   ```

   Return this final merged list.

---

## MERGE FUNCTION

The merge function is identical to merging two sorted linked lists.

Given:

```
A = 5 -> 7 -> 8 -> 30

B = 10 -> 20
```

Compare the current nodes of both lists:

```
5 vs 10  -> take 5
7 vs 10  -> take 7
8 vs 10  -> take 8
30 vs 10 -> take 10
30 vs 20 -> take 20
take remaining 30
```

Result:

```
5 -> 7 -> 8 -> 10 -> 20 -> 30
```

The only difference from normal linked-list merge is:

```
use 'bottom' instead of 'next'
```

---

## WHY tail->next = NULL ?

While merging, some nodes may still contain old 'next'
connections from the original structure.

The final flattened list should only use:

```
bottom pointers
```

Therefore we disconnect horizontal links:

```
tail->next = NULL;
```

This prevents accidental traversal through old next pointers.

---

## TIME COMPLEXITY

Let N be the total number of nodes.

Merging sorted lists repeatedly gives:

```
O(N * number_of_lists)   (common recursive solution)
```

For interview purposes, this is considered the standard
optimal approach because it uses the already-sorted property
of each bottom list and avoids extra sorting.

---

## RECURSION SUMMARY

Think of it as:

```
4 returns

3 merges with 4

2 merges with (3 + 4)

1 merges with (2 + 3 + 4)
```

and the final merged list is returned to the caller.
*/

/*logic
maan lo LL h 1 2 3 4
pehle 3 4 ko dekhnege 2 list ko sort krke merge krenge 
fir uske baad merged list ko 2 k saath megrge krenge and fir ultimallet 1 k saath
ye logic h and isko achieve kren k liye we will use recursion*/
Node*flatteningTheLLrecrsve(Node*head){
    if(head==NULL||head->next==NULL)return head;
    
    /*last elemnt m phuchnge ham using this recurison
    fir wo return hoga , 
    maal lo upr k elements h 1 2 3 4 
    4 tkk recursion jaaega fir 4 return hoga 
    fir 3 n 4 merge hokr ek list bnayenge , merge list ka use hokr , mergeist return krega
    new head jo ki last node m jaega and new merged head 2 k saath merge hoga similarly upr jaate jaate , ek list mil jaaegi hme*/
    Node*lastNode=flatteningTheLLrecrsve(head->next);
    return mergeTheLists(lastNode , head);
}




int main() {

    return 0;
}