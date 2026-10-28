#include <bits/stdc++.h>
using namespace std;

//brute force 
/*pehle jo nr hai usko binary fomrat mai convert kro
wo string vgrh wali bkchodi krke fir uski ith index set krdo fir 
decimal mai convert krdo dubara  */

int setTHeIthDigit(int n , int i){//logic is ith bit set hai ki nhi uske liye and krte the toh koi change ni hota tha
    //pr abh ith shift krke 1 ko hamm agr or kdenge toh ith wala 1 mai convert hojaega
    
    return (n|(i<<i));

}

int clearTheithDigit(int n , int i){//clearing the ith digit means , making it 0 if its 1 . eventually the ith digit should be 0
    /*logic is
    pehle 1 ko ith left shift kro
    fir uske baad uss ka not krdo taaki saare zero 1 bnn jaaeing and ith 
    digit 0 bnn jaaein and fir and krdo 
    and 0 ke saath i digit ka and 0 hi hoga and baaki digit jo 0 se 1 bne hai
    wo original binary nr ko effect ni krenge
    
    ex - n=13 , 1101
    i=2

    2 left shift to 1 , 0100
    iska not , 1011

    inka and
    00....1101 
    11....1011
    
    00....1001
    hogyi ith bit clear

    */

    return (n&(~(1<<i)));

}

int main() {
    
    return 0;
}