#include <bits/stdc++.h>
using namespace std;

/*a trees data type store
a int data , and left and right ptr 


trees
[left , data , right]

left points towards an another tree 

*/

class trees{
    public:
        int data;
        trees*left;//i would want left ptr to point towards a tree only
        trees*right;



    trees(int val , trees*leftPtr=NULL , trees*rightPtr=NULL){
        data=val;
        left=leftPtr;
        right=rightPtr;
    }

};

int main() {
    trees tre(5);
    tre.left=new trees(1);
    
    return 0;
}