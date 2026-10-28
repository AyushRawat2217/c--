#include <bits/stdc++.h>
using namespace std;

bool ithBitSetOrNot(int num , int i){//we are given num and we have to check whther its ith bit is set or not
    
    /*logic
    maan lo n=13 hai
    1101
    if asked whether 2 nd bit from left is set or not
    
    algo is
    1<<i , 1 ki bin ko i baar left shift krdo
    i.e 0100

    fir iska n ke saath and krdo
    dekh i shift isliye kiya kyuki jo last bit wala 1 hai na wo ith nr pe aajega
    abh sirf wo ek single 1 hai baaki 0 hai toh and hoga toh saare zero cancel out krdenge baaki bin nr ko
    and ith bit agr hogi toh 1 and 1 , 1 aaega non zero
    otherwise zero rhega


    similarly we can do with right shift
    jo ith wala bit hai usko i places right krdo taaki wo 
    0001 mai 1 wali position ke upr aajein and fir and krdo simple and sorted

    if((num>>i)&1)return true;
    */

   if(num&(1<<i))return true;

   return false;//if the whole condition is 0
 
}

int main() {

    
    return 0;
}