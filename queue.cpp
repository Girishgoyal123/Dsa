#include<iostream>
using namespace std;
class queue{
    private:
        int NEQ,N,f,r;
        int* Q;
    public:
        queue(int N=100){
            this->N = N;
            Q = new int[N];
            f = r = NEQ = 0;
        }
        void enqueue(const int& e){
            if(full()) throw "Queue is full";
            Q[r] = e;
            r = (r+1)%N;
            NEQ++;
        }
        void Dequeue(){
            if(empty()) throw "Queue is empty";
            f = (f+1)%N;
            NEQ--;
        }
        int size()const{
            return NEQ;
        }
        const int& front(){
            if(empty()) throw "Queue is empty";
            return Q[f];
        }
        bool empty(){
            return NEQ==0;
        }
        bool full(){
            return NEQ ==N;
        }
        void disp(){
            if(empty()) throw "Queue is empty";
            int fr = f;
            for(int i =0; i<NEQ; i++){
                cout<<Q[fr]<<" ";
                fr = (fr+1)%N;
            }
        }
};
int main(){
    try{
        queue Q1;
        Q1.enqueue(7);
        Q1.enqueue(3);
        Q1.disp();
        cout<<endl;
        cout<<Q1.empty();
        cout<<endl;
        cout<<Q1.front();
        cout<<endl;
        cout<<Q1.size()<<endl;
        Q1.Dequeue();
        Q1.Dequeue();
        Q1.disp();
    }
    catch(const char* e ){
        cout<<e;
    }
}