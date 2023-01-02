#include <iostream>
using namespace std;

class vemaybay {
    string tenchuyen;
    string ngaybay;
    float giave;
    public:
    vemaybay (string tenchuyen=0, string ngaybay=0, float giave=0){
        this->tenchuyen=tenchuyen;
        this->ngaybay=ngaybay;
        this->giave=giave;
    }
    ~vemaybay(){
        tenchuyen="";
        ngaybay="";
        giave=0;
    }
    void nhap(){
        cout<<"Ten chuyen bay: ";
        fflush(stdin);
        getline(cin, tenchuyen);
        cout<<"Ngay bay: ";
        fflush(stdin);
        getline(cin, ngaybay);
        cout<<"Gia ve: ";cin>>giave;
    }
    void xuat(){
        cout<<"Ten chuyen bay: "<<tenchuyen<<endl;
        cout<<"Ngay bay: "<<ngaybay<<endl;
        cout<<"Gia ve: "<<giave<<endl; 
        
    }
    float getgiave(){
        return giave;
    };
};

class nguoi{
    char* hoten;
    char* gioitinh;
    int tuoi;
    public:
    nguoi(char* hoten=0, char* gioitinh=0, int tuoi=0){
        this->hoten=hoten=new char[20];
        this->gioitinh=gioitinh=new char [10];
        this->tuoi=tuoi;
    }
    ~nguoi(){
        delete []hoten;
        delete []gioitinh;
        this->tuoi=0;
    }
    void nhap(){
        cin.ignore();
        cout<<"Nhap ten khach hang: ";
        cin.getline(hoten,20);
        cout<<"Gioi tinh: ";
        cin.ignore();
        cin.getline(gioitinh,10);
        cout<<"Tuoi: "; cin>>tuoi;
    }
    void xuat(){
        cout<<"Ten khach hang: "<<this->hoten<<endl;
        cout<<"Gioi tinh: "<<this->gioitinh<<endl;
        cout<<"Tuoi: "<<this->tuoi<<endl;
    }
};
class hanhkhach : public nguoi
{
    vemaybay* ve;
    int soluong;
    public:
    hanhkhach(vemaybay* ve=0, int soluong=0){
        this->ve=ve=new vemaybay[10];
        this->soluong=soluong;
    }
    ~hanhkhach(){
        delete []ve;
        soluong=0;
    }
    void nhap(){
        nguoi::nhap();
        cout<<"So luong ve: ";cin>>soluong;
        for(int i=0; i<soluong; i++){
            ve[i].nhap();
        }
    }
    void xuat(){
        nguoi::xuat();
        for(int i=0; i<soluong; i++){
            ve[i].xuat();
        }
    }
    float tongtien(){
       float tong=0;
       for (int i=0; i<soluong; i++){
        tong=tong+ve[i].getgiave();
       }
       return tong;
    }
};
void swap(hanhkhach &k1, hanhkhach &k2){
    hanhkhach temp;
    temp=k1;
    k1=k2;
    k2=temp;
}
void sapxep(hanhkhach* hk, int sk){
    for(int i=0; i<sk; i++){
        for(int j=0; j<sk; j++){
            if(hk[j].tongtien()<hk[j+1].tongtien()) swap(hk[j], hk[j+1]);
        }
    }
}

int main(){
    int sk;
    cout<<"Nhap so luong hanh khach: ";cin>>sk;
    cout<<"okk"<<endl;
    hanhkhach p;
    cout<<" ok"<<endl;
    //p.nhap();
    /*for(int i=0; i<sk; i++){
        hk[i].nhap();
    }
    sapxep(hk,sk);
    for(int i=0; i<sk; i++){
        hk[i].xuat();
    }*/
}
