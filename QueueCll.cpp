#include<iostream>
#include "cllForUse.cpp"
using namespace std;

class queue{
    private:
        cll l1;
        int n;
    public:
        queue(){
            n=0;
        }
        void enq(int x){
            l1.addlast(x);
            n++;
        }
        void deq(){
            l1.removefront();
            n--;
        }
        bool empty(){
            return l1.empty();
        }
        int size(){
            return n;
        }
        int front(){
            if(l1.empty()) throw "Queue is empty";
            return l1.front();
        }
        void display(){
            if(l1.empty()) throw "Queue is empty";
            l1.display();
        }
};
int main(){
    queue q1;
    cout<<"is empty? "<<q1.empty()<<endl;
    q1.enq(45);
    q1.enq(55);
    q1.enq(65);
    q1.enq(75);
    q1.display();
    q1.deq();
    cout<<"The front is: "<<q1.front()<<endl;
    cout<<"The current size is: "<<q1.size()<<endl;
}