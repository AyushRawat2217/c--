#include <bits/stdc++.h>
using namespace std;

//out of all combo the case in which the max will be least
int minNrOfPagesToOneStdntBF(vector<int>&arr , int student ){
    int n= arr.size();
    int maxx=INT_MIN;
     int sum=0;
    for(int i:arr) {
        sum+=i;
        maxx=max(maxx , i);//the maxm allocation cant be smaller than max
    //we start from thist to sum of all book as all can be assigned to 1

    }


    for (int i = maxx; i <=sum; i++) {

        int m=1;// to hold nr of student we distributed books to 
        /*🧠 What Goes Wrong with 0

Let’s simulate:

Books:

[10, 20, 30]

Limit:

i = 100
If you start with 0:
Add 10 → still students_used = 0 ❌ (WRONG)
Add 20 → still 0 ❌
Add 30 → still 0 ❌

At the end:

students_used = 0

Now check:

0 <= m → TRUE

👉 Your code says:

“0 students handled all books”

That’s nonsense.*/
        int pagesGivenSofar=0; //nr of pages given to a student sp far
        
        for (int j = 0; j< n; j++) {
            
            if(pagesGivenSofar+arr[j]<=i){//check before going inside the condition
                // i made a mistake here again
                pagesGivenSofar+=arr[j];
                
            }
            else{
                pagesGivenSofar=arr[j];// the book will be assigned to new student , next student
                //first book can never be bigger than i as i is maxx
                m++;
            }
            
          
        }
        if(m<=student){// we can complete the assignment of book in less or =m , not necceasrily we need to use all student
            return i;
        }
      
    }

    return -1;
}




bool canAssignPerStudentThisLoadOrNot(int mid , vector<int>&arr , int n , int students){
    int m=1;//starting with first student
    int pagesGivenSofar=0; 
    for (int i = 0; i < n; i++) {
        if((pagesGivenSofar+arr[i]) <=mid){
            pagesGivenSofar+=arr[i];
        }
        else{
            m++;
            pagesGivenSofar=arr[i];// if pages so far exceeds the mid limit then assign the new book to next guy then stack up on him
        }
        if(m>students) return false;
    }

    return true;

}

int bookAllocationOpt(vector<int>&arr , int students){

    

    int n= arr.size();
    if (students > n) return -1;
    int maxx=INT_MIN;
    int sum=0;
    for(int i:arr) {
        sum+=i;
        maxx=max(maxx , i);//the maxm allocation cant be smaller than max
    //we start from thist to sum of all book as all can be assigned to 1
    }
   int mid;

    int low = maxx;
    int high=sum;
    

       while(low<=high){ 
        int mid=low+(high-low)/2; 

        if(canAssignPerStudentThisLoadOrNot(mid , arr , n , students)){//if true then try for lesser load
        high=mid-1;
        }
        else low=mid+1;
    }
    return low;
    /*| Goal          | Pattern | Return |
| ------------- | ------- | ------ |
| Minimum valid | ❌❌❌✅✅   | `low`  |
| Maximum valid | ✅✅✅❌❌   | `high` |
*/

}




int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return 0;
}