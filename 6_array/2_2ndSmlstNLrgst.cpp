//Find Second Smallest and Second Largest Element in an array


/*logic is find the largest element and traverse
the array again to find a element which is largest buit not 
equal to largest
similar for smallest
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
 
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
}

    int max;
    int smax= INT_MIN;
    max=INT_MIN;

      for(int i=0;i<n;i++){
        if(a[i]>max){
            max=a[i];
        }
      }

       for(int i=0;i<n;i++){
        if(a[i]>smax && a[i]!=max){
            smax=a[i];
        }
      }


      cout<<smax;





return 0;
}


//into the night