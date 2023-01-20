#include<iostream>
using namespace std;

class Dia_Mat{
    private:
        int nRow,nColumn;
        int* array;
    public:
        Dia_Mat(int r=0, int c=0);
        Dia_Mat(const Dia_Mat& m);
        ~Dia_Mat();
        void Dimensions() const;
        void Store(const int &x ,int i, int j);
        int Retrieve(int i,int j) const;
};

class Tri_Dia_Mat{
    private:
        int nRow,nColumn;
        int* array;
    public:
        Tri_Dia_Mat(int r=0, int c=0);
        Tri_Dia_Mat(const Tri_Dia_Mat& m);
        ~Tri_Dia_Mat();
        void Dimensions() const;
        void Store(const int &x ,int i, int j);
        int Retrieve(int i,int j) const;
};

class low_Tri_Mat{
    private:
        int nRow,nColumn;
        int* array;
    public:
        low_Tri_Mat(int r=0, int c=0);
        low_Tri_Mat(const low_Tri_Mat& m);
        ~low_Tri_Mat();
        void Dimensions() const;
        void Store(const int &x ,int i, int j);
        int Retrieve(int i,int j) const;
};

class upp_Tri_Mat{
    private:
        int nRow,nColumn;
        int* array;
    public:
        upp_Tri_Mat(int r=0, int c=0);
        upp_Tri_Mat(const upp_Tri_Mat& m);
        ~upp_Tri_Mat();
        void Dimensions() const;
        void Store(const int &x ,int i, int j);
        int Retrieve(int i,int j) const;
};

class SymmetricMatrix{
    private:
        int nRow,nColumn;
        int* array;
    public:
        SymmetricMatrix(int r=0, int c=0);
        SymmetricMatrix(const SymmetricMatrix& m);
        ~SymmetricMatrix();
        void Dimensions() const;
        void Store(const int &x ,int i, int j);
        int Retrieve(int i,int j) const;
};
Dia_Mat::Dia_Mat(int r,int c){
    if(r<=0 ||c <= 0)
        throw "Bad Initializers";
    if(r!=c)
        throw "Diagonal matrix must be a square matrix";
    this->nRow = r;
    this->nColumn = c;
    array = new int[r];
    for(int i = 0; i<r;i++){
        array[i] =0;
    }
}
Dia_Mat::~Dia_Mat(){
    delete[] array;
}
void Dia_Mat::Dimensions()const{
    cout<<"Dimension of matrix is"<<nRow<<" x "<<nColumn;
}
void Dia_Mat::Store(const int &x, int i,int j){
    if(i<1 || i>nRow ||j<1 ||j>nColumn)
        throw "Index out of bound";
    if(i!=j && x!= 0)
        cout<< "Can't store element\nMust be zero";
    if(i==j)
        array[i-1]=x;
}
int Dia_Mat:: Retrieve(int i,int j)const{
    if(i<1 || j<1 || i>nRow ||j>nColumn)
        throw "Index out of bound";
    if(i==j)
        return array[i-1];
    else
        return 0;
}

Tri_Dia_Mat::Tri_Dia_Mat(int r,int c){
    if(r<=0 ||c <= 0)
        throw "Bad Initializers";
    if(r!=c)
        throw "TriDiagonal matrix must be a square matrix";
    this->nRow = r;
    this->nColumn = c;
    array = new int[(3*nRow)-2];
    for(int i = 0; i<3*nRow-2;i++){
        array[i] =0;
    }
}
Tri_Dia_Mat::~Tri_Dia_Mat(){
    delete[] array;
}
void Tri_Dia_Mat::Dimensions()const{
    cout<<"Dimension of matrix is"<<nRow<<" x "<<nColumn;
}
void Tri_Dia_Mat::Store(const int &x, int i,int j){
    if(i<1 || i>nRow ||j<1 ||j>nColumn)
        throw "Index out of bound";
    if((i!=j || i-j != 1 || i-j != -1) && x!= 0)
        cout<< "Can't store element\nMust be zero";
    switch(i-j)
    {
        case 1:  //lower Diagonal
            array[i-2] =x;
        case 0:  // Diagonal
            array[nRow + i-2] =x;
        case -1: // Upper Diagonal
            array[2*nRow + i -2] =x;
    }
}
int Tri_Dia_Mat:: Retrieve(int i,int j)const{
    if(i<1 || j<1 || i>nRow ||j>nColumn)
        throw "Index out of bound";
    switch(i-j)
    {
        case 1:  //lower Diagonal
            return array[i-2];
        case 0:  // Diagonal
            return array[nRow + i-2];
        case -1: // Upper Diagonal
            return array[2*nRow + i -2];
        default :
            return 0;
    }
}

