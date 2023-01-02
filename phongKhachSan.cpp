#include<iostream>
#include <iomanip>
#include<ctime>
using namespace std;

struct thoigian{
    int giay, phut, gio, ngay, thang, nam;

};

class nguoi
{
    protected:
    string hoten;
    string cccd;
    thoigian ngaysinh;
    public:
    nguoi(){
        hoten=cccd="";
        ngaysinh.ngay=0;
        ngaysinh.thang=0;
        ngaysinh.nam=0;
    }
    void nhap(){
        cout<<"Nhap ten : ";cin.ignore(); getline(cin,hoten);
        cout<<"Cccd/cmnd: ";fflush(stdin); getline(cin,cccd);
        cout<<"Ngay sinh(DD/MM/YY): "; cin>>ngaysinh.ngay; cin>>ngaysinh.thang; cin>>ngaysinh.nam;
         
    }
    void xuat(){
        cout<<left<<setw(20)<<hoten<<setw(15)<<cccd<<"     "<<ngaysinh.ngay<<"/"<<ngaysinh.thang<<"/"<<ngaysinh.nam<<"   ";
        
    }
    
};
class phong{
    protected:
    enum loaiphong{phongthuong, phongvip}lp;
    int p;
    public:
    phong(){
        this->p=0;
        this->lp=phongthuong;
    }
    void capnhatphong(){

    }
    void nhap(){
        cout<<"----------------Chon loai phong------------------"<<endl;
        cout<<"Neu phong thuong nhap 1, phong vip nhap 2: ";
        int a; cin>>a;
        if(a==1 ) lp=phongthuong;
        else lp=phongvip;
        cout<<"Nhap so phong: "; cin>>p;
    }
    float tienphong(){
        if(lp==phongthuong) return 100000;
        else return 150000;
    }
    int getphong(){
        return this->p;
    }
};
class khachhang : public nguoi, public phong
{
    time_t tgnhan;
    public:
    khachhang(){
        this->tgnhan=0;
    }
    void nhap(){
        nguoi::nhap();
        phong::nhap();
        this->tgnhan=time(NULL);

    }
    void xuat(){
        nguoi::xuat();
        cout<<"   "<<this->p;
        char* now = ctime(&this->tgnhan);
        cout<<now<<endl;
        

    }
    string getten(){
        return hoten;
    }
    int getphong(){
        return phong::p;
    }
    time_t gettg(){
        return this->tgnhan;
    }

};
void list(){
        cout<<"========================================Danh sach======================================"<<endl;
        cout<<endl;
        cout<<"1.Them khach hang."<<endl;
        cout<<"2.Tim khach hang."<<endl;
        cout<<"3.Tra phong."<<endl;
        
}
char doikt(char& ch){
    ch=ch-('a'-'A')*(ch<='z'&&ch>='a');
    return ch;
}
bool timkiem(string a, string b){
    int i=0;
    while(b[i]!='\0'){
        if((a[i]=doikt(a[i]))!=(b[i]=doikt(b[i]))) return false;
        i++;

    }
    return true;
}

int main(){
    int dk=1;
    khachhang *s =new khachhang [1000];
    int n=0;
    string ch;
    int sl;
    while(dk!=0){
        list();
        cout<<"Nhap  lua chon: ";cin>>dk;
        switch(dk){
            case 1:
            cout<<"----------------------Them khach hang------------------"<<endl;
            s[n].nhap();
            cout<<"Them khach hang thanh cong!"<<endl;
            n++;
            break;
            case 2:
            cout<<"-----------------------Tim kiem----------------------------"<<endl;
            cout<<"Nhap ten can tim kiem: ";
            cin.ignore();getline(cin,ch);
            sl=0;
            for(int i=0; i<n; i++){
                if(timkiem(s[i].getten(),ch )) {
                    cout<< i<<"   ";
                    s[i].xuat();
                    sl++;
                }
                
            }
            cout<<"Co "<<sl<<" ket qua!"<<endl;
            break;
            case 3:
            cout<<"----------------Tra phong---------------------------"<<endl;
            cout<<"Nhap so phong: "; cin>>sl;
            for (int i=0; i<n; i++){
                if(sl==s[i].getphong()) s[i].xuat();
                time_t tgtra=time(NULL);
                double  tg= difftime(tgtra, s[i].gettg());
                cout<<"thoi gian thue phong la: "<<tg/3600<<endl;
                cout<<"so tien: "<<s[i].tienphong()*tg/3600<<endl;
                delete [i]s;
                cout<<"Tra phong thanh cong!"<<endl;

            }
            break;
            default:
            cout<<"Lua chon khong phu hop!"<<endl;
        }
        cout<<"Muon thoat chuong trinh nhap 0, tiep tuc nhap bat ki: ";cin>>dk;

    }

    
}