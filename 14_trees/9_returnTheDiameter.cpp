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

/*logic is
at every node we check the left and right height and maintain the
difference of it , and return the max one always
*/

int heightOfsubTree(trees*node){

    if(node==NULL)return 0;

    int leftHeight=heightOfsubTree(node->left);
    int rightHeight=heightOfsubTree(node->right);

    return 1 + max(leftHeight , rightHeight);

}


int returnTheDiameter(trees*node ){
    if(node==NULL)return 0;//base condn

    int height=heightOfsubTree(node->left)+heightOfsubTree(node->right);//gave me height

    int left = returnTheDiameter(node->left);
    int right=returnTheDiameter(node->right);

    return max(height , max(left , right));//left n right apni height bubble up krte rhenge , and ultimaly max of 3 upr jaaega parent pe 
    //jo firse compare hoga return function mai
}


int main() {
    
    return 0;
}