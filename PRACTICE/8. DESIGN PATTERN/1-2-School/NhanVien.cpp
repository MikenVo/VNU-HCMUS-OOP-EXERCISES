#include <iostream>
#include <string>
#include <vector>
#include "school.h"
using namespace std;

// ===== Nhan vien =====
float NhanVien::LayLuong() {
	return luong;
}

void NhanVien::NhapThongTin(istream& is) {
	cout << "\n\n----- Nhap thong tin chung -----" << endl;
	cout << "Nhap ma so nhan su: ";
	getline(is, masons);
	cout << "Nhap ho va ten: ";
	getline(is, hoten);
	cout << "Nhap ngay sinh: ";
	getline(is, ngaysinh);
}

istream& operator>>(istream& is, NhanVien& nv) {
	nv.NhapThongTin(is);
	return is;
}

string NhanVien::LayMSNV() {
	return masons;
}





// ===== Giang vien =====
NhanVien* GiangVien::clone() const {
	return new GiangVien(*this);
}

bool GiangVien::KiemTraLoai(const std::string& loai) const {
	if (loai == "Giang vien" || loai == "giang vien" || loai == "Giang Vien" || loai == "GiangVien") {
		return true;
	}
	return false;
}

void GiangVien::TinhLuong() {
	int so_mon_giang_day = dshp.size();
	float result = (so_mon_giang_day * so_nam_giangday * 0.12) * 20000;
	luong = result;
}

void GiangVien::NhapThongTin(istream& is) {
	NhanVien::NhapThongTin(is);

	cout << "\n\n----- Nhap thong tin rieng cho giang vien -----\n";
	cout << "Nhap hoc ham hien tai: "; getline(is, hocham);
	cout << "Nhap hoc vi hien tai: "; getline(is, hocvi);
	cout << "Nhap so nam giang day: "; is >> so_nam_giangday;
	is.ignore(1000, '\n');

	int soLuongHP = 0;
	cout << "\n\nNhap so luong hoc phan dang dam nhiem: "; is >> soLuongHP;
	is.ignore(1000, '\n');

	dshp.clear();
	for (int i = 0; i < soLuongHP; ++i) {
		string hp;
		cout << "  + Hoc phan " << i + 1 << ": ";
		getline(is, hp);
		dshp.push_back(hp);
	}

	TinhLuong();
}

