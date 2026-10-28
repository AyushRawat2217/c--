#include <bits/stdc++.h>
using namespace std;

//backtracking yhi hai ki jbh call stacks retur hore ho toh us time kya changes krne hai

/*=========================================
SUDOKU SOLVER (BACKTRACKING)
=========================================

---------------------------
PROBLEM IDEA
---------------------------

Given a partially filled 9x9 Sudoku board, fill all empty cells ('.')
such that:

1. Each row contains digits 1-9 exactly once.
2. Each column contains digits 1-9 exactly once.
3. Each 3x3 box contains digits 1-9 exactly once.

There is guaranteed to be one valid solution.

----------------------------------------------------------
WHY BACKTRACKING?
----------------------------------------------------------

For every empty cell, multiple numbers may be valid.

Example:

.

↓

Can place:

1
3
7

We DON'T know which one leads to the final solution.

So we:

1. Try one number.
2. Recursively solve the remaining board.
3. If it works → keep it.
4. If it fails → remove it (backtrack) and try another number.

This "try → recurse → undo" is Backtracking.

----------------------------------------------------------
MAIN RECURSION IDEA
----------------------------------------------------------

solveSudoku(board)

↓

Find FIRST empty cell ('.').

↓

Try digits 1 to 9.

↓

If digit is safe:

    Place digit.

    Ask recursion:

        "Can the remaining Sudoku be solved?"

        if YES
            return true

        if NO
            remove digit
            try next digit

If no digit works

    return false

----------------------------------------------------------
VERY IMPORTANT OBSERVATION
----------------------------------------------------------

Every recursive call starts scanning the board from (0,0).

It DOES NOT continue from the previous position.

Why?

Because already-filled cells are skipped naturally.

Example:

Call 1

5 3 .
6 7 .

↓

Fill first '.'

↓

Call 2 starts AGAIN from (0,0)

5 3 4
6 7 .

↓

Cells already filled are skipped

↓

Next '.' is found automatically.

----------------------------------------------------------
BASE CASE (Hidden Base Case)
----------------------------------------------------------

There is NO explicit condition like:

if(index==n)

Instead,

Base case happens when NO empty cell exists.

The loops finish scanning the whole board.

Then execution reaches:

return true;

Meaning:

"The board is completely filled."

----------------------------------------------------------
MEANING OF return true
----------------------------------------------------------

return true means:

"I successfully solved this board."

This success travels upward.

Example:

Deepest Call

↓

return true

↓

Previous call receives true

↓

Its

if(solveSudoku())

becomes

if(true)

↓

return true

↓

Success keeps propagating upward.

----------------------------------------------------------
MEANING OF return false
----------------------------------------------------------

return false DOES NOT mean

"Sudoku has no solution."

It means

"With my CURRENT choices, I cannot solve it."

Example:

Current empty cell

Try:

1 ❌

2 ❌

3 ❌

...

9 ❌

No digit works.

↓

return false

Previous recursive call receives false.

It understands:

"My previous choice was wrong."

So it BACKTRACKS.

----------------------------------------------------------
BACKTRACKING STEP
----------------------------------------------------------

board[row][col]=digit

↓

solveSudoku(board)

↓

Returned false?

↓

Undo

board[row][col]='.'

↓

Try next digit.

----------------------------------------------------------
IMPORTANT FLOW
----------------------------------------------------------

Current Call

↓

Place digit

↓

Recursive Call

↓

TRUE ?

YES

↓

Current choice is correct

↓

return true


FALSE ?

↓

Undo current digit

↓

Try next digit

↓

No digit left?

↓

return false

----------------------------------------------------------
isValid() CHECKS
----------------------------------------------------------

Before placing a digit, verify:

1. Entire Row
2. Entire Column
3. Entire 3×3 Box

Only then place the digit.

----------------------------------------------------------
3×3 BOX
----------------------------------------------------------

Starting cell of box:

startRow = 3*(row/3)
startCol = 3*(col/3)

Loop:

rows:
startRow -> startRow+2

columns:
startCol -> startCol+2

----------------------------------------------------------
TIME COMPLEXITY
----------------------------------------------------------

Worst Case:

O(9^(number of empty cells))

because every empty cell can try up to 9 digits.

Practical runtime is much faster because
isValid() prunes many invalid choices.

----------------------------------------------------------
SPACE COMPLEXITY
----------------------------------------------------------

O(number of empty cells)

Recursion stack only.

----------------------------------------------------------
PATTERN TO REMEMBER
----------------------------------------------------------

Find choice

↓

Check if valid

↓

Choose

↓

Recurse

↓

Success?

YES → return true

NO → Undo

↓

Try next choice

↓

No choice left

↓

return false

----------------------------------------------------------
RECOGNITION CLUES
----------------------------------------------------------

Whenever a problem asks:

• Fill a board
• Find one valid arrangement
• Try all possibilities
• Undo wrong choices

Think:

BACKTRACKING

Examples:

✓ Sudoku Solver
✓ N-Queens
✓ Rat in a Maze
✓ Word Search
✓ M-Coloring
✓ Combination Sum
✓ Palindrome Partitioning
✓ Word Break (backtracking version)

=========================================
*/

/*there are three rules 
same row no same elemnt
same column no same elemnt
and  for n 
underoot n * underoot n , size matrixes should not have duplicate elemnt in it
for example for a soduko of size 9*9
it will have 9 , 3*3 mini soduko and those shoudnt have duplicate elemnts
and to fin starting row and starting column of that particular subgrid there is a formula
*/

bool isSafe2putTheNr(vector<vector<char>>&soduko , int row , int column , char c , int n){
    for (int i = 0; i < n; i++) {
      if(soduko[row][i]==c)return false;
    }

    for (int i = 0; i < n; i++) {
      if(soduko[i][column]==c)return false;
    }

    int startSubGridRow = 3*(row/3);
    int startofSubGridCol=3*(column/3);

    for (int i = startSubGridRow; i < 3; i++) {


      for (int j = startofSubGridCol; j < 3; j++) {
        if(soduko[startSubGridRow+i][startofSubGridCol+j]==c)return false;
      }
    }

    return true;

  }


bool recursion(vector<vector<char>>&soduko){//

    

    for (int i = 0; i < soduko.size(); i++) {

      for (int j = 0; j < soduko.size(); j++){

        if(soduko[i][j]=='.'){
            for (char i = '1' ; i < '9'; i++) {//to fill in the numbers
              if(isSafe2putTheNr(soduko , i , j , i , soduko.size())){
                    soduko[i][j]=i;

                    if(recursion(soduko)){
                        return true;
                    }

                    soduko[i][j]='.'; //backtrack

              }

            }

            //inside the if statement
            return false;
            
        }

        
         
      }
      
    }

    return true;

}

int main() {
    
    return 0;
}