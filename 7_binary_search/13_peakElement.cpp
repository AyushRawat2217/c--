#include <bits/stdc++.h>
using namespace std;


int searchPeak(vector<int>&arr ){ // i coded it all by myself and srivers did the same thing
    int low=1;//to keep bin search inbound
    int high=arr.size()-2; // same


    int mid;

    if(arr[0]>arr[1]) return arr[0];

    if(arr[high+1]>arr[high]) return arr[high];


    /*logic is agr mid ka prev elemnt chota and next elemnt bDaa h 
    toh right move krna h , and krte rehna h
    abh 2 cases h ki , peak elemnt mile ya aaghe sbh sorted ho ,
    peak element mill gya well n gud agr sbh sorted ho toh toh last elemnt ko peak
    kehh skte h kyuki wo prev ele se bda h

    agr mid vesa nhi h jesa prev case m socha h toh left move krenge
    */
    while(low<high){ // to avoid mid+1 when mid=n-1;
        mid= low+(high-low)/2;

        if((arr[mid]>arr[mid-1])&& (arr[mid]>arr[mid+1])){
            return arr[mid];
        }
        
        if((arr[mid]>arr[mid-1])){
            low=mid+1;
        }

        else{
            high=mid-1;
        }

    }

    return -1;
}


int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return 0;
}