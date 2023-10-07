#include<iostream>
#include<string>
using namespace std;
const int Max = 100;
typedef struct KhachSan {
	char maPhong[5];
	char tenPhong[30];
	float donGia;
	int soLuong;
	bool tinhTrang;
} ks;
typedef struct DanhSach {
	int n;
	ks list[Max];
}ds;
void nhap_KS(ks& x) {
	cin.ignore();
	cout << "\n nhap ma phong: ";
	cin.getline(x.maPhong, 5);
	cout << "\n nhap ten phong: ";
	cin.getline(x.tenPhong, 30);
	cout << "\n nhap don gia: ";
	cin >> x.donGia;
	cout << "\n nhap so luong: ";
	cin >> x.soLuong;
	cout << "\n nhap tinh trang phong (0. khong , 1.co): ";
	cin >> x.tinhTrang;
	
}
void xuat_KS(ks x) {
	cout << "\n nhap thong tin khach: ";
	cout << "\n ma phong: " << x.maPhong;
	cout << "\n ten phong: " << x.tenPhong;
	cout << "\n don gia: " << x.donGia;
	cout << "\n so luong: " << x.soLuong;
	cout << "\n tinh trang phong: " << x.tinhTrang;
}
void nhap_ds(ds& x) {
	cout << "\n nhap so luong khach: ";
		cin >> x.n;
	for (int i = 0; i < x.n; i++) {
		cout << "\n Khach san " << i + 1 << ": ";
		nhap_KS(x.list[i]);
	}
}
void xuat_ds(ds x) {
	cout << "\n*******danh sach khach san***********";
	for (int i = 0; i < x.n; i++) {;
	cout << "\n khach san " << i + 1 ;
	xuat_KS(x.list[i]);
	}
}
void PhongChuaDat(ds &x){
	for (int i = 0; i < x.n; i++) {
		if (x.list[i].tinhTrang == 0) {
			cout << "\n ten phong: " << x.list[i].tenPhong;
			cout << "\n so luong: " << x.list[i].soLuong;
			cout << endl;
		}
	}
}
void giuongMax(ds& x) {
	ks max = x.list[0]; 
	for (int i = 1; i < x.n; i++) { 
		if (x.list[i].tinhTrang == 0 && x.list[i].soLuong > max.soLuong) {
			max = x.list[i]; 
		}
	}
	xuat_KS(max);
}
void DoiTen(ds& x) {
	char k[5],k1[30];
	cout << "\n nhap ma phong can thay doi ten: ";
	cin.ignore();
	cin.getline(k, 5);
	cout << "\n nhap ten phong can doi: ";
	cin.getline(k1, 30);
	for (int i = 0; i < x.n; i++) {
		if ( strcmp(x.list[i].maPhong,k) == 0) {
			strcpy_s(x.list[i].tenPhong,k1);
			xuat_KS(x.list[i]);
			break;
		}
		
	}
}
void TachP1(ds& x, ds& x1) {
	x1.n = 0;
	for (int i = 0; i < x.n; i++) {
		if (x.list[i].tinhTrang == 1) {
			x1.list[x1.n++] = x.list[i];
		}
	}
	xuat_ds(x1);
}
void xoaTrung(ds& x) {
	for (int i = 0; i < x.n - 1; i++) {
		for (int j = i + 1; j < x.n; j++) {
			if (strcmp(x.list[i].tenPhong, x.list[j].tenPhong) == 0) {
				for (int k = j; k < x.n-1; k++) {
					x.list[k] = x.list[k + 1];
				}
				x.n--;
				j--;
			}
		}
	}
	xuat_ds(x);
}
int main() {
	ds a,a1;
	nhap_ds(a);
	/*xuat_ds(a);*/
	/*PhongChuaDat(a);*/
	/*giuongMax(a);*/
	/*DoiTen(a);*/
	/*TachP1(a, a1);*/
	xoaTrung(a);
	return 0;
}