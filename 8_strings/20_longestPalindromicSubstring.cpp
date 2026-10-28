#include <bits/stdc++.h>
using namespace std;
/*i will create substrings and send them into a function
to check whether they are palindrome or not
if yes return true find size and if keep storing the largest palindromic string*/

bool isItPalindrome(string &substring){//i will solve it using 2 ptrs
int left=0;
int right=substring.size()-1;

while(left<right){
    if(substring[left]!=substring[right])return false;
    left++;
    right--;
}

return true;
}

string returnLongestPalindromicSubstring(string &s){
    int n=s.size();
    int maxSize=0;
    string palindromicSubStr;
   
   
    for (int i = 0; i < n; i++) {
        string substring;
      for (int  j=i; j < n; j++) {
        substring=s.substr(i , j-i+1);

        if(isItPalindrome(substring)){
            if(substring.size()>maxSize){
            palindromicSubStr=substring;
            maxSize=substring.size();
            }
        }
      
    }
    }

    return palindromicSubStr;
    
}


/*there is another logic  that we can expand the characters until there is symmetry
for example - dabac , let say after traversal we reached at b , then we expnad on eunit right and left
and see there is symmetery , then at d abd c we observe symmetry vanish and we return the length we got*/


/*// Expand outward from the given center(s) as long as characters match.
// (left,right) = (i,i)   -> odd palindrome center
// (left,right) = (i,i+1) -> even palindrome center
//
// When the loop stops, left and right have already moved one step
// outside the valid palindrome, so the palindrome length is
// right - left - 1.*/
int expandingFromTheNr( string &s , int left , int right){
    int n=s.size();
    while((right<n && left>=0 ) && s[left]==s[right]){
        left--;
        right++;
    }
    return right-1 -(left+1) +1; //length = right-left+1
}



string returnLongestPalindromicSubstring(string &s){
    int n=s.size();

    int maxLen=0;
    int start;
    for (int i = 0; i < n; i++) { //EXPAND FUNCTION PROTEXT I+1 WHEN I=N-1

    int oddLength=expandingFromTheNr(s , i , i);
    int evenLength=expandingFromTheNr(s , i , i+1);
        /*// Every palindrome has a center.
// Odd-length palindromes have a single-character center (aba, racecar),
// so expand from (i, i).
//
// Even-length palindromes have a two-character center (abba, bb),
// so expand from (i, i+1).
//
// We check both because the longest palindrome can be either odd or even.*/

    
    /*now we need to find the starting point  because substr
    function needs a startig point nd we have lemght ,
    see i is the mid point the half part from it will be lenght /2 left and right -1(that is i itself)
    along */

    if(oddLength>maxLen){
    maxLen=oddLength;
    start=i-(oddLength/2);
    }

    if(evenLength>maxLen){
    maxLen=evenLength;
    start=i-(evenLength/2)+1;
    }

    /*// Odd : i is the middle character.
// start = i - len/2
//
// Even: i is the left middle character.
// start = i - len/2 + 1*/

}

return s.substr(start , maxLen);

}


int main() {
    
    return 0;
}