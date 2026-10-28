/*Two strings are anagrams if:

same characters
same frequencies
order may differ

Examples:

listen  silent
heart   earth

Not anagram:

rat car






a method can be using find , take char of one string and check in other 
if npos then return false????

answerr---That approach is incomplete.
It fails for repeated characters.

Example:

s = "aab"
t = "abb"

Your logic:

take 'a'
found in "abb" → okay
take second 'a'
still found in "abb" → okay
take 'b'
found → okay

You would return:

true

But actual answer:

false

because frequencies differ.
*/

#include <bits/stdc++.h>
using namespace std;

bool anagramCheckerBrute(const string &s1 , const string &s2){

     if(s1.size() != s2.size()) {
        return false;
      }

    map<char , int>mpp1;
    map<char , int>mpp2;

    for(char ch:s1)mpp1[ch]++;
    for(char ch:s1)mpp2[ch]++;

   /*for(char ch:s1){
        if(mpp1[ch]!=mpp2[ch])return false;
    }

    this wont work 


    Suppose:

s1 = "ab"
s2 = "abc"

Your loop checks only chars from s1:

a, b

It never checks extra 'c'.

So without length check:

if(s1.size() != s2.size())

your logic becomes unsafe.


if i check length then use it then it will work but direct map comparision is safer
        
    */ 

    return mpp1==mpp2;//map allows direct comparision

}//t c o nlogn


bool anagramCheckerOpt(const string &s1 , const string &s2){

     if(s1.size() != s2.size()) {
        return false;
      }

    vector<int>freq1(26 , 0) ;
    vector<int>freq2(26 , 0);
    for(char ch:s1) freq1[ch-'a']++;
    for(char ch:s2) freq2[ch-'a']++;

    for (int i = 0; i < 26; i++) {
      if(freq1[i]!=freq2[i]) return false;
    }

    return true;


}//tc o n



int main() {
    
    return 0;
}