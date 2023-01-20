#include<iostream>
using namespace std;

int ls(int arr[],int n, int key){
    int index = -1;
    for(int i=0; i<n;i++){
        if(arr[i]==key){
            index = i;
            break;
        }
    }
    return index;
}
int main(){
    cout<<"Enter the number of elements of array:";
    int n , key;
    cin>>n;
    int *arr = new int[n];
    cout<<"Enter the elements of array:";
    for (int i =0; i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the key you want to search in array:";
    cin>>key;
    int index = ls(arr,n,key);
    if(index == -1)
        cout<<"The key is not in the array.";
    else
        cout<<"Key found at "<<index;
    return 0;
}