#include <bits/stdc++.h>
using namespace std;

int rmvDuplicatesSortedArr(vector<int>&arr){
    int i=0;
    int j=1;
    
    while(j<arr.size()){
        /* for example
        2 2 3 5 
        i j
        
        a[i]==a[j]
        j++;

        2 2 3 5
        i   j

        now i++ and a[i] =a[j]

        2 3 3 5
          i  j
        
          j++
          2 3 3 5
            i    j

            i++;
            a[i]=a[j]

            2 3 5 3
                i j
          
        */
        if(arr[i]!=arr[j]){
            i++;
            arr[i]=arr[j];
        }
        j++;

    }
 return i+1;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < rmvDuplicatesSortedArr(arr); i++) {
      cout<<arr[i];
    }

    return 0;
}