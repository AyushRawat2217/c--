#include <bits/stdc++.h>
using namespace std;

//swap using xor
//we change the binary digit inside the decimal nr using xor manipulation

int main() {
    int a , b;
    cin>>a;
    cin>>b;

     a=a^b;//5^6
    b=a^b;//(5^6)^6=5
    a=a^b;//(5^6)^5=6

    cout<<a<<" "<<b;
    
    return 0;
}