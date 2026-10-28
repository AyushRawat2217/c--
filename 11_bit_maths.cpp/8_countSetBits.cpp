#include <bits/stdc++.h>
using namespace std;

int countingSetBitsStringApprch(int n ){

    int count=0;
    while(n!=1){
        /*if(n%2==1){
            count++;
        }

        this can be written as
        n%2==1 as n&1
n=n/2;
        as only odd nr gives remainder 1 when divided by 2 , and odd nr has lsb as 1
        and when we do and of odd and 1 , we get but for even we get 0

        so 
        if(n&1)count++;
        or simply count+=n&1           
        */

        count+=n&1;

        //n=n/2; this can be written as n>>1
        n>>1;

    }

    return count;
}

/*logic
until i clear all set bits i keep doing it and counting it*/
int countingSetBitsNminus1Approach(int n ){
    int count=0;

    while(n&(n-1)){
        count++;
        n--;
    }

    return count;

}

int main() {
    
    return 0;
}