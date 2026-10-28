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

bool subNodesChecker(trees*node1 , trees*node2){
    if(node1==NULL && node2==NULL)return true;
    if(node1==NULL || node2==NULL)return false;

    if(node1->data!=node2->data)return false;

    bool firstWay=subNodesChecker(node1->left , node1->right);
    bool secondWay=subNodesChecker(node1->right , node2->left);

    return (firstWay && secondWay);//using this i wanted to recurse my boolean value back up to top
}

bool symmetricOrNot(trees*node){
    return subNodesChecker(node->left , node->right );
}


int main() {
    
    return 0;
}