#pragma once
#include <iostream>
#include <vector>
#include "account.h"

class AppMusic {
private:
    std::vector<BaiHat*> DanhSachToanBoBaiHat;
    std::vector<TaiKhoan*> DanhSachTaiKhoan;
    TaiKhoan *TaiKhoanHienTai = nullptr;

public:
    std::vector<BaiHat*> LayDanhSachBaiHat();
    TaiKhoan* LayTaiKhoanHienTai();
    int LaySoLuongBaiHat();
    void NhapDanhSachBaiHat();
    void XuatDanhSachBaiHat();
    void BXHTop5();
    void DangKyTaiKhoan();
    bool DangNhap();
    void ChayUngDung();

    ~AppMusic();
};