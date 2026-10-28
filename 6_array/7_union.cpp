#include <bits/stdc++.h>
using namespace std;


//1st apprch
/*insert the elemnts of vectors in map , and increse value of
key of map as the frequency of elemnt increases
and at last print the key only 
duplicate elemnts converts to frequency of the key so it becomes 
easy
*/
void unionMap (vector<int>&a , vector<int>&b , int n , int m){
    map<int , int> freq;

   
    for(int i=0;i<n;i++){
        freq[a[i]]++; //mapping
    }

    for(int i=0;i<m;i++){
        freq[b[i]]++; //mapping
    }

    for(auto x:freq){
        cout<<(x.first)<<" ";
    }
}



//  2nd apprch

void unionSet (vector<int>&a , vector<int>&b , int n , int m){
    set <int>st;


    for(int i=0;i<n;i++){
        st.insert(a[i]);
    }

    for(int i=0;i<m;i++){
        st.insert(b[i]);
    }

    for(auto x:st){
        cout<<(x)<<" ";
    }

}





//3rd apprch

void twoPtr (vector<int>&a , vector<int>&b , int n , int m){
int i=0;
int j=0;
    vector<int>uni;

    while(i<n&&j<m){//loop works until both array has elemnts

        if(a[i]<b[j]){
            if (uni.size()==0|| uni.back()!=a[i]){ //If uni is empty OR last element is different → push it
                uni.push_back(a[i]);
                i++;
            }
        }

        else{
            if (uni.size()==0|| uni.back()!=b[j]){
                uni.push_back(b[j]);
                j++;

            }
        }

    }

    //if at the end elemnts are remaining

    while(i<n){
        if(uni.back()!=a[i]){

            uni.push_back(a[i]);
                i++;

        }
    }

     while(j<m){
        if(uni.back()!=b[j]){

            uni.push_back(b[j]);
                j++;

        }
    }

}

int main() {
 int n , m;
    cin >> n>>m;
  
    vector<int> a(n); //either specify size of vector or use pushback  
    vector<int> b(m); 
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
     for(int i = 0; i < m; i++) {
        cin >> b[i];
    }


    // unionMap(a , b ,n ,m);

return 0;
}