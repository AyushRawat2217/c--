#include <bits/stdc++.h>
using namespace std;

/*tc is  o N3 log(no. of unique triplets)
 */
void threeSumBF(vector<int>&arr){
    int n=arr.size();

    set<vector<int>>st;
   
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j< n; j++) {
        for (int k = j+1; k < n; k++) {
         
            if(arr[i]+arr[j]+arr[k]==0){
                vector<int>temp={arr[i],arr[j],arr[k]};
                sort(temp.begin(),temp.end());
                st.insert(temp); //to insert unique set of triplets inside set

          }
        }
      }
    }
}

/*
*/
set<vector<int>> threeSumBr(vector<int>&arr){
    int n=arr.size();
    set<vector<int>>result;

    for (int i = 0; i < n; i++) {

         set<int>st; //we have to reset this with every i , otherwise it will take duplicate values

        for (int j=i+1; j< n; j++) {
            
                int third=arr[i]+arr[j];
                if(st.find(-(third) )!= st.end()){

                    vector<int>res={arr[i],arr[j],-third};
                   

                   //this part to store unique triplets
                    sort(res.begin(),res.end());
                    result.insert(res);

            }

            st.insert(arr[j]);
        }
      
    }

    return result;   
}

void threeSumOpt(vector<int>&arr){
    int i=0;
    int n=arr.size();
    


    for(int i=1;i<n;i++){

        if(i>0 && arr[i]==arr[i-1]){
            continue;
        }
        else{
            int j=i+1;
            int k=n-1;

            while(j<k){
                int sum=arr[i]+arr[k]+arr[j];

                if(sum==0){
                    cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<" ";
                    j++;
                    k--;

                    while(j<k && arr[j]==arr[j-1]){
                        j--;
                    }

                    while( j<k && arr[k]==arr[k+1]){
                        k--;
                    }
                }
                else if(sum<0){
                    j++;

                }
                else{
                    k--;
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
       threeSumOpt(arr);
    return 0;
}