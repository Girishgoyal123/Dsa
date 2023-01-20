#include<iostream>
using namespace std;

int bineary_search(int arr[],int size, int key){
    int initial = 0;
    int final = size-1;
    int index = -1;
    while(initial<=final){
        int mid = (initial+final)/2;
        if(arr[mid]==key){
            index = mid;
            break;
        }
        else if (key<arr[mid]){
          
            final = mid-1;
        }
        else {
            initial= mid+1;
        }
    }
    return index;
}

int main(){
    int n,key,index ;
    cout<<"Enter the number of elements in array: ";
    cin>>n;
    cout<<"Enter the elements of array: ";
    int arr[n];
    for(int i =0; i<n;i++ ){
        cin>>arr[i];
    }
    cout<<"Enter the key to search: ";
    cin>>key;
    index = bineary_search(arr,n,key);
    if(index ==-1)
        cout<<"Key not found"<<endl;
    else
        cout<<"Key found at "<<index<<endl;
}