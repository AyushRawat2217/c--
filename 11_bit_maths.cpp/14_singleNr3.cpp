#include <bits/stdc++.h>
using namespace std;

/*prob
isme krna ye hai ki ek array hogi usme saare duplicate honge
bss 2 nr honge jo sirf single hai hme unn dono ki pair return krwani hai*/

//bf logic
/*simple sa hai
ya hashing use krlo yaa 2 loops lgaake pair mai 2no nr daalkr return krdo*/


//2308
pair<int,int> singleNr3(vector<int>&arr ,int n){

    int result=0;
    for (int i = 0; i < n; i++) {
      result^=arr[i];
    }
    //now my result have  xor of both the unique nrs 
    
    //now i find the rightmost set bit , because i know at that set bit 
    //both nrs bits are different thats why the combinded bit is set and i will
    //use this info to separate both the unique nrs
    //now task is finding the set bit

    //trick for rightmost bit

    int rightMostSetBit= result & (-result);
    /* Why does x & (-x) give the rightmost set bit?

    Key fact:
    -x is represented using 2's complement.

        -x = (~x) + 1

    Example:
        x = 40

        x   = 101000
        ~x  = 010111
        +1  = 011000   (-x)

        x      = 101000
        -x     = 011000
        ----------------
        x & -x = 001000

    Result:
        Only the RIGHTMOST set bit remains.

    --------------------------------------------------------

    Intuition:

    Suppose x looks like:

        xxxxx1000...000
             ^
        Rightmost set bit

    - All bits to the right are 0.
    - Computing -x (~x + 1) flips the left part and propagates a carry.
    - The rightmost set bit remains 1 in both x and -x.
    - Bits to the left differ, so AND makes them 0.
    - Bits to the right are already 0.

    Therefore:

        x      = xxxxx1000...000
        -x     = yyyyy1000...000
        ------------------------
        x & -x = 000001000...000

    Hence,

        x & (-x)

    isolates the lowest (rightmost) set bit in O(1) time.

    Common uses:
    - Separate two unique numbers in XOR problems.
    - Fenwick Tree (Binary Indexed Tree): lowbit = x & -x.
    - General bit manipulation problems requiring the lowest set bit.
*/

    //now lets separate all nrs in two groups 
    //first group which have that partivcular bit set 
    //second group which doesnt

    int firstNum=0;
    int secNum=0;
    for (int i = 0; i < n; i++) {
      if(arr[i]&rightMostSetBit)firstNum^=arr[i];
      else secNum^=arr[i];
    }

    return { min(firstNum , secNum),max(firstNum , secNum)  };

}

int main() {
    
    return 0;
}