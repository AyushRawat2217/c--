#include <bits/stdc++.h>
using namespace std;

/* problem
in arr[i][j] , if its 1 , it means i knows j 
if its 0 it means i doesnt know j
a person is celibrity when it knows no one  and everbody knows it
similarly a celibirty with other should be 0
and other with celibrity should be 1 
*/

bool checkFunction(int index , vector<vector<int>>&arr ){
    bool celbrityKnowsNoOne=true;
    bool everyOneKnowsCelibrity=true;
    
    for (int i = 0; i < arr[0].size(); i++) {//to check whether celibrity knows anyone or no
        //for that every arr[celibrity][other person] should be zero
         if(arr[index][i]==1){
            celbrityKnowsNoOne=false;
            break;
         }
    }

    for (int i = 0; i < arr.size(); i++) {//to check whether everyone checks celibrtiy or not
        //for that evert arr[other people][celibrtiy] should be 1
      if(arr[i][index]==0){
            everyOneKnowsCelibrity=false;
            break;
         }
    }
    return (celbrityKnowsNoOne && everyOneKnowsCelibrity);
}

int indexOfCelibrity(vector<vector<int>>&arr){
    for (int i = 0; i < arr.size(); i++) {
      if(checkFunction(i , arr))return i;
    }
    return -1;
}




            //OPTIMAL APPROACH 
/*LOGIC
we will use elimination aproach
*/

bool verifyCelibirtyFn(vector<vector<int>>&arr ,int index){//verify that top is celibirty or not
    bool celbrityKnowsNoOne=true;
    bool everyOneKnowsCelibrity=true;
    
    for (int i = 0; i < arr[0].size(); i++) {//to check whether celibrity knows anyone or no
        //for that every arr[celibrity][other person] should be zero
         if(arr[index][i]==1){
            celbrityKnowsNoOne=false;
            break;
         }
    }

    for (int i = 0; i < arr.size(); i++) {//to check whether everyone checks celibrtiy or not
        //for that evert arr[other people][celibrtiy] should be 1
      if(arr[i][index]==0){
            everyOneKnowsCelibrity=false;
            break;
         }
    }
    return (celbrityKnowsNoOne && everyOneKnowsCelibrity);
}


/*logic
eliminating definitely non celibrities
we maintain a top and a bottom
we check if top know bottom , if yes , then top is eliminted and pointer moved
to top++ , but if it doesnt know bottom then it means top can be a celibrity
and if it doesnt know bottom then obv bottom can t be celibirty as for bottom to
be celibrity it must be known by everyone 
so we reomve bottom definitely
may be in future top is not a celibrit but we dont care , what we care is removing
a definite non celibrity even if the one we are betting on could be a non celibrity as well in future
and at the end we do a verification



Why don't we check bottom -> top separately?

Because the elimination phase only needs to answer:

"Can I definitely eliminate at least one of these two?"

We already have that answer from top -> bottom:

top → bottom = 1 → eliminate top
top → bottom = 0 → eliminate bottom

Checking bottom → top could sometimes tell us that both are impossible, but we don't need that information. We only need to eliminate at least one person per iteration.

The final verification will determine whether the person who survives is actually a celebrity.*/



/*Logic
The main idea is to eliminate people who are definitely not celebrities.

We maintain two pointers:

top → points to the current candidate from the left
bottom → points to the current candidate from the right

At each step, we check:

arr[top][bottom]
Case 1: top knows bottom
arr[top][bottom] == 1

A celebrity knows nobody.

Since top knows bottom, top cannot be the celebrity.

Therefore, we can safely eliminate top:

top++;
Case 2: top does NOT know bottom
arr[top][bottom] == 0

A celebrity must be known by everyone.

Since top does not know bottom, bottom cannot be the celebrity.

Therefore, we can safely eliminate bottom:

bottom--;

Notice that in this case, top is not confirmed to be a celebrity. It is only still a possible candidate.

It may turn out later that top is not a celebrity either. That's okay.

The only thing we care about during the elimination phase is:

Every iteration must eliminate at least one person who is definitely not a celebrity.

Eventually, top and bottom meet:

top == bottom

At this point, only one person remains as the potential celebrity.

However, being the last remaining candidate does not guarantee that they are actually a celebrity.

For example, there might be no celebrity at all. The elimination process will still leave one candidate.

Therefore, we must perform a final verification.

The candidate is a celebrity only if:

The candidate knows nobody.
Everyone else knows the candidate.

If both conditions are satisfied, the candidate is the celebrity. Otherwise, there is no celebrity.

Core idea

Elimination phase: Find someone who could be the celebrity by removing people who definitely cannot be.

Verification phase: Prove whether the remaining candidate is actually the celebrity.

So the algorithm is:

Eliminate definitely non-celebrities
              ↓
        One candidate
              ↓
          Verify
              ↓
     Celebrity / No Celebrity*/
int indexOfCelibrity(vector<vector<int>>&arr){
    int top=0;
    int bottom=arr.size()-1;
    int potentialCelibrity;

    while(top<bottom){

        if(arr[top][bottom]==0){//top doesnt know the bottom
            bottom--;
        }
        else{//top know bottom means its not celibirty
            top++;
        }

    }//both bottom and top will be at same spot

    
    if( verifyCelibirtyFn(arr , top))return top;
    return -1;

}




int main() {
    
    return 0;
}