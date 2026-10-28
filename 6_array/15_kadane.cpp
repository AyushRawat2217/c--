#include <bits/stdc++.h>
using namespace std;
int count2=INT_MIN;

int maXsARRsum3loop(vector<int>&arr,int n){
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int count=0;

            for (int k = i; k < j; k++) {
                count+=arr[k];
            }

            count2=max(count2,count);
        }
    }
    return count2;
    
}

int maXsARRsum2loop(vector<int>&arr,int n){
    for (int i = 0; i < n; i++) {
        int count=0;
       
        for (int j = i; j < n; j++) {
            count+=arr[j];

            if(count2<count){
                count2=count;
              }
        
        }
    }
    return count2;
    
} 

int maXsARRsum1loop(vector<int>&arr,int n){

    //count 2 ka kaam ye hi ki maximum value jo count krdera h uska track rkhna
    // {-1,-2}ki array m count -2 de dega prr count 2 store krke rkhega
    //if(count<0){ count=0;} yahi kadane h
    int count=0;//current sum
    int count2=arr[0];//max value track
    for (int i = 0; i < n; i++) {


        //ye bhi toh hoskta h 2 , 3 , -3  , 10  , -3 ki vjh se count 0 krdiya toh , 
        // max sum 10 aaega orr reality m tohn2+3+-3+10 , 12 aaara h 
        count+=arr[i];
        count2=max(count,count2);

        if(count<0){
            count=0;
        }


    }
    
    return count2;
    
}

//returning subarrray

vector <int> maxSumArr(vector<int>&arr, int n){

    int mstart;
    int start;
    int end;
    int sum=0;
    int max=INT_MIN;

    

    for (int i = 0; i < n; i++) {
        if (sum==0){//starts when sum is 0
         start=i;
        }

        sum+=arr[i]; //does the sum



        if(sum>max){ //asigns final start and end
            max=sum;
            mstart=start;// we need this because first start keeps changing with new sum=0

            end=i;
        } 


        if(sum<0){
            sum=0;
        }


      
    }
    return vector<int>(arr.begin()+mstart ,arr.begin()+end);
    
}


int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result=maXsARRsum1loop(arr,n);
    cout<<result;
    return 0;
}