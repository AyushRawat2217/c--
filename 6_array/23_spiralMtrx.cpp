#include <bits/stdc++.h>
using namespace std;


/*we will use 4 pointers make a  left right bottom top
then we will traverse according to that
*/
void spiralForm(vector<vector<int>>&matrix){
    int n=matrix.size();
    int m=matrix[0].size();
    int right=m-1;
    int left=0;
    int bottom=n-1;
    int top=0;

   while(top <= bottom && left <= right){


    for (int i = left; i < right; i++) {
        cout<<matrix[top][i]<<" ";
    }
    top++;
    for (int j = top; j < bottom; j++) {
        cout<<matrix[j][right]<<" ";
    }

    right--;


    //so that centre elemnt or element when top>bottom or left>right doesnt
    //get printed again so thats why we used if conditions

    if(top<=bottom){

    for (int k = right; k>=left; k--) {
        cout<<matrix[bottom][k]<<" ";
    }
    bottom--;

}

    if(left<=right){
    for (int l = bottom ; l>top; l--) {
        cout<<matrix[l][left]<<" ";
    }

    left++;
}
    
}



}
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

    spiralForm(matrix);
    return 0;
}