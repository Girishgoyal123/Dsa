#include<iostream>
using namespace std;

// template<class t>
// void(t a,t b){
//     t temp = a;
//     a =b;
//     b= temp;
// }
template<class T>
void bubbles(){
    int n;
    cout<<"Enter the number of elements of array:";
    cin>>n;
    T arr[n];
    cout<<"Enter the elements in array:";
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                // swap<T>(arr[j],arr[j+1]);
                T temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    cout<<"The sorted array is:";
    for(int i = 0; i<n; i++)
        cout<<arr[i]<<" ";
}

template<class T>
void inst(){
    int n;
    cout<<"Enter the number of elements of array:";
    cin>>n;
    T arr[n];
    cout<<"Enter the elements in array:";
    for(int i = 0; i<n; i++)
        cin>>arr[i];

    for(int i = 1; i<n; i++){
        T temp = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    cout<<"The sorted array is:";
    for(int i = 0; i<n; i++)
        cout<<arr[i]<<" ";
}
template<class T>
void selt()
{
    int n;
    cout<<"Enter the number of elements of array:";
    cin>>n;
    T arr[n];
    cout<<"Enter the elements in array:";
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    for(int i = 0; i<n; i++){
        int min = i;
        T temp = arr[i];
        int j=i;
        for(j ; j<n; j++){
            if(arr[j]<temp){
                temp = arr[j];
                min = j;
            }
        }
        arr[min]= arr[i];
        arr[i]=temp;       
    }
    cout<<"The sorted array is:";
    for(int i = 0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main(){
    int choice,type;
    cout<<"Press 1 -> for integer\nPress 2-> for char\nPress 3-> for float\n";
    cin>>choice;
    cout<<"Press 1-> for Bubble sort\nPress 2-> Insertion sort\nPress 3-> Selection sort\n";
    cin>>type;
    switch(choice)
    {
        case 1:
            switch(type){
                case 1:
                    bubbles<int>();
                    break;
                case 2:
                    inst<int>();
                    break;
                case 3:
                    selt<int>();
                    break;
                default:
                    cout<<"Invalid Choice";
                    break;
            }break;
        case 2:
            switch(type)
            {
                case 1:
                    bubbles<char>();
                    break;
                case 2:
                    inst<char>();
                    break;
                case 3:
                    selt<char>();
                    break;
                default:
                    cout<<"Invalid Choice";
                    break;  
            }break;
        case 3:
            switch(type)
            {
                case 1:
                    bubbles<float>();
                    break;
                case 2:
                    inst<float>();
                    break;
                case 3:
                    selt<float>();
                    break;
                default:
                    cout<<"Invalid Choice";
                    break;
            }break;
        default:
            cout<<"Invalid input";
            break;
    }
}