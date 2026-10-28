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



void preInPoOrder(trees*root){
    stack<pair<trees* , int>>st;
    vector<int>pre;
    vector<int>in;
    vector<int>po;
    int state;
    trees*node;

    trees*mover=root;
    st.push({mover , 1});

    while(!st.empty()){
        
        state=st.top().second;
        node=st.top().first;

        if(state==1){
            pre.push_back(node->data);
            st.top().second++;
            if(node->left){
                st.push({node->left , 1});
            }
        }
        else if(state==2){
            in.push_back(node->data);
            st.top().second++;
            if(node->right){
                st.push({node->right , 1});
            }
        }
        else{
            po.push_back(node->data);
            st.pop();
            /*imp
// What if the node has children when state == 3?
// At state 1, we push and process the left child.
// At state 2, we push and process the right child.
// Each child is fully processed and popped before the parent resumes.
// Therefore, when the parent reaches state 3, both subtrees are already
// processed, so we add its data to postorder and safely pop the parent.*/
        }
    }
    

}
/*PROBLEM: Preorder, Inorder and Postorder Traversals in a Single Traversal

APPROACH:
Instead of traversing the binary tree three separate times, we perform
a single traversal using a stack of pairs and maintain three vectors.

DATA STRUCTURES:
1. pre  -> Stores preorder traversal.
2. in   -> Stores inorder traversal.
3. po   -> Stores postorder traversal.
4. Stack of pairs:
   - First element: Pointer to the current tree node.
   - Second element: State representing the current processing stage.

Each node is processed in three stages:
State 1 -> Preorder
State 2 -> Inorder
State 3 -> Postorder


EXAMPLE TREE:

             1
            / \
           2   3
          / \
         4   5


INITIALIZATION:
Push {root, 1} onto the stack.
Initially, all three vectors are empty.

DRY RUN:

1. Node 1, State 1:
   - Add 1 to pre.
   - Change its state to 2.
   - Push its left child, node 2, with state 1.

2. Node 2, State 1:
   - Add 2 to pre.
   - Change its state to 2.
   - Push its left child, node 4, with state 1.

3. Node 4, State 1:
   - Add 4 to pre.
   - Change its state to 2.
   - No left child exists, so do not push anything.

4. Node 4, State 2:
   - Add 4 to in.
   - Change its state to 3.
   - No right child exists.

5. Node 4, State 3:
   - Add 4 to po.
   - Pop node 4 because its processing is complete.

6. Node 2, State 2:
   - Resume node 2 from its saved state.
   - Add 2 to in.
   - Change its state to 3.
   - Push its right child, node 5, with state 1.

7. Node 5:
   - Process states 1, 2 and 3 in order.
   - Add 5 to pre, in and po respectively.
   - Pop node 5 after state 3.

8. Node 2, State 3:
   - Resume node 2.
   - Add 2 to po.
   - Pop node 2.

9. Node 1, State 2:
   - Resume node 1 from its saved state.
   - Add 1 to in.
   - Change its state to 3.
   - Push its right child, node 3, with state 1.

10. Node 3:
    - Process states 1, 2 and 3 in order.
    - Add 3 to pre, in and po respectively.
    - Pop node 3 after state 3.

11. Node 1, State 3:
    - Resume node 1.
    - Add 1 to po.
    - Pop node 1.

The stack is now empty, so the traversal is complete.


FINAL OUTPUT:

Preorder  = [1, 2, 4, 5, 3]
Inorder   = [4, 2, 5, 1, 3]
Postorder = [4, 5, 2, 3, 1]


WHY DOES THIS WORK?

The parent remains in the stack with its updated state while a child
is being processed. Once that child is completely processed and popped,
the algorithm resumes the parent from its saved state.

The left subtree is explored during State 1, and the right subtree
is explored during State 2. Therefore, when a node reaches State 3,
both subtrees have already been processed, if they exist.

This is why the node can safely be added to postorder and popped.


COMPLEXITY:

Time Complexity: O(N), since every node undergoes three constant-time
processing stages.

Auxiliary Space Complexity: O(N) for the stack in the worst case.

Output Space Complexity: O(N) for the three vectors combined.

N = Number of nodes in the binary tree.
*/

int main() {
    
    return 0;
}