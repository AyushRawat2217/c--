#include <bits/stdc++.h>
using namespace std;

int powNBf(int num , int power){
    int n=1;
    while(power>0){
        n*=num;
        power--;
    }
    return n;
}//it wont work for big n and big power

//recursive approach
//more of a dividing the base into two part so power get reduced , so maths is easier


/*INT_MIN issue:

INT_MIN = -2147483648
INT_MAX = 2147483647

Magnitude of INT_MIN is bigger, so:

-INT_MIN → 2147483648 (cannot fit in int) → overflow

Solution:

Convert exponent to long long first
Then handle negative case

Why it works:

long long can store 2147483648 safely

Flow:

If n < 0 → invert base (x = 1/x)
Convert n to positive using long long
Apply binary exponentiation

Key takeaway:

Never do -n when n == INT_MIN in int
Always promote to larger type before negation
*/
int powNbf(int num , int power){
    if(power==0)return 1;
    if (power==1)return num;

    if(power%2==0)return powNbf(num*num , power/2);
    else return num*powNBf(num , power-1);
}

int main() {
    int n , power;
    cin>>n>>power;

    cout<<powNBf(n ,power);
    return 0;
}