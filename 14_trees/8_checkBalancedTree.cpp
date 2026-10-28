#include <bits/stdc++.h>
using namespace std;
/*a balanced tree a someone 
whose left height and right hieght difference from
each node is at most 1

so logic becomes very simple
visit every node , comapre height and keep doing it
*/

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




int Height(trees*node){//here node start from left node of parent
    
    int leftheight=Height(node->left);
    int rightheight=Height(node->right);
    
    return 1 + max(leftheight , rightheight);

}

//we got helper functions ready now simply we have to traverse and keep checking height of left and right subtree
//for every node in the tree




bool isTreeBalanced(trees*node){
    
    if (node==NULL) return true; //why  ? because its both child are null ,means they have smae height so return true

    if(abs(Height(node->left)-Height(node->right))>1)return false;//if their abs is freater than 1 return false

    bool left =isTreeBalanced(node->left);
    bool right=isTreeBalanced(node->right);
  
    return left && right ; // we need the collective 
    //even if any one node , and its subtree come up as unbalanced it overall unbalanced thats why
    //dry run is the only way to solve it properly

}

/*PROBLEM: CHECK WHETHER A BINARY TREE IS HEIGHT-BALANCED

1. DEFINITION
---------------
A binary tree is height-balanced if, for EVERY node in the tree,
the absolute difference between the heights of its left and right
subtrees is at most 1.

Condition:
    abs(leftHeight - rightHeight) <= 1

IMPORTANT:
Checking only the root is NOT sufficient. Every node must satisfy
this condition, and both its left and right subtrees must also
be balanced.


2. CONCEPT 1: HEIGHT OF A BINARY TREE
-------------------------------------
The height of a node is the number of nodes on the longest path
from that node down to a leaf.

We calculate the height recursively:

    Height(NULL) = 0

    Height(node) = 1 + max(
        Height(node->left),
        Height(node->right)
    )

WHY DO WE ADD 1?
The 1 represents the current node. We take the maximum because
we want the longest path, not the shortest path.

Our Height() function can calculate the height of ANY subtree.
For example:

    Height(node->left)  -> height of the left subtree
    Height(node->right) -> height of the right subtree

Therefore, we do not need separate leftHeight() and rightHeight()
functions. One reusable Height() function is sufficient.


3. CONCEPT 2: BASE CASE
-----------------------
    if (node == NULL) return true;

An empty tree is considered balanced.

This is the stopping condition for our recursive isBalanced()
function. When recursion reaches a missing child, it returns true.

IMPORTANT:
Do NOT return true just because node->left or node->right is NULL.

A node with only one child can still be unbalanced if that child's
subtree is too tall.

For example:

        1
       /
      2
     /
    3

This tree is unbalanced at node 1, even though node 1 has no
right child.

Only the NULL node itself is automatically considered balanced.


4. CONCEPT 3: CHECK THE CURRENT NODE
------------------------------------
For every non-NULL node:

    left  = Height(node->left)
    right = Height(node->right)

Calculate the absolute difference:

    abs(left - right)

If the difference is greater than 1, immediately return false.

WHY?
The current node violates the definition of a height-balanced
tree. Therefore, the entire tree cannot be balanced.

If the difference is at most 1, the current node passes its
local height check. However, this does NOT prove that the
entire tree is balanced.

A deeper node may still violate the condition.


5. CONCEPT 4: RECURSIVELY CHECK BOTH SUBTREES
---------------------------------------------
After the current node passes its height check, recursively
check its left and right subtrees:

    bool left = isBalanced(node->left);
    bool right = isBalanced(node->right);

Each recursive call checks:
    1. Whether the current subtree's root satisfies the
       height-difference condition.
    2. Whether its left subtree is balanced.
    3. Whether its right subtree is balanced.

This process continues until NULL nodes are reached.


6. CONCEPT 5: BOOLEAN LOGIC (&& vs ||)
--------------------------------------
Finally, we return:

    return left && right;

The logical AND operator (&&) returns true only when BOTH
operands are true.

Truth table:

    left       right       left && right
    true       true            true
    true       false           false
    false      true            false
    false      false           false

WHY NOT USE || ?
Using OR would incorrectly accept a tree when one subtree
is balanced but the other is not.

The entire tree is balanced only when BOTH subtrees are
balanced and the current node passes its own height check.


7. COMPLETE ALGORITHM
----------------------
Step 1: If node is NULL, return true.
Step 2: Calculate the heights of its left and right subtrees.
Step 3: If their absolute difference exceeds 1, return false.
Step 4: Recursively check the left subtree.
Step 5: Recursively check the right subtree.
Step 6: Return left && right.

This is a combination of:
    - Tree recursion
    - Height calculation
    - Checking a condition at every node
    - Combining recursive Boolean results


8. DRY RUN
-----------
Consider the following tree:

          1
         / \
        2   3
       /
      4

At node 4:
    Left height  = 0
    Right height = 0
    Difference   = 0
    Balanced     = true

At node 2:
    Left height  = 1  (node 4)
    Right height = 0
    Difference   = 1
    Balanced     = true

At node 3:
    Left height  = 0
    Right height = 0
    Difference   = 0
    Balanced     = true

At node 1:
    Left height  = 2  (subtree rooted at node 2)
    Right height = 1  (subtree rooted at node 3)
    Difference   = 1
    Both subtrees are balanced.

Therefore, the entire tree is balanced, and the function
returns true.


9. COMMON MISTAKES
-------------------
Mistake 1:
Returning true whenever either child is NULL.

Correction:
Only node == NULL is the base case for isBalanced().

Mistake 2:
Checking the height difference only at the root.

Correction:
Every node must be checked recursively.

Mistake 3:
Calling recursive functions but ignoring their Boolean results.

Correction:
Store the results and combine them using &&.

Mistake 4:
Using || instead of &&.

Correction:
Both subtrees must be balanced.

Mistake 5:
Forgetting to return a value from a non-void function.

Correction:
Ensure every execution path returns a Boolean value.


10. TIME AND SPACE COMPLEXITY
------------------------------
Let n = number of nodes and h = height of the tree.

TIME:
O(n^2) in the worst case.

Why?
At each node, Height() may visit many nodes in its subtree.
For a skewed tree, repeated height calculations can result
in O(n^2) total work.

A balanced tree generally gives O(n log n) time for this
approach, because the height calculation at each level
processes the corresponding subtrees.

A more efficient approach can calculate heights and detect
unbalanced subtrees in a single traversal, achieving O(n)
time.

AUXILIARY SPACE:
O(h), due to recursive call stacks.

For a balanced tree, h = O(log n).
For a skewed tree, h = O(n).


FINAL TAKEAWAY
--------------
The key idea is NOT just to check whether the root is balanced.

For every node:
    1. Check its local height difference.
    2. Check its left subtree.
    3. Check its right subtree.
    4. Combine the results using logical AND.

A binary tree is balanced only if EVERY node satisfies the
height condition.
*/

int main() {
    
    return 0;
}