#include <bits/stdc++.h>
using namespace std;

struct trees{
        int data;
        trees*leftchild;
        trees*rightchild;

        trees(int val , trees*leftptr=NULL , trees*rightptr=NULL){
            data = val;
            leftchild=leftptr;
            rightchild=rightptr;
        }

};

//preorder= root left right
void preorder(trees*rootNode){
    if(rootNode==NULL)return;
    cout<<rootNode->data;//root pehle hi iternation mai aagya
    //now keep going towards the left
    preorder(rootNode->leftchild);
    preorder(rootNode->rightchild);

}

void inorder(trees*rootNode){
    if(!rootNode)return;
    inorder(rootNode->leftchild);//first go to extreme left then jbh null aajegaa
    //print the left most child , fir wo upr jaaega previous recusrive call pe toh root print bhi hoajega , and fir ham right child mai ghus
    //jaaege and waha pe inorder lgaa denge
    cout<<rootNode->data;
    inorder(rootNode->rightchild);

}


void postorder(trees*rootNode){//left right root
    if(!rootNode)return;
    postorder(rootNode->leftchild);//go to extreme left
    postorder(rootNode->rightchild);//jese hi extreme left mai , null hoga vese hi right child visit krle jis node
    //prr return hua hai pointer
    cout<<rootNode->data;
    //extreme node ke left and righjt child dodno null hai , toh wo return hokr print hoajegi
    //right after rightchild ka null aaya scene
    //fir wo aur upr jaaega and we got our leftchild fir aise hi dubara right child pint hokr rootnode print hpgi

    //just dry run lil bro
}




/* which ds to use?? why?
//i will use queue as at the front will be first elemnent
//i will insert the childs into the queue then i will remove the first element from front
//keep on adding child then removing the rear

//this is only provided by queue*/

void levelOrder(trees*rootNode){//it traverses the tree , level by level
    if(!rootNode)return;

    queue<trees*>q;
    q.push(rootNode);
   
    while(!q.empty()){
        trees*mover=q.front();
        cout<<mover->data<<endl;

        if(mover->leftchild)q.push(mover->leftchild);
        if(mover->rightchild)q.push(mover->rightchild);
        
        q.pop();
    }
    /*pehle ye rootnode front mai daala
    fir usko print krke uske bacche daale
    fir pop krdia front se
    abh leftchild hai print krke fir uske bachhe daalnege
    pop krenge , same for right child , we will keep doing it until q is empty my son */

}

int main() {
    trees*root= new trees(1);
    trees*leftchd=new trees(2);
    trees*rightchd=new trees(3);

    root->leftchild=leftchd;
    root->rightchild=rightchd;


    
    return 0;
}