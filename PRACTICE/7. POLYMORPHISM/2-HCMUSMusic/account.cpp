#include <iostream>
#include <string>
#include <vector>
#include "account.h"

bool TaiKhoan::KiemTraMatKhauHopLe(std::string pass) {
    if (pass.length() < 8) {
        return false;
    }
    for (int i = 0; i < pass.size(); i++) {
        if (isspace(pass[i])) {
            return false;
        }
    }
    return true;
}

void TaiKhoan::SetThongTinDangNhap(std::string u, std::string p) {
    TenDangNhap = u;
    MatKhau = p;
}

std::string TaiKhoan::GetTenDangNhap() const {
    return TenDangNhap;
}

std::string TaiKhoan::GetMatKhau() const {
    return MatKhau;
}

void TaiKhoan::InPlaylistCaNhan() {
    DanhSachNhacCaNhan.InPlaylist();
}

bool TaiKhoan::DangNhap() {
    std::string user, pass;
    std::cout << "===== DANG NHAP TAI KHOAN =====\n";
    std::cout << "Ten dang nhap: ";
    std::getline(std::cin, user);
    std::cout << "Mat khau: ";
    std::getline(std::cin, pass);

    if (user == TenDangNhap && KiemTraMatKhauHopLe(pass) && pass == MatKhau) {
        std::cout << "=> Dang nhap thanh cong! Xin chao " << TenDangNhap << "\n";
        return true;
    }

    std::cout << "=> Dang nhap thất bai! Sai ten dang nhap hoac mat khau.\n";
    return false;
}

void TaiKhoan::ThemVaoPlaylist(BaiHat *bh) {
    if (bh != nullptr) {
        DanhSachNhacCaNhan.ThemBaiHat(bh);
    }
}

void TaiKhoan::XoaKhoiPlaylist(std::string tenBH) {
    DanhSachNhacCaNhan.XoaBaiHat(tenBH);
}

void TaiKhoanThuong::NgheNhac(BaiHat *bh) {
    if (bh == nullptr) return;

    std::cout << "\n[DANG PHAT] Dang nghe bai hat: " << bh->LayTenBaiHat() << "\n";

    float giaTien = bh->TinhGiaTien(false);
    if (giaTien > 0) {
        std::cout << "Tai khoan dang su dung: Tai khoan thuong" << std::endl;
        std::cout << "Phi nghe bai hat: " << giaTien << " VND\n";
    }
    else {
        std::cout << "Phi nghe bai hat: mien phi" << std::endl;
    }
}

void TaiKhoanVip::NgheNhac(BaiHat *bh)
{
    if (bh == nullptr)
        return;

    std::cout << "\n[VIP][DANG PHAT] Dang nghe bai hat: " << bh->LayTenBaiHat() << "\n";

    // Tính tiền cho tài khoản VIP (isVip = true -> Giảm 50% tiền bản quyền)
    float giaTien = bh->TinhGiaTien(true);
    if (giaTien > 0)
    {
        std::cout << "Phi nghe bai hat (Da giam 50% cho VIP): " << giaTien << " VND\n";
    }
    else
    {
        std::cout << "Phi nghe bai hat: mien phi\n";
    }
}

void TaiKhoanVip::GoiYBaiHat(std::string theLoai, const std::vector<BaiHat *> &dsAll)
{
    std::cout << "\n===== Goi y bai hat HOT nhat theo the loai: " << theLoai << " =====\n";

    BaiHat *maxLuotNgheBH = nullptr;
    int maxLuotNghe = -1;

    for (int i = 0; i < dsAll.size(); i++) {
        if (dsAll[i] != nullptr && dsAll[i]->LayTheLoai() == theLoai) {
            if (dsAll[i]->LayLuotNghe() > maxLuotNghe) {
                maxLuotNghe = dsAll[i]->LayLuotNghe();
                maxLuotNgheBH = dsAll[i];
            }
        }
    }

    if (maxLuotNgheBH != nullptr) {
        std::cout << "Goi y HOT nhat danh cho ban:\n";
        maxLuotNgheBH->XuatThongTin();
    }
    else {
        std::cout << "Khong tim thay bai hat nao thuoc the loai: " << theLoai << "\n";
    }
}

void TaiKhoanVip::GiaHanTaiKhoan(double soTienNap) {
    if (MucPhiDuyTriHangThang <= 0) {
        std::cout << "Loi: Muc phi duy tri hang thang khong hop le!\n";
        return;
    }

    int soThangCongThem = static_cast<int>(soTienNap / MucPhiDuyTriHangThang);

    if (soThangCongThem > 0) {
        ThoiHanDuyTri += soThangCongThem;
        std::cout << "Nap tien thanh cong! Ban duoc gia han them " << soThangCongThem << " thang.\n";
        std::cout << "Thoi han duy tri tai khoan VIP hien tai: " << ThoiHanDuyTri << " thang.\n";
    }
    else {
        std::cout << "So tien nap khong du de gia han toi thieu 1 thang (Muc phi: " << MucPhiDuyTriHangThang << " VND/thang).\n";
    }
}