#ifndef P3_MATRIX__
#define P3_MATRIX__
#include <iostream>
using namespace std;  

class Matrix{
    public:
        Matrix();
        Matrix(int[]);
        Matrix(Matrix& mtrx2);
        ~Matrix();
        Matrix operator=(Matrix const& mtrx2);
        Matrix operator+(Matrix const& mtrx2);
        Matrix operator-(Matrix const& mtrx2);
        Matrix operator*(Matrix const& mtrx2);
        //void add_matrix(Matrix& mtrx2);
        //void sub_matrix(Matrix& mtrx2);
        //void product_matrix(Matrix& mtrx2);
        Matrix scalar_matrix(int);
        Matrix transpose_matrix();
        Matrix determinant_matrix();
        Matrix inverse_matrix();
        void set_matrix(int[]);
        void get_matrix();
        Matrix* Minor(int,int);


    private:
        int N,row,column;
        double** mtrx;
};

#endif