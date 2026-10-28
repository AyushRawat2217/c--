#include <bits/stdc++.h>
using namespace std;

int maxOneBF (vector <int> &arr , int n){
 int max1=0;
 int maxx=0;



for(int i=0;i<n;i++){

    if(arr[i]==1){
        max1=max1+1;
    }

    else{
        maxx=max(maxx,max1);
        max1=0;
    }

    }
    maxx=max(maxx,max1); //fina check is neccesary because
    /*.

🔻 Example Where You FAIL
[1,1,1,1]

Your loop:

Keeps increasing max1
NEVER hits else
NEVER updates maxx

Final output:

0 ❌ (wrong)

Correct answer:

4*/
 return maxx;
 
}
int main() {

    int n;
    cin >> n;
  
    vector<int> arr(n); //either specify size of vector or use pushback  

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout<<maxOneBF(arr, n);





return 0;
}