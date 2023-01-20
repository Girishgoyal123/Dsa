#include<iostream>
using namespace std;

class intNode{
    private:
        int elem;
        intNode *next;
    public:
        intNode(){}
        intNode(int x){
            elem = x;
            next = NULL;
        }
    
    friend class Sll;
};
class Sll{
    private:
        intNode* head;
        intNode* tail;
    public:
        Sll();
        Sll(const Sll& l1);
        ~Sll();
        bool empty()const;
        void addfront(const int& e);
        void removefront();
        const int& front();
        void addtail(const int& e);
        void removetail();
        int count();
        void insert(int pos,int x);
        void remove(int pos);
        intNode* search(int x);
        void Display();
        void concat(Sll& l1);
};
Sll::Sll(){
    head = tail = NULL;
}
Sll::Sll(const Sll& l1){
    intNode* p = l1.head;
    intNode* p1;
    this->head = NULL;
    while(p!= NULL){
        intNode* newnode = new intNode();
        newnode->elem = p->elem;
        newnode->next = NULL;
        if(head==NULL){
            head = newnode;
            p1= head;
            tail = head;
        }
        else{
            p1->next = newnode;
            p1= p1->next;
            tail = p1;
        }
        p= p->next;
    }
}
Sll::~Sll(){
    intNode* p = NULL;
    while(head!=NULL){
        p= head;
        head= head->next;
        delete p;
    }
}
bool Sll::empty()const{
    return head == NULL;
}
void Sll::addfront(const int& e){
    intNode* p = new intNode(e);
    if(empty()){
        head = p;
        tail=p;
    }
    else{
        p->next = head;
        head = p;
    }
}
void Sll::removefront(){
    if(empty()) throw "List is empty.";
    intNode* p= head;
    head= p->next;
    delete p;
}
const int& Sll::front(){
    if(head==NULL) throw "list is Empty.";
    return head->elem;
}
void Sll::addtail(const int& e){
    intNode* p = new intNode(e);
     if(empty()){
          head = p;
           tail= p;}
   else{
        tail->next = p;
        tail = p;}
}
void Sll::removetail(){
    if(empty()) throw "list is Empty.";
    intNode* p = head;
    intNode* temp = NULL;
    while(p->next != NULL){
        temp = p;
        p = p->next;
    }
    temp->next = NULL;
    tail=temp;
    delete p;
}
int Sll::count(){
    int count=1;
    if(empty()) return 0;
    else{
        intNode* temp =head;
        while(temp->next != NULL) {  
            count++;
            temp = temp->next;}
    }
    return count;
}
void Sll::insert(int pos, int x){
    intNode* p = new intNode(x);
    intNode* temp =head;
    if(empty())
        head=tail=p;
    else if(pos==1) {
        p->next = head;
        head = p;
    }
    int count = 1;
    while(temp != NULL && count<pos-1){
       temp = temp->next;
        count++;
    }
    if(temp == NULL) throw "Invalid position";
    if(temp==tail){
        temp->next=p;
        tail=p;
            }
    p->next = temp->next;
    temp->next = p; 
}

void Sll::remove(int pos){
    if(head == NULL) throw "List empty.Deletion not possible";
    if(pos==1){
        removefront();
        return;
    }
    int count = 1;
    intNode* temp =head;
    intNode* temp1 =NULL;
    while(temp!= NULL && count< pos ){
        temp1= temp;
        temp = temp->next;
        count++;
    }
    if(temp == NULL) throw "Invalid index";
    temp1->next = temp->next;
    delete temp;
}
intNode* Sll::search(int x){
    if(head == NULL) throw "List empty.";
    intNode* p = head;
    while(p != NULL){
        if(p->elem == x)
            return p;
        p = p->next;
    }
    if(p== NULL) throw "Element not in list";
    return 0;
}
void Sll::Display(){
    cout<<"{";
    intNode* p= head;
    while(p !=NULL){
        cout<<p->elem<<" ";
        p= p->next;
    }
    cout<<"}";
}
void Sll::concat(Sll& l1){
    if(empty() && l1.empty()) throw "Both lists are empty";
    else if(empty()) head = l1.head;
    else if(l1.empty()){l1.head = NULL;}
    else{
        tail->next = l1.head;
        tail = l1.tail;
        l1.head = l1.tail=NULL;}
}
int main(){
    try{
        Sll l1;
        cout<<l1.empty()<<endl;
        l1.addfront(5);
        l1.addfront(3);
        l1.addtail(10);
        l1.insert(3,7);
        Sll l2 = l1;
        l1.Display();
        l1.remove(3);
        cout<<endl<<l1.search(3);
        cout<<"\ncount: "<<l1.count()<<endl;;
        cout<<l1.front()<<endl;
        l1.removefront();
        l1.removetail();
        l1.Display();
        l1.concat(l2);
        cout<<endl;
        l1.Display();
    }
    catch(const char* e){
        cout<<"Error found:"<<e;
    }
}
