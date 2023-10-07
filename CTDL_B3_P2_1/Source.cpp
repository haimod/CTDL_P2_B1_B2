#include<iostream>
#include<math.h>
using namespace std;
const int Max = 50;
typedef struct toado {
	int x;
	int y;
	
} TD;
typedef struct danhsach{
	int n;
	TD list[Max];
}ds;
void nhapN(ds& m) {
	cout << "\n nhap so luong diem: ";
	cin >> m.n;
}
void nhapTD(TD &a) {	
	cout << "\n nhap toa do x: ";
	cin >> a.x;
	cout << "\n nhap toa do y: ";
	cin >> a.y;
}
void xuatTD(TD a) {
		cout << endl;
		cout << "x: " << a.x;
		cout << endl;
		cout << "y: " << a.y;
}
void nhapDS(ds& x) {
	for (int i = 0; i < x.n; i++) {
		cout << "\n toa do diem thu " << i+1 << endl;
		nhapTD(x.list[i]);
	}
}
void xuatDS(ds x) {
	for (int i = 0; i < x.n; i++) {
		cout << "\n toa do " << i+1 << " :";
		xuatTD(x.list[i]);
	}
}
float khoangcach(TD& a, TD& b) {
	/*cout << "\n nhap toa do A: ";
	nhapTD(a);
	cout << "\n nhap toa do B: ";
	nhapTD(b);*/
	float k = sqrt(pow((b.x - a.x),2) + pow((b.y - a.y),2));
	return k;
}
void khoangcach_ij(ds& m) {
	int k, t; 
		TD g;
		TD h;
	cout << "\n nhap vao vi tri i : ";
	cin >> k;
	for (int i = 0; i < m.n; i++) {
		if (i == k) {
			/*g.x = m.list[i].x;
			g.y = m.list[i].y;*/
			g = m.list[i];
			break;
		}
	}
	cout << "\n nhap vao vi tri j : ";
	cin >> t;
	for (int j = 0; j < m.n; j++) {
		if (t == j) {
			/*h.x = m.list[j].x;
			h.y = m.list[j].y;*/
			h = m.list[j];
			break;
		}
	}
	cout << "\n khoang cach cua i va j : " << khoangcach(g, h);
}
bool KT(TD& a, TD& b, TD& c) {
	float x = abs(khoangcach(a, b));
	float y = abs(khoangcach(b, c));
	float z = abs(khoangcach(c, a));
	if (x + y < z || y + z < x || x + z < y) {
		return false;
	}
	return true;
}
int checkTamGiac(ds m) {
	int k, t,o;
	TD g;
	TD h;
	TD l;
	cout << "\n nhap vao vi tri i : ";
	cin >> k;
	for (int i = 0; i < m.n; i++) {
		if (i == k) {
			/*g.x = m.list[i].x;
			g.y = m.list[i].y;*/
			g = m.list[i];
			break;
		}
	}
	cout << "\n nhap vao vi tri j : ";
	cin >> t;
	for (int j = 0; j < m.n; j++) {
		if (t == j) {
			/*h.x = m.list[j].x;
			h.y = m.list[j].y;*/
			h = m.list[j];
			break;
		}
	}
	cout << "\n nhap vao vi tri k : ";
	cin >> o;
	for (int k = 0; k < m.n; k++) {
		if (o == k) {
			l = m.list[k];
			break;
		}
	}
	if (KT(g, h, l)) {
		return 1;
	}
	return -0;
}
int main() {
	ds z;
	/*toado a;*/
	toado b;
	/*cout <<"\n khoang cach giua 2 diem A va B la: "<< khoangcach(a, b);*/
	nhapN(z);
	nhapDS(z);
	/*xuatDS(z);*/
	/*khoangcach_ij(z);*/
	cout << checkTamGiac(z);

	return 0;
}