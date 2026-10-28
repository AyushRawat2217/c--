#include <bits/stdc++.h>
using namespace std;

/*
maximum distance bw adjacent stn should be minimum
ek arr di h jisme elemnts already built gas stns k co ordinates h
aur hame k diya h which is we have to contruct nk new gas stn bw the current ones
such that the mx distance bw adjacent should be minimum

abh isme segments k beech daalna h hame k naye stn ko

let a array
1 , 13 , 20 , 24 , 30
k=5

isme 4 segments h
1-13 , 13-20 , 20-24 , 24-30

isme k abh ais daalna h ki inn segments k beech ka gap minimise hojaein
logic ye h ki pehle maxm gap ko fill krenge fir next max and keep doing it until we get exhausted of k

ye kese krna h ?

ek aisi array bnayenge usko hashArray keh skte h , usme ham segment ko nr of stn jo hmne uss segment m daale h
uske saath map krenge , and we will use a fn for this

fir ek dusra fn bnayenge jiska use ham , hashArray ka use krke , min distance bw adjacent array elemnt nikaalne 
mai use krenge , ye h logic
*/


//point is we have to minimise the maximum distance
double maxDistBwGasStBF(vector<int>&arr , int nrOfGasStn){

    int n=arr.size();
    vector<int>howManyStnInSegments(n-1 , 0);// as there are n-1 segments and using this 
    //we will determine which segments has how many stn alloted out of k

 

    for (int i = 1; i <=nrOfGasStn; i++) { //fitting in every gas stn inside array
        
        int maxIndex=-1;
        double maxDistance=-1.0;

        for (int j = 0; j < n-1; j++) {
        int diff=arr[j+1]-arr[j];//diff bw adjacent already built gas stn
        //we will use it to find max distance then we will fill that segment

        double distBwGSInSeg = diff/(double)(howManyStnInSegments[j]+1);//the dist bw adjacent stn because of addn of new 
        /*jitne stn segment k andr honge utne+1 se divide krke 
        distbwGdInseg nikl jaaega*/

        if(distBwGSInSeg>maxDistance){// to fing the max segment to add next stns in 
            maxDistance=distBwGSInSeg;
            maxIndex=j;
        }

      }

      howManyStnInSegments[maxIndex]++;//at that index where max Distance segment is present
      //we add one more stn
    }
   //after this full 0-n-1 iteration we find the biggest distance segment
    //then we add a stn in that segment 

    


    //2nd part is now we find the maximum distance 
    double maxDistanceOverall= -1.0;
    for (int i = 0; i < n-1; i++) {
       int diff=arr[i+1]-arr[i];
       double distBwGSInSeg = diff/(double)(howManyStnInSegments[i]+1);
       maxDistanceOverall=max(maxDistanceOverall , distBwGSInSeg);
    }

    return maxDistanceOverall;

}

//the mistake i did was i had to deal in double as dist was decimal and double is more precise that float


double maxDistBwGasStBr(vector<int>&arr , int nrOfGasStn){

    int n=arr.size();
    vector<int>howManyStnInSegments(n-1 , 0);// as there are n-1 segments and using this 
    //we will determine which segments has how many stn alloted out of k
 
    priority_queue<pair<double , int >>distAndSegNr; //double will store the distance , int will store segment nr
    //priority queue because max distance will be at top 


    //first we will insert all diff inside pq
    for (int j = 0; j < n-1; j++) {
        int diff=arr[j+1]-arr[j];//diff bw adjacent already built gas stn
        //we will use it to find max distance then we will fill that segmentfor (int j = 0; j < n-1; j++) {
        
        distAndSegNr.push({diff , j});

         }



    for (int i = 1; i <=nrOfGasStn; i++) { 
    auto topp = distAndSegNr.top();//contain max segment distance and its nr
    distAndSegNr.pop();//remove the top part of quque

    int MaxSegNr = topp.second; 
    howManyStnInSegments[MaxSegNr]++; //add a gas stn

    double newLengthOfBiggestSegment=(arr[MaxSegNr+1]-arr[MaxSegNr])/(double)(howManyStnInSegments[MaxSegNr]+1);

    distAndSegNr.push({newLengthOfBiggestSegment , MaxSegNr});

    }
return distAndSegNr.top().first;

}



bool canPlace(vector<int>&arr , int nrOfGasStn , int n , double mid){//mid is the assumed distance bw adjacent gas stn
    /*assumed may distance used to find how many gas stn can be put
    between two segments
     if less comes try for more less distance*/
    
     int count=0;
    for (int i = 0; i < n-1; i++) {
      int diff=arr[i+1]-arr[i];
      int parts= ceil(diff/mid);// using this we derive how many segments we will get when we use mid
      count+=(parts-1);
    }
    return (count<=nrOfGasStn) ; // if true then we will check for a lower value
    //else we will do for a higher

}

double maxDistBwGasStnBinarySearch(vector<int>&arr , int nrOfGasStn){
    int n=arr.size();
    double low=0;
    double high=arr[n-1] - arr[0];//High must be the max possible gap, not the coordinate.

    while(high-low>1e-6){// to be precise we used this logic 
        double mid = low+(high-low)/2;

        if(canPlace(arr , nrOfGasStn , n , mid)) high=mid;
        else low=mid;

    }
    return high;
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