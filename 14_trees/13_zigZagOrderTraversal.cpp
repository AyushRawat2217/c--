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

//531
//we have to use concept of level order
//i will write code of LOT

void zigZagTraversal(trees*node , vector<vector<int>>&ans){
    queue<trees*>q;
    trees*mover=node;
    q.push(mover);
    bool leftTORight=true;


    while(!q.empty()){
        int size=q.size();
        vector<int>levels(size);

        for (int i = 0; i < size; i++) {
          mover=q.front();
          q.pop();

          int index=leftTORight?i:size-i-1;
          levels[index]=node->data;


          if(mover->left)q.push(mover->left);
          if(mover->right)q.push(mover->right);
        }

        ans.push_back(levels);
        leftTORight=!leftTORight;

    }

    /*ZIGZAG LEVEL ORDER TRAVERSAL

Example Tree:

        1
       / \
      2   3
     / \ / \
    4  5 6  7

Expected Output:
[[1], [3, 2], [4, 5, 6, 7]]


1. Create a 2D vector 'ans' to store the final answer.
   Each inner vector represents one level of the tree.

2. If the root is NULL, return the empty answer because
   there are no nodes to traverse.

3. Create a queue and push the root into it.
   The queue performs normal BFS, processing nodes level
   by level.

4. Initialize 'leftToRight' as true.
   true  -> Store the current level from left to right.
   false -> Store the current level from right to left.

5. Start a while loop that continues until the queue
   becomes empty. Each iteration processes one level.

6. Store the current queue size in 'size' BEFORE
   processing any nodes.

   Example:
   Queue = [2, 3]
   size = 2

   We must process exactly two nodes for this level.
   Their children will be processed at the next level.

7. Create a vector 'level' of size 'size'.
   This vector stores the values of the current level.

   Example:
   size = 2
   level = [0, 0]

8. Run an inner loop exactly 'size' times.
   In each iteration:
   - Take the front node from the queue.
   - Remove it from the queue.
   - Calculate the index where its value belongs.
   - Store its value at that index.
   - Push its children into the queue if they exist.

9. Calculate the index using the traversal direction.

   If leftToRight is true:
       index = i

   If leftToRight is false:
       index = size - 1 - i

   Example: Queue processes nodes 2, then 3.
   Direction = right to left.
   size = 2

   Node 2:
   i = 0
   index = 2 - 1 - 0 = 1
   Store 2 at level[1].

   Node 3:
   i = 1
   index = 2 - 1 - 1 = 0
   Store 3 at level[0].

   Result:
   level = [3, 2]

   IMPORTANT:
   The queue still processes nodes in normal BFS order.
   Only the index used to store values changes.

10. Push the left child into the queue first, followed
    by the right child, if those children exist.
    They belong to the next level.

11. After processing exactly 'size' nodes, the current
    level is complete. Add the entire 'level' vector
    to the final answer using ans.push_back(level).

12. Toggle the direction using:
    leftToRight = !leftToRight;

    This alternates the direction after every level.

    Level 0 -> Left to right  -> [1]
    Level 1 -> Right to left  -> [3, 2]
    Level 2 -> Left to right  -> [4, 5, 6, 7]

13. When the queue becomes empty, all levels have been
    processed. Return the final 2D vector.

CORE IDEA:
- Queue: Processes nodes level by level.
- size: Separates the current level from the next.
- level: Stores values of the current level.
- index: Controls the zigzag order.
- ans: Stores all completed levels.
*/


}

int main() {
    
    return 0;
}