#include <bits/stdc++.h>
using namespace std;

/*Input: s = "welcome to the jungle"
Output: "jungle the to welcome"
Explanation: The words in the input string are 
"welcome", "to", "the", and "jungle". Reversing the order of 
these words gives "jungle", "the", "to", and "welcome". 
The output string should have exactly one space between each word.

Input: s = " amazing coding skills "
Output: "skills coding amazing"
Explanation: The input string has leading and trailing spaces, as well 
as multiple spaces between the words "amazing", "coding", and "skills".
 After trimming the leading and trailing spaces and reducing the 
 multiple spaces between words to a single space, the words are 
 "amazing", "coding", and "skills". Reversing the order of these words gives "skills", "coding", and "amazing". The output string should not have any leading or trailing spaces and 
 should have exactly one space between each word.
 
 */

string reverseWordsInStringBF(string &s){
    string str;
    //s.empty() is necessary because  if string  is empty then there is no indexes and program crashes
    while(!s.empty()&&s[0]==' ')s.erase(0,1); 
    //ease(starting index , length u want to remove include elemnt of tarting index)

    while(!s.empty()&&s[s.size()-1]==' ')s.erase(s.size()-1,1); 

   
    int end = s.size()-1;

    for (int i =s.size()-1;i>=0; i--) {

        if(s[i]==' '&& s[i+1]!=' ')// its the point where after space the word starts and its
        // the point we need so that we append our tring from here (i+1) index
    {
        if(!str.empty()){//to get space between words after first word
            str+=' ';
  //sexy rule      
           /*to create a space between between first word
            and next word , jese first word append kiya 
            uss time str empty tha toh kuch nhi hua fir new word append kiya
            toh str m pehle space aaegi fir new word aaega
            */
        }

        str+=s.substr(i+1 , end-i);

        end=i-1; // after i extracted the word and im standing at white space and right to it is word
        //if there is single spcae bewtween word then to reach at end of 2nd word 
        //i will move 1 unit left


    }

    else if(s[i]==' ')end=i-1;
    // till the point where the elemnt to left is a word , we have to stop at word
    // so after stopping at pace we shift 1 unit left so we i-1

        
    
    }
    str+=s.substr(0 , end+1);

    return str;


}
//the issue here is the erase function it takes up on2 time complexity
//now we will try to solve with o n without erase and substr




/*logic is we will reverse the full string
then we will reverse the words in their place itself

reverse (s.begin() , s.end())

/

reverse(begin+0 , begin+4);

includes:

0 1 2 3

/
*/
string reverseWordsInStringBf2(string &s){

    //its bf because of erase
  
    //s.empty() is necessary because  if string  is empty then there is no indexes and program crashes
    while(!s.empty()&&s[0]==' ')s.erase(0,1); 
    //ease(starting index , length u want to remove include elemnt of tarting index)
    while(!s.empty()&&s[s.size()-1]==' ')s.erase(s.size()-1,1); 

    reverse(s.begin(), s.end());

    int start=0;

for (int i = 0; i < s.size(); i++) {//-1 is for handling boundary condition
   

    //correct start detection


    if(s[i]!=' ' && (s[i]==0||s[i-1]==' '))start=i;
   
   
    if(s[i]!=' '&&(i==s.size()-1)||s[i+1]==' ' ) //i==s.size()-1 because after last word there is no space so this wont work
    //so to inculcate last word i need to tell program that if i is size -1 include that and reverse that
    reverse(s.begin()+start , s.begin()+i+1);//+1 to include i 

    /*SHORT-CIRCUIT RULE

In:

A || B

if A becomes true,
then B is NEVER checked.

Useful for boundary conditions.

Safe:

(i == s.size()-1 || s[i+1]==' ')

If i is already last index,
second condition never runs,
so s[i+1] is never accessed.

Dangerous:

(s[i+1]==' ' || i==s.size()-1)

Here s[i+1] is checked FIRST,
so out-of-bounds access can happen.
*/


   /*else if(s[i]==' ')start=i+1; 
   this start detection is wrong because
   it may fail 
   more robust is

   Instead of updating start on spaces,
detect actual word starts:

this teaches me to narrow down the selction learning properties 
of something to be something
   
   */  

   

}




return s;
}


string reverseWordsInStringOpt(string &s){
    int n= s.size()-1;//we will start from last index

    int i=n;
    string str;

    while(i>=0){//lets start from behind and keep appending from behind , thats logic 
        //by marking end and start

        //sbse pehle trailing spaces htana
        while(i >= 0 && s[i]==' ' )i--;//i>=0 so that it doesnt out of bound

        if(i<0)break; //pointer out of boundss , if string has no useful charcter only spaces , its not empty but if i=-1 its invslid

        int end=i;


        while(s[i]!=' '&& i>=0)//keep moving left through ALL letters until space encountered

        {
            i--;

            //i will stop at space and right of it is word so we need to add 1 in i 
        }

        if(!str.empty())str+=' ';//add space after first word always

        str+=s.substr(i+1, end-i);

    }

    return str;


} 

int main() {
    
    return 0;
}