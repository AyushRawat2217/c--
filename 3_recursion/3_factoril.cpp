#include <bits/stdc++.h>
using namespace std;
int factorial(int fac,int n){
    
    if(n>0){
        fac=fac*n;
        factorial(fac,n-1);
        return fac;
        

    }
    else{
       return fac;
    }
    

}
int main() {
int n;
cin>>n;
cout<<factorial(1,n);
return 0;
}