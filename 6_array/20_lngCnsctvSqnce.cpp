#include <bits/stdc++.h>
using namespace std;
/*longest consecutive series of elemnts inside array , order of elemnts doesnt matter*/

/*algo 
take the first elmeent search the just next elemnt inside it if found
store that then increase that by one and find next ad use a flag as well if after i linear search elemnt is found
return the elemnt else no*/

bool linSrch(vector<int>&arr,int num){
    for (int i = 0; i < arr.size(); i++) {
        if(num==arr[i]){
            return true;
        }
      
    }
    return false;
}

int lngCnsArrBF(vector<int>&arr,int n){
    //we use linear search , for loop traverse every element and while loop inside it
    //checck are consecutive elements present in loop or not
    int maxc=INT_MIN;
    for (int i = 0; i < n; i++) {
        int num=arr[i];
        int cnt=1;


        while(linSrch(arr,num+1)){ // linear search return that whether elemnt is found or not
            num++;
            cnt++;

        }
        maxc=max(cnt,maxc);

    }

    return maxc;
} 


//just sort the array and check the consecutive nrs
int lngCnsArrBr(vector<int>&arr,int n){
   
    int maxc=INT_MIN;
    
    sort(arr.begin(),arr.end());
    int cnt=1;

    for (int i = 0; i < n-1; i++) {
        if(arr[i]+1==arr[i+1]){
            cnt++;
        }
        else{
            cnt=1;
        }
        maxc=max(cnt,maxc);
    }
    

    return maxc;
} // tc o logn



/*logic is creating a unorderedset so we can enjoy
find function it offers along with the perk that  insertion to set is a on
time complexity process
*/
int lngCnsArrOPT(vector<int>&arr,int n){
    
    int maxc=INT_MIN;

    unordered_set<int>sett;
    for(auto &it:arr){
        sett.insert(it);
    }

     int cnt=1;
     for(auto &it:sett){
        if(sett.find(it-1)==sett.end()){//to initialise cnt we use this code as we need to ensure , for a number we want to find its next consecutive
            //we need to be sure that its the nr which is starting the series , if its in mid of series than we wont waste time on counting consecutive nr
            //of lesser than whole series we will find a number which has no prior consecutive nr then we will move and fid its consecutive nrs
            
            cnt=1;
            
            int x=it;//as we use it in main loop we dont want to change it so we store it in a variable
            while(sett.find(x+1)!=sett.end()){//if x+1 exists then increase x and count and check for just next one
                x=x+1;
                cnt++;
            }

            maxc=max(maxc,cnt);
        }
    }

    return maxc;
} 



int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int res = lngCnsArrBF(arr,n);
    cout<<res;
    return 0;
}