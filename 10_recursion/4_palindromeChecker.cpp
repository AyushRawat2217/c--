#include <bits/stdc++.h>
using namespace std;

//using fnl recursion
void reversingTheOrgStr(string &s , int left){//left start from 0
    if(left>(s.size()-1-left))return;
    swap(s[left], s[s.size()-1-left]);
    reversingTheOrgStr(s , left+1);
}//it changes the original string

//if i want soemthing which returns me the paindrome

/*APPROACH:
    ----------
    Check whether a string is a palindrome by comparing
    characters from both ends simultaneously.

    We maintain two pointers:

        left  -> starts from the beginning (0)
        right -> starts from the end (n - 1)

    At every recursive call:

    1. Compare s[left] and s[right].

       - If they are different, the string cannot be a palindrome.
         Return false immediately.

       - If they are equal, the current outer pair is valid.
         Now recursively verify the remaining inner substring.

    2. Move both pointers towards the center:

            left + 1
            right - 1

    3. Continue until the pointers meet or cross.

    BASE CASE:
    ----------
    if(left >= right)
        return true;

    This means we have successfully compared every required pair.

    There are two possibilities:

    Odd Length Example:

        "madam"

         m a d a m
         ^       ^
         ✓

           a d a
           ^   ^
           ✓

             d
             ^
        left == right

        The middle character does not need comparison.
        Return true.

    Even Length Example:

        "abba"

         a b b a
         ^     ^
         ✓

           b b
           ^ ^
           ✓

        After moving pointers:

            left = 2
            right = 1

        left > right

        Every pair has already been checked.
        Return true.

    DRY RUN:
    --------

    String = "racecar"

        left=0, right=6
        'r' == 'r' ✓

                |
                V

        left=1, right=5
        'a' == 'a' ✓

                |
                V

        left=2, right=4
        'c' == 'c' ✓

                |
                V

        left=3, right=3

        left >= right
        Return true

    Since every outer pair matched,
    the string is a palindrome.

    EARLY TERMINATION EXAMPLE:
    --------------------------

    String = "abca"

        left=0, right=3
        'a' == 'a' ✓

                |
                V

        left=1, right=2
        'b' != 'c' ✗

        Return false immediately.

    No further recursive calls are made because
    one mismatching pair is sufficient to conclude
    that the string is not a palindrome.

    INTUITION:
    ----------
    Each recursive call is responsible for checking
    exactly one pair of characters.

    If the current pair matches,
    it delegates the responsibility of checking the
    remaining inner substring to the next recursive call.

    Thus, the problem size decreases from both ends
    after every call until the middle of the string is reached.

    Time Complexity : O(n)
        Each character is compared at most once.

    Space Complexity : O(n)
        Due to the recursion call stack.
*/
bool palindromeChecker2(string &s , int left , int right){//left start from 0
    if(left>right)return true;

    if(s[left]!=s[right])return false;
    else return palindromeChecker2(s, left+1 , right-1);
}// the answer is bubbling up

int main() {
    int n;
    return 0;
}