#include <iostream>
using namespace std;

class sinhvien{
private:
  char *ho, *ten;
  float* diem;
  float dtb;// diem trung binh ca nhan
public:
  static int siso;
  static int somonhoc;
  static float DTB;// diem trung binh cho ca lop
  sinhvien(char* ho=0, char* ten=0){
    this->ho=ho; this ->ten=ten;
    siso++;
  }

  void nhap(){
    char* ho, *ten;
    float* diem;
    float tong=0;
    ho= new char[20];
    ten= new char[10];
    diem=new float[10];
    cout<<"Nhap ho: ";
    cin.getline(ho,20);
    fflush(stdin);
    cin>>ten;

    cout<<"Nhap diem cac mon hoc: ";
    for(int i=0; i<somonhoc; i++){
      cin>>diem[i];
      tong=+diem[i];

    }

  }
 void xuat(){
   cout<<"Ho ten: "<<ho<<ten<<endl;

 }
};
int main(){

  sinhvien sv1;
  sv1.nhap();
  sv1.xuat();
}
