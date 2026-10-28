#include <bits/stdc++.h>
using namespace std;

//940
void sumOfEleOfSbsts(vector<int>&arr , int n ,vector<int>&sumArr){
/*using bit method take or not take
the array elemnt , store sum in the refrence at last sort it*/

    for (int i = 0; i < (1<<n); i++) {
        int sum=0;
        for (int j = 0; j< n; j++) {
          if(i& (1<<j))sum+=arr[j];
        }
        sumArr.push_back(sum);
    }
    /*arr = {10, 20, 30, 40}
index  3  2  1  0

Suppose mask = 13

13 = 1101₂

Bit Position : 3  2  1  0
Mask Bits    : 1  1  0  1
Array Index  : 3  2  1  0

Decision:
bit 0 = 1 -> Take arr[0] = 10
bit 1 = 0 -> Skip arr[1] = 20
bit 2 = 1 -> Take arr[2] = 30
bit 3 = 1 -> Take arr[3] = 40

Subset formed = {10, 30, 40}

Check each bit using:

j = 0: mask & (1<<0) = 1101 & 0001 = 0001 -> Take
j = 1: mask & (1<<1) = 1101 & 0010 = 0000 -> Skip
j = 2: mask & (1<<2) = 1101 & 0100 = 0100 -> Take
j = 3: mask & (1<<3) = 1101 & 1000 = 1000 -> Take
*/
    
sort(sumArr.begin() , sumArr.end());

}

//9:58
void recursionMeth(vector<int>&arr , int index ,int currSum, vector<int>&sumArr){
    if(index==(arr.size())){
        sumArr.push_back(currSum);
        return;
    }
    recursionMeth(arr , index+1 , currSum+arr[index] , sumArr );//i can directly sum arr[index] here
    
    recursionMeth(arr , index+1 , currSum-arr[index] , sumArr ); // when previpus refcusion return to here then i will kip the respective elemnt
}

vector<int>sortedSumArr(vector<int>&arr ,vector<int>&sumArr){
    vector<int>subset;
    recursionMeth(arr , 0,0,sumArr);

    sort(sumArr.begin(), sumArr.end());
    return sumArr;
}

int main() {
    
    return 0;
}