#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class BSTnode{
    public:
        int data;
        BSTnode* left;
        BSTnode* right;
        BSTnode(){
            left = right = NULL;
        }
        BSTnode(int x){
            left = right = NULL;
            data = x;
        }
};

class BST{
    public:
        BSTnode* root;
        BST(){
            root = NULL;
        }
        ~BST(){
            clear(root);
        }
        bool empty(){
            return root== NULL;
        }
        void insert(int x);
        void deleteByCopying(int x);
        void deleteByMerging(int x);
        void height()
        {
           cout<<"The height of tree is: "<< height(root);
        }
        void clear(){
            clear(root);
        }
        void search(int x){
            search(root,x);
        }
        void replace(int x,int y){
            replce(root, x, y);
        }
        int findMax(){
            BSTnode* p = root;
            while(p->right!= NULL)
                p= p->right;
            return p->data;
        }
        int findMin(){
            BSTnode* p = root;
            while(p->left!= NULL)
                p= p->left;
            return p->data;
        }
        void preorder(){
            preorder(root);
        }
        void inorder(){
            inorder(root);
        }
        void postorder(){
            postorder(root);
        }
        void breadthFirstSearch();
        bool isBST(BST t1);
        protected:
            int height(BSTnode* root);
            void clear(BSTnode* ele);
            void replce(BSTnode* ele,int x,int y);
            BSTnode* search(BSTnode* ele, int x);
            void preorder(BSTnode* ele);
            void inorder(BSTnode* ele);
            void postorder(BSTnode* ele);
      
};

void BST::clear(BSTnode* ele){
    if(ele!=NULL){
        clear(ele->left);
        clear(ele->right);
        if(ele->left!= NULL)
            ele->left = NULL;
        if(ele->right!= NULL)
            ele->right = NULL;
        ele = NULL;
    }
}
int BST::height(BSTnode* node){
    if(node==NULL)
        return -1;
    return max(1+height(node->left),1+height(node->right));
}
BSTnode* BST::search(BSTnode* node, int x){
    if(node==NULL) throw "Empty tree";
    if(node->data==x)
        return node;
    else if(node->data>x)
        return search(node->left,x);
    else if(node->data<x)
        return search(node->right, x);
    else return NULL;
}
void BST::replce(BSTnode* node, int x,int y){
    if(root==NULL){
        BSTnode* temp = new BSTnode(y);
        root = temp;
    }
    else if(node->data==x){
        deleteByMerging(x);
        insert(y);
    }
    else if(node->data>x)
        return replce(node->left,x,y);
    else if(node->data<x)
        return replce(node->right,x,y);
    else cout<<"Elements not found";


}
void BST::preorder(BSTnode* ele){
    if(ele==NULL)
        return;
    cout<<ele->data<<" ";
    preorder(ele->left);
    preorder(ele->right);
}
void BST::inorder(BSTnode* ele){
    if(ele==NULL)
        return;
    inorder(ele->left);
    cout<<ele->data<<" ";
    inorder(ele->right);
}
void postorder(BSTnode* ele){
    if(ele==NULL)
        return;
    postorder(ele->left);
    postorder(ele->right);
    cout<<ele->data<<" ";
}
void BST::breadthFirstSearch(){
    queue<BSTnode*> queue1;
    BSTnode* p =root;
    if(p!=NULL){
        queue1.push(p);
        while(!queue1.empty()){
            p = queue1.front();
            queue1.pop();
            cout<<p->data<<" ";
            if(p->left!=NULL)
                queue1.push(p->left);
            if(p->right!=NULL)
                queue1.push(p->right);
        }
    }
}
void BST::insert(int x){
    BSTnode *p = root, *prev = NULL;
    while(p!=NULL){
        prev = p;
        if(p->data>x)
            p=p->left;
        else p = p->right;
    }
    BSTnode* n = new BSTnode(x);
    if(root==NULL)
        root = n;
    else if (prev->data<x)
        prev->right = n;
    else prev->left = n;   
}
void BST::deleteByCopying(int x){
    if(root==NULL) throw "Deletion not possible.";
    BSTnode* p = root, *prev = NULL;
    while(p!=NULL && p->data != x){
        prev = p;
        (p->data<x)? p = p->right: p = p->left;
    }
    if(p==NULL) throw "Element not in tree.";
    if(p->left == NULL ){
        (p->data<prev->data)?prev->left = p->right:prev->right = p->right;
        delete p;
    }
    else if(p->right == NULL ){
        (p->data<prev->data)?prev->left = p->left:prev->right = p->left;
        delete p;
    }
    else{
        BSTnode* temp = p->right;
        BSTnode* Ftemp = p;

        while(temp->left!= NULL){
            Ftemp = temp;
            temp = temp->left;
        }
        p->data = temp->data;
        if(Ftemp == p)
            Ftemp->right= temp->right;
        else Ftemp->left = temp->right;
        delete temp;
    }
}
void BST::deleteByMerging(int x){
    if(root==NULL) throw "Deletion not possible.";
    BSTnode* p = root, *prev = NULL;
    while(p!=NULL && p->data != x){
        prev = p;
        (p->data<x)? p = p->right: p = p->left;
    }
    if(p==NULL) throw "Element not in tree.";
    if(p->left == NULL ){
        (p->data<prev->data)?prev->left = p->right:prev->right = p->right;
        delete p;
    }
    else if(p->right == NULL ){
        (p->data<prev->data)?prev->left = p->left:prev->right = p->left;
        delete p;
    }
    else{
        BSTnode* temp = p->right;
        BSTnode* Ftemp = p;

        while(temp->left!= NULL){
            Ftemp = temp;
            temp = temp->left;
        }
        temp->left = p->left;
        (p->data<prev->data)?prev->left= p->right:prev->right= p->right;
        delete p;
    }
}
int main(){
    try{
    BST t;
    t.insert(50);
    t.insert(40);
    t.insert(30);
    t.insert(20);
    t.insert(60);
    t.insert(70);
    t.insert(80);
    t.inorder();
    cout<<endl;
    t.height();
    cout<<endl;
    t.breadthFirstSearch();
    cout<<endl;
    t.deleteByCopying(50);
    t.breadthFirstSearch();
    cout<<endl;
    t.deleteByMerging(30);
    t.breadthFirstSearch();
    cout<<endl;
    t.replace(40,100);
    t.inorder();
    cout<<endl;
    }
    catch(const char* e){
        cout<<"e";
    }
}