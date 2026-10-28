#include <bits/stdc++.h>
using namespace std;

void printSubsequenceElemnt(vector<int>&arr){}


//its going to oprint those susenwnece whose sum of elemnt is going to be k
void printingSbsqnces(vector<int>&arr , vector<int>&list , int sum , int index , int k){//dum is track of sum of elemnts of subsequence createed
if(index>=arr.size()){
    if(sum==k)printSubsequenceElemnt(list);
    return;
}
list.push_back(arr[index]);
sum+=arr[index];
printingSbsqnces(arr , list , sum , index+1 , k);
list.pop_back();
sum-=arr[index];
printingSbsqnces(arr , list , sum , index+1 , k);
}

int main() {
    int n , sum ,k;
    cin>>n;
    vector<int>arr;
    vector<int>empty;
    printingSbsqnces(arr , empty ,sum , 0 , k);
    return 0;
}