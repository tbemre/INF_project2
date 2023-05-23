#include "210102002024_Project3_Matrix.h"

Matrix::Matrix()
{
    N=2;
    mtrx = new double* [N];         //This function is the default constructor, allocates memory for 2x2.
    for(int i=0; i<N;i++){
        mtrx[i] = new double [N+1];
    }
}

Matrix::Matrix(int r,int col)  //This function is constructor, allocates memory on given values. 
{
    N=r;
    mtrx = new double* [N];      
    for(int i=0; i<N;i++){
        mtrx[i] = new double [col];
    }
    row=r;
    column=col;
}

Matrix::Matrix(int row, int col, int arr[]) // This function is constructor, allocates memory and create matrix with numbers in given array.
{
    N = row;
    this->row = row;
    column = col;
    mtrx = new double* [N];
    for(int i = 0; i < N; i++){
        mtrx[i] = new double[column];
    }
    int size, i = 0;
    int r = 0, c = 0;
    size = row * col;
    while(i < size)
    {
        mtrx[r][c] = arr[i];
        i++;
        c++;
        if(c == col){
            c = 0;
            r++;
        }
    }
}

Matrix::~Matrix() //destructor , frees the memory.
{
    for(int i = 0; i < N; i++){
        delete[] mtrx[i];
    }
    delete[] mtrx;
}

Matrix::Matrix(Matrix const& mtrx2) // copy constructor
{
    N = mtrx2.N;
    row = mtrx2.row;
    column = mtrx2.column;
    
    mtrx = new double* [N];
    for(int i = 0; i < N; i++){
        mtrx[i] = new double[column];
        for(int j = 0; j < column; j++){
            mtrx[i][j] = mtrx2.mtrx[i][j];
        }
    }
}

Matrix Matrix::operator=(Matrix const& mtrx2) //copy operator
{
    N = mtrx2.N;
    row = mtrx2.row;
    column = mtrx2.column;

    mtrx = new double* [N];
    for(int i = 0; i < N; i++){
        mtrx[i] = new double[column];
        for(int j = 0; j < column; j++){
            mtrx[i][j] = mtrx2.mtrx[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator+(Matrix const& mtrx2) // addition operator
{
    Matrix temp(mtrx2.row,mtrx2.column);
    if(row==mtrx2.row && column==mtrx2.column)
    {
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                temp.mtrx[i][j] = mtrx[i][j] + mtrx2.mtrx[i][j];
            }
        }
    }
    return temp;
}

Matrix Matrix::operator*(Matrix const& mtrx2) //Multipy operator.
{
    Matrix temp(row,mtrx2.column);
    if(column == mtrx2.row)
    {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < mtrx2.column; j++) {
                temp.mtrx[i][j] = 0;
                for (int k = 0; k < column; k++) {
                    temp.mtrx[i][j] += ((mtrx[i][k]) * (mtrx2.mtrx[k][j]));
                }
            }
        }
    }
    return temp;
}

Matrix Matrix::operator-(Matrix const& mtrx2) // subtraction operator.
{
    Matrix temp(mtrx2.row,mtrx2.column);
    if(row==mtrx2.row && column==mtrx2.column)
    {
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                temp.mtrx[i][j] = mtrx[i][j] - mtrx2.mtrx[i][j];
            }
        }
    }
    return temp;
}

Matrix Matrix::scalar_matrix(int value)  // This function product the matrix by the number entered.
{
    Matrix temp(row,column);
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            temp.mtrx[i][j] = mtrx[i][j] * value;
        }
    }
    return temp;
}

Matrix Matrix::transpose_matrix() // This function give transpose of matrix.
{
    Matrix temp(column, row);
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            temp.mtrx[j][i] = mtrx[i][j];
        }
    }
    return temp;
}

void Matrix::inverse_matrix() //this function  get inverse of matrix with Gauss-Jordan elimination.
{
    if(this->Determinant()==0){
        cout<<"This matrix cannot be inverted.";
        return;
    }
    Matrix temp1(row,column);
    Matrix temp2 = *this;
    for (int i = 0; i < N; i++) {
        temp1.mtrx[i][i] = 1.0;
    }

    for (int i = 0; i < N; i++) {   //Gauss-Jordan elimination and measure inverse
    double pivot = temp2.mtrx[i][i];
        for (int j = 0; j < N; j++) {
            temp2.mtrx[i][j] /= pivot;
            temp1.mtrx[i][j] /= pivot;
        }
        for (int j = 0; j < N; j++) {
            if (j != i) {
                double ratio = temp2.mtrx[j][i];
                
                for (int k = 0; k < N; k++) {
                    temp2.mtrx[j][k] -= ratio * temp2.mtrx[i][k];
                    temp1.mtrx[j][k] -= ratio * temp1.mtrx[i][k];
                }
            }
        }
    }
    temp1.Matrix::get_matrix();

}

Matrix* Matrix::Minor(int a,int b) //This function get minor of matrix.this function was written before in the project1 by me.
{   
    Matrix* temp = new Matrix(N-1,N-1);
    int row_count = 0;
    for(int i=0;i<N;i++){
        if(i==a){
            continue;
        }
        int col_count = 0;
        for(int j=0;j<N;j++){
            if(j==b){
                continue;
            }
            temp->mtrx[row_count][col_count] = mtrx[i][j];
            col_count++;
        }
        row_count++;
    }
    return temp;
}

int Matrix::Determinant() //This function get determimant of matrix.this function was written before in the project1 by me.
{
    if(row!=column){throw runtime_error("The determinant of this matrix cannot be taken!");}
    int det=0;
    if (N==1) {
        return mtrx[0][0];
    }
    else{
        for(int i=0;i<N;i++){
            Matrix* temp = this->Minor(0,i);
            det += (i % 2 == 0 ? 1 :-1) * (mtrx[0][i]) * temp->Determinant();  //recursive function.
            delete temp;
        }
    }
    return det;
}

void Matrix::get_matrix() // This function prints the matrix on the console.
{
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            cout<<setw(3)<<setfill(' ')<<mtrx[i][j] << " ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void Matrix::set_matrix(int r, int col,int arr[])  // This function is used to change the matrix. similar to constructor 
{
    if(r != row || col != column)
    {
        for(int i = 0; i < N; i++){
            delete[] mtrx[i];
        }
        delete[] mtrx;

        N = r;
        row = r;
        column = col;

        mtrx = new double* [N];
        for(int i = 0; i < N; i++){
            mtrx[i] = new double[column];
        }
    }

    int size, i = 0;
    int ro = 0, c = 0;
    size = r * col;
    while(i < size)
    {
        mtrx[ro][c++] = arr[i++];
        if(c == col){
            c = 0;
            ro++;
        }
    }
}
