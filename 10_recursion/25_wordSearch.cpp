#include <bits/stdc++.h>
using namespace std;

 //for the directions
int rdir[]={1 , -1 , 0 , 0};
int cdir[]={0 , 0 , 1, -1};

bool finderFn(vector<vector<char>>&arr , string &word , int index , int row , int column){//index if of word
    //base conditions
    if(index==word.size())return true; //we succesfully traversed the whole word with matchups , so means yes we can mae the word with the arr
    if(row<0 || column<0  || row==arr.size() || column==arr[0].size() || arr[row][column]=='v'){//if arr[row][column] is visited then also return
        return false;
    }

    if(arr[row][column]!=word[index]){ //if its not equla return back
        return false;
    }

    char temp=arr[row][column];
    arr[row][column]='*';// * means visited

    //main code
    for (int i = 0; i < 4; i++) {
        //this helps me moving fown left above 
      int new_row= row + rdir[i];
      int new_col= column+cdir[i];


      /*

 Call 1 (A)
  |
  ---> Call 2 (B)
          |
          ---> Call 3
                  returns TRUE
          |
          returns TRUE
  |
  returns TRUE
  
  if ultimately true comes up backtracked to frst call means we founf the string  , so first call must return true
  */
      if(finderFn(arr , word , index+1 , new_row , new_col)){
         arr[row][column]=temp;
        return true;
      }

    }

    arr[row][column]=temp;

    return false;//if  we ae not returned true till end we will return fale at last
    
}


bool helperFn(vector<vector<char>>&arr , string &word , int nrow , int ncol){//nroq= arr,size m mcol= arr[0].size()
    for (int i = 0; i < nrow; i++) {

        for (int j = 0; j < ncol; j++) {
            if(arr[i][j]==word[0]){
                if(finderFn(arr , word , 0 , i , j)){//finder returns me true if we could make the word from the arr 
                    return true;
                }
            }
        }
      
    }

    return false;
}

int main() {
    
    return 0;
}