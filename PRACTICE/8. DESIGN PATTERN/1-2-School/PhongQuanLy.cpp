#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "school.h"
using namespace std;

PhongQuanLy* PhongQuanLy::instance = nullptr;

PhongQuanLy* PhongQuanLy::GetInstance() {
	if (instance == NULL) {
		instance = new PhongQuanLy();
	}
	return instance;
}

void PhongQuanLy::DeleteInstance() {
	if (instance) {
		delete instance;
		instance = NULL;
	}
}

void PhongQuanLy::DangKyMau(NhanVien* mau) {
	if (mau != nullptr) {
		dsMau.push_back(mau);
	}
}

void PhongQuanLy::ThemNhanSuTheoLoai(const std::string& loai) {
	NhanVien* prototype = nullptr;
	for (NhanVien* mau : dsMau) {
		if (mau != nullptr && mau->KiemTraLoai(loai)) {
			prototype = mau;
			break;
		}
	}

	if (prototype == nullptr) {
		std::cout << "Khong tim thay mau nhan su: " << loai << endl;
		return;
	}

	NhanVien* nvmoi = prototype->clone();
	std::cin >> *nvmoi;
	nvmoi->TinhLuong();
	dsns.push_back(nvmoi);
	std::cout << "Them nhan su thanh cong!" << endl;
}

int PhongQuanLy::TimNhanVien(const std::string& maso) {
	for (size_t i = 0; i < dsns.size(); ++i) {
		if (dsns[i] != nullptr && dsns[i]->LayMSNV() == maso) {
			return static_cast<int>(i);
		}
	}
	return -1;
}

void PhongQuanLy::XoaNhanVien(const std::string& maSo) {
	int index = TimNhanVien(maSo);
	if (index == -1) {
		std::cout << "Khong tim thay nhan vien co ma so: " << maSo << endl;
		return;
	}

	delete dsns[index];
	dsns.erase(dsns.begin() + index);
	std::cout << "Da xoa nhan vien co ma so " << maSo << " thanh cong!" << endl;
}

void PhongQuanLy::GiaoViecchoNhanVien(int index) {
	if (index >= 0 && index < static_cast<int>(dsns.size()) && dsns[index] != nullptr) {
		dsns[index]->GiaoViec();
	}
	else {
		std::cout << "Khong tim ra nhan vien" << endl;
	}
}

float PhongQuanLy::TinhTongLuong() {
	double tong = 0.0;
	for (NhanVien* nv : dsns) {
		if (nv != nullptr) {
			tong += nv->LayLuong();
		}
	}
	return tong;
}

void PhongQuanLy::InDanhSachNhanSu() {
	if (dsns.empty()) {
		std::cout << "Danh sach nhan su hien dang trong!" << endl;
		return;
	}

	for (size_t i = 0; i < dsns.size(); ++i) {
		std::cout << "\n--- Nhan vien thu " << i + 1 << " ---" << endl;
		dsns[i]->InThongTin();
	}
}

int PhongQuanLy::LaySoluongNhanSu() {
	return static_cast<int>(dsns.size());
}

void PhongQuanLy::TimNhanVienLuongCao() {
	if (dsns.empty()) {
		std::cout << "Danh sach nhan su hien dang trong!" << endl;
		return;
	}

	float maxLuong = dsns[0]->LayLuong();
	for (NhanVien* nv : dsns) {
		if (nv != nullptr && nv->LayLuong() > maxLuong) {
			maxLuong = nv->LayLuong();
		}
	}

	std::cout << "===== Nhan vien co muc luong cao nhat (" << std::fixed << std::setprecision(0) << maxLuong << " VND) =====" << endl;
	for (NhanVien* nv : dsns) {
		if (nv != nullptr && nv->LayLuong() == maxLuong) {
			nv->InThongTin();
		}
	}
}

PhongQuanLy::~PhongQuanLy() {
	for (NhanVien* nv : dsns) {
		delete nv;
	}
	dsns.clear();

	for (NhanVien* mau : dsMau) {
		delete mau;
	}
	dsMau.clear();
}
