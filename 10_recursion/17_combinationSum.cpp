#include <bits/stdc++.h>
using namespace std;
void printArrElement(vector<int>&arr){

}

//
/*we will either take same elemnt of take next elemnt*/
void returnCombination(vector<int>&given ,  int index , int target, vector<int>&combnArr){//n i size of array
   if(index>=given.size()){
    if(target==0){
        printArrElement(combnArr);
    }
    return;
   }

    if(given[index]<=target){//this block use to use to repeat us elemnt until we reach target 
    combnArr.push_back(given[index]);
    returnCombination(given,index , target-(given[index]) , combnArr ); 
    combnArr.pop_back();
    //when we are using refrence then we need pop back to return our combn arr to previous state
    //had we passed it by value or copy we wouldnt require it
    }
    returnCombination(given,index+1 , target , combnArr );//its use to skip to next elemnt when DDING CURRIent index elemnt is greater than required nr to trach target

}

int main() {
    
    return 0;
}