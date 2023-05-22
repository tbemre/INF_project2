#include "210102002024_Project3_Matrix.h"

int Determinant(Matrix mtrx);

int main(){
    cout<<"Welcome! Caesar delivered a message to his spyfor matrix operations:“Dhyupun av Jolnn bzlyz: Wslhzl kv uva hzzpza hufvul dov ohz zohylk aopz hzzpnutlua dpao fvb. Iljhbzl aopz hzzpnutlua dhz npclu av ptwyvcl aolpy hipspaplz. Fvb dhua av olsw aolt, iba zabkluaz jvwf huk whzal aolzl huzdlyz. Aolf  hyl  uva  bzpun  fvby  huzdly  hz  bzlmbs  thalyphs  mvy  aolt.  Pa  pz  fvby  jvuzjpluapvbz ylzwvuzpipspaf av ollk aopz tlzzhnl. Aohur fvb mvy fvby zbwwvya.”\n";
    int arr[]={1,0,0,0,0,2,3,4,5,6,3,4,5,6,7,4,5,6,7,8,5,6,7,8,9};
    Matrix mtrx1(5,5,arr);
    mtrx1.get_matrix();
    Matrix mtrx2(mtrx1);
    mtrx2.get_matrix();
    Matrix mtrx3 = mtrx1 * mtrx2;
    mtrx3.get_matrix();
    //mtrx1.scalar_matrix(-1).get_matrix();
    mtrx3 = mtrx1.transpose_matrix();
    mtrx3.get_matrix();
    return 0;
}
