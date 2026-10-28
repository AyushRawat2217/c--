#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node*next;
        Node*random;
    
        Node(int val , Node*ptr=NULL , Node*rndm=NULL){
            data=val;
            next=ptr;
            random=rndm;
        }
    
};

/*CLONE LINKED LIST WITH NEXT AND RANDOM POINTER

Problem:
---------
Each node contains:
1. next   -> points to the next node in the list.
2. random -> points to any node in the list (or NULL).

We must create a DEEP COPY of the list.

Deep Copy Meaning:
------------------
For every original node, create exactly ONE new node having the same value.

Example:

Original:
1 -> 2 -> 3

Copy:
1' -> 2' -> 3'

Values are same, but memory locations are different.

1 != 1'
2 != 2'
3 != 3'

The copied list must be completely independent of the original list.


Important Realization:
----------------------
The challenge is NOT copying values.

Copying values is easy.

The challenge is preserving the RANDOM POINTER RELATIONSHIPS.

Example:

Original:
1 -> 2 -> 3

random:
1 -> 3
2 -> 3

Correct Copy:
1' -> 2' -> 3'

random:
1' -> 3'
2' -> 3'

Notice both random pointers point to the SAME copied node (3').


Common Doubt:
-------------
"Why can't I simply create a new node with the same value whenever
I encounter a random pointer?"

Example:

Original:
1 -> 2 -> 3

random:
1 -> 3
2 -> 3

Wrong Approach:

1'.random -> new Node(3)
2'.random -> new Node(3)

This creates:

1'.random -> X(3)
2'.random -> Y(3)

where X and Y are different nodes.

But in the original list both random pointers point to the SAME node.

Therefore the structure of the copied list becomes incorrect.


Another Important Point:
------------------------
A random pointer points to a NODE, not to a VALUE.

Multiple nodes may have the same value.

Example:

7 -> 7 -> 7

If random points to the third node,
the value alone does not tell us which node to connect to.

Hence values cannot uniquely identify nodes.


Core Requirement:
-----------------
For every original node, there must exist exactly one corresponding
copied node.

Conceptually:

Original Node A ---> Copy Node A'
Original Node B ---> Copy Node B'
Original Node C ---> Copy Node C'

Then:

copy->random = copy of (original->random)

To achieve this efficiently we need a way to find:
"Given an original node, where is its copy?"

This is why solutions use:
1. HashMap (Original Node -> Copied Node)
or
2. O(1) Space Interleaving Technique.


Key Learning:
-------------
We are not merely copying node values.

We are cloning the entire pointer structure formed by:
- next pointers
- random pointers

The copied list must behave exactly like the original list,
while consisting of completely new nodes in memory.
*/

/*deep copy mlb copy aisi kro ki original list jesa hi ho 
bss memory location different ho*/

/*bf approach
ye h ki we will create a map with keys as actual nodes
and values as copied nodes
aur original linked list ka refrence lekr ham key ki jgh copied valuesshift krdenge
isme aisa hoga ki connection preserve rhega*/

/*APPROACH : HASHMAP (ORIGINAL NODE -> COPIED NODE)

Idea:
-----
The main difficulty in this problem is the random pointer.

While copying a node, we may know that:

original->random = someNode

but we need:

copy->random = copyOfSomeNode

Therefore, we need a way to quickly find the copied version
of any original node.

We store this mapping in a HashMap:

Original Node ----> Copied Node


STEP 1 : Create all copied nodes
--------------------------------
Traverse the original list once.

For every original node:
    - Create a new node with the same value.
    - Store the mapping:

      mpp[originalNode] = copiedNode

Example:

Original:
1 -> 2 -> 3

Map:
1 -> 1'
2 -> 2'
3 -> 3'

At this point only nodes are created.
next and random pointers are not connected yet.


STEP 2 : Connect next and random pointers
-----------------------------------------
Traverse the original list again.

For every original node:

1. Connect next pointer

   copy->next = copy of(original->next)

   Using the map:

   mpp[original]->next = mpp[original->next]


2. Connect random pointer

   copy->random = copy of(original->random)

   Using the map:

   mpp[original]->random = mpp[original->random]

Since the map already contains the copied version of every
original node, both pointers can be connected in O(1)
average time (using unordered_map).


Why this works:
---------------
Each original node gets exactly one copied node.

Whenever multiple nodes point to the same original node
through random pointers, they will all point to the same
copied node because the map always returns the same copy.

Thus the complete pointer structure of the original list
is preserved in the cloned list.


Complexity:
-----------
Using map:
    Time  = O(N log N)
    Space = O(N)

Using unordered_map:
    Time  = O(N) average
    Space = O(N)
*/

Node*deepCopyingTheLLBf(Node*head){
    unordered_map<Node* , Node*>mpp;
    Node*originalNode=head;
    while(originalNode){
        Node*copiedNode=new Node(originalNode->data);
        mpp[originalNode]=copiedNode;
        originalNode=originalNode->next;
    }

    originalNode=head;
    while(originalNode){

        //if it exist do it otherwise do NULL
        mpp[originalNode]->next =
            originalNode->next ? mpp[originalNode->next] : NULL;

        mpp[originalNode]->random =
            originalNode->random ? mpp[originalNode->random] : NULL;

        originalNode=originalNode->next;
    }
   
    return mpp[head];
    
}


