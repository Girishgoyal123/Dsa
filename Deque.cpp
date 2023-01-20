#include<iostream>
#include "dllForUse.cpp"
using namespace std;

class dequeue{
    private:
        dll l1;
        int n;
    public:
        dequeue(){
            n=0;
        }
        void addfront(int x){
            l1.addfront(x);
            n++;
        }
        void deletefront(){
            if(l1.empty()) throw "Queue is empty";
            l1.removefront();
            n--;
        }
        void addback(int x){
            l1.addtail(x);
            n++;
        }
        void deleteback(){
            if(empty()) throw "Queue is empty";
            l1.removetail();
            n--;
        }
        int size(){
            return n;
        }
        bool empty(){
            return l1.empty();
        }
        int front(){
            if (empty()) throw "Queue is empty";
            return l1.front();
        }
        void display(){
            if(empty()) throw "No elements in list";
            l1.display();
        }
};
int main(){
    try{
        dequeue q1;
        cout<<"is empty? "<<q1.empty()<<endl;
        q1.addback(56);
        q1.addback(66);
        q1.addfront(46);
        q1.addfront(36);
        q1.addfront(26);
        q1.display();
        q1.addfront(16);
        q1.display();
        q1.deleteback();
        cout<<"The current size is: "<<q1.size()<<endl;
        cout<<"The front is: "<<q1.front()<<endl;
        q1.deletefront();
        q1.deletefront();
        q1.display();
    }
    catch(const char* str){
        cout<<str;
    }

}