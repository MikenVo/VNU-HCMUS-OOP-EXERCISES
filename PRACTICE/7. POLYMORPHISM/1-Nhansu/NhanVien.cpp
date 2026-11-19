#include <iostream>
#include <string>
#include <vector>
#include "school.h"
using namespace std;

// ===== Nhan vien =====
void NhanVien::GanLuong(float luongmoi) {
	luong = luongmoi;
}

float NhanVien::LayLuong() {
	return luong;
}

istream& operator>>(istream& is, NhanVien& nv) {
	cout << "\n\n----- Thong tin ca nhan -----" << endl;
	cout << "Nhap ho va ten: "; getline(is, nv.hoten);
	cout << "Nhap ngay sinh (DD/MM/YYYY): "; is >> nv.ngaysinh;
	cout << "Nhap ma so nhan su: "; is >> nv.masons;
	is.ignore(1000, '\n');
	cout << endl;
	return is;
}

string NhanVien::LayMSNV() {
	return masons;
}

NhanVien::~NhanVien() {}





// ===== Giang vien =====
void GiangVien::TinhLuong() {
	int so_mon_giang_day = dshp.size();
	float result = (so_mon_giang_day * so_nam_giangday * 0.12) * 20000;
	GanLuong(result);
}

istream& operator>>(istream& is, GiangVien& gv) {
	is >> static_cast<NhanVien&>(gv);
	cout << "\n----- Nhap thong tin rieng cho giang vien -----" << endl;
	cout << "Nhap hoc ham hien tai: "; getline(is, gv.hocham);
	cout << "Nhap hoc vi hien tai: "; getline(is, gv.hocvi);
	cout << "Nhap so nam giang day: "; is >> gv.so_nam_giangday;
	is.ignore(1000, '\n');

	return is;
}

void GiangVien::InThongTin() {
	cout << "\n\n----- Thong tin giang vien -----" << endl;
	cout << "Ho va ten: " << hoten << endl;
	cout << "Ngay thang nam sinh (DD/MM/YYYY): " << ngaysinh << endl;
	cout << "Ma so nhan su: " << masons << endl;
	cout << "Luong hien tai: " << luong << endl;
	cout << "Hoc ham hien tai: " << hocham << endl;
	cout << "Hoc vi hien tai: " << hocvi << endl;
	cout << "So nam giang day: " << so_nam_giangday << endl;
	cout << "Danh sach hoc phan: " << dshp.size() << endl;
	for (int i = 0; i < dshp.size(); i++) {
		cout << "    " << i + 1 << ". " << dshp[i] << endl;
	}
}

void GiangVien::GiaoViec() {
	string tenhp;
	cout << "Nhap ten hoc phan: "; getline(cin, tenhp);

	for (int i = 0; i < dshp.size(); i++) {
		if (dshp[i] == tenhp) {
			cout << "Giang vien nay dang dam nhan hoc phan nay" << endl;
			return;
		}
	}
	dshp.push_back(tenhp);
	cout << "Da them hoc phan thanh cong" << endl;
	TinhLuong();
}

GiangVien::~GiangVien() {}





// ===== Tro giang =====
void TroGiang::TinhLuong() {
	float result = (so_mon_trogiang * 0.3) * 18000;
	GanLuong(result);
}

istream& operator>>(istream& is, TroGiang& tg) {
	is >> static_cast<NhanVien&>(tg);
	cout << "\n----- Nhap thong tin rieng cho tro giang -----" << endl;
	cout << "Nhap so mon tro giang: "; is >> tg.so_mon_trogiang;
	return is;
}

void TroGiang::InThongTin() {
	cout << "\n\n----- Thong tin tro giang -----" << endl;
	cout << "Ho va ten: " << hoten << endl;
	cout << "Ngay thang nam sinh (DD/MM/YYYY): " << ngaysinh << endl;
	cout << "Ma so nhan su: " << masons << endl;
	cout << "Luong hien tai: " << luong << endl;
	cout << "So mon tro giang: " << so_mon_trogiang << endl;
}

void TroGiang::GiaoViec() {
	unsigned int so_mon_them;
	cout << "Co them bao nhieu mon tro giang nay se dam nhan? ";
	cin >> so_mon_them;
	cin.ignore(1000, '\n');
	so_mon_trogiang += so_mon_them;
	TinhLuong();
}

TroGiang::~TroGiang() {}






// ===== Nghien cuu vien =====
void NghienCuuVien::TinhLuong() {
	unsigned int soduanD = 0;
	for (int i = 0; i < duanNC.size(); i++) {
		if (duanNC[i][0] == 'D') soduanD++;
	}

	float result = (so_nam_kinhnghiem * 2 + soduanD) * 20000;
	GanLuong(result);
}

void NghienCuuVien::GiaoViec() {
	string maduan;
	cout << "Nhap ma du an ma nghien cuu vien dang lam (VD: D01, M02, E93): "; cin >> maduan;
	cin.ignore();
	duanNC.push_back(maduan);
	TinhLuong();
}

