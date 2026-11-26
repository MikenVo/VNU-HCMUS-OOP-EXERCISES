#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "app.h"

int AppMusic::LaySoLuongBaiHat() {
    return DanhSachToanBoBaiHat.size();
}

std::vector<BaiHat*> AppMusic::LayDanhSachBaiHat() {
    return DanhSachToanBoBaiHat;
}

TaiKhoan* AppMusic::LayTaiKhoanHienTai() {
    return TaiKhoanHienTai;
}

void AppMusic::NhapDanhSachBaiHat() {
    int soLuong;
    std::cout << "Nhap so luong bai hat muon them vao ung dung: ";
    std::cin >> soLuong;
    std::cin.ignore(1000, '\n');

    for (int i = 0; i < soLuong; ++i) {
        std::cout << "\n\n--- Nhap bai hat thu " << i + 1 << " ---\n";
        std::cout << "Chon loai bai hat (1. Pho thong | 2. Ban quyen): ";
        int loai;
        std::cin >> loai;
        std::cin.ignore(1000, '\n');

        BaiHat* bh = nullptr;
        if (loai == 1) {
            bh = new BaiHatPhoThong();
        } else if (loai == 2) {
            bh = new BaiHatBanQuyen();
        }

        if (bh != nullptr) {
            bh->NhapThongTin();
            DanhSachToanBoBaiHat.push_back(bh);
            std::cout << "Them bai hat thanh cong" << std::endl;
        } else {
            std::cout << "Loai bai hat khong hop le" << std::endl;
        }
    }
}

// ===== 2. XUẤT DANH SÁCH BÀI HÁT =====
void AppMusic::XuatDanhSachBaiHat() {
    std::cout << "\n\n===== Danh sach cac bai hat co trong ung dung =====" << std::endl;

    if (DanhSachToanBoBaiHat.empty()) {
        std::cout << "(He thong chua co bai hat nao)\n";
        return;
    }

    for (size_t i = 0; i < DanhSachToanBoBaiHat.size(); ++i) {
        if (DanhSachToanBoBaiHat[i] != nullptr) {
            DanhSachToanBoBaiHat[i]->XuatThongTin();
        }
    }
}

void AppMusic::BXHTop5() {
    std::cout << "\n\n===== Bang xep hang =====" << std::endl;

    if (DanhSachToanBoBaiHat.empty()) {
        std::cout << "Chua co du lieu bai hat de xep hang" << std::endl;
        return;
    }

    std::vector<BaiHat*> bxh = DanhSachToanBoBaiHat;

    std::sort(bxh.begin(), bxh.end(), [](BaiHat* a, BaiHat* b) {
        return a->LayLuotNghe() > b->LayLuotNghe();
    });

    size_t top = std::min(static_cast<size_t>(5), bxh.size());
    for (size_t i = 0; i < top; ++i) {
        std::cout << "\n[TOP " << i + 1 << "] Luot nghe: " << bxh[i]->LayLuotNghe();
        bxh[i]->XuatThongTin();
    }
}

void AppMusic::DangKyTaiKhoan() {
    std::cout << "\n\n===== Dang ky tai khoan moi =====" << std::endl;
    std::cout << "Chon loai tai khoan (1. Thuong | 2. VIP): ";
    int loai;
    std::cin >> loai;
    std::cin.ignore(1000, '\n');

    std::string user, pass;
    std::cout << "Nhap ten dang nhap: ";
    std::getline(std::cin, user);

    for (TaiKhoan* tk : DanhSachTaiKhoan) {
        if (tk->GetTenDangNhap() == user) {
            std::cout << "Loi: Ten dang nhap da ton tai" << std::endl;
            return;
        }
    }

    TaiKhoan* tkMoi = nullptr;
    if (loai == 1) {
        tkMoi = new TaiKhoanThuong();
    } else if (loai == 2) {
        tkMoi = new TaiKhoanVip();
    } else {
        std::cout << "=> Loai tai khoan khong hop le!\n";
        return;
    }

    while (true) {
        std::cout << "Nhap mat khau (>= 8 ky tu, khong chua khoang trang): ";
        std::getline(std::cin, pass);

        if (tkMoi->KiemTraMatKhauHopLe(pass)) {
            break;
        }
        std::cout << "=> Mat khau khong hop le! Vui long nhap lai.\n";
    }

    tkMoi->SetThongTinDangNhap(user, pass);

    DanhSachTaiKhoan.push_back(tkMoi);
    std::cout << "=> Dang ky tai khoan thanh cong!\n";
}

bool AppMusic::DangNhap() {
    std::string user, pass;
    std::cout << "\n===== ĐĂNG NHẬP HỆ THỐNG =====\n";
    std::cout << "Ten dang nhap: ";
    std::getline(std::cin, user);
    std::cout << "Mat khau: ";
    std::getline(std::cin, pass);

    for (TaiKhoan* tk : DanhSachTaiKhoan) {
        if (tk->GetTenDangNhap() == user && tk->GetMatKhau() == pass) {
            TaiKhoanHienTai = tk;
            std::cout << "=> Dang nhap thanh cong! Xin chao " << user << "\n";
            return true;
        }
    }

    std::cout << "=> Dang nhap thất bai! Sai ten dang nhap hoac mat khau.\n";
    return false;
}

void AppMusic::ChayUngDung() {
    int choice;
    do {
        std::cout << "\n\n========================================\n";
        std::cout << "     ỨNG DỤNG NGHE NHẠC ĐA NĂNG\n";
        std::cout << "========================================\n";
        std::cout << "1. Nhap danh sach bai hat\n";
        std::cout << "2. Xuat danh sach bai hat\n";
        std::cout << "3. Xem Bang Xep Hang Top 5\n";
        std::cout << "4. Dang ky tai khoan\n";
        std::cout << "5. Dang nhap\n";
        std::cout << "6. Thoat ung dung\n";
        std::cout << "Lua chon cua ban: ";
        std::cin >> choice;
        std::cin.ignore(1000, '\n');

        switch (choice) {
            case 1:
                NhapDanhSachBaiHat();
                break;
            case 2:
                XuatDanhSachBaiHat();
                break;
            case 3:
                BXHTop5();
                break;
            case 4:
                DangKyTaiKhoan();
                break;
            case 5:
                if (DangNhap()) {
                    // Xử lý menu người dùng đã đăng nhập ở đây
                }
                break;
            case 6:
                std::cout << "Thoat ung dung. Cam on ban da su dung!\n";
                break;
            default:
                std::cout << "Thao tac khong hop le! Vui long nhap lai.\n";
                break;
        }
    } while (choice != 6);
}

AppMusic::~AppMusic() {
    for (BaiHat* bh : DanhSachToanBoBaiHat) {
        delete bh;
    }
    DanhSachToanBoBaiHat.clear();

    for (TaiKhoan* tk : DanhSachTaiKhoan) {
        delete tk;
    }
    DanhSachTaiKhoan.clear();

    TaiKhoanHienTai = nullptr;
}