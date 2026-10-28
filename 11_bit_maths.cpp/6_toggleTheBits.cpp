#include <bits/stdc++.h>
using namespace std;

//toggle mean make 1 to 0 , and 0 to 1

//2041
int toggleTheBit(int n , int i){
    
    
    /*logic 
    
    is using the xor operator

    1101 , i=2 
    result = 1001
    
    1>>i ,0100
    
    1101 ^ 0100 = 1001

    ye isliye hora ki , for non ith nrs -: maanlo original bit 0 hai  toh xor ki vjh se wo 0 ^ 0=0 hi aaega and for 1 , 1^0 aaega 1.
    for ith , 0^1 = 1 and 1^1=0 , toggle hojaega aise
    */


    return (n^(1<<i));



}

int main() {
    
    return 0;
}