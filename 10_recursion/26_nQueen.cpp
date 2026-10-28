#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>>&board , int row , int column){// the current row and column queen is
    // string q = board[row][column];
    for (int i = 0; i < board.size(); i++) {//checking the row first , fix row changing coumns
      if(board[row][i]=='Q')return false;
    }

    int i=row;
    int j= column;
    while(i>0 && j > 0 ){//it is checking from current posn to towards upper left corner
        if(board[i][j]=='Q')return false;
        j--;
        i--;
    }

    
    i=row;
    i=column;
    
     while(i<board.size() && j > 0 ){//it is checking from current posn to towards upper left cornerlower left corner
        if(board[i][j]=='Q')return false;
        j--;
        i++;
    }

    /*as we are filling he queen colum wise
    q then nxt colm q then next q 
    
    for the newest queen added all queen are left of it 
    so we have to check upper left lower right (as these are behind q)
    and horizontal , and vertical is not possible as we putting every queen columnwise*/
    
    return true;
}

/*N-Queens Backtracking Algorithm

Idea:
Place exactly one queen in each column.

At any recursive call:
- Queens have already been placed safely in columns [0 ... column-1].
- We now need to place a queen in the current column.

Steps:
1. If all columns are processed:
      column == n
   then a valid arrangement is found.
   Store the board and return.

2. For the current column, try every row.
      (row = 0 to n-1)

3. For each row:
      - Check if placing a queen at (row, column) is safe.
      - If not safe, skip this row.

4. If safe:
      - Place the queen.
      - Recursively solve for the next column.
      - Remove the queen (Backtrack) to restore
        the board for future choices.

Why Backtracking?
A queen placement may work for the current column
but prevent valid placements in later columns.
After exploring that possibility, we remove the queen
and try another row in the same column.

Recursive State:
    mainRec(column)

Meaning:
    "Place queens safely in all columns starting
     from 'column'."

Choice:
    Which row should contain the queen in the
    current column?

Constraint:
    isSafe(row, column)

Base Case:
    column == n

Time Complexity:
    O(N!) approximately

Space Complexity:
    O(N) recursion stack
    (excluding storage of solutions)
*/
void mainRecBf(int column , vector<vector<char>>&board , vector<vector<vector<char>>>&result ){//column =0 

    if(column==board[0].size()){
        result.push_back(board);
        return;
    }

    for (int row = 0; row < board.size(); row++) {
      if(isSafe(board , row , column)){//if its possible to put
        //then put the queen
        board[row][column]='Q';

        //check for other column recusively
        mainRecBf(column+1 , board , result);
        board[row][column]='.';//changing it back to default so next combinantion gets the default board again with no previous q

      }
    }
}


/*i hvae created array lwftrows upper diag or lowerdiag
to store the positions where i have put my queen , its like map of chessboard where 
queen are placed

     0 1 2 3
    +---------
0 |  0 1 2 3
1 |  1 2 3 4
2 |  2 3 4 5
3 |  3 4 5 6

*/

/**************************************************

N-Queens Optimized Approach (Hashing)

Goal:
Place one queen in every column such that no two
queens attack each other.

Observation:
The brute-force isSafe() checks entire diagonals
and rows repeatedly.

Instead, store attacked rows and diagonals in O(1).

--------------------------------------------------
Data Structures

leftrow[n]
    leftrow[r] = 1
    => row r already contains a queen

upperDiag[2*n - 1]
    upperDiag[row + col] = 1
    => "\" diagonal occupied

lowerDiag[2*n - 1]
    lowerDiag[(n-1) + col - row] = 1
    => "/" diagonal occupied

--------------------------------------------------
Choice

Current recursive state:
    mainRecOpt(column)

Meaning:
    Place queens safely starting from this column.

For current column:
    Try every row.

--------------------------------------------------
Validity Check

if(
    leftrow[row] == 0 &&
    upperDiag[row+col] == 0 &&
    lowerDiag[(n-1)+col-row] == 0
)

Then queen can be placed.

--------------------------------------------------
Choose

board[row][col] = 'Q';

leftrow[row] = 1;
upperDiag[row+col] = 1;
lowerDiag[(n-1)+col-row] = 1;

--------------------------------------------------
Recurse

mainRecOpt(col+1)

--------------------------------------------------
Backtrack

board[row][col] = '.';

leftrow[row] = 0;
upperDiag[row+col] = 0;
lowerDiag[(n-1)+col-row] = 0;

--------------------------------------------------
Base Case

if(col == n)

All queens successfully placed.

Store board and return.

--------------------------------------------------
Complexity

Safety Check:
    O(1)

Overall:
    O(N!)

Space:
    O(N) recursion
    O(N) hashing arrays

**************************************************/

