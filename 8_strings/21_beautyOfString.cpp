#include <bits/stdc++.h>
using namespace std;
/* for brute force 
i can think of ,  passing every substring to a function having frequency map which return beauty
but its o n3 tc
making substring requires 3 loopsn , then passing it to map for frequncy*/

/*mental shift to optimise my brute force approach
see i will be making new substrings then i will find beauuty of each one
but i can optimise it as , if i know beauty or frwuency of pervios substring i can use
frwuency of that and i can add frquecy of the new char which i encouterd
point is i dont need to create separate memory bases everytime to gather frwuency i can use the old data

optimisation is this shit only brute force is genrating same thing again and again and optimisation is
using the old data in new data without recalculating thing over an dover again*/

int maxNminFreqInMap(unordered_map<char , int>&mpp){
    int maxFreq=0;
    int minFreq=INT_MAX;
   for(auto it:mpp){
    maxFreq= max(maxFreq ,it.second);
    minFreq=min(minFreq , it.second);
    //i already have data of frequency in map no need to use substring to search frequency for wvey character , just select largest and smallest frquency from map itself
   }
   return (maxFreq - minFreq);
}

int sumOFbeautyOfStringMapAprroach(string &s){
    int n=s.size();
    int sumOfBeauty=0;
    for (int i = 0; i < n; i++) {
        unordered_map<char ,int>mpp;
      for (int j = i; j < n; j++) {
        mpp[s[j]]++;//char mappped with frequency
        sumOfBeauty+=maxNminFreqInMap(mpp);
    }

    }
    return sumOfBeauty;

}



/*why map approach is less optimised that freq[26] approach
becuase when domain is small like only 26 letter of alphabet then best suited approch is
freq 26 because it offer constant time complexity, as n=26 , and its cpu friendly as well as due
to contuguous nature its fire
*/




int maxNminFreqInArray(int freq[]){
    int maxFreq=0;
    int minFreq=INT_MAX;//NO GUARATEED UPPER LIMIT
   for (int i = 0; i < 26; i++) {
    if(freq[i]>0){//as the freq array contains 0 nrs AS WELL
     maxFreq=max(maxFreq , freq[i]);
     minFreq=min(minFreq , freq[i]);
    }
   }
   return (maxFreq - minFreq);

}

int sumOFbeautyOfStringArrayApproachOpt(string &s){
    int n=s.size();
    int sumOfBeauty=0;
    for (int i = 0; i < n; i++) {
        int freq[26]={0};   
      for (int j = i; j < n; j++) {
        freq[s[j]-'a']++;
        sumOfBeauty+=maxNminFreqInArray(freq);
    }

    }
    return sumOfBeauty;

}



int main() {
    
    return 0;
}

//intro to problem
/*Step 1: Beauty of a String

Beauty =

(highest frequency of any character) − (lowest frequency of any character that appears)

⚠️ Characters with frequency 0 are ignored.

Example

String = "xyx"

Frequency table:

Character	Frequency
x	2
y	1

Most frequent = 2

Least frequent (among appearing chars) = 1

Beauty = 2 − 1 = 1

Step 2: Find Beauty of EVERY Substring

For "xyx" the substrings are:

"x"
"xy"
"xyx"
"y"
"yx"
"x"

Now compute beauty of each.*/