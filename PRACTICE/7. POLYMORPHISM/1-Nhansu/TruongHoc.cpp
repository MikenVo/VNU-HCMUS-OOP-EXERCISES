#include <iostream>
#include <string>
#include <vector>
#include "school.h"
using namespace std;

TruongHoc::~TruongHoc() {
    for (NhanVien* nv : dsns) {
        delete nv;
    }
    dsns.clear();
}

int TruongHoc::TimNhanVien(string ms) {
    for (int i = 0; i < dsns.size(); i++) {
        if (dsns[i]->LayMSNV() == ms) {
            cout << "Da tim ra nhan vien trong danh sach" << endl;
            return i;
        }
    }
    cout << "Khong tim ra nhan vien trong danh sach" << endl;
    return -1;
}

void TruongHoc::TimNhanVienLuongCao() {
    if (dsns.size() == 0) {
        cout << "Khong co nhan su de tim" << endl;
        return;
    }

    float luonglonnhat = dsns[0]->LayLuong();
    int index = 0;
    for (int i = 0; i < dsns.size(); i++) {
        if (dsns[i]->LayLuong() > luonglonnhat) {
            luonglonnhat = dsns[i]->LayLuong();
            index = i;
        }
    }

    cout << "Nhan vien co luong cao nhat" << endl; dsns[index]->InThongTin();
}

void TruongHoc::GiaoViecchoNhanVien(int index) {
    dsns[index]->GiaoViec();
}

void TruongHoc::ThemNhanSu(NhanVien* nvmoi) {
    if (nvmoi != nullptr) {
        dsns.push_back(nvmoi);
    }
}

void TruongHoc::XoaNhanVien() {
    if (dsns.empty()) {
        cout << "Danh sach nhan su hien dang rong!\n";
        return;
    }

    string msXoa;
    cout << "Nhap ma so nhan su can xoa: ";
    cin >> msXoa;
    cin.ignore(1000, '\n'); // Dọn sạch bộ nhớ đệm

    bool timThay = false;
    for (auto it = dsns.begin(); it != dsns.end(); ++it) {
        if ((*it)->LayMSNV() == msXoa) {
            delete *it;
            dsns.erase(it);

            cout << "=> Da xoa thanh cong nhan vien co MSNS: " << msXoa << endl;
            timThay = true;
            break;
        }
    }

    if (!timThay)
    {
        cout << "=> Khong tim thay nhan vien co MSNS: " << msXoa << endl;
    }
}

float TruongHoc::TinhTongLuong() {
	float tongLuong = 0.0f;

	for (int i = 0; i < dsns.size(); i++) {
		tongLuong += dsns[i]->LayLuong();
	}

	return tongLuong;
}

void TruongHoc::InDanhSachNhanSu() {
    if (dsns.size() == 0) {cout << "Chua co nhan su nao trong truong" << endl; return;}

    for (int i = 0; i < dsns.size(); i++) {
        dsns[i]->InThongTin();
    }
}

int TruongHoc::LaySoluongNhanSu() {
    return dsns.size();
}