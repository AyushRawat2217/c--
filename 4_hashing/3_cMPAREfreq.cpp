#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n];

/*


brute force approach
    for(int i=0;i<n;i++){
        cout<<"enter"<<i;
        cin>>arr[i];
    }
int maxFreq = 0, minFreq = INT_MAX;
int most = -1, least = -1;
int count;
    for(int i=0;i<n;i++){

        count=0;
        for(int j=0;j<n;j++){
            if(arr[i]==arr[j]){
                count+=1;
            }
        
    }
     if(count > maxFreq) {
        maxFreq = count;
        most = arr[i];
    }

    if(count < minFreq) {
        minFreq = count;
        least = arr[i];
    }



    }

    cout<<most<<" "<<least;

*/




// optimal approach using map hashing
int maxFreq = 0, minFreq = INT_MAX; //specifying comparision variables
int most = -1, least = -1;


for(int i=0;i<n;i++){
        cout<<"enter"<<i;
        cin>>arr[i];
    }

   unordered_map<int, int> freq; //initialising the map

   for(int x:arr){
    freq[x]++;
    }

   for(auto i:freq){ //traversing a map



    if(i.second > maxFreq) {
        maxFreq = i.second;
        most = i.first;
    }

    if(i.second < minFreq) {
        minFreq = i.second;
        least = i.first;
    }
    
   }


   //i.first is the number and i.second is the number of times it appears

















return 0;
}