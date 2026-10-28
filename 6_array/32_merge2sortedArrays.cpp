#include <bits/stdc++.h>
using namespace std;


vector<int>mergeSortedArray2ptrs(vector<int>&num1 , vector<int>&num2){
    int n=num1.size();
    int m=num2.size();

    
    int i = n-1;
    int j=0;

    while(i>0 && j<m){
        if(num1[i]>num2[j]){
            swap(num1[i],num2[j]);
            i-- , j++;
        }
        else{
            break;
        }
        

    }

    sort(num1.begin(),num1.end());
    sort(num2.begin(),num2.end());
    


    
   
    
   


}

vector<int>mergeSortedArray3ptrs(vector<int>&num1 , vector<int>&num2){
    int n=num1.size();
    int m=num2.size();

   /* the zeroes used at last are actually the
   free spaces they arent part of free spaces inside the vector*/

   int i=n-1;
   int j=m+n-1;
   int k=m-1;

   while(j>=0){
    if(num1[i]>num2[k]){
         num1[k]=num1[i];
         i--;
    }
    else{
        num1[k]=num1[j];
        j--;
    }
    k--;

   }

}
    
vector<int>mergeSortedArrayGapOpt(vector<int>&num1 , vector<int>&num2){
    int n=num1.size();
    int m=num2.size();
    int gap=(m+n)/2 + (m+n)%2;

   

    while (gap>0){

        int left=0;
        int right=gap; // maintaning distance bw left and right
        
       
        if(right>(m+n)){
             gap=(gap/2)+(gap%2);
            
        }

        while(right<(m+n))//if right goes out of bound new gap will be generated
        {

            if(right<n && num1[left]>num1[right]){ // when ptr is in num 1 only
            swap(num1[left],num1[right]);
            }

            else if(left<n && right>=n && num1[left]>num2[right]){ //when one ptr is in num1 and other ptr is in num2
            swap(num1[left],num2[right-n]); // we subtract n , as num 1 0...n , num2 0....m , so if ptr is n+1 , but num2 dont have index n+@ , so to remain inside num2 we need to subtract n
            }

            else if(left>=n && num2[left]>num2[right]){ // left is greater than num1 inside num2 then obviously right too will be
            swap(num1[left-n],num1[right-n]);
        }

        left++ , right++;  // to move ptrs ahead , if left move right too
        // why right is not left+gap
       // because verytime we  start from left=0 , so 0+gap is gap

    }

    

    if(gap==1){  //to pass the last gap=1;
        gap=0;
    }

    gap=(gap/2)+(gap%2);

}

}

int main() {
    int m ,n;
    cin >> m>>n;

    vector<int>num1(m);
    for (int i = 0; i < n; i++) {
        cin >> num1[i];
    }
    
    vector<int> num2(n);
    for (int i = 0; i < n; i++) {
        cin >> num2[i];
    }

    vector<int>result=mergeSortedArray2ptrs(num1 , num2);


    return 0;
}