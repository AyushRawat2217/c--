#include <bits/stdc++.h>
using namespace std;

int findMssngNr(vector<int>&arr , int n){
    vector<int>num(10 , 0);

    for(int i:arr){
        num[i]=1;
    }
    
    for (int i = 0; i < 10; i++) {
      if(num[i]==0)return i;
    }
    return -1;

}


int main() {
    
    return 0;
}