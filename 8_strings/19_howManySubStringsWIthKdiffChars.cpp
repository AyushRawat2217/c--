
/*my heart will go on */

#include <bits/stdc++.h>
using namespace std;

/*logic is i  will keep storing occuring charcters
in a map along with their freuency 
if size of map increases than k then stop the iteration , then moe with next character and do the same */
int returnNumberOfSubstrings(string &s , int nrOfDistChar){
    int n=s.size();
    

    int countOfRequiredSubstring=0;
    for (int i = 0; i < n; i++) {
        map<char , int>mpp;//i want map to get reset for every new i
      for (int j = i; j < n; j++) {
        mpp[s[j]]++;
        if(mpp.size()==nrOfDistChar)
        {
            countOfRequiredSubstring++; //jbtk map m character daalne size nrdist char k barabar tbtk keep looping
            //jis point pe jyada hogya tbh break krdo and new iteration start kro
        }//if exact found
        else if (mpp.size()>nrOfDistChar)break;
        
      }

    }

    return countOfRequiredSubstring;
}


int main() {
    
    return 0;
}