#include <bits/stdc++.h>
using namespace std;
/*we are given a array having heights of the histogram
we have to find a rectange which has max area 
*/

//12:38

/*logic is
we will take the index given to us , and from that point
we will move right and left simulatnoeusly along with the condition
that height of left or right rextangle is not smaller that the index from which we are moving*/
int ithMaxAreaFinder(const vector<int>&height , int  index){

    int width;
    int right =index;
    int left=index;

    while(left>=0 && (height[left]>=height[index])){//we land on first invalid position of left
        left--;
    }

    while(right<height.size() && (height[right]>=height[index])){// we land on first invalid position of right
        right++;
    }

    width=right-left-1;

    return (height[index]*width);
}

int maxAreaOfRecBf( const vector<int>&height){
    int maxArea=0;
    int ithMaxArea;
    for (int i = 0; i < height.size(); i++) {

      ithMaxArea= ithMaxAreaFinder(height , i);
      maxArea=max(maxArea , ithMaxArea);
    
    }
    return maxArea;
}




       //OPTIMAL APPROACH 1

/*logic
fing the nse and pse  indexes
whatver heights are behind them
will be the heights which are valid and which can
be incorporated inside the heights of graphs */

int maxAreaOfRecOpt1( vector<int>&height){
    vector<int>nseArr;
    vector<int>pseArr;

    nse(height , nseArr);
    pse(height , pseArr);

    int maxArea=0;
    int width;
    int left;
    int right;

    for (int i = 0; i < height.size(); i++) {
      right=(nseArr[i]==-1)?(height.size()+1):nseArr[i];

      width=right-pseArr[i]+1;
      maxArea=max(maxArea , (width*height[i]));
      
    }
    return maxArea;
    
}

void nse(vector<int>&height , vector<int>&nseArr){
    stack<int>st;//stack of index
    st.push(height.size()-1);

    for (int i = height.size()-2; i >=0; i++) {
        
        while(!st.empty() && height[st.top()]>height[i]){
                st.pop();
        }

        nseArr[i]=(st.empty())?-1:st.top();

        st.push(i);
    
    }

}

void pse(vector<int>&height , vector<int>&pseArr){//tells us where is the previous smaller elemnt of ith element
    stack<int>st;//stack of index
    st.push(0);

    for (int i =1; i<height.size(); i++) {
        
        while(!st.empty() && height[st.top()]>height[i]){
                st.pop();
        }

        pseArr[i]=(st.empty())?-1:st.top();

        st.push(i);
    
    }

}





                //OPTIMAL APPROACH 2


                /*logic
                isme jbh ham pse bna te hai usi ke saath saath nse mil jaat ahia
                agr pop hora hai mlb elemnt chota hai toh whi nse hogya na lullu
                aur pse wo hoga jo second last elemnt hoga stack ke*/
int maxAreaOfRecOpt1( vector<int>&height){
    stack<int>st;
    st.push(0);
    int nse;
    int pse=-1;
    int maxArea;
    int element;

    for (int i =  1; i < height.size(); i++) {

        while(!st.empty() && height[st.top()]>height[i]){

                element=st.top();

                st.pop();
                nse=i;
                pse=(st.empty())?-1:st.top();//after popping the main element the last second is the element
                //which is maller than the popped elemnt

                maxArea=max(maxArea , st.top()*(nse-pse-1));
                
        }

        st.push(i);
         
    }

    //if there are elements remaining
    while(!st.empty()){//it means those elemnt didnt get any nse 
             element=st.top();

                st.pop();
                nse=height.size();
                pse=(st.empty())?-1:st.top();//after popping the main element the last second is the element
                //which is maller than the popped elemnt

                maxArea=max(maxArea , st.top()*(nse-pse-1));
    }
    
}

//tc oN + On



int main() {
    
    return 0;
}