#include <iostream>
#include "NhanVien.h"
#include <string>
using namespace std;

// Setters
void NhanVien::NhapTen(string s) {
    this->hoten = s;
}

void NhanVien::NhapSoNgay(int so_ngay) {
    this->so_ngay = so_ngay;
}

void NhanVien::GanChucDanh() {
    int so_ngay = this->so_ngay;
    if (so_ngay >= 0 && so_ngay <= 365) {
        this->chuc_danh = "Nhân viên";
    }
    else if (so_ngay > 365 && so_ngay <= 730) {
        this->chuc_danh = "Quản lý";
    }
    else if (so_ngay > 730 && so_ngay <= 1460) {
        this->chuc_danh = "Trưởng phòng";
    }
    else if (so_ngay > 1460) {
        this->chuc_danh = "Trưởng ban quản lý";
    }
}

void NhanVien::GanTenGoi() {
    string chuc_danh = this->chuc_danh;
    string hoten = this->hoten;
    int pos = 0;
    for (int i = hoten.size() - 1; i >= 0; i--) {
        if (hoten[i] == ' ') {
            pos = i;
            break;
        }
    }

    string name = hoten.substr(pos);
    if (pos != 0) {
        this->ten_goi = chuc_danh + name;
    }
    else {
        this->ten_goi = chuc_danh + " " + name;
    }
}

void NhanVien::GanHesoluong() {
    string chuc_danh = this->chuc_danh;
    if (chuc_danh == "Nhân viên") {
        this->hesoluong = 1.0;
    }
    else if (chuc_danh == "Quản lý") {
        this->hesoluong = 1.5;
    }
    else if (chuc_danh == "Trưởng phòng") {
        this->hesoluong = 2.25;
    }
    else if (chuc_danh == "Trưởng ban quản lý") {
        this->hesoluong = 4.0;
    }
}

// Getter
string NhanVien::XuatTen() {
    return this->hoten;
}

int NhanVien::Xuatso_ngay() {
    return this->so_ngay;
}

string NhanVien::Xuatchuc_danh() {
    return this->chuc_danh;
}

string NhanVien::Xuatten_goi() {
    return this->ten_goi;
}

float NhanVien::XuatHesoluong() {
    return this->hesoluong;
}

// Input/Output
void NhanVien::Nhap() {
    cout << "Nhập họ tên: ";
    getline(cin, hoten);
    cout << "Nhập số ngày làm việc: ";
    cin >> so_ngay;

    // Gọi các hàm nội bộ để tự động tính toán dữ liệu phái sinh
    GanChucDanh();
    GanTenGoi();
    GanHesoluong();
}

void NhanVien::Xuat() {
    cout << "----Thông tin nhân viên----" << endl;
    cout << "Họ và tên: " << hoten << endl;
    cout << "Số ngày làm: " << so_ngay << endl;
    cout << "Chức danh: " << chuc_danh << endl;
    cout << "Tên gọi: " << ten_goi << endl;
    cout << "Hệ số lương: " << hesoluong << endl;
}