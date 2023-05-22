#include "210102002024_Project3_Matrix.h"

Matrix::Matrix()
{
    N=2;
    mtrx = new double* [N];
    for(int i=0; i<N;i++){
        mtrx[i] = new double [N+1];
    }
}

Matrix::Matrix(int r,int col)
{
    N=r;
    mtrx = new double* [N];
    for(int i=0; i<N;i++){
        mtrx[i] = new double [col];
    }
    row=r;
    column=col;
}

Matrix::Matrix(int row, int col, int arr[])
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

Matrix::~Matrix()
{
    for(int i = 0; i < N; i++){
        delete[] mtrx[i];
    }
    delete[] mtrx;
}

Matrix::Matrix(Matrix const& mtrx2)
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

Matrix Matrix::operator=(Matrix const& mtrx2)
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

Matrix Matrix::operator+(Matrix const& mtrx2)
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

Matrix Matrix::operator*(Matrix const& mtrx2)
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

Matrix Matrix::operator-(Matrix const& mtrx2)
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

Matrix Matrix::scalar_matrix(int value)
{
    Matrix temp(row,column);
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            temp.mtrx[i][j] = mtrx[i][j] * value;
        }
    }
    return temp;
}

Matrix Matrix::transpose_matrix()
{
    Matrix temp(column, row);
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            temp.mtrx[j][i] = mtrx[i][j];
        }
    }
    return temp;
}

Matrix Matrix::inverse_matrix()
{
    ;
}


void Matrix::get_matrix()
{
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            cout<<setw(3)<<setfill(' ')<<mtrx[i][j] << " ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void Matrix::set_matrix(int r, int col,int arr[])
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
