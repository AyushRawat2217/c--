#include <bits/stdc++.h>
using namespace std;
//nr of bits we need to flip to conver given integer to goal integer

/*logic 
pretty simple logic 
soppose we have given = 3 , and goal =4
3= 011 
4=100
expected ans=3 bits to flip to get to goal int.

lets say we do xor 
011 ^ 100 = 111

now onserve xor gives 1 when both nr are different , if both diff thna it means
given bit to be changed
so answer is simply the nr of set bits of xor

*/
int minBitFlips(int given , int goal){

int shifts=0;
int xxor = given^goal;

//now we will simply use the algo of counting the set bits

while(xxor & (xxor-1)){
    shifts++;
}

return shifts;
}

int main() {
    
    return 0;
}