#include <bits/stdc++.h>
using namespace std;

vector<int> msnfAndRptingNrBf(vector<int>&arr){
    int n= arr.size();
    int count;

    int missing;

    vector<int>result;

    for (int i = 0; i < n; i++) {

        count=0;

        for (int j = 0; j< n; j++) {

            if((i+1)==arr[j]){
                count++;
            }
           

        }

        if(count==2){
            
            result.push_back(i+1);
        }
        else if(count==0){
            missing=i+1;
        }
      
    }

    result.push_back(missing);

    return result;
}

vector<int> msnfAndRptingNrBr(vector<int>&arr){
    int n= arr.size();
    int count;

    int repeat;

    int missing;

    vector<int>result;

    unordered_map<int , int >mpp;

    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
      
    }

    for (int i = 0; i < n; i++) {
      if(mpp[arr[i]]==2){
        repeat=arr[i];
      }
      else if(mpp[arr[i]]==20){
        missing=arr[i];
      }

    }

    result={repeat,missing};



    

    

    return result;
}


//this approach when missing nr is fraray from repeating it fails
/*
vector<int> msnfAndRptingNrOpt(vector<int>&arr){
    int n= arr.size();
    int count=0;

    int repeat;

    int missing;

    vector<int>result;

    sort(arr.begin(),arr.end());

    for (int i = 0; i < n; i++) {

        if((i+1)==arr[i]){
            count++;
            if(i<n-1 && arr[i]==arr[i+1]){
                count++;
            }
           
        }

        if(count==0){
            missing=i+1;
        }

        if(count==2){
            repeat=arr[i];
        }

        count=0; 
      
    }



    result.push_back(repeat);
    result.push_back(missing);




    

    

    return result;
}

*/


vector<int> msnfAndRptingNrBr2(vector<int>&arr){
    int n= arr.size();
    int count=0;

    int repeat;

    int missing;

    unordered_set<int>stt;
    

    vector<int>result;
    int cnt=0;

    for (int i = 0; i < n; i++) {

        cnt+=arr[i];

      
    }

    for (int i = 0; i <n; i++) {
        stt.insert(arr[i]);
    }

    for(auto &it:stt){
        count+=it;
    }

    int sum= (n*(n+1))/2;

    cout<<count<<" "<<cnt<<" "<<sum<<endl;

    missing=sum-count;
    repeat=(cnt+missing)-sum;






   


    result.push_back(repeat);
    result.push_back(missing);




    

    

    return result;
}

vector<int> msnfAndRptingNrPeak1(vector<int>&arr){
    int n= arr.size();
    int repeat;
    int missing;
    vector<int>result;
    
    int cnt=0; // sum of all elemnts of array
    for (int i = 0; i < n; i++) {
        cnt+=arr[i];
    }

    int sum= (n*(n+1))/2;

    int a = sum-cnt; //all nr -(all nr - missing+repeating)=-repeating+missing
    
    int sumSqr = (n*(n + 1)*((2*n)+ 1))/ 6;

    int sumsqrArr=0;

    for(int &it:arr){
        sumsqrArr+=(it*it);
    }
    
    int b= sumsqrArr - sumsqrArr; // -repeating**2 + missing**2 =(-repeating+missing or a)(missing+repeating or c)

    int c = b/a; // it gives missing+repeating

    repeat=(c-a)/2;

    missing=(c+a)/2;

    result.push_back(repeat);
    result.push_back(missing);
    return result;
}



/*

logic- xor approach
a^a=0
a^1=a
a^0=a


1s complemnet is inverting all the bits
2s comolement is 1s complemnt +1





It does TWO things:

All trailing zeros → stay 0

First 1 from right → becomes isolated




You are:

isolating the lowest active 1-bit

That bit is guaranteed to be:

a position where missing ≠ repeating



when we do rptXOrMiss and ~rptXOrMiss(2s comp)
we get the bit where both elemnts missing and repeating distinct at

so at last we find the elemnts which has that bit at that particular place
along with those which dont

and then we will do same with natural nrs and at last we will
xor all the separated elements , nr which appear once , will get cancelled
and in both contaners repeating or missing element will be only there


then one more loop to find which is which

*/
vector<int> msnfAndRptingNrPeak2(vector<int>&arr){
    int n= arr.size();
    int repeat;
    int missing;
    vector<int>result;
    int arrXor=0; // xor of all elemnts of array
    int nXor=0;

    for (int i = 1; i <=n; i++) {
       nXor^=i;
    }

    for (int i = 0; i < n; i++) {
        arrXor^=arr[i];
    }

    int rptXOrMiss=nXor^arrXor;

    int rightmostBit= rptXOrMiss & (~rptXOrMiss);

    int a=0;
    int b=0;

    for (int i:arr) { // to separate elememnts

        if(rightmostBit & i ){
            a^=i;
        }
        else{
            b^=i;
        }
      
    }

    for (int i = 1; i <=n; i++) {
      if(rightmostBit & i ){
            a^=i;
        }
        else{
            b^=i;
        }
    }


    for(int i:arr){
        if(a==i){
            missing=b;
            repeat=a;
            break;
        }
        else{
            missing=a;
            repeat=b;
        }
    }

    result.push_back(repeat);
    result.push_back(missing);

    return result;
}




int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int>result = msnfAndRptingNrPeak2(arr);

    for(auto &it:result){
        cout<<it<<endl;
    }
    return 0;
}