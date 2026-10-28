#include <bits/stdc++.h>
using namespace std;

bool isNrPowerOf2(int n){
    /*if a nr is power of 2 then
    it has just one set bit , other wise its not
    if i n&n-1 then it should become 0*/

    if(n&(n-1))return false;
    return true;
}

int main() {
    
    return 0;
}