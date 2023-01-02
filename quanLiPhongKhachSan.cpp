#include <iostream>
#include <iomanip>
//#include <conio.h>
#include <stdio.h>
using namespace std;

class phongkhachsan {
	const int phongvip[40] = { 100, 101, 102, 103 ,104, 105, 106, 107, 108, 109, 110,
		111, 112 ,113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126,
		127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139 };


public:
	static int* p;
	int phong;
	phongkhachsan(int phong = 0) {
		p = new int[100];
		this->phong = phong;
	}
	void xuatphong();
	void traphong();
	void nhapphong();

};

void phongkhachsan::nhapphong() {
	cout << "Nhap phong: ";
lai:
	cin >> phong;
	if (phong < 100 || phong>139) {
		cout << "Khong co phong nay! Vui long nhap lai: ";
		goto lai;
	}
	phongkhachsan::p[phong - 100] = phong;

}

void phongkhachsan::xuatphong() {
	cout << "Cac phong con trong la: ";
	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 40; j++) {
			if (i == phongkhachsan::p[j] - 100) goto den;
		}
		cout << setw(5) << left << phongvip[i];
	den:;
	}
	cout << endl;
}
void phongkhachsan::traphong() {

	phongkhachsan::p[phong - 100] = 0;
}

class customer : public phongkhachsan
{
	char* ten;
	char* gt;
	char* birthday;//ngay sinh thay  tuoi
	char* cmnd;
	int id;
	char* sdt;//moi khach hang co 1 id rieng de quan li. id se la 1 day so. Ta lay id se la so dien thoai
public:
	static int stt;
	customer(char* ten = 0, char* gt = 0, char* birthday = 0, char* cmnd = 0, char* sdt = 0, int id = 0) {
		this->ten = ten;
		this->gt = gt;
		this->birthday = birthday;
		this->cmnd = cmnd;
		this->sdt = sdt;
		this->id = id;
	}
	void nhap();

	void themKH(int id);
	void capNhatInFo(int& n, customer cArr);
	void xoaKH();
	friend void find_Ten(customer kh, char* a, int& b);
	friend void find_SDT(customer kh, char* a, int& b);
	friend void xuattoanbo(customer cArr);
	friend void xuat(customer cArr);
	void press();
	static void doikitu(char& ch) {
		if (ch <= 'z' && ch >= 'a') ch = ch - 32;
	}// doi ki tu sang in hoa
	static void doichuoi(char* a) {
		int i = 0;
		while (a[i] != '\0') {
			doikitu(a[i]);
			i++;
		}
	}//doi ten sang in hoa
	//ham tim kiem ten
	static int tim(char* b, char* a) {

		doichuoi(b);
		int i = 0;
		while (b[i] != '\0') {
			i++;
			if (a[i] == b[i]) continue;
			else break;
		}
		if (b[i] == '\0') return 0;
		else return 1;
	}

};
int* phongkhachsan::p;
int customer::stt = 0;
void customer::nhap() {
	ten = new char[10];
	birthday = new char[20];
	gt = new char[10];
	cmnd = new char[15];
	sdt = new char[15];
	cin.ignore(10, '\n');
	cout << "Nhap ten khach hang: ";
	cin.getline(ten, 20);
	fflush(stdin);
	doichuoi(ten);
	cout << "Nhap so dien thoai: ";
	cin.getline(sdt, 15);
	fflush(stdin);
	cout << "Nhap gioi tinh: ";
	cin.getline(gt, 10);
	fflush(stdin);
	cout << "Nhap ngay/thang/nam sinh: ";
	cin.getline(birthday, 20);
	fflush(stdin);
	cout << "Nhap so CMND: ";
	cin.getline(cmnd, 15);
	fflush(stdin);
}
void customer::themKH(int stt) {
	cout << "Nhap khach hang thu " << stt + 1 << ":" << endl;
	nhap();
	id = stt + 1;
}

