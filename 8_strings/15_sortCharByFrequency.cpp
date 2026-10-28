


/*logic is first sroting all char along with their frequency then
using a custom sort funtion to prioritise the high frequency chars
or alphabetically greater elemnt if frequwncy are same

sort(arr.begin(), arr.end() , comparator)
comparator is a custom function which lets user use sort according to him
default setting of sort is putting elemnts in alphabetical order but if we 
want it to be descendig we can do it too
*/

/*first we will create a frequncy array or unordrd map
Only lowercase letters given?
→ use freq[26]

Anything else / not specified?
→ use unordered_map

then i will convert he freq array or map to pair vecor ehich i will feed into
sort function , as resason in mentioned in code itself in commented format

then i will create a comparator  of sort function
which sort according to big freuency first and if frequency are same
then it taks alphabetical order into consideration
*/
#include <bits/stdc++.h>
using namespace std;


/*Think of it like this

For every comparison, sort() asks:

Should A come before B?

Your comparator answers:

true  -> Yes
false -> No

That's all.*/

bool comparator(pair<char , int>&p1 , pair<char , int>&p2){//passinng 2 pairs as arguemnt then creating a code to compare them
    if(p1.second!=p2.second)return p1.second>p2.second;

    return p1.first<p2.first;

    //it asks should p1 come before p2? and does for every possible cmbination ad sort accordingly
}

vector<char> sortCharacterByFrequencyUsingMap(string const &s){
    int n=s.size();

    unordered_map<char , int>mpp;

    for(char ch:s)mpp[ch]++;


    /*❌ unordered_map cannot be sorted directly.

Why?

Because sort() requires random access iterators (like vector, array, deque).

unordered_map provides hash-table iterators, not random access iterators.

So this won't compile.*/

    vector<pair<char , int>>charNfreq;
    for(auto it:mpp)charNfreq.push_back({it.first , it.second});//feeded the map elemnts into vector 

    sort(charNfreq.begin(), charNfreq.end() , comparator); 


    vector<char>result;
    for(auto it:charNfreq)result.push_back(it.first);

    return result;
    
}


//tc O(n + k log k)

//...............................................................................................





bool comparator2(const pair< int , char>&p1 ,const pair< int , char>&p2){//passinng 2 pairs as arguemnt then creating a code to compare them
    if(p1.first!=p2.first)return p1.first>p2.first;

    return p1.second<p2.second;

    //it asks should p1 come before p2? and does for every possible cmbination ad sort accordingly
}



vector<char> sortCharacterByFrequencyUsingFreqArr(string const &s){
    int n=s.size();

   vector<pair<int , char>>freqArr(26);

   for (int i = 0; i < 26; i++) {
     freqArr[i]={0,'a'+i};
     /*i create a list of pairs like , 0 , a 
     0 , b 
     0, c .................. till 0,z*/
   }

   for(char ch:s) freqArr[ch-'a'].first++; 
   /*ch-'a' is a very smart move to access indexes
   if ch is c , then c-'a' return , 2 , and at index 2
   there is 0 , c */



   //now we have the freq array along with the pairs whose char appeared in string 1 or more times



    sort(freqArr.begin(), freqArr.end() , comparator2); 


    vector<char>result;
    for(auto ch:freqArr)if(ch.first>0)result.push_back(ch.second);
    return result;
    
}

//tc on

int main() {
    
    return 0;
}