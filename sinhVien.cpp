#include <iostream>
#include<algorithm>
using namespace std;

class ngaysinh{
    int ngay, thang, nam;
    public:
    ngaysinh(){
       this->ngay=0;
       this->thang=0;
       this->nam=0;
    }
    ~ngaysinh(){
        this->ngay=0;
       this->thang=0;
       this->nam=0;
    }
    void nhap(){
        cout<<"Nhap ngay sinh: ";cin>>this->ngay;
        cout<<"Thang: ";cin>>this->thang;
        cout<<"Nam: ";cin>>this->nam;
    }
    void xuat(){
        cout<<"Ngay/Thang/Nam sinh: "<<this->ngay<<"/"<<this->thang<<"/"<<this->nam<<endl;
    }
};

class nguoi : public ngaysinh
{
    char* hoten;
    char* quequan;
    public:
    nguoi(char* hoten=0, char* quequan=0){
        this->hoten=hoten=new char [20];
        this->quequan=quequan=new char [20];
    }
    
    void nhap(){
        cout<<"Nhap ho ten: ";
        cin.ignore();
        cin.getline(hoten,20);
        cout<<"Nhap que quan: ";
        //cin.ignore();
        cin.getline(quequan,20);
        
        ngaysinh::nhap();
    }
    void xuat(){
        cout<<"Ho ten: "<<hoten;
        cout<<endl;
        cout<<"Que quan: "<<quequan<<endl;
        ngaysinh::xuat();
    }
    ~nguoi(){
        delete []hoten;
        delete []quequan;
        cout<<"Ham huy dc goi!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
    }
};
class thisinh : public nguoi{
    char* maso;
    float toan, li, hoa;
    public:
    thisinh(char* maso=0, float toan=0, float li=0, float hoa=0){
        this->maso=maso=new char [10];
        this->toan=toan;
        this->li=li;
         this->hoa=hoa;
    }
    // ~thisinh(){
    //     delete []maso;
    //     toan=0; li=0; hoa=0;
    // }
    void nhap(){
        nguoi::nhap();
        cout<<"Nhap ma so thi sinh: ";
        cin>>maso;
        cout<<"----------------------Nhap diem---------------------"<<endl;
        cout<<"Toan: ";cin>>toan;
        cout<<"Li: ";cin>>li;
        cout<<"Hoa: ";cin>>hoa;
    }
    void xuat(){
        nguoi::xuat();
        cout<<"Ma so thi sinh: "<<maso<<endl;
        cout<<"-------------------------Diem thi-------------------"<<endl;
        cout<<"Toan: "<<toan<<"               Li: "<<li<<"            Hoa: "<<hoa<<endl;
    }
    float tongdiem(){
        return (toan+li+hoa);
    }

};
void swap(thisinh& s1, thisinh& s2){
    thisinh stemp;
    stemp=s1;
    s1=s2;
    s2=stemp;
}
bool cpm(thisinh a, thisinh b){
    return a.tongdiem()>b.tongdiem();
}


int main(){
    int n;
    cout<<"Nhap so luong thi sinh: ";cin>>n;
    thisinh *s=new thisinh [n];
    for(int i=0; i<n; i++){
        s[i].nhap();
    }
   /* for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(s[j].tongdiem()<s[j+1].tongdiem()) swap(s[j], s[j+1]);
        }
    }*/
    s[0].xuat();
    s[1].xuat();
    swap(s[0],s[1]);
   // sort(s, s+n, cpm);
    for(int i=0; i<n; i++){
        s[i].xuat();
    }
}