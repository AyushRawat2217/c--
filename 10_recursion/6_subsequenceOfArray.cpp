#include <bits/stdc++.h>
using namespace std;

/* PROBLEM:
    --------
    Print all possible subsequences of a given array.

    A subsequence is obtained by removing zero or more elements
    WITHOUT changing the relative order of the remaining elements.

    Example:

        Array = [3,1,2]

    Valid Subsequences:

        []
        [3]
        [1]
        [2]
        [3,1]
        [3,2]
        [1,2]
        [3,1,2]

    Invalid:

        [2,3]      // Order changed
        [1,3]      // Order changed

    ---------------------------------------------------------------
    CORE IDEA
    ---------------------------------------------------------------

    For every element we have exactly TWO independent choices:

        1. Take it.
        2. Don't Take it.

    These choices are made ONE ELEMENT AT A TIME.

    For example,

        [3,1,2]

    Index 0 (3)

            Take
              |
              V
            [3]

    or

            Don't Take
                 |
                 V
               []

    After making this decision, we move to the next index
    and AGAIN ask the same question.

    This process continues until every element has been
    processed.

    ---------------------------------------------------------------
    WHY THERE ARE 2^N SUBSEQUENCES
    ---------------------------------------------------------------

    Each element contributes two choices.

            Take
            Skip

    Therefore,

        n elements
            =>
        2 × 2 × 2 × ... × 2
            =>
        2^n

    Example:

        n = 3

            2^3 = 8 subsequences

    ---------------------------------------------------------------
    RECURSION TREE
    ---------------------------------------------------------------

                           []
                    /                 \
               Take 3              Skip 3
                 [3]                 []
               /     \             /     \
          Take1     Skip1      Take1    Skip1
          [3,1]      [3]         [1]      []
          /   \      /  \        / \      / \
       T2    S2    T2   S2    T2  S2   T2  S2

        Outputs:

        [3,1,2]
        [3,1]
        [3,2]
        [3]
        [1,2]
        [1]
        [2]
        []

    Every root-to-leaf path represents ONE subsequence.

    ---------------------------------------------------------------
    WHY DO WE NEED TWO VECTORS?
    ---------------------------------------------------------------

    We maintain:

        nums
            Original array
            Never changes.

        ds
            Current subsequence being constructed.

    nums = [3,1,2]

    ds changes continuously.

        []
        [3]
        [3,1]
        [3,1,2]
        ...

    The original array should NEVER be modified.

    ---------------------------------------------------------------
    WHY push_back() ?
    ---------------------------------------------------------------

    When we decide to TAKE an element,

        ds.push_back(nums[index]);

    Example:

        ds = [3]

    Take 1

        ds = [3,1]

    This means our current subsequence now contains 1.

    ---------------------------------------------------------------
    WHY pop_back() ?
    ---------------------------------------------------------------

    pop_back() is NOT the "Don't Take" operation.

    It simply UNDOS the previous "Take" choice.

    Example:

        ds = [3]

    Take 1

        ds = [3,1]

    Explore every subsequence beginning with

        [3,1]

    After returning,

        ds is STILL

        [3,1]

    But now we want to explore

        [3]

    (without 1)

    Therefore,

        ds.pop_back();

    becomes

        [3]

    Now we can correctly explore the
    "Don't Take 1" branch.

    This undo operation is called

        BACKTRACKING

    ---------------------------------------------------------------
    WHAT DOES "DON'T TAKE" ACTUALLY MEAN?
    ---------------------------------------------------------------

    Don't Take does NOT mean

        "Ignore every remaining element."

    It simply means

        "Skip ONLY the current element."

    Example:

        Array = [3,1,2]

    Decisions:

        Take 3
        Skip 1
        Take 2

    Produces

        [3,2]

    Another path:

        Skip 3
        Take 1
        Skip 2

    Produces

        [1]

    Every element gets its own independent decision.

    ---------------------------------------------------------------
    PASS BY VALUE vs PASS BY REFERENCE
    ---------------------------------------------------------------

    PASS BY VALUE

        void solve(vector<int> ds)

    Every recursive call receives its own COPY
    of the subsequence vector.

        Call A

            ds = [3]

                  |

                  Copy

                  |

        Call B

            ds = [3,1]

    Modifying Call B's vector never affects Call A.

    PASS BY REFERENCE

        void solve(vector<int>& ds)

    There is only ONE vector shared among every
    recursive call.

        []

        ↓

        [3]

        ↓

        [3,1]

    Therefore after exploring one branch,
    we MUST restore the vector back to its previous state.

    That's why

        pop_back()

    becomes essential.

    ---------------------------------------------------------------
    WHY pop_back() IS STILL REQUIRED WITH PASS BY VALUE
    ---------------------------------------------------------------

    Although each recursive call receives a COPY,
    within the CURRENT FUNCTION the vector is still modified.

    Example:

        ds = [3]

        push_back(1)

        ds = [3,1]

    First recursive call receives

        [3,1]

    When it returns,

        CURRENT FUNCTION STILL HAS

        [3,1]

    But the second recursive call ("Don't Take")
    should start with

        [3]

    Therefore we restore the current function's vector.

        pop_back()

        ds = [3]

    Then call the second recursive branch.

    ---------------------------------------------------------------
    BASE CASE
    ---------------------------------------------------------------

    When

        index == nums.size()

    every element has already been processed.

    At this moment,

        ds

    represents one complete subsequence.

    Therefore,

        print(ds);

    and return.

    ---------------------------------------------------------------
    INTUITION
    ---------------------------------------------------------------

    Every recursive call asks ONLY ONE question:

        Should I take the current element?

            YES

                OR

            NO

    After making the decision,
    recursion moves to the next index
    and asks exactly the same question again.

    Eventually every possible combination of
    Take / Don't Take is explored.

    This is why recursion naturally generates
    all possible subsequences.

    ---------------------------------------------------------------
    COMPLEXITIES
    ---------------------------------------------------------------

    Number of subsequences

        = 2^n

    Time Complexity

        O(2^n * n)

    because there are 2^n subsequences and printing each
    subsequence may take O(n).

    Space Complexity

        O(n)

    due to recursion depth (and O(n) extra for the current
    subsequence if passed by reference).
*/


