#include <iostream>

using namespace std;

class diem{
    int x, y;
    public:
    diem(int x=0, int y=0){
        this->x=x;
        this->y=y;
    }
    void nhap(){
        cout<<"Nhap hoanh do: ";cin>>x;
        cout<<"Nhap tung do: ";cin>>y;
    }
    void xuat(){
        cout<<"(x,y)=("<<x<<","<<y<<")"<<endl;
    }
    int gethd(){
        return x;
    }
    int gettd(){
        return y;
    }
    void putpixle(int x, int y, int);

};
int main(){
    diem s;
    s.nhap();
    s.putpixle(s.gethd(), s.gettd(), WHITE);

}