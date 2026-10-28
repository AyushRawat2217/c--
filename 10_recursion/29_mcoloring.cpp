#include <bits/stdc++.h>
using namespace std;

/*=========================================
M-COLORING PROBLEM (Backtracking)
=========================================

INPUT:

graph[][] is an Adjacency Matrix.

graph[i][j] = 1  -> Vertex i is connected to Vertex j.
graph[i][j] = 0  -> No edge between i and j.

Example:

      0
     / \
    1---2

Adjacency Matrix:

        0 1 2
      --------
0 -->  0 1 1
1 -->  1 0 1
2 -->  1 1 0

Read graph[2]:

graph[2][0] = 1 -> Vertex 2 is connected to 0
graph[2][1] = 1 -> Vertex 2 is connected to 1
graph[2][2] = 0 -> Ignore (not connected to itself)

--------------------------------------------------

color[] stores the current color of every vertex.

Initially:

Vertex : 0 1 2
Color  : 0 0 0

0 = No color assigned
1 = Color 1
2 = Color 2
3 = Color 3
...

During recursion this array keeps changing.

Example:

Vertex : 0 1 2
Color  : 1 2 0

means:
Vertex 0 -> Color 1
Vertex 1 -> Color 2
Vertex 2 -> Not colored yet

--------------------------------------------------

APPROACH

We color ONE vertex at a time.

Suppose we are currently at vertex 'node'.

We don't know which color will work, so we try every color
from 1 to M.

For every color:

1. Check if assigning this color is safe.
2. Safe means:
      - None of the adjacent vertices already has this color.
3. If safe:
      - Assign the color.
      - Recursively color the next vertex.
4. If recursion succeeds:
      - Return true immediately.
5. Otherwise:
      - Remove the assigned color (Backtracking)
      - Try the next color.

If every color fails,
return false.

--------------------------------------------------

isSafe()

Checks every vertex k.

If

graph[node][k] == 1

then k is a neighbour of 'node'.

Now check

color[k]

If the neighbour already has the same color that we are trying
to assign, then this color cannot be used.

Otherwise continue checking other neighbours.

If no neighbour has the same color,
return true.

--------------------------------------------------

BACKTRACKING IDEA

Try Color 1
    ↓
Works?
    ↓
Yes → Color next vertex
    ↓
Later fails?
    ↓
Undo current color
    ↓
Try Color 2
    ↓
Try Color 3
    ↓
...

Recursion explores vertices.
The for-loop explores different color choices for each vertex.

Time Complexity:
O(M^N) in the worst case

Space Complexity:
O(N) (recursion stack + color array)
*/

/*the directed graph is from of 
index will represent the node and the elemnt which are vector have 0 ,1 
the o will mean ith index of the vector elemnt(i.e the ith node) is not connected 
*/

//this function is to check wheher we can color the node with the color ball or not


bool isItSafeToColor(int n , int color ,   int node , int colorArr[] , vector<vector<int>>&graph ){//n is number of colors
     
    for (int i = 0; i < graph.size(); i++) {//loop is to visit every adjacent vertex which node has () graph[i][node]==1)
       if(i!=node && graph[i][node]==1 && colorArr[i]==color)return false ; //if the ith vertice is adjacent and has same color return false
     }

     return true;
}
/*krna ye hai ki har node mai check krna hai
ki ye color aaskta hai ki nhi 
recusiion ka use isliye kiya hai ki we dont know cwhich combinations fits in*/

bool mColoringBackTracking(int n ,  int node , int colorArr[] , vector<vector<int>>&graph){

    if(node==graph.size())return true;//graph.size() is nr of vertexes
    
    for (int color =  1 ;color < n; color++) {
      if(isItSafeToColor(n , color , node , colorArr , graph)){//if its safe to color that node with the given color then do it and mark in color array
            colorArr[node]==color;//mark the node in color ARR that it is colored
            if(mColoringBackTracking(n ,node+1 , colorArr , graph ))return true;//move to next node
            colorArr[node]=0;//bactrtacking and resetting
      }

    }
    return false;
}

int main() {
    
    return 0;
}