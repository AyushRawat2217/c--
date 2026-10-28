#include <bits/stdc++.h>
using namespace std;

int maxProdofSbaryBf(vector<int>&arr){
    int n=arr.size();
    int max1=1;
    int max2;
    for (int i = 0; i < n; i++) {
        max2=1;
        
      for (int j = i; j< n; j++) {

        max2=max2*arr[j];
        max1=max(max1,max2);
       
      }
    }

    return max1;
}

/*Sum problems are easy. Product problems are dangerous.

Why?

Because of:

Negative numbers → flip sign
Zero → resets everything

That means:

A small negative today can become a massive positive tomorrow*/


/*
“min is the worst product of a subarray ending at current index”*/


int maxProdofSbaryOpt(vector<int>&arr){
    int n=arr.size();
    int maxSoFar=arr[0];
    int minSoFar=arr[0];
    int res=arr[0];

    for (int i = 1; i < n; i++) {
     
      /* we used tempmin max bcs if we use minsof and maxof directly'
      then we would be manipulating min by using the max whose value just changed but we need a absolute and histrocal value*/


      /*At index i, you ask:

      Continue with current unit (extend max)
        Use risky unit (extend min)
      Abandon both and start a new unit from here

        That third option is arr[i].*/
      int tempMax = max(arr[i], max(maxSoFar * arr[i], minSoFar * arr[i]));
     int tempMin = min(arr[i], min(maxSoFar * arr[i], minSoFar * arr[i]));
       //this min could be future asset
      maxSoFar=tempMax;
      minSoFar=tempMin; //stores a negative value which may in future give a big value
      
      res=max(maxSoFar, res); //res stores past biggest maxSofar , even if we start for a new subarray we keep track of older max
    }
}


/*
Prefix–Suffix works because at least one traversal reaches the optimal 
subarray without being corrupted by earlier negatives or zeros*/
int maxProdofSbaryOpt2(vector<int>&arr){
    int n=arr.size();
    int prefix=1;
    int suffix=1;
    int res=INT_MIN;

    /*
    logic ye h ki dono side se try krna h add krne ka
    dekh 4 cases h , 

    max prodcut wali array pehle aajaein
    5 ,6 ,7 -1(odd negative quantity)[onq]
    prefix krdega kaam

    cse 2 , onq good even nq
    dekh prefix aaega prod krega and chud jaaega start m
    prr suffix even nq se positive sum laaega + good bhi multiply hoga life sett , res m stored


    case 3 enq good onq
    vice verse , prefix play krr jaaegaa


    case 4- onq good

    suffix pel dega 

    sbh covered h iske andr

    ek doubt aaega ki agr negatives beech m hue??
    bhai traversal k time , negative qunatify honge and enq and onq ki form lenge , at the end
    */


    /*
    more techchoda way

    Prefix–Suffix Insight:

Maximum product depends on position of disruptive elements (negatives/zeros).

- If disruption happens early → prefix gets corrupted → suffix captures optimal segment
- If disruption happens late → suffix gets corrupted → prefix captures optimal segment

Thus, at least one traversal reaches the optimal subarray in a clean state.
    */
    for (int i = 0; i < n; i++) {
      prefix*=arr[i];
      suffix*=arr[n-1-i];

      res= max(prefix , max(suffix , res)); //gving res a chance to get compared with zero , kyuki zero is greater than negative 
      if(arr[i]==0){
        prefix=1;
      }
      if(arr[n-1-i]==0){
        suffix=1;
      }
      
     
    }
    return res;

}


int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result=maxProdofSbaryOpt(arr);
    cout<<result;
    return 0;
}