#include <bits/stdc++.h>
using namespace std;

void reverse (string &res){

}


//code to convert decimal to binary
void decimal2bin(int num , string &res){
     while(num!=1){//jbtk 1 ni aajata ed tkk ka
        if(num%2)res+="0";
        else res+="1";

        num=num/2;

    }
    
    reverse(res);//reverse the result
}
//tc is o log2n , space complex is log2n 
//2 se divide hora hai isliye log 2 n


int bin2decimal (string &bin){

    int size =bin.size();
    int powerOf2=1;
    int result=0;

    for (int i = size; i >=0; i--) {
      if(bin[i]=='1'){
        result+=powerOf2;//smart move alg se end wale one ke liye condition ni bnani pdi
        //kyuki last one ke time toh 2 se ni hai 1 se mult hota hai , 2 ki pwer 0 is 1
   
      }
//fkin smart move didnt need to create else 
           powerOf2*=2;
      
    }

    return result;
}

int main() {
    int num;
    cin>>num;
    string res;

    cout<<res;

    return 0;
}