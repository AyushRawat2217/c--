#include <bits/stdc++.h>
using namespace std;

//name ko recursion ka use krke n bar print krna
void printName(const string &s , int n ){
    if(n==0)return;//saala void k saath return use krkste h aaj hi pta chla bc
    cout<<s;
    printName(s,n-1);
}

//print nr 1-n
/*APPROACH:
    ----------
    We want to print numbers from 1 to N using recursion
    without maintaining an extra "start" variable.

    IDEA:
    -----
    Instead of moving upward (1 -> 2 -> 3 -> ... -> N),
    we move downward (N -> N-1 -> N-2 -> ... -> 0).

    The recursive call is made FIRST:

        printNr(n - 1);

    This keeps reducing the problem size until we reach
    the base case:

        n == 0

    At that point recursion stops and the function calls
    start returning (stack unwinding).

    While returning, each stack frame prints its own value
    of n.

    Since the frames return in the order:

        1, 2, 3, ... , N

    the numbers are printed in increasing order.

    DRY RUN (N = 4):
    ----------------

    Call Stack Creation:

        printNr(4)
            -> printNr(3)
                -> printNr(2)
                    -> printNr(1)
                        -> printNr(0)   // Base Case

    Stack Unwinding:

        printNr(0) returns

        printNr(1):
            cout << 1

        printNr(2):
            cout << 2

        printNr(3):
            cout << 3

        printNr(4):
            cout << 4

    Output:
        1234

    KEY OBSERVATION:
    ----------------
    In recursion:

        Work BEFORE recursive call
            => happens while moving down the stack

        Work AFTER recursive call
            => happens while unwinding the stack

    Here we print AFTER the recursive call,
    therefore numbers appear from 1 to N.
*/

void printNr(int n ){
    if(n==0)return;
    printNr(n-1);//pehle fn call n=0 tkk jaaegi fir
    //return hoga and previos call p jaaegi 
    cout<<n;
}


//printing nr N to 1
void printNrNto1(int n){
    if(n==0)return;
    cout<<n;
    printNrNto1(n-1);
}


//sum of first n numbers , using functional recursion
int sumOfNnr(int n){
    if(n<1)return 0;//base condom
    int sum=n+sumOfNnr(n-1);
    return sum;

    /*isme aise hogA ki
    sbse pehle sumofNnr recurively int sum k andr
    sumOfNnr(0) tkk jaaega fir uss point k baad 0 return krega fn
    fir wo int sum= 1+0; hoga
    sum=1 , fir sum return hoga sumOfNr(2) wale stack p
    waha p sum=2+1 , sum=3 , sum = 3 return hoga sumOfnnr(4) wale stack m aise hota jaaega until
    until sumofNr(n) tkk ni phuch jaata
    */
}

//sum of n to nr parametired fucktion
void sumOfNnumbers(int n , int parameter=0){
    if(n<1){
        cout<<parameter;
        return;
    }
    sumOfNnumbers((n-1) , (n+parameter));//as n get reduced parameter keeps on getting buildinf up

}

int main() {
    int n;
    cin>>n;

    cout<<sumOfNnr(n);
    return 0;
}