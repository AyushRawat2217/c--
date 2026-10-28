#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int hash[13]={0};
     for(int i=0;i<n;i++){
        hash[a[i]]+=1;
     }


     while(n--){
        int num;
        cout<<"enter number you wanna find";
    
        cin>>num;
        
        cout<<hash[num]<<endl;
     }

return 0;
}