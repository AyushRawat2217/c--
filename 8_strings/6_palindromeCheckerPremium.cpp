/*Valid Palindrome


Ignore:

spaces
special characters
uppercase/lowercase difference

Example:

Input:

A man, a plan, a canal: Panama

Output:

true

Because after cleaning:

amanaplanacanalpanama

Use:

two pointers
tolower()
isalnum()*/


/* fist approach is cleaning the strings if ch is alnum the skip else
erase the elemnt then convert the string to lower case then check plaindrome validity 


2nd appraoch is better we just increse poinet count when we get into a specil character
and whenever we find a char which is not alnum then we ignore that particular character 
*/
#include <bits/stdc++.h>
using namespace std;
bool validPalindrome(const string &s){
    int left=0;
    int right=s.size()-1;

    while(left<right){
        if(!isalnum(s[left]))left++; //ignore char which ar enot digit and number

        else if(!isalnum(s[right]))right--;

        else{ //both left and right are alnum
            if(s[left]!=s[right]) return false;

            left++ , right--;
        }
    
    }

    return true;

}
int main() {
    
    return 0;
}