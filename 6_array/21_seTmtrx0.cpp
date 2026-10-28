#include <bits/stdc++.h>
using namespace std;

int setMtrxZeroBf(int a[100][100], int n)
{
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 0)
            {

                // 1
                /*
                for (int l = 0; l < n; l++) {
                    if(a[l][j]!=0){
                        a[l][j]=-1;
                    }
                }

                for (int k = 0; k < n; k++) {
                    if(a[k][j]!=0){
                        a[k][j]=-1;
                    }
                }*/

                // 2
                /*

                this block of code keeps complexity to on4
                 for (int k = 0; k < n; k++)
                {


                    //to reframe elemnets to -1
                    for (int l = 0; l < n; l++)
                    {//to reframe but not let 0 change to -1
                        if((k==i|| l==j)&&a[k][l]!=0){
                            a[k][l]=-1;

                        }
                    }
                }
                  */
            }
        }
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == -1)
            {
                a[i][j] = 0;
            }
        }
    }
}


void setMtrxBr(vector<vector<int>>&matrix){
    int n=matrix.size();
    int m=matrix[0].size();

    //logic is ham row col array bnate h and unme zero stroe krte h 
    //fir 2d array m jaha 0 aata h uss row col ko 1 mark krdete h
    //jo row col ko 1 h uske saath k nrs ko 0 krdete h next loop se


    //this doesnt risk stack overflow
   vector<int> row(n, 0);
   vector<int> col(m, 0);

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
           if(matrix[i][j]==0){
                row[i]=1;
                col[j]=1;

           }
        }
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            if(row[i]==1||col[j]==1){
                matrix[i][j]=0;
            }
           
        }
    }






}



//to reduce space complexity we dont make 2 separate arrays to mark
void setMtrxOpt(vector<vector<int>>&matrix){
     int n=matrix.size();
    int m=matrix[0].size();

    //1 checking that first row n column has zero or not
    
    bool firstRowHasZero=false;
    bool firstColHasZero=false;

    for (int i = 0; i < n; i++) {
        if(matrix[0][i]==0){
            firstRowHasZero=true;
        }

    }
    for (int i = 0; i < n; i++) {
        if(matrix[i][0]==0){
            firstColHasZero=true;
        }
    }
    




    //2 now we will traverse the 2d matrix except row 0 and column 0 , n mark element of row col 0 , as 0 if we find zero
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        if(matrix[i][j]==0){
            matrix[0][j]=0;
            matrix[i][0]=0;
        }
      }
    }

    //3  now we marked , row 0 n col 0 , so we will mark rest elemnt zero using it
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        if(matrix[0][j]==0||matrix[i][0]==0){
            matrix[i][j]=0;
        }
      }
    }


    //now at first we marked whether first row n col has zero or not , and if they have
    //then we will turn the whole row or col zero whichever has zero
    //agr doubt aara h ki row ka ek element 0 h , chlo poori row zero krdi prr uska repective columns?
    //dekh wo cheez 3rd step m wo hogya already

    if(firstRowHasZero){
        for (int i = 0; i < n; i++) {
            matrix[0][i]=0;
          
        }
    }
    if(firstColHasZero){
        for (int i = 0; i < n; i++) {
            matrix[i][0]=0;
          
        }
    }



}
int main()
{
    int n, m;
    cin >> n >> m;

    // vector<vector<int>>matrix; //the matrix vector is storing vectors inside it

    vector<vector<int>> matrix(n, vector<int>(m)); //n rows , m columns
    /*
    This means:

Create a vector of size n

Each element of this vector is initialized with:

vector<int>(m)


So:

You get n rows.

Each row has m columns.
    */
    
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
           cin>>matrix[i][j];
        }
    }

    setMtrxOpt(matrix);



    return 0;
}