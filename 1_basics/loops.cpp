#include <bits/stdc++.h>
using namespace std;
int main() {

// {

//     *    
//    ***   
//   *****  
//  ******* 
// *********
// for(int i=0;i<5;i++){
//     for(int j=0;j<(5-i-1);j++){
//         cout<<" ";
//     }
//       for(int j=0;j<(2*i+1);j++){
//         cout<<"*";
//     }
//     for(int j=0;j<(5-i-1);j++){
//         cout<<" ";
//     }

//      cout<<endl;

   
  
// }

// }





// *
// **
// ***
// ****
// *****
// ****
// ***
// **
// *

// for(int i=1;i<=9;i++){
//     if(i<=5){
//         for(int j=1;j<=i;j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }

//     else{
//          for(int j=(9-i+1);j>=1;j--){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
// }



// 1
// 01
// 101
// 0101
// 10101


// int num=1;
// for(int i=1;i<=5;i++){
//     if(i%2==0)num=0;
//     else num=1;

//     for(int j=1;j<=i;j++){
//         cout<<num;
//         num=1-num;
//     }
//     cout<<endl;
// }

// 1
// 1 21
// 12 321
// 123 4321
// int n=6;
// for (int i=1;i<=4;i++){
//     int n=1;
//     for(int j=1;j<i;j++){
//         cout<<j;
//     }

//    for(int j=1;j<=(n);j++){
//     cout<<" ";
        
//     }

//     for(int j=i;j>=1;j--){
//         cout<<j;
//     }
//     cout<<endl;

//     n-=2;




    

// }

// 1 3
// 2 2
// 3 1
// 4 0


// for(int i=0;i<4;i++){


//   for(int j=0;j<(4-i);j++){
//     cout<<" ";
//   }
// }



{

// E
// DE
// CDE
// BCDE
// ABCDE
// for(char i='E';i>='A';i--){
//   for(char j=i;j<='E';j++){

//     cout<<j;


// }
// cout<<endl;
// }

}

// {

// **********
// ****  ****
// ***    ***
// **      **
// *        *
// *        *
// **      **
// ***    ***
// ****  ****
// **********



// for(int i=0;i<=4;i++){
//   for(int j=0;j<5-i;j++){
//     cout<<"*";
//   }

//   for(int j=0;j<2*i;j++){
//     cout<<" ";
//   }

//   for(int j=0;j<5-i;j++){
//     cout<<"*";
//   }

//   cout<<endl;

  

// }


// for(int i=4;i>=0;i--){
//   for(int j=0;j<5-i;j++){
//     cout<<"*";
//   }

//   for(int j=0;j<2*i;j++){
//     cout<<" ";
//   }

//   for(int j=0;j<5-i;j++){
//     cout<<"*";
//   }

//   cout<<endl;

  

// }
// }

    int n = 8; // number of rows in each half

    // UPPER half
    for (int i = 1; i <= n; i++) {
        // left stars
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }

        // spaces between two star blocks
        for (int j = 1; j <= (2*n - 2*i); j++) {
            cout << " ";
        }

        // right stars
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }

        cout << endl;
    }

    // LOWER half
    for (int i = n; i >= 1; i--) {
        // left stars
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }

        // spaces
        for (int j = 1; j <= (2*n - 2*i); j++) {
            cout << " ";
        }

        // right stars
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }

        cout << endl;
    }




return 0;
}