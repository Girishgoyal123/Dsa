#include<iostream>
using namespace std;

class DiagonalMatrix{
    private:
        int nRow,nColumn;
        int* array;
    public:
        DiagonalMatrix(int r=0, int c=0);
        DiagonalMatrix(const DiagonalMatrix& m);
        ~DiagonalMatrix();
        void Dimensions() const;
        void Store(const int &x ,int i, int j);
        int Retrieve(int i,int j) const;
};

class TriDiagonalMatrix{
    private:
        int nRow,nColumn;
        int* array;
    public:
        TriDiagonalMatrix(int r=0, int c=0);
        TriDiagonalMatrix(const TriDiagonalMatrix& m);
        ~TriDiagonalMatrix();
        void Dimensions() const;
        void Store(const int &x ,int i, int j);
        int Retrieve(int i,int j) const;
};

class lowerTriangleMatrix{
    private:
        int nRow,nColumn;
        int* array;
    public:
        lowerTriangleMatrix(int r=0, int c=0);
        lowerTriangleMatrix(const lowerTriangleMatrix& m);
        ~lowerTriangleMatrix();
        void Dimensions() const;
        void Store(const int &x ,int i, int j);
        int Retrieve(int i,int j) const;
};

class upperTriangleMatrix{
    private:
        int nRow,nColumn;
        int* array;
    public:
        upperTriangleMatrix(int r=0, int c=0);
        upperTriangleMatrix(const upperTriangleMatrix& m);
        ~upperTriangleMatrix();
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
DiagonalMatrix::DiagonalMatrix(int r,int c){
    if(r<=0 ||c <= 0)
        throw "Bad Initializers";
    if(r!=c)
        throw "Diagonal matrix must be a square matrix";
    this->nRow = r;
    this->nColumn = c;
    array = new int[r];
}
DiagonalMatrix::~DiagonalMatrix(){
    delete[] array;
}
void DiagonalMatrix::Dimensions()const{
    cout<<"Dimension of matrix is"<<nRow<<" x "<<nColumn;
}
void DiagonalMatrix::Store(const int &x, int i,int j){
    if(i<1 || i>nRow ||j<1 ||j>nColumn)
        throw "Index out of bound";
    if(i!=j && x!= 0)
        throw "Can't store element\nMust be zero";
    if(i==j)
        array[i-1]=x;
}
int DiagonalMatrix:: Retrieve(int i,int j)const{
    if(i<1 || j<1 || i>nRow ||j>nColumn)
        throw "Index out of bound";
    if(i==j)
        return array[i-1];
    else
        return 0;
}

TriDiagonalMatrix::TriDiagonalMatrix(int r,int c){
    if(r<=0 ||c <= 0)
        throw "Bad Initializers";
    if(r!=c)
        throw "TriDiagonal matrix must be a square matrix";
    this->nRow = r;
    this->nColumn = c;
    array = new int[(3*nRow)-2];
}
TriDiagonalMatrix::~TriDiagonalMatrix(){
    delete[] array;
}
void TriDiagonalMatrix::Dimensions()const{
    cout<<"Dimension of matrix is"<<nRow<<" x "<<nColumn;
}
void TriDiagonalMatrix::Store(const int &x, int i,int j){
    if(i<1 || i>nRow ||j<1 ||j>nColumn)
        throw "Index out of bound";
    // if((i!=j || i-j != 1 || i-j != -1) && x!= 0)
    //     throw "Can't store element\nMust be zero";
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
int TriDiagonalMatrix:: Retrieve(int i,int j)const{
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

lowerTriangleMatrix::lowerTriangleMatrix(int r,int c){
    if(r<=0 ||c <= 0)
        throw "Bad Initializers";
    if(r!=c)
        throw "Triangular matrix must be a square matrix";
    this->nRow = r;
    this->nColumn = c;
    array = new int[nRow*(nRow+1)/2];
}
lowerTriangleMatrix::~lowerTriangleMatrix(){
    delete[] array;
}
void lowerTriangleMatrix::Dimensions()const{
    cout<<"Dimension of matrix is"<<nRow<<" x "<<nColumn;
}
void lowerTriangleMatrix::Store(const int &x, int i,int j){
    if(i<1 || i>nRow ||j<1 ||j>nColumn)
        throw "Index out of bound";
    if(i>=j)
        array[i*(i-1)/2 + j-1] =x;
    else
        throw "Element Must be zero";
}
int lowerTriangleMatrix:: Retrieve(int i,int j)const{
    if(i<1 || j<1 || i>nRow ||j>nColumn)
        throw "Index out of bound";
    if(i<j)
        return 0;
    else 
        return array[i*(i-1)/2 +j-1];
}

upperTriangleMatrix::upperTriangleMatrix(int r,int c){
    if(r<=0 ||c <= 0)
        throw "Bad Initializers";
    if(r!=c)
        throw "Triangular matrix must be a square matrix";
    this->nRow = r;
    this->nColumn = c;
    array = new int[nRow*(nRow+1)/2];
}
upperTriangleMatrix::~upperTriangleMatrix(){
    delete[] array;
}
void upperTriangleMatrix::Dimensions()const{
    cout<<"Dimension of matrix is"<<nRow<<" x "<<nColumn;
}
void upperTriangleMatrix::Store(const int &x, int i,int j){
    if(i<1 || i>nRow ||j<1 ||j>nColumn)
        throw "Index out of bound";
    if(i<=j)
        array[j*(j-1)/2 + i-1] =x;
    else
        throw "Element Must be zero";
}
int upperTriangleMatrix:: Retrieve(int i,int j)const{
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
            throw "Element must be same as of at index j,i ";
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
                    DiagonalMatrix a(rows,column);
                    for(int k =0; k<rows; k++){
                        cout<<"Enter the value to be entered: ";
                        cin>>x;
                        cout<<"Enter the index: ";
                        cin>>i>>j;
                        a.Store(x,i,j);
                    }
                    cout<<"The matrix is\n";
                    for(int k=1;k<=rows;k++){
                        for(int l= 1; l<=column;l++){
                           cout<<a.Retrieve(k,l);
                            cout<<" ";
                        }
                        cout<<endl;
                    }
                    break;
                }
                case 2 :
                {
                    TriDiagonalMatrix b(rows,column);
                    for(int k =0; k<3*rows-2; k++){
                        cout<<"Enter the value to be entered: ";
                        cin>>x;
                        cout<<"Enter the index: ";
                        cin>>i>>j;
                        b.Store(x,i,j);
                    }
                    cout<<"The matrix is\n";
                    for(int k=1;k<=rows;k++){
                        for(int l= 1; l<=column;l++){
                            cout<<b.Retrieve(k,l);
                            cout<<" ";
                        }
                        cout<<endl;
                    }
                    break;
                }

                case 3:
                {
                    lowerTriangleMatrix c(rows,column);
                    for(int k =0; k<rows*(rows+1)/2; k++){
                        cout<<"Enter the value to be entered: ";
                        cin>>x;
                        cout<<"Enter the index: ";
                        cin>>i>>j;
                        c.Store(x,i,j);
                    }
                    cout<<"The matrix is\n";
                    for(int k=1;k<=rows;k++){
                        for(int l= 1; l<=column;l++){
                            cout<<c.Retrieve(k,l);
                            cout<<" ";
                        }
                        cout<<endl;
                    }
                    break;
                }
                case 4:
                {
                    upperTriangleMatrix d(rows,column);
                    for(int k =0; k<rows*(rows+1)/2; k++){
                        cout<<"Enter the value to be entered: ";
                        cin>>x;
                        cout<<"Enter the index: ";
                        cin>>i>>j;
                        d.Store(x,i,j);
                    }
                    cout<<"The matrix is\n";
                    for(int k=1;k<=rows;k++){
                        for(int l= 1; l<=column;l++){
                            cout<<d.Retrieve(k,l);
                            cout<<" ";
                        }
                        cout<<endl;
                    }
                    break;
                }
                case 5:
                {
                    SymmetricMatrix e(rows,column);
                    for(int k =0; k<rows*(rows+1)/2; k++){
                        cout<<"Enter the value to be entered: ";
                        cin>>x;
                        cout<<"Enter the index: ";
                        cin>>i>>j;
                        e.Store(x,i,j);
                    }
                    cout<<"The matrix is\n";
                    for(int k=1;k<=rows;k++){
                        for(int l= 1; l<=column;l++){
                            cout<<e.Retrieve(k,l);
                            cout<<" ";
                        }
                        cout<<endl;
                    }
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