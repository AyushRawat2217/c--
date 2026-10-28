#include <bits/stdc++.h>
using namespace std;

/*problem
maan lo numerator and denominator diya hai
22 and 3 , toh 22/3 =7.smthng , answer aaega 7 
output 7 dena hai

aur undeflow and overflow ke casses bhi hai
agr answer is less than -2^31 , or greater than +2^31-1
toh respectively int min and int max krdena result as output
*/

/*logic is
we keep adding the denominator in sum until wo num ka nearest
smallest in bnn jaata and jitne baar sum krre hai count krte rho krte rho and last mai count return krdo
prr iska drawlbak ye hai ki maanlo num int max se bada hai ya itne magnitude kaa hai
toh fir toh fatt jaaegi sum krte krte hai time out error aajega isliye we use a optimal soln 

ex maanlo
num=22 and den =3 
3+3+3+3+3+3+3
iss point pe ek aur jyaada 3 add krunga oth 22 ke cross hojaega uska koi point ni hai
isliye loop end and return count*/
int divideUsngBItManBF(int num , int den){
int sum=0;
int count=0;
while((sum+den)<=num){
    sum+=den;
    count++;
}
return count;
}


int divideUsngBItManOpt(int num , int den){
    //checking for signs
    int sign=1;
    if(num>0&&den>0 || num<0&&den<0)sign=-1;

    //abs is used to take both num and den as positive value
    int nm=abs(num);
    int dn=abs(den);
    int ans=0;

    while(nm>=dn){//keep removing dm from nm until nm is less than dn and carry a count
        //which stores how many dm i took

    int count=0;
    while(nm>=(dn*(pow(2 , count)))){ //we need to repeat his loop as whole not only the inside but this loop as whole thats why we required the bigger loop
        //dn*pow(2 , count) can be written as d<<count that is d * 2 power count
        count++;
    }

    ans+=pow(2,count);//that is how many 3 i removed from n so far
    nm-= dn<<count;

}
    
}

int main() {
    
    return 0;
}