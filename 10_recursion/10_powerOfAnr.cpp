#include <bits/stdc++.h>
using namespace std;

int powerOfnrRec(int nr ,int power  , int result){
    if(power<1)return result;
    result*=nr;
    return powerOfnrRec(nr , power-1 ,result);
}

int main() {
    int n;
    cin>>n;
 int pwr;
 cin>>pwr;
 cout<<powerOfnrRec(n , pwr , 1);
    return 0;
}