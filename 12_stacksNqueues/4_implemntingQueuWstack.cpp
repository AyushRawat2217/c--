#include <bits/stdc++.h>
using namespace std;

//approach 1
class Queue1{
    stack<int>st1 ,st2;

    public:
        void push(int x){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }//pehle saare elemnts s2 ke andar daal do 

            st1.push(x);//main elemnt ko push kro st1 ke andr taaki wo sbse pehle andr jaaein and last to getout bne jo ki queue mai hora hai

            //fir sbko re push krdo s2 se s1
            ///yha pe we could push x s2 mai hi taaki prr baat barabar hai
            while(!st2.empty()){
                st1.push(st2.top());
                st2.pop();
            }


        }

        int top(){
            return st1.top();
        }

        void pop(){
            st1.pop();
        }


};

//in this case the push operation is very expenisce O2n


//approach  2

class Queue2{
    stack<int>st1 ,st2;

    public:
        void push(int x){
            st1.push(x);
        }

        int top(){
            if(!st2.empty())st2.top();//agr st2 mai elemnt bache hai toh whi se top ya pop krdo 

            else{while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            st2.top();
        }
        }

        void pop(){
        if(st2.empty())st2.pop();
          
          else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            st2.pop();
        }
        }

//here we divided the work among functions
/*pehle push hi sbh krra tha abh top and pop both with on comlexity koi ek
particular expensive fn ni h
isme s1 mai sbh daalenge and top pop ke time sw mai daal denge sbh*/
};

int main() {
    
    return 0;
}