/*logic
i will put the copied node bewtween the two nodes of ll
example if list is 1 2 3 4
then i will copy of 1 bw 1 and 2 and simililary for other
1 1 2 2 3 3 4 4 NULL
*/


/*OPTIMAL APPROACH (O(N) TIME, O(1) EXTRA SPACE)
==============================================

Core Idea:
----------
Instead of using a HashMap to store:

Original Node ---> Copied Node

we temporarily place each copied node immediately after its
corresponding original node.

This allows us to find the copy of any original node in O(1) time:

copyOf(node) = node->next

This temporary relationship acts like a "free HashMap".


---------------------------------------------------------------
STEP 1 : INSERT COPIED NODES BETWEEN ORIGINAL NODES
---------------------------------------------------------------

Original List:

1 -> 2 -> 3 -> NULL

After inserting copies:

1 -> 1' -> 2 -> 2' -> 3 -> 3' -> NULL

Observation:

1->next = 1'
2->next = 2'
3->next = 3'

Thus:

copyOf(node) = node->next


---------------------------------------------------------------
STEP 2 : SET RANDOM POINTERS OF COPIED NODES
---------------------------------------------------------------

Suppose:

1.random -> 3

Current structure:

1 -> 1' -> 2 -> 2' -> 3 -> 3'

Since:

copyOf(3) = 3->next = 3'

We can directly write:

1'->random = 1->random->next

General Formula:

copyNode->random =
    (originalNode->random)
    ? originalNode->random->next
    : NULL;

Why this works:
---------------
originalNode->random points to some original node.

Since every original node's copy is placed immediately after it:

originalNode->random->next

gives the copied version of the random target.


---------------------------------------------------------------
IMPORTANT REALIZATION
---------------------------------------------------------------

Random pointers must be assigned BEFORE destroying the
relationship:

copyOf(node) = node->next

Once the lists are completely separated, we lose this
free mapping.

That is why we exploit the interleaved structure first
to fix all random pointers.


---------------------------------------------------------------
STEP 3 : SEPARATE THE TWO LISTS
---------------------------------------------------------------

Current structure:

1 -> 1' -> 2 -> 2' -> 3 -> 3'

Goal:

Original:
1 -> 2 -> 3

Copied:
1' -> 2' -> 3'

For every group:

original -> copy -> nextOriginal

Example:

1 -> 1' -> 2

Store:

originalNode = 1
copyNode     = 1'
nextOriginal = 2

Then:

originalNode->next = nextOriginal

restores the original list.

copyNode->next =
    nextOriginal ? nextOriginal->next : NULL

connects copied nodes together.

After processing all nodes:

Original:
1 -> 2 -> 3

Copied:
1' -> 2' -> 3'


---------------------------------------------------------------
WHY WE DO NOT CONNECT COPIED NODES EARLY
---------------------------------------------------------------

A common thought is:

"Let me connect all copied nodes first."

Example:

1 -> 1' -> 2 -> 2' -> 3 -> 3'

If we modify:

1'->next = 2'

too early,

we destroy the path:

1 -> 1' -> 2

which was helping us traverse and use the
interleaved structure.

Therefore it is cleaner to:

1. Interleave nodes
2. Set random pointers
3. Separate lists

This preserves the invariant:

copyOf(node) = node->next

until it is no longer needed.


---------------------------------------------------------------
COMPLEXITY
---------------------------------------------------------------

Time  : O(N)

Pass 1 -> Insert copied nodes
Pass 2 -> Set random pointers
Pass 3 -> Separate lists

Total = O(N)

Space : O(1)

No HashMap is used.
Only a few pointer variables are required.


---------------------------------------------------------------
KEY LEARNING
---------------------------------------------------------------

We are not merely copying values.

We are cloning the entire pointer structure formed by:

1. next pointers
2. random pointers

The interleaving trick temporarily stores the mapping:

Original Node ---> Copied Node

inside the linked list itself, eliminating the need
for extra memory.
*/
Node*deepCopyingLLOpt(Node*head){
    Node*origninalNode=head;

    //setupping copied nodes bw the the nodes orignial nodes
    while(origninalNode){
        Node*copyNode=new Node(origninalNode->data);
        Node*nxtPtr=origninalNode->next;
        origninalNode->next=copyNode;
        copyNode->next=nxtPtr;
        origninalNode=origninalNode->next->next;
    }

    //giving copied random pointers to the copied nodes
    origninalNode=head;
    while(origninalNode ){
        Node*copyNode=origninalNode->next;
        copyNode->random=(origninalNode->random)?origninalNode->random->next:NULL;
        origninalNode=origninalNode->next->next;
    }



    //separating both list org and copied
    Node*copyHead=head->next;
    origninalNode=head;
    while(origninalNode){
        Node*copyNode=origninalNode->next;
        Node*nxtOrgNode=copyNode->next;

        origninalNode->next=nxtOrgNode;
        copyNode->next=(nxtOrgNode)?nxtOrgNode->next:NULL;

        origninalNode=origninalNode->next;
    }

    return head;
    
}

int main() {
    
    return 0;
}