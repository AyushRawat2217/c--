#include <bits/stdc++.h>
using namespace std;

bool isItSorted(int arr[],int n){
    for(int i=0;i<n-1;i++){
        if(arr[i+1]<arr[i]){
            return false;

        }
    
    }

    return true;

}
int main() {
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    


    bool a=isItSorted(arr,n);

    if(!a){
        cout<<"NO";
    }
    else{
        cout<<"yes";
    }



    

return 0;
}