#include <bits/stdc++.h>
using namespace std;
int hashh[10000000];
int main() {
    string s="ababcde";

    for(int i=0;i<(s.size());i++){
        hashh[s[i]]+=1;
    }

    while(true){
        char c;
        cout<<"enter char"<<" ";
        cin>>c;

        cout<<hashh[c]<<endl;


    }

return 0;
}