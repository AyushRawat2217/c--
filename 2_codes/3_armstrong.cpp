#include <bits/stdc++.h>
using namespace std;
bool amstg(int n){
    int count = 0;
    int b=n;
    while (b > 0)
    {
        count+=pow(b%10,3);
       
        b =  b/ 10;
    }
    
return (n==count);




}
int main() {
int n;
cin>>n;

if(amstg(n)) cout<<"yes , it is armstrong";
else cout<<"no ,it is not";


}