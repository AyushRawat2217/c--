#include <bits/stdc++.h>
using namespace std;

void revArrayRec(vector<int>arr,int i , int j){// 2 ptrs approach where i is iniliased as 0 and j as n-1
    if(i<j)return ;
    swap(arr[i],arr[j]);
    revArrayRec(arr ,i+1 , j-1);
}

void revArrayRec2ptr( vector<int>&arr , int i ){
    if((i)>(arr.size()-i-1))return ;
    swap(arr[i] , arr[arr.size()-1-i]);
    revArrayRec2ptr(arr ,i-1 );
}


int main() {
    
    return 0;
}