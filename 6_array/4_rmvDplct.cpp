#include <bits/stdc++.h>
#include <vector>
using namespace std;

int twoptr(int arr[],int n){ //opt
    int i=0;
    int j=1;


    while(j<n){
        if(arr[i]!=arr[j]){
            i++;
            arr[i]=arr[j];
        }
       j++;
    }

    return i+1; // as we push the duplicate elemtnt power to last elemnt so we only print elemnt till that part where there are no duplicates
//best way  to revise is dry  run
}


void rmvDPlct(int arr[],int n){ //brute force
    vector<int>b;

    
    for(int i=0;i<n-1;i++){
        if(arr[i]!=arr[i+1]){
            
            b.push_back(arr[i]);
        }
    }

    b.push_back(arr[n-1]);

    for(int x:b){
        cout<<x<<endl;
    }


}


int main() {
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }


    int a=twoptr(arr,n);

     for(int i=0;i<a;i++){
        cout<<arr[i];
    }

   
    


return 0;
}