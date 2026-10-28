#include <bits/stdc++.h>
using namespace std;
/* we will map sum elemnt of upto every index wrt to index
then we will will check after doing curr sum - taget , is that diff presnt in the array or not
if yes then we got the subaray , i will return pair of index begin n end
*/
pair<int , int>sbarryWsumK(vector<int>&arr , int target ){
    unordered_map<int , int>mpp;
    int sum=0;
    pair<int , int>index;
    
    int len=0;
    for (int i = 0; i < arr.size(); i++) {
      
      sum+=arr[i];
      if(mpp.find(sum-target)!=mpp.end()){
        len=max(i-mpp[sum-target]+1 , len);
      }
      mpp[sum]=i;
    }
    return index;

}

/*the variations in it are count subaaray which has sum k , so i have to find sum-k, the same
approach but this time i will have count variable , similarly  for sum=0 , then i have to make k=0  , 
so the proble a re same */

int main() {
    
    return 0;
}