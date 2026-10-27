#include <iostream>
#include <vector>
#include <string>
#include "initial.h"
using namespace std;

// ===== Hoc phan =====
string HocPhan::LayTenHocPhan() {
    return tenhocphan;
}

int HocPhan::LaySotinchi() {
    return sotinchi;
}

istream &operator>>(istream &is, HocPhan &hp) {
    cout << "Nhap ten hoc phan: ";
    is >> ws;
    getline(is, hp.tenhocphan);
    cout << "Nhap so tin chi: ";
    is >> hp.sotinchi;
    return is;
}

ostream &operator<<(ostream &os, const HocPhan &hp) {
    os << "Ten hoc phan: " << hp.tenhocphan << endl;
    os << "So tin chi: " << hp.sotinchi << endl;
    return os;
}

// ===== Nhan vien =====
float NhanVien::LayLuong() {
    return luong;
}

istream &operator>>(istream &is, NhanVien &nv) {
    cout << "Nhap ho va ten: ";
    is >> ws;
    getline(is, nv.hoten);
    cout << "Nhap ngay sinh (DD/MM/YYYY): ";
    is >> ws;
    getline(is, nv.ngaysinh);
    cout << "Nhap ma so nhan su: ";
    is >> ws;
    getline(is, nv.maso);
    return is;
}

ostream &operator<<(ostream &os, const NhanVien &nv) {
    os << "Ho va ten: " << nv.hoten << endl;
    os << "Ngay sinh: " << nv.ngaysinh << endl;
    os << "Ma so nhan su: " << nv.maso << endl;
    os << "Luong hien tai: " << nv.luong << endl;
    return os;
}

// ===== Giang vien =====
void GiangVien::ThemHocPhan(HocPhan hp) {
    dshp.push_back(hp);
}

void GiangVien::tinhLuong() {
    if (dshp.empty()) {
        luong = 0;
    }
    else {
        int soMonDay = dshp.size();
        luong = (soMonDay * sonamday * 0.12) * 20000;
    }
}

void GiangVien::XuatThongtin() {
    cout << "\n===== Thong tin nhan su =====" << endl;
    cout << "Ho va ten: " << hoten << endl;
    cout << "Ngay sinh: " << ngaysinh << endl;
    cout << "Ma so nhan su: " << maso << endl;
    cout << "Luong hien tai: " << luong << endl;
    cout << "Hoc ham: " << hocham << endl;
    cout << "Hoc vi: " << hocvi << endl;
    cout << "So nam day: " << sonamday << endl;
    cout << "--- Danh sach mon day ---" << endl;
    for (int i = 0; i < dshp.size(); i++) {
        cout << i + 1 << ". " << dshp[i].LayTenHocPhan() << endl;
    }
}

istream &operator>>(istream &is, GiangVien &gv) {
    is >> static_cast<NhanVien &>(gv);
    cout << "Nhap hoc ham: ";
    is >> ws;
    getline(is, gv.hocham);
    cout << "Nhap hoc vi: ";
    getline(is, gv.hocvi);
    cout << "Nhap so nam day: ";
    is >> gv.sonamday;

    int soMon;
    cout << "Nhap so luong mon day: ";
    is >> soMon;
    gv.dshp.clear();
    for (int i = 0; i < soMon; i++) {
        HocPhan hp;
        cout << "--- Nhap mon thu " << i + 1 << " ---" << endl;
        is >> hp;
        gv.ThemHocPhan(hp);
    }
    return is;
}

ostream &operator<<(ostream &os, const GiangVien &gv) {
    os << "\n===== Thong tin nhan su =====" << endl;
    os << "Ho va ten: " << gv.hoten << endl;
    os << "Ngay sinh: " << gv.ngaysinh << endl;
    os << "Ma so nhan su: " << gv.maso << endl;
    os << "Luong hien tai: " << gv.luong << endl;
    os << "Hoc ham: " << gv.hocham << endl;
    os << "Hoc vi: " << gv.hocvi << endl;
    os << "So nam day: " << gv.sonamday << endl;
    os << "So mon day: " << gv.dshp.size() << endl;
    return os;
}

// ===== Tro giang =====
void TroGiang::tinhLuong() {
    if (somontrogiang == 0) {
        luong = 0;
    }
    else {
        luong = (somontrogiang * 0.3) * 18000;
    }
}

void TroGiang::XuatThongtin() {
    cout << "\n===== Thong tin nhan su =====" << endl;
    cout << "Ho va ten: " << hoten << endl;
    cout << "Ngay sinh: " << ngaysinh << endl;
    cout << "Ma so nhan su: " << maso << endl;
    cout << "Luong hien tai: " << luong << endl;
    cout << "So mon tro giang: " << somontrogiang << endl;
}

istream &operator>>(istream &is, TroGiang &tg) {
    is >> static_cast<NhanVien &>(tg);
    cout << "Nhap so mon tro giang: ";
    is >> tg.somontrogiang;
    return is;
}

ostream &operator<<(ostream &os, const TroGiang &tg) {
    os << "\n===== Thong tin nhan su =====" << endl;
    os << "Ho va ten: " << tg.hoten << endl;
    os << "Ngay sinh: " << tg.ngaysinh << endl;
    os << "Ma so nhan su: " << tg.maso << endl;
    os << "Luong hien tai: " << tg.luong << endl;
    os << "So mon tro giang: " << tg.somontrogiang << endl;
    return os;
}

