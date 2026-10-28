#include <bits/stdc++.h>
using namespace std;
int main() {

    //brute force approach
    int n;
    cout<<"enter number";
cin>>n;

// int count=0;
// while(n>0){
//     n=(n/10);
  
//     count+=1;

// }
// cout<<count;

//optimal

cout<<(int(log10(n)+1));


return 0;
}