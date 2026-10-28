#include <bits/stdc++.h>
using namespace std;

//code to check whether a nr is prime or not
bool primeNrChecker(int n){
    /*why did we use 1-root n , not 1 -n?
    because after 1-root n , multiplaction flip hojati hai
    jese
    18 hai , iska root n 4 hai abs terms mai
    1 18
    2 9
    3 6
    dekh 4 tkk tha fir uske baad it started repeting itself in flipped order
    nd it chnge o(N) to o(root n)
    6 3
    9 2
    18 1
    */



    /*Algorithm:
1. If n <= 1, return false because 0 and 1 are not prime.
2. Check every number from i = 2 while i * i <= n.
3. If n is divisible by any i, return false immediately.
4. If no divisor is found, return true.

Why only till sqrt(n)?
Factors always occur in pairs.
If n = a * b and both a and b were greater than sqrt(n),
then a * b > n, which is impossible.
So at least one factor must be <= sqrt(n).

Why no 'count' variable?
We only need to know if a divisor exists.
The first divisor found proves n is not prime,
so we return false immediately.

Dry Run:

n = 0
Step 1: n <= 1 -> return false

n = 1
Step 1: n <= 1 -> return false

n = 2
Step 1: n <= 1 -> false
Loop condition:
i = 2
2 * 2 <= 2 ? false
Loop doesn't execute.
Return true.

n = 3
Step 1: n <= 1 -> false
Loop condition:
i = 2
2 * 2 <= 3 ? false
Loop doesn't execute.
Return true.

n = 4
i = 2
2 * 2 <= 4 ? true
4 % 2 == 0 -> return false

n = 17
i = 2 -> not divisible
i = 3 -> not divisible
Next: 4 * 4 <= 17 ? true
i = 4 -> not divisible
Next: 5 * 5 <= 17 ? false
No divisor found -> return true.
*/
   

if(n<=1)return false;
    for (int i = 2; i*i<=n; i++) {
      if(n%i==0)return false;
    }
    return true;
}



//the problem ask us to collect print prime factors of a nr  , the factors which are prime
void collectPrimeFactorsBf(int n ,vector<int>&listPf){
    
    if(n<=1)return;
    for (int i = 2; i < n; i++) {//i r the factors we are checking
      
        if(n%i==0){
            if(primeNrChecker(i)){//if i is prime then add it to list
                listPf.push_back(i);
            }
        }
    }
}
//tc is o(n* root n) , sc cant be determined

//we can reduce the tc
void collectPrimeFactorsBf(int n ,vector<int>&listPf){
    //as factors flip after root n
    /*for n=36
    2 18
    3 12
    4 9
    6 6
    9 4
    .
    .
    .

    it repeated from 6 
    so one factor is i other is n/i , so i can use n/i to find other factor
    and check whther it is prime or not like without travering while 1-n
    */

    for (int i = 2; i*i<n; i++) {

      if(n%i==0){
        if(primeNrChecker(i))listPf.push_back(i);
        if(i != (n/i)){
            if(primeNrChecker(n/i))listPf.push_back(n/i);
        }
      }
    }
}
//tc o(root n * 2* root n) main loop rootnm , and 2 prime checker , sc cant be determined
//btw its not even exact because loop will skip many i's and it just worts case


void collectPrimeFactorsBr(int n ,vector<int>&listPf){

    for (int i = 2; i <=n; i++) {
      if(n%i==0){
        listPf.push_back(i);
        while(n%i==0){//keep dividing by the smallest 
            //ek point k baad maanlo i=2 hai , and we have divide it by 2 such way ki or ni hora
            //fir next nr pe move krenge n in future ye 4 , 6 , 8 ..etc se divide bhi ni hoga kyuki 2 ke saare factors khtm krdiye hmmne
            n=n/i;
        }
      }

    }
}//tc is on


void collectPrimeFactorsOpt(int n ,vector<int>&listPf){

    for (int i = 2; i*i<=n; i++) {
      if(n%i==0){
        listPf.push_back(i);
        while(n%i==0){//keep dividing by the smallest 
            //ek point k baad maanlo i=2 hai , and we have divide it by 2 such way ki or ni hora
            //fir next nr pe move krenge n in future ye 4 , 6 , 8 ..etc se divide bhi ni hoga kyuki 2 ke saare factors khtm krdiye hmmne
            n=n/i;
        }
      }
      if(n!=1)listPf.push_back(n);
      /*dry run
      16

      2 to 4

      2 16
      2  8
      2  4
      2  2
         1

      3 21
         7
         n becomes 7 and 7 i out of tange as 7> root 21
         but later n!=1 . so we incorporate 7 in list

     
      */
    }
}


int main() {
    int n;
    cin>>n;
    if(primeNrChecker(n))cout<<"true";
    else cout<<"false";
    
    return 0;
}