// ===== Nghien cuu vien =====
void NghienCuuVien::ThemDuAnNghienCuu(string maduan) {
    dsdl.push_back(maduan);
}

void NghienCuuVien::tinhLuong() {
    if (dsdl.empty()) {
        luong = 0;
    }
    else {
        int num = 0;
        for (int i = 0; i < dsdl.size(); i++) {
            if (!dsdl[i].empty() && dsdl[i][0] == 'D') {
                num++;
            }
        }
        luong = (sonamlam * 2 + num) * 20000;
    }
}

void NghienCuuVien::XuatThongtin() {
    cout << "\n===== Thong tin nhan su =====" << endl;
    cout << "Ho va ten: " << hoten << endl;
    cout << "Ngay sinh: " << ngaysinh << endl;
    cout << "Ma so nhan su: " << maso << endl;
    cout << "Luong hien tai: " << luong << endl;
    cout << "--- Danh sach du an ---" << endl;
    for (int i = 0; i < dsdl.size(); i++) {
        cout << i + 1 << ". " << dsdl[i] << endl;
    }
}

istream &operator>>(istream &is, NghienCuuVien &ncv) {
    is >> static_cast<NhanVien &>(ncv);
    cout << "Nhap so nam kinh nghiem: ";
    is >> ncv.sonamlam;

    int soDuAn;
    cout << "Nhap so luong du an tham gia: ";
    is >> soDuAn;
    ncv.dsdl.clear();
    for (int i = 0; i < soDuAn; i++) {
        string maDA;
        cout << "Nhap ma du an thu " << i + 1 << ": ";
        is >> ws;
        getline(is, maDA);
        ncv.ThemDuAnNghienCuu(maDA);
    }
    return is;
}

ostream &operator<<(ostream &os, const NghienCuuVien &ncv) {
    os << "\n===== Thong tin nhan su =====" << endl;
    os << "Ho va ten: " << ncv.hoten << endl;
    os << "Ngay sinh: " << ncv.ngaysinh << endl;
    os << "Ma so nhan su: " << ncv.maso << endl;
    os << "Luong hien tai: " << ncv.luong << endl;
    os << "So nam kinh nghiem: " << ncv.sonamlam << endl;
    os << "So du an tham gia: " << ncv.dsdl.size() << endl;
    return os;
}

// ===== Chuyen vien =====
void ChuyenVien::tinhLuong() {
    if (dsht.empty()) {
        luong = 0;
    }
    else {
        int num = 0;
        for (int i = 0; i < dsht.size(); i++) {
            if (!dsht[i].empty() && dsht[i][0] == 'T') {
                num++;
            }
        }
        luong = (sonamlam * 4 + num) * 18000;
    }
}

void ChuyenVien::XuatThongtin() {
    cout << "\n===== Thong tin nhan su =====" << endl;
    cout << "Ho va ten: " << hoten << endl;
    cout << "Ngay sinh: " << ngaysinh << endl;
    cout << "Ma so nhan su: " << maso << endl;
    cout << "Luong hien tai: " << luong << endl;
    cout << "--- Danh sach du an da hoan thanh ---" << endl;
    for (int i = 0; i < dsht.size(); i++) {
        cout << i + 1 << ". " << dsht[i] << endl;
    }
}

istream &operator>>(istream &is, ChuyenVien &cv) {
    is >> static_cast<NhanVien &>(cv);
    cout << "Nhap so nam kinh nghiem: ";
    is >> cv.sonamlam;

    int soDuAn;
    cout << "Nhap so luong du an hoan thanh: ";
    is >> soDuAn;
    cv.dsht.clear();
    for (int i = 0; i < soDuAn; i++) {
        string maDA;
        cout << "Nhap ma du an thu " << i + 1 << ": ";
        is >> ws;
        getline(is, maDA);
        cv.dsht.push_back(maDA);
    }
    return is;
}

ostream &operator<<(ostream &os, const ChuyenVien &cv) {
    os << "\n===== Thong tin nhan su =====" << endl;
    os << "Ho va ten: " << cv.hoten << endl;
    os << "Ngay sinh: " << cv.ngaysinh << endl;
    os << "Ma so nhan su: " << cv.maso << endl;
    os << "Luong hien tai: " << cv.luong << endl;
    os << "So nam kinh nghiem: " << cv.sonamlam << endl;
    os << "So du an hoan thanh: " << cv.dsht.size() << endl;
    return os;
}

// ===== Truong hoc =====
void TruongHoc::ThemNhanSu(NhanVien *nvMoi) {
    dsNhansu.push_back(nvMoi);
}

void TruongHoc::XuatDanhSach() {
    for (int i = 0; i < dsNhansu.size(); i++) {
        dsNhansu[i]->XuatThongtin();
    }
}

float TruongHoc::tinhTongLuong() {
    float tong = 0;
    for (int i = 0; i < dsNhansu.size(); i++) {
        dsNhansu[i]->tinhLuong();
        tong += dsNhansu[i]->LayLuong();
    }
    return tong;
}

TruongHoc::~TruongHoc() {
    for (int i = 0; i < dsNhansu.size(); i++) {
        delete dsNhansu[i];
    }
    dsNhansu.clear();
}