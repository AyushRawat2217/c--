#include <bits/stdc++.h>
using namespace std;

/*ALGORITHM (Recursive atoi)

1. Start from the first valid digit after handling:
   - Leading whitespaces
   - Optional '+' or '-' sign

2. Recursive Function Parameters:
   - index     -> current character position
   - sign      -> 1 for positive, -1 for negative
   - n         -> length of string
   - resultNr  -> number formed so far

3. Base Case:
   - If index reaches the end of the string
     OR
   - Current character is not a digit

   Return:
       resultNr * sign

   This represents the final number formed from all
   consecutive digits encountered so far.

4. Processing Step:
   - Convert current character into its numeric value.
   - Append it to the previously formed number:

         resultNr = resultNr * 10 + digit

5. Overflow Handling:
   - If the formed number exceeds INT_MAX,
     return INT_MAX.
   - If the formed number goes below INT_MIN,
     return INT_MIN.

6. Recursive Call:
   - Move to the next character.
   - Pass the updated resultNr.

7. Return the value obtained from deeper recursive calls.
   No additional work is performed during backtracking;
   the final answer simply propagates back through the
   recursive call stack.

Example:
Input: "-123abc"

Call 1: resultNr = 1
Call 2: resultNr = 12
Call 3: resultNr = 123
Call 4: encounters 'a' -> return -123

The value -123 then bubbles back unchanged through
all previous recursive calls.

Time Complexity : O(k)
    k = number of consecutive digits processed

Space Complexity : O(k)
    due to recursion stack
*/

int atoiRec(string &s , int index , int sign , int n , long long resultNr){
    if(index>=n || !isdigit(s[index])){//base condtion
        return (resultNr*sign);
        //suppose the first encountered index is non digit then it will be 0atoiRec(s , index+1 , sign ,  n , resultNr );
        //if after constructing a reultant nr , we get a non digit , then also it will return the digit we created so far
        // Return the number formed so far.
        // This value then propagates back through all recursive calls.

    }

    resultNr=resultNr*10 + (s[index]-'0');//calculating the digits acculmulation 
    
    if((resultNr*sign)>=INT_MAX)return INT_MAX;
    else if((resultNr*sign )<=INT_MIN)return INT_MIN;

    /*if(sign == 1 && resultNr > INT_MAX)
    return INT_MAX;

     if(sign == -1 && resultNr > 2147483648LL)
      return INT_MIN;*/

    return atoiRec(s , index+1 , sign ,  n , resultNr );
}

void removingWHiteSpacesNtakingSign(string &s){
    int i=0;
    int n=s.size();
    while(i<n && s[i]==' '){
        i++;
    }

    int sign=1;
    if(i<n && (s[i]=='-')){
        sign=-1;
    }

//i start right after we got all whitespaces skipped n the first s
    atoiRec(s , i , sign , n , 0);
}

int main() {
    
    return 0;
}