low_Tri_Mat::low_Tri_Mat(int r,int c){
    if(r<=0 ||c <= 0)
        throw "Bad Initializers";
    if(r!=c)
        throw "Triangular matrix must be a square matrix";
    this->nRow = r;
    this->nColumn = c;
    array = new int[nRow*(nRow+1)/2];
    for(int i = 0; i<nRow*(nRow+1)/2;i++){
        array[i] =0;
    }
}
low_Tri_Mat::~low_Tri_Mat(){
    delete[] array;
}
void low_Tri_Mat::Dimensions()const{
    cout<<"Dimension of matrix is"<<nRow<<" x "<<nColumn;
}
void low_Tri_Mat::Store(const int &x, int i,int j){
    if(i<1 || i>nRow ||j<1 ||j>nColumn)
        throw "Index out of bound";
    if(i>=j)
        array[i*(i-1)/2 + j-1] =x;
    else
        throw "Element Must be zero";
}
int low_Tri_Mat:: Retrieve(int i,int j)const{
    if(i<1 || j<1 || i>nRow ||j>nColumn)
        throw "Index out of bound";
    if(i<j)
        return 0;
    else 
        return array[i*(i-1)/2 +j-1];
}

upp_Tri_Mat::upp_Tri_Mat(int r,int c){
    if(r<=0 ||c <= 0)
        throw "Bad Initializers";
    if(r!=c)
        throw "Triangular matrix must be a square matrix";
    this->nRow = r;
    this->nColumn = c;
    array = new int[nRow*(nRow+1)/2];
    for(int i = 0; i<nRow*(nRow+1)/2;i++){
        array[i] =0;
    }
}
upp_Tri_Mat::~upp_Tri_Mat(){
    delete[] array;
}
void upp_Tri_Mat::Dimensions()const{
    cout<<"Dimension of matrix is"<<nRow<<" x "<<nColumn;
}
void upp_Tri_Mat::Store(const int &x, int i,int j){
    if(i<1 || i>nRow ||j<1 ||j>nColumn)
        throw "Index out of bound";
    if(i<=j)
        array[j*(j-1)/2 + i-1] =x;
    else
        cout<< "Element Must be zero";
}
int upp_Tri_Mat:: Retrieve(int i,int j)const{
    if(i<1 || j<1 || i>nRow ||j>nColumn)
        throw "Index out of bound";
    if(i<j)
        return 0;
    else 
        return array[j*(j-1)/2 +i-1];
}

SymmetricMatrix::SymmetricMatrix(int r,int c){
    if(r<=0 ||c <= 0)
        throw "Bad Initializers";
    if(r!=c)
        throw "Symmetric matrix must be a square matrix";
    this->nRow = r;
    this->nColumn = c;
    array = new int[nRow*(nRow+1)/2];
    for(int i = 0; i<nRow*(nRow+1)/2;i++){
        array[i] =0;
    }
}
SymmetricMatrix::~SymmetricMatrix(){
    delete[] array;
}
void SymmetricMatrix::Dimensions()const{
    cout<<"Dimension of matrix is"<<nRow<<" x "<<nColumn;
}
void SymmetricMatrix::Store(const int &x, int i,int j){
    if(i<1 || i>nRow ||j<1 ||j>nColumn)
        throw "Index out of bound";
    if(i>=j)
        array[i*(i-1)/2 + j-1] =x;
    else
        if(x!=array[j*(j-1)/2+i-1])
            cout<< "Element must be same as of at index j,i ";
}
int SymmetricMatrix:: Retrieve(int i,int j)const{
    if(i<1 || j<1 || i>nRow ||j>nColumn)
        throw "Index out of bound";
    if(i>=j)
        return array[i*(i-1)/2 +j-1];
    else
        return array[j*(j-1)/2+i-1];
}

