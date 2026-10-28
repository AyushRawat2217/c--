//we have to clear the rightmost set bit
//ex-: 110100 , after clearing it becomes 110000

/*logic


// =============================
// Why does (n - 1) flip bits?
// =============================
//
// Binary subtraction works exactly like decimal subtraction:
// If you can't subtract 1 from the last bit (0 - 1), the computer BORROWS
// from the nearest 1 on the left.
//
// Example:
//
//      1010100
//   -  0000001
//
// Starting from the right:
// - 0 - 1 is not possible, so borrow.
// - Move left until the first 1 is found.
// - That borrowed 1 becomes 0.
// - Every 0 crossed during borrowing becomes 1.
//
// Result:
//
// Original : 1010100
// n - 1    : 1010011
//because of subtracting from 1
// Observation:
// • The rightmost set bit (1) becomes 0.
// • Every bit to its right becomes 1.
// • Bits to its left remain unchanged.
//
// General Pattern:
//
// Original : xxxxx1000...000
// n - 1    : xxxxx0111...111
//
// Now perform:
//
// n & (n - 1)
//
// xxxxx1000...000
// xxxxx0111...111
// ----------------
// xxxxx0000...000
//
// Why?
// • Higher bits remain unchanged (1&1 = 1, 0&0 = 0).
// • The rightmost set bit is removed (1&0 = 0).
// • Right-side bits stay 0 because the original already had 0s there (0&1 = 0).
//
// Final Result:
// n & (n - 1) removes the rightmost (least significant) set bit.
//
// Tip:
// Think of (n - 1) as "borrowing from the rightmost 1":
// - That 1 is consumed (becomes 0).
// - All zeros after it temporarily become 1 due to the borrow.
// - AND with the original wipes those temporary 1s away, leaving only the
//   rightmost set bit removed.


*/

#include <bits/stdc++.h>
using namespace std;

int clearingLeftmostSetBit(int n){
    return (n &(n-1));
}

int main() {
    
    return 0;
}