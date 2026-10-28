#include <bits/stdc++.h>
using namespace std;

/* ek bandar hai usko kele khaane hai
pr for ek ghnte mai sirf kuch kele hi khaa skti hai
uss jgh kaa maalik h ghnte baad check krne aata hai
koko ko tbtk per hour ke hisaab se sbh kele khane hai
pile array di hai jism ith pile mai nr of bananas hai
hame find krna ka uski minimum speed kitni hogi ki bana or hour khaane ki
bkl h ghnte mai saare khaade
*/

//optimal ke liye brute force study krni pdegi
/*notes
hame dekhna pdega ki max nr of banana kis pile mai
 hai
 fir hame min bhi
 taaki ek range mil jaaein

 fir uss range mai binary search krke ham nr of hours taken nikaale
 */

bool helperFn(vector<int>&pile , int h , int mid){//checks the nr of hours it takes for a binary search guessed rate
    int hours=0;
    for (int i = 0; i < pile.size(); i++) {
        int banana=pile[i];

        
int leftover = (banana % mid > 0) ? 1 : 0;
// If banana is not perfectly divisible by mid, some bananas remain.
// Any positive remainder requires one additional hour, regardless of its size.
// Example: banana = 17, mid = 5
// banana / mid = 3 complete hours, banana % mid = 2 leftover bananas.
// Since 2 > 0, leftover = 1 (one extra hour).
// If banana = 15, mid = 5, the remainder is 0, so leftover = 0.

hours += (banana / mid) + leftover;
// Total hours for this pile = complete hours + extra hour if bananas remain.
// Example: 17 / 5 = 3, leftover = 1, so total hours = 4.
// Example: 15 / 5 = 3, leftover = 0, so total hours = 3.

        
        if(hours>h)return false;
    }
    return true;
}

int kokoEatinKela(vector<int>&pile , int h){
    int low=pile[0];
    int high=0;

    for(int i:pile){
        low=min(low , i);
        high=max(high ,i);
    }

    while(low<=high){
        int mid=low+(high-low)/2;

        //it means that we got it done in mid , means rate  at mid provided hours less than or equal to h , we can check for lesser rate
        //if mid is answer and we still move smaller than smaller one will take more time , and end up false , we will have low=mid +1 , we will back to mid
        //hence we win
        if(helperFn(pile , h , mid))high=mid-1;
        else low=mid+1;
    }
    return low;
}


int main() {
    
    return 0;
}