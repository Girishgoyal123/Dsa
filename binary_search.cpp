#include<iostream>
using namespace std;

void max(int arr[],int size){
    int max_term = arr[0];
    for(int i=0; i<size; i++){
        if(arr[i]>max_term){
            max_term = arr[i];
        }
    }
    cout<<"Maximum element is "<<max_term<<endl;
}

void min(int arr[],int size){
    int min_term = arr[0];
    for(int i=0; i<size; i++){
        if(arr[i]<min_term){
            min_term = arr[i];
        }
    }
    cout<<"Minimum element is "<<min_term<<endl;
}

int linear_search(int arr[],int n, int key){
    int index = -1;
    for(int i=0; i<n;i++){
        if(arr[i]==key){
            index = i;
            break;
        }
    }
    return index;
}

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
    cout<<"Enter the number of elements in array:";
    int n,key;
    cin>>n;
    int *arr = new int[n];
    cout<<"Enter a array:";
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int index = 0;
    while(true){
        cout<<"Press 1 for finding maximum element\nPress 2 for finding minimum element\n";
        cout<<"Press 3 for binary search\nPress 4 for linear search\nPress 0 to quit\n";
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
                max(arr,n);
                break;
            case 2:
                min(arr,n);
                break;
            case 3:
                cout<<"Enter a key to check";
                cin>>key;
                index = bineary_search(arr,n,key);
                if(index ==-1)
                    cout<<"Key not found"<<endl;
                else
                    cout<<"Key found at "<<index<<endl;
                break;
            case 4:
                cout<<"Enter a key to check";
                cin>>key;
                index = linear_search(arr,n,key);
                if(index ==-1)
                    cout<<"Key not found"<<endl;
                else
                    cout<<"Key found at "<<index<<endl;
                break;
            case 0:
                break;
                
        }
    }
}