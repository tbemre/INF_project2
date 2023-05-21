#include "210102002024_Project3_Matrix.h"

Matrix::Matrix()
{
    N=2;
    mtrx = new double* [N];
    for(int i=0; i<N;i++){
        mtrx[i] = new double [N+1];
    }
}

Matrix::~Matrix()
{
    cout<<"\n Destructor executed\n";
}

Matrix::Matrix(Matrix& mtrx2)
{
    mtrx = mtrx2.mtrx;
    N = mtrx2.N;
    row = mtrx2.row;
    column = mtrx2.column;
}

Matrix Matrix::operator=(Matrix const& mtrx2)
{
    mtrx = mtrx2.mtrx;
    N = mtrx2.N;
    row = mtrx2.row;
    column = mtrx2.column;
    return *this;
}

Matrix Matrix::operator+(Matrix const& mtrx2)
{
    Matrix temp;
    if(row==mtrx2.row||column==mtrx2.column)
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
    Matrix temp;
    if(row==mtrx2.column)
    {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                temp.mtrx[i][j] = 0;
                for (int k = 0; k < column; k++) {
                    temp.mtrx[i][j] = temp.mtrx[i][j] + ((mtrx[i][k]) * (mtrx2.mtrx[k][j]));
                }
            }
        }
    }
    return temp;
}

Matrix Matrix::operator-(Matrix const& mtrx2)
{
    Matrix temp;
    if(row==mtrx2.row||column==mtrx2.column)
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
    Matrix temp;
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            temp.mtrx[i][j] = mtrx[i][j] * value;
        }
    }
    return temp;
}

Matrix Matrix::transpose_matrix()
{
    Matrix temp;
    temp.row = column;
    temp.column = row;
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            temp.mtrx[i][j] = mtrx[j][i];
        }
    }
    return temp;
}

void Matrix::get_matrix()
{
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            cout<<mtrx[i][j]<<" "<<endl;
        }
        cout<<"\n";
    }
}

void Matrix::set_matrix(int arr[])
{
    int temp,size;
    size = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++){
        for(int j=0;j<column;j++){
            cout<<mtrx[i][j]<<" "<<endl;
        }
        cout<<"\n";
    }
}
