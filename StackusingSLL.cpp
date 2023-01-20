#include<iostream>
#include "SinglyLinkedLIstForUse.cpp"
using namespace std;

class Stack{
    private:
        int n;
        Sll s1;
    public:
        Stack(){
            n=0;
        }
        void push(const int& x);
        int top();
        void pop();
        void display();
        int size()const{
            return n;
        }
        bool empty();       
};
bool Stack::empty(){
    return n==0;
}
void Stack::push(const int& x){
    s1.addtail(x);
    n++;
}
int Stack::top(){
    if(empty()) throw "Empty Stack";
    return s1.front();
}
void Stack::pop(){
    if(empty()) throw "Empty Stack";
    s1.removefront();
}
void Stack::display(){
    s1.Display();
}
int main(){
    Stack s;
    s.push(50);
    s.push(40);
    s.push(30);
    s.push(20);
    s.push(10);
    s.display();
    
}