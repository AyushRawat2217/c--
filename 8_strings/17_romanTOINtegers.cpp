#include <bits/stdc++.h>
using namespace std;

int returnRomanValues(char &ch){

    switch(ch){
  
    case 'I':
        return 1;
        break;
    
    case 'V':
        return 5;
        break;
    
    case 'X':
        return 10;
        break;
    
    case 'L':
        return 50;
        break;
    
    case 'C':
        return 100;
        break;
    
    case 'D':
        return 500;
        break;
    
    case 'M':
        return 1000;
        break;
    
    default:
        return 0;
        break;
}

}

/*logic is create a function which return roman valuse for default 
roman flags such AS i , c , x , v ETC
if roman nr from right to left are in increasing order then simply add the values of roman number
u encounter using the function we created

ex VI , v is greaater than i , i is 1 and v is 5 
result+=1 , then result +=5 , 6

but if trend breaks then substract that particular char from the result*/
int romanToInteger(string &s){
    int n=s.size();
    int result=0;

    char prevChar=s[n-1];
    result+=returnRomanValues(prevChar);
    
    for (int i = n-2; i >=0; i++) {
       if(returnRomanValues(s[i])>=returnRomanValues(prevChar)) result+=returnRomanValues(s[i]);
       else result-=returnRomanValues(s[i]);

       prevChar=s[i];
    
    }

    return result;
}

int main() {
    
    return 0;
}