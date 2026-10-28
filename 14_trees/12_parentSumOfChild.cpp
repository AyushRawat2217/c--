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

bool checkTree(trees* root) {
    if(root==NULL)return true;
    if(root->left==NULL && root->right==NULL)return true;
    
    
    int rtLeft=(root->left==NULL)?0:root->left->data;
    int rtright=(root->right==NULL)?0:root->right->data;
    if(root->data!= rtLeft +rtright)return false;

    bool left=checkTree(root->left);
    bool right=checkTree(root->right);

    return (left&&right);

}

int main() {
    
    return 0;
}