int main(){
    int rows,column,choice;
    cout<<"Enter the number of rows ";
    cin>>rows;
    cout<<"Enter the number of columns ";
    cin>>column;
    int x , i,j;
    try{
        do{
            cout<<"Press 1-> Diagonal Matrix\nPress 2-> Tridiagonal Matrix\nPress 3 -> Lower Trinagle Matrix\nPress 4 -> Upper Trinagle Matrix\nPress 5 -> Symmetric Matrix\nPress 0 -> to exit\n ";
            cin>>choice;
            switch(choice)
            {
                case 1:
                {
                    Dia_Mat a(rows,column);
                    int go;
                    do{
                        cout<<"Press 1 to insert a value,Press 2 to display: ";
                        cin>>go;
                        switch (go)
                        {
                        case 1:
                            cout<<"Enter the value to be entered: ";
                            cin>>x;
                            cout<<"Enter the index: ";
                            cin>>i>>j;
                            a.Store(x,i,j);
                            break;
                            
                        case 2:
                            cout<<"==============================";
                            cout<<"\nThe matrix is\n";
                            for(int k=1;k<=rows;k++){
                                for(int l= 1; l<=column;l++){
                                cout<<"\t"<<a.Retrieve(k,l);
                                    cout<<" ";
                                }
                                cout<<endl;
                            }
                            break;

                        default:
                            break;
                        }
                    }while(go!=2);
                    break;
                }
                case 2:
                {
                    Tri_Dia_Mat a(rows,column);
                    int go;
                    do{
                        cout<<"Press 1 to insert a value,Press 2 to display: ";
                        cin>>go;
                        switch (go)
                        {
                        case 1:
                            cout<<"Enter the value to be entered: ";
                            cin>>x;
                            cout<<"Enter the index: ";
                            cin>>i>>j;
                            a.Store(x,i,j);
                            break;
                            
                        case 2:
                            cout<<"==============================";
                            cout<<"\nThe matrix is\n";
                            for(int k=1;k<=rows;k++){
                                for(int l= 1; l<=column;l++){
                                cout<<"\t"<<a.Retrieve(k,l);
                                    cout<<" ";
                                }
                                cout<<endl;
                            }
                            break;

                        default:
                            break;
                        }
                    }while(go!=2);
                    break;
                }

                case 3:
                {
                    low_Tri_Mat a(rows,column);
                    int go;
                    do{
                        cout<<"Press 1 to insert a value,Press 2 to display: ";
                        cin>>go;
                        switch (go)
                        {
                        case 1:
                            cout<<"Enter the value to be entered: ";
                            cin>>x;
                            cout<<"Enter the index: ";
                            cin>>i>>j;
                            a.Store(x,i,j);
                            break;
                            
                        case 2:
                            cout<<"==============================";
                            cout<<"\nThe matrix is\n";
                            for(int k=1;k<=rows;k++){
                                for(int l= 1; l<=column;l++){
                                cout<<"\t"<<a.Retrieve(k,l);
                                    cout<<" ";
                                }
                                cout<<endl;
                            }
                            break;

                        default:
                            break;
                        }
                    }while(go!=2);
                    break;
                }

                case 4:
                {
                    upp_Tri_Mat a(rows,column);
                    int go;
                    do{
                        cout<<"Press 1 to insert a value,Press 2 to display: ";
                        cin>>go;
                        switch (go)
                        {
                        case 1:
                            cout<<"Enter the value to be entered: ";
                            cin>>x;
                            cout<<"Enter the index: ";
                            cin>>i>>j;
                            a.Store(x,i,j);
                            break;
                            
                        case 2:
                            cout<<"==============================";
                            cout<<"\nThe matrix is\n";
                            for(int k=1;k<=rows;k++){
                                for(int l= 1; l<=column;l++){
                                cout<<"\t"<<a.Retrieve(k,l);
                                    cout<<" ";
                                }
                                cout<<endl;
                            }
                            break;

                        default:
                            break;
                        }
                    }while(go!=2);
                    break;
                }
                
                case 5:
                {
                    SymmetricMatrix a(rows,column);
                    int go;
                    do{
                        cout<<"Press 1 to insert a value,Press 2 to display: ";
                        cin>>go;
                        switch (go)
                        {
                        case 1:
                            cout<<"Enter the value to be entered: ";
                            cin>>x;
                            cout<<"Enter the index: ";
                            cin>>i>>j;
                            a.Store(x,i,j);
                            break;
                            
                        case 2:
                            cout<<"==============================";
                            cout<<"\nThe matrix is\n";
                            for(int k=1;k<=rows;k++){
                                for(int l= 1; l<=column;l++){
                                cout<<"\t"<<a.Retrieve(k,l);
                                    cout<<" ";
                                }
                                cout<<endl;
                            }
                            break;

                        default:
                            break;
                        }
                    }while(go!=2);
                    break;
                }
                
                default : 
                    cout<<"Invalid Input";
                    break;                
            }
        }while(choice !=0);
    }
    catch(const char* exp){
        cout<<"Error Found : " << exp;
    }
}