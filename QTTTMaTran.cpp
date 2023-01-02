#include <iostream>
using namespace std;

class matran{
  short hang;
  short cot;
  double *elems;
public:
  matran (short hang=0, short cot=0){
    this->hang=hang; this->cot=cot;
    elems =new double[12*12];
  }
  friend ostream& operator <<(ostream& os, matran& mt){

    for(int i=0; i<mt.hang; i++){
      for(int j=0; j<mt.cot; j++){
        os<<mt.elems[i*mt.hang+j]<<" ";
      }
      os<<endl;
    }
  }
  friend istream& operator>>(istream& is, matran& mt){

    cout<<"Nhap ma tran: "<<endl;
    for(int i=0; i<mt.hang; i++){

      for(int j=0; j<mt.cot; j++){

        is>>mt.elems[i*mt.hang+j];
      }
    }
  }
  friend matran& operator +(matran& mt1, matran& mt2 ){

    for(int i=0; i<mt1.hang; i++){

      for(int j=0; j<mt1.cot; j++){

      return {mt1.elems[i*mt1.hang+j]+  mt2.elems[i*mt1.hang+j]};
      }
    }

  }
};
int main(){
  matran mt1(2,3), mt2(2,3), mt3(2,3);
  cin>>mt1;
  cin>>mt2;
  mt3=mt1+mt2;

}
