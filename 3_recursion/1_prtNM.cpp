#include <bits/stdc++.h>
using namespace std;


void printName(int count ,int n ,string name){

   if (count>n) return ;

   cout<<name<<endl;
   printName(count+1,n,name);
}


int main() {

    int n;
    cin>>n;
    string name;
    cin>>name;
    printName(1,n,name);
    



return 0;
}