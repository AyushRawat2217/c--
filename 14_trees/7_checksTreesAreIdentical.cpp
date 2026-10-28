#include <bits/stdc++.h>
using namespace std;

struct trees{
        int data;
        trees*left;
        trees*right;

        trees(int val , trees*leftptr=NULL , trees*rightptr=NULL){
            data = val;
            left=leftptr;
            right=rightptr;
        }

};

bool checkIdenticallness(trees*tree1 , trees*tree2){

    if(tree1==NULL && tree2==NULL){//BOTH ARE NULL
        return true;
    }
    if(tree1==NULL || tree2==NULL){//if one of them is null other is not then its simply returning false
        return false;
    }
    if(tree1->data!=tree2->data)return false;
    //base conditions till here


    //now i need to check things for left and right children as well
    /*as i go left then i keep going until i reach the last and return the first base case 
    if same happens*/
    return((checkIdenticallness(tree1->left , tree2->left) && checkIdenticallness(tree1->right , tree2->right)));
    /*ye && wali bkchodi isliye ki hai
    so that agr kbhi beech mai false aaaye toh universally false hi rhe
    even if right wali side se true aaye*/
    
}

/*
===============================================================================
PROBLEM: SAME TREE / IDENTICAL TREES
===============================================================================

GOAL:
-----
We are given the roots of two binary trees, p and q.

We must determine whether these two trees are IDENTICAL.

Two binary trees are identical if BOTH of the following conditions hold:

1. STRUCTURE:
   Corresponding nodes must exist in the same positions.

2. VALUES:
   Corresponding nodes must contain the same values.

For example:

       Tree P                 Tree Q

          1                      1
         / \                    / \
        2   3                  2   3

   These trees are identical because their structures and values match.

But consider:

       Tree P                 Tree Q

          1                      1
         /                        \
        2                          2

   These trees are NOT identical.

   Both trees contain the values 1 and 2, but node 2 is on the left
   in Tree P and on the right in Tree Q.

   Therefore, simply comparing the values is NOT sufficient.
   We must compare both the structure and the values.


===============================================================================
APPROACH: RECURSION
===============================================================================

THE MAIN IDEA:
--------------
Instead of comparing the entire trees at once, we compare two nodes
at a time.

We ask:

"Are the trees rooted at p and q identical?"

If the current nodes match, we ask the SAME question about their
left subtrees and then their right subtrees.

This is possible because every subtree is itself a binary tree.

For example:

             1
            / \
           2   3
          / \
         4   5

The subtree rooted at node 2 is:

           2
          / \
         4   5

This subtree is also a binary tree. Therefore, the same function
can compare it with the corresponding subtree in the other tree.

This is the key observation that leads us to recursion.


===============================================================================
COMPLETE C++ IMPLEMENTATION
===============================================================================

bool isSameTree(TreeNode* p, TreeNode* q)
{
    // CASE 1: Both nodes are NULL.
    if (p == NULL && q == NULL)
        return true;

    // CASE 2: Exactly one node is NULL.
    if (p == NULL || q == NULL)
        return false;

    // CASE 3: Both nodes exist, but their values differ.
    if (p->val != q->val)
        return false;

    // CASE 4: Current nodes match.
    // Compare left subtrees and right subtrees recursively.
    return isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}


===============================================================================
DETAILED EXPLANATION OF EACH CONDITION
===============================================================================

CASE 1:
-------
if (p == NULL && q == NULL)
    return true;

WHAT DOES NULL MEAN?

NULL means that a node does not exist at that position.

A NULL pointer does not contain a node value. We cannot access
p->val if p is NULL.

WHY RETURN TRUE WHEN BOTH ARE NULL?

Suppose both trees have a root node with value 1 and neither root
has any children.

       Tree P                 Tree Q

          1                      1
         / \                    / \
       NULL NULL              NULL NULL

Both trees have no left child and no right child.

Their structures match at these positions.

Therefore:

isSameTree(NULL, NULL) returns true.

IMPORTANT:
We are NOT comparing the data of two NULL nodes.
We are confirming that both trees have no node at this position.


CASE 2:
-------
if (p == NULL || q == NULL)
    return false;

WHAT DOES || MEAN?

|| means OR.

This condition is true if at least one of the pointers is NULL.

There are two possibilities:

1. p is NULL and q exists.
2. p exists and q is NULL.

In either situation, one tree has a node and the other does not.

Example:

       Tree P                 Tree Q

          1                      1
         /                        \
        2                          NULL

At the left-child position:
- Tree P has node 2.
- Tree Q has no left child.

The structures differ, so the trees are not identical.

WHY DO WE CHECK THIS BEFORE ACCESSING p->val OR q->val?

Because accessing a node's data through a NULL pointer is invalid.

These NULL checks ensure that both pointers refer to existing nodes
before we access their values.


CASE 3:
-------
if (p->val != q->val)
    return false;

At this point, the first two conditions have established that both
p and q exist.

Now we can safely compare their values.

If the values differ, the trees cannot be identical.

Example:

       Tree P                 Tree Q

          1                      1
         / \                    / \
        2   3                  9   3

The roots match, but the left children contain 2 and 9.

isSameTree(node2, node9) returns false.

There is no need to inspect their descendants because a mismatch
has already proved that the trees are not identical.


===============================================================================
THE MOST IMPORTANT PART: RECURSIVE CALLS
===============================================================================

return isSameTree(p->left, q->left) &&
       isSameTree(p->right, q->right);

We reach this statement only after confirming that:
- Both current nodes exist.
- Their values are equal.

The remaining question is whether their children also match.

PART A: COMPARE THE LEFT SUBTREES

isSameTree(p->left, q->left)

This calls the SAME function again, but with the left children
as the new arguments.

The original p and q are not changed.

Instead, a new function call starts with its own parameters.

PART B: COMPARE THE RIGHT SUBTREES

isSameTree(p->right, q->right)

After the left call returns true, C++ evaluates this right call.

This compares the right children of the original p and q.

WHY DO WE USE &&?

&& means AND.

For the trees to be identical:
- The left subtrees must be identical.
- The right subtrees must be identical.

Both results must be true.

true  && true  = true
true  && false = false
false && true  = false
false && false = false

If the left call returns false, C++ short-circuits the expression:
the right call is skipped because the complete result must be false.

IMPORTANT:
The two recursive calls do NOT execute simultaneously.

C++ evaluates the left call first, waits for its result, and then
evaluates the right call if the left result is true.


===============================================================================
COMPLETE DRY RUN WITH SUBTREES INSIDE SUBTREES
===============================================================================

Consider the following two trees:

TREE P:                         TREE Q:

          1                               1
         / \                             / \
        2   3                           2   3
       / \                             / \
      4   5                           4   5
     /                                 /
    6                                 6

Both trees have exactly the same structure and values.

We will follow every important recursive call.


STEP 1: START AT THE ROOT
-------------------------

Initial call:

isSameTree(rootP, rootQ)

Assume both root values are 1.

Check the conditions:

1. Are both pointers NULL? No.
2. Is either pointer NULL? No.
3. Are the values different? No. Both contain 1.

Now we execute:

return isSameTree(p->left, q->left) &&
       isSameTree(p->right, q->right);

C++ starts with the LEFT recursive call.

isSameTree(node2_P, node2_Q)

The original call comparing node 1 is now waiting for this
left recursive call to finish.


STEP 2: COMPARE NODE 2
----------------------

Current call:

isSameTree(node2_P, node2_Q)

Both nodes contain 2.

The values match, so the function reaches its recursive expression:

isSameTree(node4_P, node4_Q) &&
isSameTree(node5_P, node5_Q)

The left call must execute first.

isSameTree(node4_P, node4_Q)

The call comparing node 2 pauses while node 4 is checked.


STEP 3: COMPARE NODE 4
----------------------

Current call:

isSameTree(node4_P, node4_Q)

Both nodes contain 4.

The function reaches:

isSameTree(node4_P->left, node4_Q->left) &&
isSameTree(node4_P->right, node4_Q->right)

The left children are node 6 in both trees.

Therefore, the next call is:

isSameTree(node6_P, node6_Q)

The call comparing node 4 waits for this call to return.


STEP 4: COMPARE NODE 6
----------------------

Current call:

isSameTree(node6_P, node6_Q)

Both nodes contain 6.

Neither node has a left child.

Therefore:

isSameTree(NULL, NULL)

Both pointers are NULL, so this call returns true.

Now the function compares the right children of node 6:

isSameTree(NULL, NULL)

Again, both pointers are NULL, so this call returns true.

The result at node 6 is:

true && true = true

Therefore:

isSameTree(node6_P, node6_Q) returns true.

IMPORTANT:
This does NOT finish the entire algorithm.
It finishes only the call comparing node 6.


STEP 5: RETURN TO NODE 4
------------------------

The call comparing node 6 has returned true.

Where does execution go?

It returns to the suspended call comparing node 4.

The left comparison of node 4 is now complete:

isSameTree(node6_P, node6_Q) = true

The function now evaluates the RIGHT comparison at node 4.

Both right children are NULL:

isSameTree(NULL, NULL) = true

Therefore, the result at node 4 is:

true && true = true

So:

isSameTree(node4_P, node4_Q) returns true.

The function now returns to the waiting call at node 2.


STEP 6: RETURN TO NODE 2 AND MOVE TO NODE 5
-------------------------------------------

This is the crucial part.

The call comparing node 2 originally contained:

return isSameTree(p->left, q->left) &&
       isSameTree(p->right, q->right);

Its left call was:

isSameTree(node4_P, node4_Q)

That call has now returned true.

Therefore, C++ resumes the expression at node 2.

Conceptually, the expression now has this state:

return true && isSameTree(node5_P, node5_Q);

Since the left result is true, C++ evaluates the right call.

isSameTree(node5_P, node5_Q)

Both nodes contain 5.

Their left children are NULL, so that comparison returns true.

Their right children are NULL, so that comparison also returns true.

Therefore:

isSameTree(node5_P, node5_Q)
returns true && true
returns true.

Now both comparisons at node 2 are complete:

true && true = true

So:

isSameTree(node2_P, node2_Q) returns true.

The function returns to the original call comparing node 1.


STEP 7: RETURN TO NODE 1 AND MOVE TO NODE 3
-------------------------------------------

The original call was:

isSameTree(rootP, rootQ)

Its left comparison has returned true.

Conceptually, the expression now has this state:

return true && isSameTree(node3_P, node3_Q);

Because the left result is true, C++ evaluates the right call.

isSameTree(node3_P, node3_Q)

Both nodes contain 3.

Their left children are NULL, so the left comparison returns true.

Their right children are NULL, so the right comparison returns true.

Therefore:

isSameTree(node3_P, node3_Q) returns true.


STEP 8: FINAL RESULT AT THE ROOT
--------------------------------

We now return to the original call comparing node 1.

The left subtree returned true.
The right subtree returned true.

The final expression is:

return true && true;

Result:

true

Both trees have the same structure and corresponding values.

Therefore, the answer is TRUE.


===============================================================================
HOW THE CALL STACK HANDLES RECURSION
===============================================================================

A function call that makes another function call must wait for the
new call to finish before continuing.

The call stack remembers the waiting calls and their local variables.

During the deepest part of our example, the active calls look like:

isSameTree(1, 1)    WAITING
    isSameTree(2, 2)    WAITING
        isSameTree(4, 4)    WAITING
            isSameTree(6, 6)    CURRENT CALL

Node 6 reaches the NULL base cases and returns true.

Then the active calls unwind:

isSameTree(6, 6) returns true
isSameTree(4, 4) resumes and eventually returns true
isSameTree(2, 2) resumes and eventually returns true
isSameTree(1, 1) resumes and eventually returns true

After node 4 finishes, the waiting call at node 2 can move to node 5.
After node 2 finishes, the waiting call at node 1 can move to node 3.

You do NOT manually navigate back to these nodes.
The call stack automatically resumes the correct waiting function.


===============================================================================
WHY DOES RECURSION EVENTUALLY STOP?
===============================================================================

Every recursive call moves to the children of the current nodes.

A finite binary tree eventually reaches positions where the children
do not exist. At these positions, the pointers are NULL.

The base cases handle those positions and return a result.

This prevents the recursion from continuing indefinitely.


===============================================================================
COMMON MISTAKES
===============================================================================

1. Comparing only p->val and q->val.
   Matching roots do not guarantee that the entire trees match.

2. Forgetting to handle NULL pointers.
   Accessing p->val when p is NULL is invalid.

3. Comparing p->left with q->right.
   The left child must match the left child, and the right child
   must match the right child.

4. Using || instead of &&.
   Both subtrees must match, not merely one of them.

5. Thinking recursive calls run simultaneously.
   The left call executes first. Its result returns before the
   right call is evaluated.

6. Thinking a return from a child ends the whole algorithm.
   A return completes only the current function call. Its caller
   resumes and continues its own work.

7. Thinking p and q are permanently moved to the children.
   Each recursive call receives its own parameters. The caller's
   local pointers remain available when execution resumes.


===============================================================================
COMPLEXITY ANALYSIS
===============================================================================

TIME COMPLEXITY: O(N)

In the worst case, we compare every node in the trees.
If both trees have N nodes, the total work is O(N).

An early mismatch can make the algorithm finish sooner.

SPACE COMPLEXITY: O(H)

H is the height of the tree, representing the maximum recursion depth.

Balanced tree:
H = O(log N)

Highly skewed tree:
H = O(N)

The additional space comes from the recursive call stack.


===============================================================================
FINAL REASONING TEMPLATE
===============================================================================

Whenever you solve a recursive binary-tree comparison problem, ask:

1. What happens if both nodes are NULL?
2. What happens if exactly one node is NULL?
3. What condition must hold at the current nodes?
4. Can I solve the same problem on the left children?
5. Can I solve the same problem on the right children?
6. How must I combine the two results?

For Identical Trees:

- Both NULL                       -> true
- Exactly one NULL                -> false
- Different values                -> false
- Matching values and both
  subtrees identical              -> true

The complete logic is:

isSameTree(left subtrees) &&
isSameTree(right subtrees)

The SAME function solves the problem at every depth.
===============================================================================
*/


int main() {
    
    return 0;
}