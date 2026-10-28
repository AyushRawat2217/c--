// #include <bits/stdc++.h>
// using namespace std;

// int divisors (int n){
//     for (int i=1;i<=(sqrt(n));i++){
//         if(n%i==0){
//             cout<<i<<endl;
//             if(i!=n%i){
//                 cout<<(n/i)<<endl;
//    }
            
//             }
        


//     }
//     return 0;

// }
// int main() {
//     int n;
//     cin>>n;
//     divisors(n);

// return 0;
// }
#include <bits/stdc++.h>
using namespace std;

void divisors(int n) {
    for (int i = 1; i*i <= (n); i++) {
        if (n % i == 0) {
            cout << i << " ";
            if (i != n / i) {
                cout << n / i << " ";
            }
        }
    }
}
    
int main() {
    int n;
    cin >> n;
    divisors(n);
    return 0;
}
