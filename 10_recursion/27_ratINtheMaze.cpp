#include <bits/stdc++.h>
using namespace std;


bool isSafe(int row , int column , vector<vector<int>>&maze,vector<vector<int>>&visited  , int n){
        return(row>=0    &&    column>=0    && row<n   &&   column<n             && visited[row][column]==0 && maze[row][column]==1    );//the first part basic condition s, the seconf part , i shpudlnt be already visted , and maze sould be 1 at that point
}





void ratInTheMaze(vector<vector<int>>&maze,vector<vector<int>>&visited ,vector<string>&combo , string result ,int row , int column , int n){//i also will have a visited matrix
    if(maze[row][column]==0){
        return;
    }
    if(row==n-1 && column==n-1){
        combo.push_back(result);
        return;
    }

    visited[row][column]=1;//already visisted one mark them

    //now try moving in every of the direction , heck using is safe , if its safe then move else not

    //lets move down
    if(isSafe(row+1 , column , maze ,visited , n)){//if true then it means its open
        ratInTheMaze(maze , visited , combo , result+"D" , row+1 , column , n);
    }
    
    //up
    if(isSafe(row-1 , column , maze ,visited , n)){//if true then it means its open
        ratInTheMaze(maze , visited , combo , result+"U" , row-1, column , n);
    }

    if(isSafe(row , column-1 , maze ,visited , n)){//if true then it means its open
        ratInTheMaze(maze , visited , combo , result+"L" , row , column-1 , n);
    }


    if(isSafe(row , column+1 , maze ,visited , n)){//if true then it means its open
        ratInTheMaze(maze , visited , combo , result+"R" , row , column +1, n);
    }


    visited[row][column]=0;//unmark it again
}

int main() {
    
    return 0;
}