#include <bits/stdc++.h>
using namespace std;

/* consecutive nrs ki sequence sbse lmbi konsi bnri hai wo find out krni hai */
//boht tagda logic hai

int findLngstCnsctvNr(vector<int>&arr){
    unordered_set<int>sett;
    for(auto &it:arr){//inserting all elemnts
        sett.insert(it);
    }

    int maxx=0;
    int count=1;
    for(int it:arr){
        if(sett.find(it-1)==sett.end()){//tbhi move krna hai jbh it ke pehle wala elemnt present na ho
            //agr hoga mlb it , first elemnt ni hai sequence k

            count=1;

            int x=it;
            while(sett.find(x+1)!=sett.end()){
                x=x+1;
                count++;
            }

            maxx=max(maxx , count);

        }

    }
    return maxx;
}


int main() {
    
    return 0;

}
