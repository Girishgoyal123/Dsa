#include<iostream>
#include "stack.cpp"
using namespace std;

bool isoperator(char ch){
    return (ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^');
        
}
int evaluate(string str){
    stack<char>s1;
    int len = str.length();
    for(int i = 0; i<len; i++){
        if(isoperator(str[i])){
            s1.push(str[i]);
        }
    }

}