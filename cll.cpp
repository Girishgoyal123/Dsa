#include<iostream>
using namespace std;

class node{
    private:
        int data;
        node* next;
        node* prev;
    public:
        node(){
            next =prev = NULL;
        }
        node(int x){
            next= prev = NULL;
            data = x;
        }
    friend class cll;
};
class cll{
    private:   
        node* cursor;
    public:
        cll(){
            cursor =NULL;
        }
        bool empty();
        void addfront(int x);
        void addlast(int x);
        void removefront();
        void removelast();
        void insert(int x, int afterY);
        void remove(int x);
        node* search(int x);
        void concat(cll& l2);
        void display();
};
bool cll::empty(){
    return cursor == NULL;
}
void cll::addfront(int x){
    node* p = new node(x);
    if(cursor==NULL){
        cursor = p;
        cursor->next = p;
        cursor->prev = p;
    }
    else{
        p->next = cursor->next;
        p->next->prev = p;
        cursor->next = p;
        p->prev = cursor;
    }
}
void cll::addlast(int x){
    node *p = new node(x);
    if(empty()){
        cursor = p;
        cursor->next = p;
        cursor->prev = p;
    }
    else{
        p->next = cursor->next;
        p->next->prev = p;
        cursor->next = p;
        p->prev = cursor;
        cursor = p;
    }
}
void cll::removefront(){
    if(empty()) throw "Deletion not possible";
    if(cursor->next == cursor){
        delete cursor;
        node* cursor = NULL;
    }
    node* temp = cursor->next;
    cursor->next = temp->next;
    temp->next->prev = cursor;
    delete temp;
}
void cll::removelast(){
    if(empty()) throw "Deletion not possible";
    if(cursor->next == cursor){
        delete cursor;
        node* cursor = NULL;
    }
    node* temp = cursor;
    cursor->next->prev = cursor->prev;
    cursor->prev->next = cursor->next;
    cursor = cursor->prev;
    delete temp;
}
void cll::insert(int x, int y){
    if(empty()){
        cout<< " Can't insert,"<<y<<" is not present in list";
        return;
    } 
    node* temp = cursor->next;
    while(temp!= cursor && temp->data!= y){
        temp = temp->next;
    }
    if(temp== cursor && temp->data != y){
        cout<< " Can't insert,"<<y<<" is not present in list";
    }
    else{
        node* p = new node(x);
        p->next= temp->next;
        p->next->prev = p;
        temp->next= p;
        p->prev = temp;
    }
}
void cll::remove(int x){
    if (empty()) throw " Deletion not possible, empty list";
    node* temp = cursor->next;
    while(temp!= cursor && temp->data != x){
        temp = temp->next;
    }
    if(temp==cursor){
        if(temp->data !=x) throw "Element not found";
        cursor->next->prev = cursor->prev;
        cursor->prev->next = cursor->next;
        cursor = cursor->prev;
        delete temp;
    }
    else{
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
    }
}
node* cll::search(int x){
    if(empty()) throw "Empty list";
    node* temp = cursor->next;
    while(temp!= cursor && temp->data != x){
        temp = temp->next;
    }
    if(temp== cursor && temp->data != x){
        cout<<x<<" is not present in list";
        return NULL;
    }
    else return temp;
}
void cll::concat(cll& l2){
    if(!empty() && !l2.empty()){
        node* temp = cursor->next;
        cursor->next = l2.cursor->next;
        cursor->next->prev = cursor;
        temp->prev = l2.cursor;
        l2.cursor->next = temp;
        l2.cursor =NULL;
    }
    if(l2.empty()) return;
    if(empty()){
        cursor= l2.cursor;
        l2.cursor;
    }
}
void cll::display(){
    if(empty()) return;
    node* temp = cursor->next;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp!= cursor->next);
    cout<<endl;
}
int main(){
    cll l1;
    l1.addfront(23);
    l1.addfront(13);
    l1.addfront(14);
    l1.addfront(17);
    l1.display();
    cout<<l1.search(13)<<endl;
    l1.addlast(67);
    l1.insert(45,13);
    l1.display();
    l1.removefront();
    l1.removelast();
    l1.remove(23);
    l1.display();
    cll l2;
    l2.addfront(55);
    l2.addfront(45);
    l2.addfront(35);
    l1.concat(l2);
    l1.display();
}