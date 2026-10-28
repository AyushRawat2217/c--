#include <bits/stdc++.h>
using namespace std;

class Stack{
queue<int>q;//we will use built in queue function

public:
    void push(int x){
        /* abhi tkk hota ye aara tha ki
        queue mai elemnt aaega toh ek ke peeche ek fir ek
        aisa hoga jo sbse pehle input hua whi element
        bnta tha top
        prr stack ke case mai last input elemnt hi top hoga toh isliye 
        agr hmne ek elemnt push kiya wueue mai toh hame baaki elemnts remove krke peeche daalne honge
        new elemnt ke 

        ex input , 1 2 3 , quueue= 1 2 3
        but stack=3 2 1
        toh isliye htakr peeche daalne hai , size-1 tkk ke elemnt
        */
        q.push(x);
        for (int i = 0; i < q.size(); i++) {
          q.push(q.front());
          q.pop();
        }

    }

    void pop(){//as queue is already reversed by push function
        q.pop();
    }

    int top(){
        return q.front();
    }

};

int main() {
    
    return 0;
}