/*==================================================
N-Queens Optimized (Hashing Approach)
==================================================

Idea:
Place exactly one queen in each column.

Instead of scanning rows and diagonals every time
(O(N) isSafe check), maintain hash arrays to know
instantly whether a row or diagonal is occupied.

--------------------------------------------------
Hash Arrays
--------------------------------------------------

leftrow[row]

Tracks occupied rows.

Example:
leftrow[2] = 1
=> Row 2 already contains a queen.


upperDiag[row + col]

Tracks "\" diagonals.

4x4 Example:

        0 1 2 3
      +---------
0     |0 1 2 3
1     |1 2 3 4
2     |2 3 4 5
3     |3 4 5 6

Cells on same "\" diagonal
have same value of (row + col).


lowerDiag[(n-1) + col - row]

Tracks "/" diagonals.

4x4 Example:

        0 1 2 3
      +---------
0     |3 4 5 6
1     |2 3 4 5
2     |1 2 3 4
3     |0 1 2 3

Cells on same "/" diagonal
have same value of
(n-1 + col - row).

--------------------------------------------------
Recursive State
--------------------------------------------------

mainRecOpt(column)

Meaning:

Queens are already safely placed in
columns [0 ... column-1].

Now place a queen in current column.

--------------------------------------------------
Safety Check
--------------------------------------------------

A position (row,col) is safe if:

leftrow[row] == 0
&&
upperDiag[row+col] == 0
&&
lowerDiag[n-1+col-row] == 0

--------------------------------------------------
Choose
--------------------------------------------------

Place Queen:

board[row][col] = 'Q';

leftrow[row] = 1;
upperDiag[row+col] = 1;
lowerDiag[n-1+col-row] = 1;

--------------------------------------------------
Explore
--------------------------------------------------

Solve remaining columns:

mainRecOpt(column+1)

--------------------------------------------------
Backtrack
--------------------------------------------------

Remove Queen:

board[row][col] = '.';

leftrow[row] = 0;
upperDiag[row+col] = 0;
lowerDiag[n-1+col-row] = 0;

This restores the board and hash arrays
for the next possible row choice.

--------------------------------------------------
Base Case
--------------------------------------------------

if(column == n)

All columns processed.
Valid configuration found.

Store board and return.

--------------------------------------------------
Complexity
--------------------------------------------------

Safety Check : O(1)

Overall      : O(N!)

Extra Space  : O(N)
(Hash arrays + recursion stack)

==================================================
*/
void mainRecOpt(int column , vector<vector<char>>&board  ,  vector<vector<vector<char>>>&result , vector<int>&leftrow  , vector<int>&upperDiag , 
vector<int>&lowerDiag){

    if(column==board[0].size()){
        result.push_back(board);
        return;
    }


    for(int row=0 ;row<board.size() ;row++){
        if(leftrow[row]==0 && upperDiag[row+column]==0 && lowerDiag[board.size()-1+column -row]==0){
            board[row][column]='Q';
            leftrow[row]==1;
            upperDiag[row+column]=1;
            lowerDiag[board.size()-1+column -row]=1;
            mainRecOpt(column+1 , board , result , leftrow , upperDiag , lowerDiag);
            board[row][column]='.';
             leftrow[row]==0;
            upperDiag[row+column]=0;
            lowerDiag[board.size()-1+column -row]=0;
            
        }
    }

}


/*now i will*/
int main() {
    
    return 0;
}