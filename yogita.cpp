#include<iostream>
using namespace std;
class Cnode{
    private:
    int data;
    Cnode* next;
    Cnode* prev;
    public:
    Cnode(){
        prev=next=NULL;
    }
    Cnode(int x){
        data = x;
        prev = next = NULL;
    }
    friend class CLL;
};
class CLL{
    private:
    Cnode* cursor;
    public:
    CLL(){
        cursor=NULL;
    }
    bool isEmpty();
    void addFront(int x);
    void addTail(int x);
    void deleteFront();
    void deleteTail();
    void display();
};
bool CLL::isEmpty(){
    return cursor==NULL;
}
void CLL::addFront(int x){
    Cnode* temp=new Cnode(x);
    temp->prev=cursor;
    temp->next=cursor->next;
    cursor->next=temp;
    temp->next->prev=temp;
}
void CLL:: addTail(int x){
    Cnode* temp=new Cnode(x);
    temp->prev=cursor->prev;
    temp->next=cursor;
    cursor->prev=temp;
    temp->prev->next=temp;
}
void CLL::deleteFront(){
    Cnode* temp=cursor->next;
    cursor->next=temp->next;
    temp->next->prev=cursor;
    delete temp;
}
void CLL:: deleteTail(){
    Cnode* temp=cursor;
    cursor->prev->next=temp->next;
    temp->next->prev=cursor->prev;
    delete temp;
}
void CLL::display(){
    Cnode* temp=cursor->next;
    while(temp!=cursor){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    try{
        CLL l;
        cout<<l.isEmpty();
        l.addFront(10);
        l.addFront(19);
        cout<<"our linked list is: "<<endl;
        l.display();
    }
    catch(const char* str){
        cout<<str;
    }
}