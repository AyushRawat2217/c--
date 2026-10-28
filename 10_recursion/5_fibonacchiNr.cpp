#include <bits/stdc++.h>
using namespace std;
/*printing n fibonacci nr
0 1 1 2 3 5 8 13 21*/

/*ye multiple recusrion ka concept h
isme f(n-1) n f(n-2) alg alg time m chlre h
 */



 /*  for refrence not the actual course of action

                                    fib(5)
                                 /        \
                           fib(4)          fib(3)
                          /      \        /      \
                    fib(3)      fib(2) fib(2)   fib(1)
                   /     \      /    \   /   \
             fib(2)    fib(1) fib(1) fib(0) fib(1) fib(0)
             /    \
        fib(1)  fib(0)
        
*/


/*DRY RUN (fib(5))
    ----------------

    Fibonacci follows the recurrence relation:

        fib(n) = fib(n-1) + fib(n-2)

    Base Cases:

        fib(0) = 0
        fib(1) = 1

    ----------------------------------------------------------------
    IMPORTANT:
    ----------------------------------------------------------------
    Although every node in the recursion tree has two children,
    they are NOT executed together.

    Since the code is:

        int last = fibonacciNrs(n - 1);
        int prevOfLast = fibonacciNrs(n - 2);

    the function FIRST computes fib(n-1) completely.
    Only after it returns does it start computing fib(n-2).

    Therefore recursion executes in a Depth-First Search (DFS) manner.

    ----------------------------------------------------------------
    ACTUAL EXECUTION ORDER
    ----------------------------------------------------------------


/*
fib(5)
│
├── fib(4)
│   │
│   ├── fib(3)
│   │   │
│   │   ├── fib(2)
│   │   │   │
│   │   │   ├── fib(1) → returns 1
│   │   │   └── fib(0) → returns 0
│   │   │
│   │   │   fib(2) = 1 + 0 = 1 → returns 1 //fib(2) krra h actual work
│   │   │
│   │   └── fib(1) → returns 1
│   │
│   │   fib(3) = 1 + 1 = 2 → returns 2
│   │
│   └── fib(2)
│       │
│       ├── fib(1) → returns 1
│       └── fib(0) → returns 0
│
│       fib(2) = 1 + 0 = 1 → returns 1
│
│   fib(4) = 2 + 1 = 3 → returns 3
│
└── fib(3)
    │
    ├── fib(2)
    │   │
    │   ├── fib(1) → returns 1
    │   └── fib(0) → returns 0
    │
    │   fib(2) = 1 + 0 = 1 → returns 1
    │
    └── fib(1) → returns 1
│
│   fib(3) = 1 + 1 = 2 → returns 2

fib(5) = 3 + 2 = 5
   

    ----------------------------------------------------------------
    HOW THE ANSWER IS FORMED
    ----------------------------------------------------------------

    fib(2) returns 1
           ↓
    fib(3) receives:
        fib(2) = 1
        fib(1) = 1
        returns 2
           ↓
    fib(4) receives:
        fib(3) = 2
        fib(2) = 1
        returns 3
           ↓
    fib(5) receives:
        fib(4) = 3
        fib(3) = 2
        returns 5

    Observe that every function waits until BOTH recursive calls
    have returned. Once both answers are available, it adds them
    and returns the result to its parent.

    This is a classic example of Functional Recursion where values
    are computed during stack unwinding and bubble up to the
    original caller.
*/




int nthNroFfibonacciSeries(int n ){
if(n<=1){//abh jbh n=0 hoga toh 0 return hojaega similarly 1 return hoga jbh n=1 return hoga
    return n;
}

int last=nthNroFfibonacciSeries(n-1);
int prevOfLast=nthNroFfibonacciSeries(n-2);
return last + prevOfLast;
//current n is the sum of its previous and previous of it previous when 

}


/*tc is o 2 ki power n
sc is n , as n recursive stacks each*/


int main() {
    int n;
    cin>>n;
    nthNroFfibonacciSeries(n );
    return 0;
}