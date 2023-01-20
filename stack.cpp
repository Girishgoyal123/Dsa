#include<iostream>
using namespace std;

template<typename t>
class stack{
    private:
        t* a;
        int tp,size;
    public:
        stack(int size= 100);
        void push(const t& x);
        void pop();
        const t& top()const;
        bool empty()const;
        bool full()const;
        int sizof()const;
        void display();
};
template<typename t>
stack<t>::stack(int size){
    size = size;
    tp = -1;
    a = new int[size];
}
template<typename t>
void stack<t>::push(const t& x){
    if(full()) throw "Stack Full.\ncan't push.";
    a[++tp] = x;
}
template<typename t>
void stack<t>::pop(){
    if(empty()) throw "Empty Stack.";
    tp--;
}
template<typename t>
bool stack<t>:: empty()const{
    return tp == -1;
}
template<typename t>
bool stack<t>::full()const{
    return tp == size-1;
}
template<typename t>
const t& stack<t>::top()const{
    if(empty()) throw "Stack empty ";
    return a[tp];
}
template<typename t>
int stack<t>::sizof()const{
    return tp+1;
}
template<typename t>
void stack<t>::display(){
    int n = sizof() - 1;
    for(int i=n;i>=0;i--){
        cout<<a[i]<<" ";
    }
}
int main(){
    stack<int>s1;
    s1.push(5);
    s1.push(10);
    s1.push(15);
    s1.push(20);
    s1.push(25);
    s1.push(30);
    s1.display();
    s1.pop();
    cout<<endl;
    s1.display();
    cout<<"\nThe top element is: "<<s1.top();
    cout<<"\nIs empty? -> "<<s1.empty();
    cout<<"\nIs full? -> "<<s1.full();
    cout<<"\nCurrent Size of stack is: "<<s1.sizof();
    cout<<endl;

}