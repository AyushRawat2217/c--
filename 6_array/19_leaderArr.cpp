#include <bits/stdc++.h>
using namespace std;


/*leadder is if all elemnts to its right are smaller than it , and 
the last elemnent is default leader

Example 1:
Input:
 arr = [4, 7, 1, 0]  
Output:
 7 1 0  
Explanation:
 The rightmost element (0) is always a leader.  
7 and 1 are greater than the elements to their right, making them leaders as well.*/


void ldrArrBf(vector <int>&arr, int n){
    for (int i = 0; i < n; i++) {
        int ldr =1; //i could have used true false here

        for (int j= i+1; j < n; j++) {

            if(arr[i]<arr[j]){
                ldr=0;
                break;
            }
          
        }
        if(ldr==1){
            cout<<arr[i];
        }
      
    }
}
//tc-o n2

/*logic is last se shrur kro , rightmost elemnt print krdo 
fir left jaao , agr left bda h right side k max elemnt se toh wo leader h 
otherwise nhi h*/

void ldrArrOpt (vector <int>&arr, int n){
    int max1=INT_MIN;
    cout<<arr[n-1]<<endl;
    for (int i = n-1; i>0; i--) {
        max1=max(max1,arr[i]);
        if(arr[i-1]>max1){
            cout<<arr[i-1]<<endl;
        }

        
      
    }

}
//tc-on


int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ldrArrOpt(arr,n);
    
    return 0;
}