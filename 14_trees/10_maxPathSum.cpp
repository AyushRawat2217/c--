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



int biggestPathInTheTree(trees*node , int &maxSum){
    if(node==NULL)return 0;

    int left = max(0 ,biggestPathInTheTree(node->left , maxSum));
    int right=max(0 ,biggestPathInTheTree(node->right , maxSum));
    //we want tonot take negative values , thats why we ensure a 0


    //a parent gets returned both left+right values
    maxSum=max(maxSum , node->data + left + right);

    return node->data + max(left , right);//returning best contribution by suchilds + self to parent

}

int maxPathmAIN(trees*node){
    int maxSum=INT_MIN;
    biggestPathInTheTree(node , maxSum);
    return maxSum;
}
/*APPROACH: RECURSION + MAXIMUM PATH SUM

Goal:
Find the maximum sum of any non-empty path in a binary tree.
The path can start and end at any nodes; it does not have to pass
through the root. A node can appear only once in a path.

1. RECURSIVE FUNCTION AND BASE CASE
   The solve() function returns the maximum path sum contribution
   that the current node can provide to its parent.

   If the current node is NULL, return 0 because there is no node
   contributing to the path.

2. CALCULATE LEFT AND RIGHT CONTRIBUTIONS
   Recursively calculate the best contribution from the left and
   right subtrees.

   Use max(0, contribution) for each side:
   - If the contribution is positive, include it because it increases
     the path sum.
   - If the contribution is negative, ignore it by treating it as 0
     because including it would decrease the path sum.

   We do this because a maximum-sum path should never include a
   negative subtree contribution when it can simply avoid that branch.

3. CALCULATE THE PATH PASSING THROUGH THE CURRENT NODE
   Calculate:

       currentPath = node->val + left + right

   This represents a path that starts somewhere in the left subtree,
   travels through the current node, and continues into the right
   subtree.

   Both left and right contributions can be used here because this
   calculation considers the complete path passing through the node.

   Example:

             20
            /  \
           15   7

       currentPath = 15 + 20 + 7 = 42

   This path has a sum of 42.

4. MAINTAIN THE GLOBAL MAXIMUM
   Maintain a variable maxSum that stores the largest path sum found
   anywhere in the tree.

       maxSum = max(maxSum, currentPath)

   Every node calculates its own candidate path and compares it with
   the best answer found so far.

   Pass maxSum by reference (int &maxSum), or store it as a class
   member, so all recursive calls update the SAME variable.

   If maxSum were passed as an ordinary int, each call would receive
   a copy, and its updates would not modify the original variable.

   Initialize maxSum to INT_MIN, not 0, because the tree may contain
   only negative values. The path must be non-empty, so the answer
   cannot be 0 when every node is negative.

5. RETURN ONLY ONE BRANCH TO THE PARENT
   Return:

       node->val + max(left, right)

   The parent can extend a path through the current node using only
   ONE child branch.

   We cannot return left + right to the parent because that would
   represent a path using both branches. Extending that entire path
   upward would require the path to split into three directions or
   revisit a node, which is not allowed.

   Therefore:
   - For updating maxSum, use both left and right contributions.
   - For the recursive return value, use only the better contribution.

6. FINAL ANSWER
   The main function initializes maxSum, calls solve() on the root,
   and returns maxSum after the recursion finishes.

   The returned value from solve(root) is not necessarily the final
   answer. The best path may lie entirely inside a subtree and may
   never pass through the root.

IMPORTANT DISTINCTION:

   currentPath = node->val + left + right
   -> Calculates a complete path through the current node and updates
      the global answer.

   return node->val + max(left, right)
   -> Calculates the best single downward path that can be extended
      by the parent.

   max(0, contribution)
   -> Discards a negative child contribution without discarding the
      current node itself.

TIME COMPLEXITY: O(N)
   Each node is visited once.

SPACE COMPLEXITY: O(H)
   Recursive call stack, where H is the height of the tree.
   In the worst case of a skewed tree, H = N; for a balanced tree,
   H is approximately log(N).
*/
int main() {
    
    return 0;
}