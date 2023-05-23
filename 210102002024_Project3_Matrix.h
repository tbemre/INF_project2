#ifndef P3_MATRIX__
#define P3_MATRIX__
#include <iostream>
#include <iomanip>
using namespace std;  

class Matrix{
    public:
        Matrix();
        Matrix(int,int,int[]);
        Matrix(int,int);
        Matrix(Matrix const& mtrx2);
        ~Matrix();
        Matrix operator=(Matrix const& mtrx2);
        Matrix operator+(Matrix const& mtrx2);
        Matrix operator-(Matrix const& mtrx2);
        Matrix operator*(Matrix const& mtrx2);
        Matrix scalar_matrix(int);
        Matrix transpose_matrix();
        void inverse_matrix();
        void set_matrix(int,int,int[]);
        void get_matrix();
        Matrix* Minor(int,int);
        int Determinant();
    private:
        int N,row,column;
        double** mtrx;
};

#endif