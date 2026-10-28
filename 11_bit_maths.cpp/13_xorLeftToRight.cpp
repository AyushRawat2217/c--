#include <bits/stdc++.h>
using namespace std;

int xorLtoRBf(int left , int right){

    int result=left;
    for (int i = left+1; i <= right; i++) {
      result^=i;
    }

    return result;
}
//2245
/*logic 
there is a pattern to itPattern

Let:

f(n)=1^2^3^....n

| `n % 4` | `XOR(1...n)` |
| ------- | ------------ |
| `0`     | `n`          |
| `1`     | `1`          |
| `2`     | `n + 1`      |
| `3`     | `0`          |


we will exploit this

xor of nr bw l to r = (1^2^3..l-1)^(1^2^3...r)

numbers from 1 to l-1 are not needed so they eventually will get canceeled out
they will give zero as they are same and at the end 0^0 wll be zero
and 0^any nmbr is any nmbr

*/

int xorUptoN(int n) {
    switch (n % 4) {
        case 0: return n;
        case 1: return 1;
        case 2: return n + 1;
        case 3: return 0;
    }
    return 0;
}

int xorLtoROpt(int left , int right){
    return (xorUptoN(left-1)^xorUptoN(right));
}

int main() {
    
    return 0;
}