#include<iostream>
using namespace std;

template<typename T>
class intNode{
    public:
        T elem;
        intNode<T>* next;
    
        intNode(){}
        intNode(int x){
            elem = x;
            next = NULL;
        }
    
    //friend class<T> Sll;
};
template<typename T>
class Sll{
    private:
        intNode<T>* head;
        intNode<T>* tail;
    public:
        Sll();
        Sll(const Sll& l1);
        ~Sll();
        bool empty()const;
        void addfront(const T& e);
        void removefront();
        const T& front();
        void addtail(const T& e);
        void removetail();
        int count();
        void insert(int pos,T x);
        void remove(int pos);
       // intNode<T>* search(T x);
        void Display();
        void concat(Sll& l1);
};
template<typename T>
Sll<T>::Sll(){
    head = tail = NULL;
}
template<typename T>
Sll<T>::Sll(const Sll& l1){
    intNode<T>* p = l1.head;
    intNode<T>* p1;
    this->head = NULL;
    while(p!= NULL){
        intNode<T>* newnode = new intNode<T>();
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
template<typename T>
Sll<T>::~Sll(){
    intNode<T>* p = NULL;
    while(head!=NULL){
        p= head;
        head= head->next;
        delete p;
    }
}
template<typename T>
bool Sll<T>::empty()const{
    return head == NULL;
}
template<typename T>
void Sll<T>::addfront(const T& e){
    intNode<T>* p = new intNode<T>(e);
    if(empty()){
        head = p;
        tail=p;
    }
    else{
        p->next = head;
        head = p;
    }
}
template<typename T>
void Sll<T>::removefront(){
    if(empty()) throw "List is empty.";
    intNode<T>* p= head;
    head= p->next;
    delete p;
}
template<typename T>
const T& Sll<T>::front(){
    if(head==NULL) throw "list is Empty.";
    return head->elem;
}
template<typename T>
void Sll<T>::addtail(const T& e){
    intNode<T>* p = new intNode<T>(e);
     if(empty()){
          head = p;
           tail= p;}
   else{
        tail->next = p;
        tail = p;}
    // p->elem = e;
    // intNode<T>* temp= head->next;
    // while(temp->next != NULL) temp = temp->next;
    // temp->next = p;
    // p->next = NULL;
}
template<typename T>
void Sll<T>::removetail(){
    if(empty()) throw "list is Empty.";
    intNode<T>* p = head;
    intNode<T>* temp = NULL;
    while(p->next != NULL){
        temp = p;
        p = p->next;
    }
    temp->next = NULL;
    tail=temp;
    delete p;
}
template<typename T>
int Sll<T>::count(){
    int count=1;
    if(empty()) return 0;
    else{
        intNode<T>* temp =head;
        while(temp->next != NULL) {  
            count++;
            temp = temp->next;}
    }
    return count;
}
template<typename T>
void Sll<T>::insert(int pos, T x){
    intNode<T>* p = new intNode<T>(x);
    intNode<T>* temp =head;
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

        // Removal of a element
// void Sll::remove(int x){
//     intNode<T>* p = head;
//     intNode<T>* temp =NULL;
//     if(empty()) throw "Can't remove, list is already empty.";
//     while(p != NULL && p->elem !=x){
//         temp = p;
//         p = p->next;
//     }
//     if (p==NULL) throw "Invalid value";
//     if(temp==NULL) head = head->next;
//     else{
//         temp->next = p->next;
//         delete p;
//     }
// }
template<typename T>
void Sll<T>::remove(int pos){
    if(head == NULL) throw "List empty.Deletion not possible";
    if(pos==1){
        removefront();
        return;
    }
    int count = 1;
    intNode<T>* temp =head;
    intNode<T>* temp1 =NULL;
    while(temp!= NULL && count< pos ){
        temp1= temp;
        temp = temp->next;
        count++;
    }
    if(temp == NULL) throw "Invalid index";
    temp1->next = temp->next;
    delete temp;
}
// template<typename T>
// intNode<T>* Sll<T>::search(T x){
//     if(head == NULL) throw "List empty.";
//     intNode<T>* p = head;
//     while(p != NULL){
//         if(p->elem == x)
//             return p;
//         p = p->next;
//     }
//     if(p== NULL) throw "Element not in list";
//     return 0;
// }
template<typename T>
void Sll<T>::Display(){
    cout<<"{";
    intNode<T>* p= head;
    while(p !=NULL){
        cout<<p->elem<<" ";
        p= p->next;
    }
    cout<<"}";
}
template<typename T>
void Sll<T>::concat(Sll& l1){
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
        Sll<int>l1;
        cout<<l1.empty()<<endl;
        l1.addfront(5);
        l1.addfront(3);
        l1.addtail(10);
        l1.insert(3,7);
        Sll<int> l2 = l1;
        l1.Display();
        l1.remove(3);
       // cout<<l1.search(3);
        cout<<"\ncount: "<<l1.count()<<endl;;
        cout<<l1.front()<<endl;
        l1.removefront();
        l1.removetail();
        l1.Display();
        l1.concat(l2);
        l1.Display();
    }
    catch(const char* e){
        cout<<"Error found:"<<e;
    }

    

}
