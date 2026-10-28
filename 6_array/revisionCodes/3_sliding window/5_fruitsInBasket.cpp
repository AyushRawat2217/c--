#include <bits/stdc++.h>
using namespace std;

/*2 baskets , they can store 1 fruits type each
aisi  longest contigupus array nikaal jisme at most 2 fruit type of
*/

int fun(vector<int>&arr ){
    int left=0;
    map<int , int>bucket;
    int ans;
    
    for (int right = 0; right < arr.size(); right++) {
        bucket[right]++;

        while(bucket.size()>2){//until bucket size is greater than 2 
                bucket[left]--;//keep removing the fruits until there is just max 2 types are left

                if (bucket[arr[left]] == 0)
                bucket.erase(arr[left]);// remove the key nga

            left++;
        }

        ans=max(ans , right=left+1);

    }
    return ans;
    
}

int main() {
    
    return 0;
}