void printArray(vector<int>Arr){}

/*pehe subsequence dekh

maanle le 3 1 2 hai
pehle toh index 0 se start hoga toh pehle toh pussh back fn h
n fir contunous recursive calls h toh sarre elemnt push back hojaenge and poora vector print hokr 
return hojaega fir uske baad last elemnt pop hoga and recurisve call hogi n base condition run hogi and
ek subsequnce print hoga jisme last elemnt ni h becuase of the line 5th ,  
fir return hoga to line 3 kyuki reccursion m ham top to bottom stack jaate h and jis recusrion call m 3 2 1 print hua , usi  k neeche krenge ham
3 2 print hoga retrun h 
  */


  //vimpppppppp
//after a take happens function return back to skip part it doesnt go all the way up just one step back and does skip the elemt which it took

/* DRY RUN
    Array = [3,1,2]

    Function:

        solve(nums, ds, index)

    --------------------------------------------------------
    INITIAL CALL
    --------------------------------------------------------

    Call #1

        ds = []
        index = 0

    Current Element = 3

    --------------------------------------------------------
    TAKE 3
    --------------------------------------------------------

        ds.push_back(3);

        ds = [3]

    Recursive Call

        solve(index = 1)

    IMPORTANT:
    Call #1 pauses here.
    It waits until the entire subtree of index = 1 finishes.

    ========================================================
                    CALL #2
    ========================================================

        ds = [3]
        index = 1

    Current Element = 1

    --------------------------------------------------------
    TAKE 1
    --------------------------------------------------------

        ds.push_back(1);

        ds = [3,1]

    Recursive Call

        solve(index = 2)

    Call #2 pauses here.

    ========================================================
                    CALL #3
    ========================================================

        ds = [3,1]
        index = 2

    Current Element = 2

    --------------------------------------------------------
    TAKE 2
    --------------------------------------------------------

        ds.push_back(2);

        ds = [3,1,2]

    Recursive Call

        solve(index = 3)

    Call #3 pauses here.

    ========================================================
                    CALL #4
    ========================================================

        index = 3 == size

    Base Case

        Print

            [3,1,2]

    return;

    ========================================================
                BACK TO CALL #3
    ========================================================

    Call #3 resumes AFTER the recursive call.

    It DOES NOT start from the top again.

    Next instruction is

        pop_back();

    Undo the previous decision.

        ds = [3,1]

    --------------------------------------------------------
    DON'T TAKE 2
    --------------------------------------------------------

    Execute

        solve(index = 3)

    Since index == size,

    Base Case

        Print

            [3,1]

    return;

    Call #3 has no more statements.

    return;

    ========================================================
                BACK TO CALL #2
    ========================================================

    Call #2 resumes AFTER its recursive call.

    Execute

        pop_back();

    Undo taking 1.

        ds = [3]

    --------------------------------------------------------
    DON'T TAKE 1
    --------------------------------------------------------

    Execute

        solve(index = 2)

    ****************************************************************

    THIS IS THE MOST IMPORTANT STEP.

    This creates a BRAND NEW recursive call.

    It does NOT continue from where Call #3 stopped.

    Instead, it starts from the TOP of the function with

        ds = [3]
        index = 2

    Since index = 2,

    the function again asks

        Take 2 ?
        Don't Take 2 ?

    ****************************************************************

    ========================================================
                    CALL #5
    ========================================================

        ds = [3]
        index = 2

    --------------------------------------------------------
    TAKE 2
    --------------------------------------------------------

        push_back(2);

        ds = [3,2]

    solve(index = 3)

    Base Case

        Print

            [3,2]

    return;

    --------------------------------------------------------
    DON'T TAKE 2
    --------------------------------------------------------

    Undo

        pop_back();

        ds = [3]

    solve(index = 3)

    Base Case

        Print

            [3]

    return;

    Call #5 finishes.

    return;

    ========================================================
                BACK TO CALL #2
    ========================================================

    No statements left.

    return;

    ========================================================
                BACK TO CALL #1
    ========================================================

    Call #1 resumes after its recursive call.

    Undo taking 3.

        pop_back();

        ds = []

    --------------------------------------------------------
    DON'T TAKE 3
    --------------------------------------------------------

    Execute

        solve(index = 1)

    A NEW recursive call starts with

        ds = []
        index = 1

    The exact same process repeats and generates

        [1,2]
        [1]
        [2]
        []

    ========================================================
                    FINAL LEARNING
    ========================================================

    Every recursive call is responsible for ONLY ONE index.

    For that index it performs BOTH decisions:

        1. Take
        2. Don't Take

    The lifecycle of every recursive call is

        Enter Function
              ↓
        Take Current Element
              ↓
        Recurse
              ↓
        Child Returns
              ↓
        Undo Current Choice (pop_back)
              ↓
        Recurse Again (Don't Take)
              ↓
        Return to Parent

    IMPORTANT:

    pop_back() is NOT the "Don't Take" operation.

    It only restores the vector to its previous state.

    The actual "Don't Take" branch is explored by the SECOND
    recursive call.

    That second recursive call starts from the TOP of the
    function with the NEXT index.

    Example:

        Take 3
        Skip 1

    does NOT immediately print

        [3]

    Instead, recursion creates a NEW function with

        index = 2
        ds = [3]

    That new function again asks

        Take 2 ?
        Don't Take 2 ?

    producing

        [3,2]
        [3]

    This is the essence of Backtracking:

        Choose
            ↓
        Explore
            ↓
        Undo
            ↓
        Explore Alternative
            ↓
        Return
*/

void printSubsequenceOfArray(vector<int>&arr, vector<int>&subsequenceArr , int index){

    //1
    if(index>=arr.size()){
        printArray(subsequenceArr);
        return;
    }
   //2 
   subsequenceArr.push_back(arr[index]);//adding the new ele into the list
   //3 
   printSubsequenceOfArray(arr ,subsequenceArr ,index+1);//keeps on adding
    
   //4
    subsequenceArr.pop_back();//
    
    //5
    printSubsequenceOfArray(arr , subsequenceArr,index+1);
}


int main() {
    
    return 0;
}