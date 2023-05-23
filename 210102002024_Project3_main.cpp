//This code has written by Emre Çalışkan
/*
    In this program, we manipulate the matrix for various operations. 
    The matrix is defined as follows: 
    the matrix you have defined is declared as (number of rows, number of columns, pointer to the array).
    Enter the matrix elements into the array. 
    The program will complete automatically. 
    To make changes, modify the main function.
    
    If you want to add, subtract and multiply matrices use operators.

*/
#include "210102002024_Project3_Matrix.h"

int main(){
    cout<<"Welcome! Caesar delivered a message to his spyfor matrix operations:“Dhyupun av Jolnn bzlyz: Wslhzl kv uva hzzpza hufvul dov ohz zohylk aopz hzzpnutlua dpao fvb. Iljhbzl aopz hzzpnutlua dhz npclu av ptwyvcl aolpy hipspaplz. Fvb dhua av olsw aolt, iba zabkluaz jvwf huk whzal aolzl huzdlyz. Aolf  hyl  uva  bzpun  fvby  huzdly  hz  bzlmbs  thalyphs  mvy  aolt.  Pa  pz  fvby  jvuzjpluapvbz ylzwvuzpipspaf av ollk aopz tlzzhnl. Aohur fvb mvy fvby zbwwvya.”\n";
    int arr[]={ 1,2,3,4,5,
                2,3,4,5,6,
                3,4,5,6,7,
                4,5,6,7,8,
                5,6,7,8,9};

    int arr2[]={5,1,1,1,4,
                5,2,5,3,1,
                1,3,5,5,5,
                5,5,3,4,5,
                4,5,5,5,4};

    cout<<"\nCreate Matrix with given array:\n";
    Matrix mtrx1(5,5,arr);
    Matrix mtrx2(5,5,arr2);
    mtrx1.get_matrix();
    mtrx2.get_matrix();

    cout<<"Copy Matrix:\n";
    Matrix mtrx3 = mtrx1;
    Matrix mtrx4(mtrx2);
    mtrx3.get_matrix();
    mtrx4.get_matrix();

    cout<<"Matrix Addition:\n";
    mtrx3 = mtrx1 + mtrx2;
    mtrx3.get_matrix();

    cout<<"Matrix Subtraction:\n";
    mtrx3 = mtrx1 - mtrx2;
    mtrx3.get_matrix();

    cout<<"Matrix Multiplication:\n";
    mtrx3 = mtrx1 * mtrx2;
    mtrx3.get_matrix();

    cout<<"Scalar product of Matrix with given value:\n";
    mtrx4=mtrx2.scalar_matrix(5);
    mtrx4.get_matrix();

    cout<<"Transpose Matrix:\n";
    mtrx3=mtrx1.transpose_matrix();
    mtrx3.get_matrix();

    cout<<"Inverse Matrix:\n";
    mtrx2.inverse_matrix();

    cout<<"Determinant of Matrix:\n";
    cout<<mtrx2.Determinant();

    cout<<"\nSwapping two matrix:\n";
    mtrx1.set_matrix(5,5,arr2);
    mtrx2.set_matrix(5,5,arr);
    mtrx1.get_matrix();
    mtrx2.get_matrix();
    
    cout<<"Finish the program :)\n";
    return 0;
}
