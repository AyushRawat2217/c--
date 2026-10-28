#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>rotate90Bf(vector<vector<int>>&matrix){
    int n=matrix.size();
    int m=matrix[0].size();

    vector<vector<int>>matrix2(n,vector<int>(m));
    

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {//by visualisation
           matrix2[j][n-i]=matrix[i][j];
        }
    }

    return matrix2;
}


//logic is first we transpose the matrix then we revesre the elemnts of the rows
void rotate90OPt(vector<vector<int>>&matrix){
    int n=matrix.size();
    int m=matrix[0].size();

    int i=0;
    int j=n-1;

    vector<vector<int>>matrix2(n,vector<int>(m));
    

    ///transpose
    for (int i = 0; i < n; i++)
    {

        for (int j = i+1; j < m; j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    //reverse
    for(auto &it:matrix){
        reverse(it.begin(),it.end());

        
    }

    



 
}




//2nd method is first i do transpose of the matrix 
int main() {
     int n, m;
    cin >> n >> m;

    // vector<vector<int>>matrix; //the matrix vector is storing vectors inside it

    vector<vector<int>> matrix(n, vector<int>(m)); //n rows , m columns
    
    
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
           cin>>matrix[i][j];
        }
    }
    return 0;
}