istream& operator>>(istream& is, NghienCuuVien& ncv) {
	is >> static_cast<NhanVien&>(ncv);
	cout << "\n----- Nhap thong tin rieng cho nghien cuu vien -----" << endl;
	cout << "Nhap so nam kinh nghiem: "; is >> ncv.so_nam_kinhnghiem;
	is.ignore();

	return is;
}

void NghienCuuVien::InThongTin() {
	cout << "\n\n----- Thong tin nghien cuu vien -----" << endl;
	cout << "Ho va ten: " << hoten << endl;
	cout << "Ngay thang nam sinh (DD/MM/YYYY): " << ngaysinh << endl;
	cout << "Ma so nhan su: " << masons << endl;
	cout << "Luong hien tai: " << luong << endl;
	cout << "So nam kinh nghiem: " << so_nam_kinhnghiem << endl;
	cout << "Danh sach du an: " << duanNC.size() << endl;
	for (int i = 0; i < duanNC.size(); i++) {
		cout << "    " << i + 1 << ". " << duanNC[i] << endl;
	}
}

NghienCuuVien::~NghienCuuVien() {}





// ===== Chuyen vien =====
void ChuyenVien::TinhLuong() {
	unsigned int soduanT = 0;
	for (int i = 0; i < duanGD.size(); i++) {
		if (duanGD[i][0] == 'T') soduanT++;
	}

	float result = (so_nam_kinhnghiem * 4 + soduanT) * 18000;
	GanLuong(result);
}

void ChuyenVien::GiaoViec() {
	string maduan;
	cout << "Nhap ma du an ma chuyen vien dang lam (VD: D01, M02, E93): "; cin >> maduan;
	cin.ignore(1000, '\n');
	duanGD.push_back(maduan);
	TinhLuong();
}

istream& operator>>(istream& is, ChuyenVien& cv) {
	is >> static_cast<NhanVien&>(cv);
	cout << "\n----- Nhap thong tin rieng cho chuyen vien -----" << endl;
	cout << "Nhap so nam kinh nghiem: "; is >> cv.so_nam_kinhnghiem;
	is.ignore(1000, '\n');
	return is;
}

void ChuyenVien::InThongTin() {
	cout << "\n\n----- Thong tin chuyen vien -----" << endl;
	cout << "Ho va ten: " << hoten << endl;
	cout << "Ngay thang nam sinh (DD/MM/YYYY): " << ngaysinh << endl;
	cout << "Ma so nhan su: " << masons << endl;
	cout << "Luong hien tai: " << luong << endl;
	cout << "So nam kinh nghiem: " << so_nam_kinhnghiem << endl;
	cout << "Danh sach du an: " << duanGD.size() << endl;
	for (int i = 0; i < duanGD.size(); i++) {
		cout << "    " << i + 1 << ". " << duanGD[i] << endl;
	}
}

ChuyenVien::~ChuyenVien() {}





void ThucTapSinh::TinhLuong() {
	unsigned int tong_so_duanDB = duanDB.size();
	float result = 0.10f * tong_so_duanDB * 10000;
	GanLuong(result);
}

void ThucTapSinh::GiaoViec() {
	string maduan;
	
	while (true) {
		cout << "Nhap ma du an du bi ma thuc tap sinh dang lam. Bat buoc phai la du an 'R' (VD: R01, R02, R93): "; cin >> maduan;
		cin.ignore(1000, '\n');

		if (maduan[0] == 'R') {
			duanDB.push_back(maduan);
			cout << "Da them du an thanh cong" << endl;
			break;
		}
		else {
			cout << "Ma du an khong hop le" << endl;
		}
	}
	TinhLuong();
}

istream& operator>>(istream& is, ThucTapSinh& tts) {
	is >> static_cast<NhanVien&>(tts);
	cout << "\n----- Nhap thong tin cho thuc tap sinh -----" << endl;
	cout << "Nhap vao so nam thuc tap: "; is >> tts.so_thang_thuc_tap;
	is.ignore(1000, '\n');
	return is;
}

void ThucTapSinh::InThongTin() {
	cout << "\n\n----- Thong tin thuc tap sinh -----" << endl;
	cout << "Ho va ten: " << hoten << endl;
	cout << "Ngay thang nam sinh (DD/MM/YYYY): " << ngaysinh << endl;
	cout << "Ma so nhan su: " << masons << endl;
	cout << "Luong hien tai: " << luong << endl;
	cout << "So thang thuc tap: " << so_thang_thuc_tap << endl;
	cout << "Danh sach du an: " << duanDB.size() << endl;
	for (int i = 0; i < duanDB.size(); i++) {
		cout << "    " << i + 1 << ". " << duanDB[i] << endl;
	}
}

ThucTapSinh::~ThucTapSinh() {}