#include <bits/stdc++.h>
using namespace std;
int prnt1N(int start , int end){
    if(start<=end){
        
        cout<<start<<endl;
        prnt1N(start+1,end);


    }
    return 0;

}
int main() {
    int n;
    cin>>n;
    cout<<"Numbers are:\n";
    prnt1N(1,n);

return 0;
}