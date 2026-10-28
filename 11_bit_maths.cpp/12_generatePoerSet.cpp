#include <bits/stdc++.h>
using namespace std;

void generatePowerSet(vector<int>&arr , vector<vector<int>>&powerset){
    /*logic 
    shift operator wala hai 
    1 is set 0 is clear
    jitna array ka size o se lekr uss size tkk
    ki bit valus ka use krna hai

    jese 000
    001
    010
    100
    110
    111
    011
    aise krke hme con=mbinations milega and set bit hai toh uss nr wale elemnt ko lena
    otherwise ni lena
    
    3=011
    */
    int n=arr.size();

    for (int bit = 0; bit < (1<<n); bit++) {//1<<n is 2**n , these are bit combos
      
        vector<int>subset;
        for (int index = 0; index < n; index++) {
           if(bit&(1<<index)){//if the index numbered bit from right is set include it otherwise skip
            /*ex
            011 hai and arr ke elemnt 3 2 1 hai
            toh subset ke andr 2 1 aajega kyuki unki 1 ki right se indexth bit is also 1
            which make it and with bit(for loop wala) non zero
            */
            subset.push_back(arr[index]);
           }

        }
        powerset.push_back(subset);
    }

}

int main() {
    
    return 0;
}