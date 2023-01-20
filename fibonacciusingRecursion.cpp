#include<iostream>
using namespace std;

int fib(int n){
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    else{
        return fib(n-1)+fib(n-2);
    }
}
int cal(int x,int n ){
    if(n==0){
        return 1;
    }
    return x*cal(x,n-1);
}
int main(){
    cout<< cal(2,5)<<endl;
    int n =10;
    for (int i= 0; i<n; i++){
        cout<<fib(i)<<" ";
}
    }
    