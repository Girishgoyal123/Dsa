#include<iostream>
using namespace std;

class Array1D {
    int size;
    int *arr;
    public:
        Array1D(int s=0){
            if(s<=0) throw "Invalid Size";
            this->size = s;
            arr = new int [size];
        }
        int &operator[](int index)const;
        int getsize() const;
        void resize(int s);
        friend ostream & operator << (ostream &out, const Array1D &obj);
        friend istream & operator >> (istream &in,  Array1D &obj);
};
int &Array1D :: operator[](int index)const{
    if(index<0 || index >=size){
        throw "Array out of bound exception";
    }
        
    else
        return arr[index];   
}
int Array1D:: getsize() const{
    return size;
}
void Array1D :: resize(int s){
    if(size <= s)   
        return ;
    size = s;
    delete []arr;
    arr = new int [size];
    return ;
}
istream& operator>>(istream &in , Array1D &obj){
    for(int i = 0 ; i<obj.getsize();i++)
        cin>>obj[i];
    return in;
}
ostream& operator<<(ostream &out,const Array1D &obj ){
    out<<"{";
    for(int i = 0 ; i< obj.getsize(); i++){
        out<<" "<<obj[i];
        if(i<(obj.getsize()-1))
            out<<" ";
    }
    out<<"}";
    return out;
}
int main(){
    Array1D arr(5);
    cout<<"Enter elements of array ";
    try{
        for(int i = 0; i< 5; i++) cin>>arr[i];
        cout<<arr[5];
    }
    catch(const char* exp){
        cout<<"Error Found : " << exp;
    }
    
}