void GiangVien::InThongTin() {
	cout << "\n----- Thong tin giang vien -----" << endl;
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





// ===== Tro giang =====
NhanVien* TroGiang::clone() const {
	return new TroGiang(*this);
}

bool TroGiang::KiemTraLoai(const std::string& loai) const {
	if (loai == "Tro giang" || loai == "tro giang" || loai == "Tro Giang" || loai == "TroGiang") {
		return true;
	}
	return false;
}

void TroGiang::TinhLuong() {
	float result = (so_mon_trogiang * 0.3) * 18000;
	luong = result;
}

void TroGiang::NhapThongTin(istream& is) {
	NhanVien::NhapThongTin(is);

	cout << "\n\n----- Nhap thong tin rieng cho tro giang -----\n";
	cout << "Nhap so luong hoc phan dang tro giang: "; cin >> so_mon_trogiang;
	is.ignore(1000, '\n');
	TinhLuong();
}

void TroGiang::InThongTin() {
	cout << "\n----- Thong tin tro giang -----" << endl;
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






// ===== Nghien cuu vien =====
NhanVien* NghienCuuVien::clone() const {
	return new NghienCuuVien(*this);
}

bool NghienCuuVien::KiemTraLoai(const std::string& loai) const {
	if (loai == "Nghien cuu vien" || loai == "nghien cuu vien" || loai == "Nghien Cuu Vien" || loai == "NghienCuuVien") {
		return true;
	}
	return false;
}

void NghienCuuVien::TinhLuong() {
	unsigned int soduanD = 0;
	for (int i = 0; i < duanNC.size(); i++) {
		if (duanNC[i][0] == 'D') soduanD++;
	}

	float result = (so_nam_kinhnghiem * 2 + soduanD) * 20000;
	luong = result;
}

void NghienCuuVien::GiaoViec() {
	string maduan;
	cout << "Nhap ma du an ma nghien cuu vien dang lam (VD: D01, M02, E93): "; cin >> maduan;
	cin.ignore(1000, '\n');
	duanNC.push_back(maduan);
	TinhLuong();
}

void NghienCuuVien::NhapThongTin(istream& is) {
	NhanVien::NhapThongTin(is);

	cout << "\n\n----- Nhap thong tin rieng cho tro giang -----\n";
	cout << "Nhap so nam kinh nghiem: "; cin >> so_nam_kinhnghiem;
	unsigned int soduan;
	cout << "Nhap so du an da va dang lam: "; cin >> soduan;
	for (int i = 0; i < soduan; i++) {
		string maduan;
		cout << "Nhap ma du an nghien cuu vien dang lam (VD: D01, M02, E93): "; cin >> maduan;
		cin.ignore(1000, '\n');
		duanNC.push_back(maduan);
	}
	TinhLuong();
}

void NghienCuuVien::InThongTin() {
	cout << "\n----- Thong tin nghien cuu vien -----" << endl;
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





// ===== Chuyen vien =====
NhanVien* ChuyenVien::clone() const {
	return new ChuyenVien(*this);
}

bool ChuyenVien::KiemTraLoai(const std::string& loai) const {
	if (loai == "Chuyen vien" || loai == "chuyen vien" || loai == "Chuyen Vien" || loai == "ChuyenVien") {
		return true;
	}
	return false;
}

void ChuyenVien::TinhLuong() {
	unsigned int soduanT = 0;
	for (int i = 0; i < duanGD.size(); i++) {
		if (duanGD[i][0] == 'T') soduanT++;
	}

	float result = (so_nam_kinhnghiem * 4 + soduanT) * 18000;
	luong = result;
}

void ChuyenVien::GiaoViec() {
	string maduan;
	cout << "Nhap ma du an ma chuyen vien dang lam (VD: D01, M02, E93): "; cin >> maduan;
	cin.ignore(1000, '\n');
	duanGD.push_back(maduan);
	TinhLuong();
}

void ChuyenVien::NhapThongTin(istream& is) {
	NhanVien::NhapThongTin(is);

	cout << "\n\n----- Nhap thong tin rieng cho tro giang -----\n";
	cout << "Nhap so nam kinh nghiem: ";
	cin >> so_nam_kinhnghiem;
	unsigned int soduan;
	cout << "Nhap so du an da va dang lam: ";
	cin >> soduan;
	for (int i = 0; i < soduan; i++)
	{
		string maduan;
		cout << "Nhap ma du an nghien cuu vien dang lam (VD: D01, M02, E93): ";
		cin >> maduan;
		cin.ignore(1000, '\n');
		duanGD.push_back(maduan);
	}
	TinhLuong();
}

void ChuyenVien::InThongTin() {
	cout << "\n----- Thong tin chuyen vien -----" << endl;
	cout << "Ho va ten: " << hoten << endl;
	cout << "Ngay thang nam sinh (DD/MM/YYYY): " << ngaysinh << endl;
	cout << "Ma so nhan su: " << masons << endl;
	TinhLuong();
	cout << "Luong hien tai: " << luong << endl;
	cout << "So nam kinh nghiem: " << so_nam_kinhnghiem << endl;
	cout << "Danh sach du an: " << duanGD.size() << endl;
	for (int i = 0; i < duanGD.size(); i++) {
		cout << "    " << i + 1 << ". " << duanGD[i] << endl;
	}
}





// ===== Thuc tap sinh =====
NhanVien* ThucTapSinh::clone() const {
	return new ThucTapSinh(*this);
}

bool ThucTapSinh::KiemTraLoai(const std::string& loai) const {
	if (loai == "Thuc tap sinh" || loai == "thuc tap sinh" || loai == "Thuc Tap Sinh" || loai == "ThucTapSinh") {
		return true;
	}
	return false;
}

void ThucTapSinh::TinhLuong() {
	unsigned int tong_so_duanDB = duanDB.size();
	float result = 0.10f * tong_so_duanDB * 10000;
	luong = result;
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

void ThucTapSinh::NhapThongTin(istream& is) {
	NhanVien::NhapThongTin(is);

	cout << "\n\n----- Nhap thong tin rieng cho tro giang -----\n";
	cout << "Nhap so thang thuc tap: ";
	cin >> so_thang_thuc_tap;
	unsigned int soduan;
	cout << "Nhap so du an da va dang lam: ";
	cin >> soduan;
	for (int i = 0; i < soduan; i++) {
		string maduan;
		cout << "Nhap ma du an nghien cuu vien dang lam (VD: D01, M02, E93): ";
		cin >> maduan;
		cin.ignore(1000, '\n');
		duanDB.push_back(maduan);
	}
	TinhLuong();
}

void ThucTapSinh::InThongTin() {
	cout << "\n----- Thong tin thuc tap sinh -----" << endl;
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