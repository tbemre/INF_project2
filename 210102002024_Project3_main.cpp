//This code has written by Emre Çalışkan

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
    cout<<"Create Matrix with given array";
    Matrix mtrx1(5,5,arr);
    Matrix mtrx2(5,5,arr2);
    mtrx1.get_matrix();
    mtrx2.get_matrix();
    cout<<"Copy Matrix";
    Matrix mtrx3 = mtrx1;
    Matrix mtrx4(mtrx2);
    mtrx3.get_matrix();
    mtrx4.get_matrix();
    

    return 0;
}
