#include <bits/stdc++.h>
using namespace std;

/*  Problem
atoi() = Convert a string into an integer.

Rules:

1. Skip all leading whitespaces.
   Example: "   -123" -> "-123"

2. Read at most one optional sign (+ or -).
   Example: "+123", "-123"

3. Starting from the current position, read consecutive digits only.
   Example: "123abc" -> read 123 and stop at 'a'

4. If the first meaningful character is not a digit or sign,
   return 0.
   Example: "words123" -> 0

5. If multiple signs appear, parsing fails because after an
   optional sign a digit is expected.
   Example: "--123", "+-12" -> 0

6. Ignore everything after the first non-digit character
   encountered while reading the number.
   Example: "+12Ab4" -> 12

7. Clamp the answer to the 32-bit signed integer range:
   [-2147483648, 2147483647]

Mental model:

[spaces] [optional one sign] [continuous digits] [ignore rest]

Examples:
"   -123abc"     -> -123
"4193 with words"-> 4193
"words123"       -> 0
"+12Ab4"         -> 12
"--123"          -> 0
*/

/*Algorithm
PROBLEM:
Convert a string into a 32-bit signed integer (atoi).

PATTERN:

[spaces] [optional sign] [continuous digits] [ignore rest]

Examples:
"   -123abc"      -> -123
"4193 with words" -> 4193
"words123"        -> 0
"+12Ab4"          -> 12
"--123"           -> 0


ALGORITHM:

1. Initialize:
   result = 0
   sign = +1
   index = 0

2. Skip all leading whitespaces.
   while current character is ' '
       move ahead

3. Check for one optional sign.
   if current character is '+'
       sign = +1
       move ahead
   else if current character is '-'
       sign = -1
       move ahead

4. Read digits continuously.
   while current character is a digit:
       result = result * 10 + digit
       move ahead

5. If overflow occurs:
       return INT_MAX or INT_MIN

6. Return:
       sign * result


WHY result = result*10 + digit ?

Example: "123"

result = 0

read 1:
result = 0*10 + 1 = 1

read 2:
result = 1*10 + 2 = 12

read 3:
result = 12*10 + 3 = 123


TIME COMPLEXITY:
O(n)

SPACE COMPLEXITY:
O(1)
*/

signed int atoi(const string &s){
    long long int result=0;
    int n=s.size();
    int j=0;
    int sign=1;

    while(j<n&&s[j]==' '){//until whitespaces are their keep increasing the j
        j++;
    }

    if(j<n && (s[j]=='-'||s[j]=='+') ){ //till here loop runs just once when code encounters the first sign
        if(s[j]=='-')sign=-1;
        j++;
    }
    //now we got the sign but after string it could be like +++--- at first encounter of + sign is +1 , but
    //just after the first encounter of sign , j moves 1 place right , if there are multiple sign next line of code will handle it



/*if we encpunter the sign after prev if statement while loop never works and result =0 is
returned similarly if ther is a non digit elemnt */
    while(j<n && isdigit(s[j])){
        result=(result*10)+(s[j]-'0');//got the digits till here

        //now lets handle overflow and underflow right before moving to next iteration

        if(result >= INT_MAX && sign==1) return INT_MAX;
        else if(result>=(INT_MAX+1) && sign ==-1) return INT_MIN;
        //why aDDED 1
        /*It means there is one extra valid negative number compared to positive numbers.

32-bit signed integer range is:

INT_MIN = -2147483648
INT_MAX =  2147483647

Notice:

Negative side : 2147483648 values
Positive side : 2147483647 values

The negative side gets one extra value because of how binary numbers are stored.*/

        j++;

    }
    
    return (sign*result);
}

int main() {
    
    return 0;
}