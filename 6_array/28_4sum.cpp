#include <bits/stdc++.h>
using namespace std;


/*
using 4 loops 
*/
vector <vector<int>> fourSumBf(){
}


/*better approach logic is using
that we will set 3 loops to catch 3 numbers and sum of those 3 will be negative of the
4th elemnt , and we will keep stacking the kth index elemnt inside the set 
and every time for i n j , it will search whether the negatve of
i ,j , k index elemnts sum exist or not , if yes
we store the quadruplets 


*/
set<vector<int>> fouRsumBr(vector<int>&arr){

    int n=arr.size();
    int fourth;

    set<vector<int>>result;
    for (int i = 0; i < n; i++) {
        
        
        for (int j = i+1; j < n; j++) {

            set<int>stt;
            /*
            we keep it inside j loop because 
            if we keep inside i , then for i=1 j=2 , i=1 , j=1 would repeat
            and we need unique cases
            */

            for (int k =  j+1; k < n; k++) {

              fourth = -(arr[i] + arr[j] + arr[k]);

               

                if(stt.find(fourth)!=stt.end()){
                    vector<int>vec={arr[i],arr[j],arr[k] ,fourth};
                    sort(vec.begin(),vec.end());
                    result.insert(vec);
                }

                stt.insert(arr[k]);
                //if we inserted before seacing then there could be a case 
                //that 3rd n 4th elemnt come at same index
                //insert k=2 , then serch what if 4th elemnt satisy index 2 elemnt we dont want that

                

            }
          
        }

      
    }

    return result;

}


/*
we have to keep i ,j ,k  at the prev 3 positions
and l at last position and as we did in  3 sum we skips duplicate elemnts and
check whether four sum is 0 along with other conditions
*/
void fourSumOpt(vector<int>&arr){
    int i=0;
    int n=arr.size();

     set<vector<int>>result;

   
    int k;
    int l;

    for (int i = 1; i < n; i++) {

        if(i>0 && arr[i]==arr[i-1]){
            continue;
        }

        for(int j=i+1;j<n;j++){
            if(j!=i+1&&arr[j]==arr[j-1]){
                continue;
            }

            k=j+1;
            l=n-1;

            while(k<l){ //2 ptrs concept

                int sum=arr[i]+arr[j]+arr[k]+arr[l];



                /*
                sum 0 hai toh krlo add , fir unique elemnt tkk traveserse krlo
                agr sum>0 hai toh thoda negative leao , l ko peeche krke
                and agr +ve h toh positive kro k ko badha ke*/

                if(sum==0){  
                    vector<int>vec={arr[i],arr[j],arr[k] ,arr[l]};
                    sort(vec.begin(),vec.end());
                    result.insert(vec);
                    k++;
                    l--;
                    while(k<l && arr[k]==arr[k-1]){
                        k++;
                    }
                    while(k<l && arr[l]==arr[l+1]){
                        l--;
                    }
                }

                else if(sum<0){
                    k++;
                }
                else{
                    l--;
                }



            }


        }
        
      
    }
}



int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    set<vector<int>>stt =fouRsumBr(arr);

    for(vector<int>it:stt){
        for(int it2:it){
            cout<<it2;
        }
    }
    return 0;
}