void customer::capNhatInFo(int& n, customer cArr) {

	if (n <= customer::stt)
	{
		xuat(cArr);
		cout << endl;
		cout << "-----Nhung muc co the cap nhat------\n";
		cout << "1.Cap nhat ten.\n";
		cout << "2.Cap nhat so dien thoai.\n";
		cout << "3.Cap nhat gioi tinh.\n";
		cout << "4.Cap nhat ngay sinh.\n";
		cout << "5.Cap nhat chung minh nhan dan.\n";
		cout << "6.Cap nhat phong.\n";
		cout << "Chon muc can cap nhat: ";
		int m;
		cin >> m;
		switch (m) {
		case 1:
			cout << "1.Cap nhat ten.\n";
			cout << "Nhap ten khach hang: ";
			cin.ignore();
			cin.getline(ten, 20);
			doichuoi(ten);
			break;
		case 2:
			cout << "2.Cap nhat so dien thoai.\n";
			cout << "Nhap so dien thoai: ";
			cin.ignore();
			cin.getline(sdt, 15);

			break;
		case 3:
			cout << "3.Cap nhat gioi tinh.\n";
			cout << "Nhap gioi tinh: ";
			cin.ignore();
			cin.getline(gt, 10);
			break;
		case 4:
			cout << "4.Cap nhat ngay sinh.\n";
			cout << "Nhap ngay/thang/nam sinh: ";
			cin.ignore();
			cin.getline(birthday, 20);
			break;
		case 5:
			cout << "4.Cap nhat CMND\n";
			cout << "Nhap CMND: ";
			cin.ignore();
			cin.getline(cmnd, 15);
			break;
		case 6:
			cout << "5. Cap nhat so phong.\n";
			cArr.traphong();
			cArr.xuatphong();
			cArr.nhapphong();
			break;
		default:
			break;
		}

		cout << "Cap nhat thong tin khach hang thanh cong!";
	}
	else cout << "Khach hang nay hien khong ton tai!";
}

void find_Ten(customer cArr, char* a, int& b) {

	int t;

	t = customer::tim(a, cArr.ten);
	if (t == 0) {
		xuat(cArr);
		b++;
	}
}

void find_SDT(customer cArr, char* a, int& b) {
	int t;

	t = customer::tim(a, cArr.sdt);
	if (t == 0) {
		xuat(cArr);
		b++;
	}
}

void customer::xoaKH() {
	traphong();
	delete[]ten;
	delete[]gt;
	delete[]birthday;
	delete[]cmnd;
	delete[]sdt;
	id = -1;
	cout << "Xoa khach hang thanh cong!\n";
}

void customer::press() {
	int m;
	cout << "\n\nNhap mot so bat ki de tiep tuc hoac 0 de ket thuc: ";
	cin >> m;
	if (m != 0) system("cls");
	if (m == 0) exit(0);
}
void xuat(customer cArr)
{
	cout << "============XUAT==============\n";
	cout << "Ten KH: " << cArr.ten << endl;
	cout << "So dien thoai: " << cArr.sdt << endl;
	cout << "Gioi tinh KH: " << cArr.gt << endl;
	cout << "Ngay sinh: " << cArr.birthday << endl;
	cout << "so CMND KH: " << cArr.cmnd << endl;
	cout << "So ID: " << cArr.id << endl;
	cout << "So phong: " << cArr.phong;
	cout << endl;
}
void xuattoanbo(customer cArr) {
	if (cArr.id >= 0) {

		cout << setw(4) << left << cArr.id << setw(20) << left << cArr.ten << setw(20) << left << cArr.sdt << setw(20) << left << cArr.gt
			<< setw(20) << left << cArr.birthday << setw(20) << left << cArr.cmnd << setw(20) << left << cArr.phong;

		cout << endl;
	}
}

