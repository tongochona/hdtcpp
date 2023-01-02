#include <iostream>
using namespace std;

class thongtin{
    char* ten;
    int tuoi;
    char* cccd;
    char* quequan;
    public:
    thongtin(char* ten=0, int tuoi=0, char* cccd=0, char* quequan=0){
        this->ten=ten;
        this->tuoi=tuoi;
        this->cccd=cccd;
        this->quequan=quequan;
    }
    void nhap(){
        ten= new char [20];
        cout<<"Nhap ten: ";
        cin.ignore();
        cin.getline(ten,20);

    }
    ~thongtin(){
        delete []ten;
        cout<<"Ham huy ddc goij!";
    }
};
int main(){
    thongtin nguoi1;
    nguoi1.nhap();
}