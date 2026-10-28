/*
pascal triangle
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1  

this problem has 3 types first when u will be given
the row no. n col no. n u have to print that elemnt
2. when u will be given the row no. n u hve to print the elemnts
3. wehn u will be given n , n u have to print the whole pascal triangle
*/









#include <bits/stdc++.h>
using namespace std;
 //case 1 , n and r(column) is given
    /*logic is the nth row r th column element is n-1 C r-1
    we first create a factorial function then use it to return the value
    */

int ncr(int n , int r){
    int ans=1;
    for (int i = 0; i<r; i++) {
        
        ans= (ans*(n-i))/(i+1); //we take help of operator precedence here first multiply then divide
        // cout<<ans<<endl
    }
    return ans;
    }

int elementOfPtriangle(int n , int r){
    return ncr(n-1 , r-1);
}






/*case 2 we will be given row no. then i have to print the
uss row k elements

logic is i will be pusbacking nth row rth elemnt in a vector then returning it
nth row has , n elemnts

*/

vector <int> RowOfPtriangleBf(int n){
    vector<int>row;
    for (int i = 1; i <= n; i++) {
        row.push_back(ncr(n-1 ,i-1));
    }
    return row;
    //its tc is o n*r , so we will optimise it , n eleimate the ncr formula we r using
}

vector <int> RowOfPtriangleOpt(int n){
    int ans =1;
    vector<int>row;
    row.push_back(1);
    for (int i = 1; i < n; i++) {
        //here we substituted the function ncr with calculation it was doing inside a separate function
        //using this we reduced the time complexity
        ans= (ans*(n-i))/i;
    }
    return row;
    
}








/*
case 3-: we have to print the whole pascale triangle now till nth row

,we will use two loops to do so

bf inside this would be using the ncr funtion making it tc n2r
but the optimal approach will be doing calculation inside the loops
*/

void printPacalTriangle(int n){
    int ans=1;
    for (int i = 1; i <=n; i++) {
        cout<<ans;
      for (int j = 1; j <i; j++) {
        ans=ans*(i-j)/j;
        cout<<ans;  
      }
      cout<<endl;
      ans=1;
    }
}




int main() {
    int n ,r;
    cin >> n>>r;
    
    // vector<int> arr(n);
    // for (int i = 0; i < n; i++) {
    //     cin >> arr[i];
    // }

    // int result = ncr(n-1,r-1);
    // cout<<result;
    vector<int >result=RowOfPtriangleBf(n);

    for(auto &it : result){
        cout<<it<<" ";

    }

    
    return 0;
}