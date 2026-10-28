#include <bits/stdc++.h>
using namespace std;


//all this till main fn works for small ranges only , for better soln we need to to use sieve of erashthones
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

void insertCountOfPrime(int start , int end , vector<int>&result){
    int count=0;
    for (int i = start; i <= end; i++) {
      if(primeNrChecker(i))count++;
    }
    result.push_back(count);
}

void mainFn(vector<vector<int>>&arr , vector<int>&result){
    for (int i = 0; i < arr.size(); i++) {
        insertCountOfPrime(arr[i][0] ,arr[i][1] , result);
    }
}

















//optimal soln using sieve of erasthothenes

//first create a function which build an array till n , which marks prime number as true and non prime as false
//index are nrs and values are true false

vector<bool> primeNrTillN(int n){
   vector<bool>primeNr(n+1 , true);

   primeNr[0]=primeNr[1]=false;
   for (int i = 2; i <=n; i++) {
          
      if(primeNr[i]){//if i is prime nr

        for (int j = i*i; i <= n; j+=i) {//j ko i ke multiple jitna badha
      /*why we start from i*i?
      // Why do we start marking from i * i ?

// For any number i, all multiples smaller than i*i
// (like i*2, i*3, ..., i*(i-1)) are already marked
// by smaller prime numbers.

// Example:
// i = 5
// Multiples: 10 (2×5), 15 (3×5), 20 (4×5)
// These were already removed when processing 2 and 3.

// So the first new multiple that hasn't been touched yet is:
// 5 × 5 = 25

// General logic:
// If x = i * k and k < i
// → k is already processed
// → x is already marked

// Therefore, we start from i*i to avoid redundant work
// and keep the time complexity optimal (O(N log log N)).*/
          
          primeNr[j]=false;

        }

       }

      
     
   }

   return primeNr;
}
//here we have our prime nr strip



//now we will create a function prifix which return how many primes are there till a nr
/*logic
// PREFIX ARRAY FOR PRIME COUNT

// prefix[i] = number of prime numbers from 1 to i (inclusive)

// Core idea:
// Each position carries forward the previous count,
// and adds +1 only if current number is prime.

// Formula:
// prefix[i] = prefix[i-1] + (primeNr[i] ? 1 : 0)

// Example:

// Number:    1  2  3  4  5  6  7
// isPrime:   F  T  T  F  T  F  T
// prefix:    0  1  2  2  3  3  4

// Explanation:
// i = 2 → prime → prefix[2] = 0 + 1 = 1
// i = 3 → prime → prefix[3] = 1 + 1 = 2
// i = 4 → not prime → prefix[4] = 2
// i = 5 → prime → prefix[5] = 2 + 1 = 3

// So prefix[i] always stores cumulative count of primes till i.

// Usage in queries:
// To count primes in range [L, R]:
// answer = prefix[R] - prefix[L - 1]

// This works because:
// prefix[R] gives primes till R
// prefix[L-1] removes primes before L

*/
vector<int> prefix(vector<bool>primeNr , int num){//num is the upper limit of range we are given
  
  vector<int>prefix;

  for (int i = 1; i <=num; i++) {
      if(primeNr[i])prefix[i]=prefix[i-1]+1;
      else prefix[i]=prefix[i-1];
    }
    
return prefix;
}


vector<int>mainFnOpt(vector<vector<int>>&arr , int n ){
   vector<int>result;
   int maxN = 0;
    
    // find max range
    for (auto &q : arr){//we got the max upper limit
        maxN = max(maxN, q[1]);
    }
    vector<bool>primeNr=primeNrTillN(maxN);//to create that prime nr strip

    vector<int>prefixx;//to store what prefixx returns


    int countOfPrime;
    for (int i = 0; i < n; i++) {
       prefixx=prefix(primeNr , arr[i][1]);

       countOfPrime=prefixx[arr[i][0]]-prefixx[arr[i][1]];
       result.push_back(countOfPrime);

    }

    return result;
   
}



int main() {

    int n;
    cin>>n;
    vector<vector<int>>arr(n , vector<int>(2));
    
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 2; j++) {
        cin>>arr[i][j];
      }
    }

    vector<int>result;

    mainFn(arr ,result );

    for(int i:result)cout<<i<<" ";

    return 0;
}