#include<iostream>
using namespace std;

class Dnode{
    private:
        int elem;
        Dnode* next;
        Dnode* prev;
    public:
        Dnode(){next= prev= NULL;        }
        Dnode(int x){
            elem = x;
            next = prev= NULL;
        }
    friend class dll;
};
class dll{
    private:
        Dnode* header;
        Dnode* trailer;
    public:
        dll();
        bool empty();
        void addfront(int x);
        void removefront();
        void addtail(int x);
        void removetail();
        void insert(int x , int pos);
        void remove(int pos);
        Dnode* search(int x);
        void concat(dll& l1);
        void display();
        int front(){
            if(empty()) throw "List is empty";
            return header->next->elem;
        }
};
dll::dll(){
    header = new Dnode;
    trailer = new Dnode;
    header->next = trailer;
    trailer->prev = header;    
}
bool dll::empty(){
    return header->next == trailer;
}
void dll::addfront(int x){
    Dnode* p = new Dnode(x);
    p->next = header->next;
    p->prev = header;
    p->next->prev = p;
    header->next = p;
}
void dll::addtail(int x){
    Dnode* p = new Dnode(x);
    p->next = trailer;
    p->prev = trailer->prev;
    p->prev->next = p;
    trailer->prev = p;
}
void dll::removefront(){
    if(header->next==trailer) throw "Empty list";
    cout<<"Deleted Front\n";
    Dnode* temp = header->next;
    header->next = temp->next;
    temp->next->prev = header;  
    delete temp;  
}
void dll::removetail(){
    if(header->next==trailer) throw "Empty list";
    cout<<"Deleted back\n";
    Dnode* temp = trailer->prev;
    trailer->prev = temp->prev;
    temp->prev->next = trailer; 
    delete temp;    
}
void dll::insert(int x, int pos){
    Dnode* p = new Dnode(x);
    if(header->next==trailer && pos!= 1)
        throw "invalid insertion";
    else if(pos==1)
        addfront(x);
    else{int count = 1;
    Dnode* temp = header->next;
    while(temp!= trailer && count<pos-1){
        temp= temp->next;
        count++;
    }
    
     if(temp== trailer)
        throw "Invalid insertion";
    else {
        p->next=temp->next;
        p->prev= temp;
        temp->next->prev= p;
        temp->next = p;
    }
    }
}
void dll::remove(int pos){
    if(header->next==trailer) throw "Empty list";
    if(pos==1) {
        removefront();
        return;
    }
    int count =1;
    Dnode* temp = header->next;
    while(temp!= trailer && count!= pos){
        temp =temp->next;
        count++;
    }
    if(temp==trailer)
        throw "Invalid deletion";
    else
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
}
Dnode* dll::search(int x){
    if(empty()) throw "Empty list";
    Dnode* temp = header->next;
    while(temp!= trailer &&temp->elem!=x){
        temp = temp->next;
    }
    if(temp==trailer)throw "Invalid element,Element not found";
    return temp;
}
void dll::concat(dll& l2){
    if(empty() && l2.empty())
        return;
    else if(empty())
    {
        header->next = l2.header->next;
        trailer->prev = l2.trailer->prev;
        l2.header->next->prev = header;
        l2.trailer->prev->next = trailer;
        l2.header->next  = l2.trailer;
        l2.trailer->prev = l2.header;
    }
    else if(l2.empty()) return;  
    else {
        trailer->prev->next = l2.header->next;
        l2.header->next->prev = trailer->prev;
        trailer->prev = l2.trailer->prev;
        l2.trailer->prev->next = trailer;
        l2.header->next  = l2.trailer;
        l2.trailer->prev = l2.header;
    }      

}
void dll::display(){
    if (empty()) throw "List is empty";
    Dnode* p = header->next;
    while(p!=trailer){
        cout<<p->elem<<" ";
        p = p->next;
    }
    cout<<endl;
}
int main(){
    try{
    dll l1;
    // l1.addfront(34);
    // l1.addfront(44);
    // l1.addfront(54);
    // l1.addtail(24);
    // l1.display();
    // cout<<endl;
    // l1.remove(2);
    // l1.insert(56,2);
    // // cout<<l1.search(54)<<"\n";
    // l1.removefront();
    // l1.removefront();
    // l1.removetail();
    l1.display();
    cout<<endl;
    dll l2;
    l2.addfront(78);
    l2.addfront(68);
    l2.addfront(58);
    l2.addfront(48);
    l2.display();
    cout<<"\n";
    l1.concat(l2);
    l1.display();
    l2.display();
    }
    catch(const char* str){
        cout<<str;
    }
}