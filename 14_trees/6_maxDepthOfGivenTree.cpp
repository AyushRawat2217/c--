#include <bits/stdc++.h>
using namespace std;


struct trees{
        int data;
        trees*left;
        trees*right;

        trees(int val , trees*leftptr=NULL , trees*rightptr=NULL){
            data = val;
            left=leftptr;
            right=rightptr;
        }

};

int maxDepth(trees*node ){//initial height to be zero
    if(node==NULL)return 0;

    int leftmax=maxDepth(node->left) ;
    int rightmax=maxDepth(node->right);
    //at the end of both these statements i will be having a height value

    return 1+ max(leftmax ,rightmax);

}

int main() {
    
    return 0;
}