int main()
{
	customer cArr[50];

	int key;

	while (true)
	{
		cout << "=========================================QUAN LY KHACH HANG=========================================\n";


		cout << "\n _______________________________ ";  cout << "\t"; cout << " ___________________________________ ";  cout << "\t"; cout << " __________________ ";
		cout << "\n|                               |";  cout << "\t"; cout << "|                                   |";  cout << "\t"; cout << "|                  |";
		cout << "\n|1.Them Khach Hang              |";  cout << "\t"; cout << "|4.Tim Khach Hang Theo Ten          |";  cout << "\t"; cout << "|7.Xuat khach hang |";
		cout << "\n|_______________________________|";  cout << "\t"; cout << "|___________________________________|";  cout << "\t"; cout << "|__________________|";

	    cout << "\n _______________________________ ";  cout << "\t"; cout << " ___________________________________ ";  cout << "\t"; cout << " __________________ ";
		cout << "\n|                               |";  cout << "\t"; cout << "|                                   |";  cout << "\t"; cout << "|                  |";
		cout << "\n|2.Cap Nhat Thong Tin Khach Hang|";  cout << "\t"; cout << "|5.Tim Khach Hang Theo So Dien Thoai|";  cout << "\t"; cout << "|0.Thoat           |";
		cout << "\n|_______________________________|";  cout << "\t"; cout << "|___________________________________|";  cout << "\t"; cout << "|__________________|";

		cout << "\n _______________________________ ";  cout << "\t"; cout << " ___________________________________ ";
		cout << "\n|                               |";  cout << "\t"; cout << "|                                   |";
		cout << "\n|3.Xoa Khach Hang               |";  cout << "\t"; cout << "|6.Tim Kiem Khach Hang Theo So Phong|";
		cout << "\n|_______________________________|";  cout << "\t"; cout << "|___________________________________|";

		cout << "\n\nNhap tuy chon: ";
		cin >> key;
		switch (key)
		{
		case 0:
			exit(0);
		case 1:
			cout << "\n1. Them khach hang.\n";
			cArr[customer::stt].themKH(customer::stt);
			cArr[customer::stt].xuatphong();
			cArr[customer::stt].nhapphong();
			customer::stt++;
			cout << "Them khach hang thanh cong!" << endl;
			cout << "So thu tu " << customer::stt << endl;
			cArr[customer::stt].press();
			break;
		case 2:
			cout << "\n2. Cap nhat thong tin khach hang\n";
			int n;
			cout << "Cap nhat thong tin khach hang thu: ";
			cin >> n;
			cArr[n - 1].capNhatInFo(n, cArr[n - 1]);
			cArr[n - 1].press();
			break;
		case 3:
			cout << "\n3. Xoa Khach Hang.\n";

			cout << "Nhap id khach hang muon xoa thong tin: ";
			cin >> n;
			cArr[n - 1].xoaKH();
			cArr[n - 1].press();
			break;
		case 4:
			char* a;
			int b;
			b = 0;
			a = new char[20];
			cout << "Nhap ten khach hang muon tim kiem: ";
			cin.ignore();
			cin.getline(a, 20);
			for (int i = 0; i < customer::stt; i++) {

				find_Ten(cArr[i], a, b);
			}
			cout << "Co " << b << " ket qua tim thay!" << endl;
			cArr[customer::stt].press();
			break;
		case 5:
			char* x;
			int y;
			y = 0;
			x = new char[20];
			cout << "Nhap so dien thoai khach hang muon tim kiem: ";
			cin >> x;
			for (int i = 0; i < customer::stt; i++) {

				find_SDT(cArr[i], x, y);
			}
			cout << "Co " << y << " ket qua tim thay!" << endl;
			cArr[customer::stt].press();
			break;
		case 6:
			int tp;
			cout << "Nhap phong tim kiem: ";
			cin >> tp;
			for (int i = 0; i < customer::stt; i++) {
				if (tp == cArr[i].phong)
					xuat(cArr[i]);
				else cout << "Hien Phong Nay Dang Trong.";
					break;

				if (i == customer::stt) cout << "Phong trong!";
			}
			cArr[customer::stt].press();
			break;
		case 7:

			cout << setw(4) << left << "Stt" << setw(20) << left << "Ten khach hang" << setw(20) << left << "So dien thoai" << setw(20) << left << "Gioi tinh"
				<< setw(20) << left << "Ngay sinh" << setw(20) << left << "So CMND" << setw(20) << left << "So Phong" << endl;
			for (int i = 0; i < customer::stt; i++) {
				xuattoanbo(cArr[i]);
			}
			cArr[customer::stt].press();
			break;
		default:
			break;
		}

	}
}
