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

void isLeftBoundary(trees*root , vector<int>&leftb){
    if((root->right==NULL && root->left==NULL) || isleaf(root))return;
    leftb.push_back(root->data);
    if(root->left)isLeftBoundary(root->left , leftb);
    else isLeftBoundary(root->right , leftb);
}

void isRightBoundary(trees*root , vector<int>&rightb){
    if((root->right==NULL && root->left==NULL) || isleaf(root))return;
    if(root->right)isRightBoundary(root->right , rightb);
    else isRightBoundary(root->left , rightb);
    rightb.push_back(root->data);
}

bool isleaf(trees*node ){
    return (node->right==NULL && node->left==NULL);
}

void addLeafNodes(trees*node , vector<int>&leaf){
    if(node==NULL)return;
    if(isleaf(node))leaf.push_back(node->data);

    addLeafNodes(node->left , leaf);
    addLeafNodes(node->right , leaf);

}

//sundar pyari nanhi divu

void boundaryElement(trees*root){
    
}

int main() {
    
    return 0;
}