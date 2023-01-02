#include <iostream>
using namespace std;

class phanso{
  int tu, mau;
public:
  phanso();
  phanso(int tu, int mau){
    this->tu=tu, this->mau=mau;
  }
friend istream& operator>> (istream& is, phanso& ps){
  cout<<"Nhap tu so: ";is>>ps.tu;
  cout<<"Nhap mau so: ";is>>ps.mau;
}
friend ostream& operator<< (ostream& os, phanso& ps){
  os<<""<<ps.tu<<"/"<<ps.mau<<"";
  return os;
}
phanso operator + (phanso&ps){
  return phanso(tu*ps.mau+mau*ps.tu,mau*ps.mau);
}
phanso operator - (phanso&ps){
  return phanso(tu*ps.mau-mau*ps.tu,mau*ps.mau);
}
phanso operator * (phanso&ps){
  return phanso(tu*ps.tu,mau*ps.mau);
}
phanso operator / (phanso&ps){
  return phanso(tu*ps.mau,mau*ps.tu);
}
};
int main(){
  phanso ps1(0,0), ps2(0,0), ps3(0,0), ps4(0,0), ps5(0,0), ps6(0,0);
  cout<<"Nhap phan so 1:";
  cin>>ps1;
  cout<<"Nhap phan so 2:";
  cin>>ps2;
  ps3=ps1+ps2;
  ps4=ps1-ps2;
  ps5=ps1*ps2;
  ps6=ps1/ps2;
}
