#include<iostream>
using namespace std;

void swap(int a , int b){
    int temp = b;
    b = a;
    a = temp;
}

void bubble_sort(int arr[],int size){
    bool sorted = false;
    for(int i=0; !sorted && i<size-1; i++){
        sorted = true;
        for(int j = 0; j <= size-i-1; j++ ){
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                sorted = false;
            }
        }
    }
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

void insertion_sort(int a[], int size){
    for(int i= 1; i<size; i++){
        int temp= a[i];
        int j= i-1;
        while(j>=0 && a[j]>temp){
            a[j+1]= a[j];
            j--;
        }
        a[j+1]=temp;
    }
    for(int i=0; i<size; i++){
        cout<<a[i]<<" ";
    }
}
int main(){
    cout<<"Enter the size of array.\n";
    int size ,*arr;
    cin>>size;
    cout<<"Enter the  elements of array.\n";
    arr = new int[size];
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    insertion_sort(arr,size);
}