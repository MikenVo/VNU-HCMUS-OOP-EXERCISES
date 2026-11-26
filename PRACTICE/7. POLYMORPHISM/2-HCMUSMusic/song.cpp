#include <iostream>
#include <string>
#include "song.h"

int BaiHat::LayLuotNghe() const { return LuotNghe; }
std::string BaiHat::LayTheLoai() const { return TheLoai; }
std::string BaiHat::LayTenBaiHat() const { return TenBaiHat; }
std::string BaiHat::LayTenCaSy() const { return TenCaSy; }
BaiHat::~BaiHat() {}

void BaiHat::NhapThongTin() {
    std::cout << "Nhap ten bai hat: ";
    std::getline(std::cin, TenBaiHat);
    std::cout << "Nhap loi bai hat: ";
    std::getline(std::cin, LoiBaiHat);
    std::cout << "Nhap ten ca sy: ";
    std::getline(std::cin, TenCaSy);

    int chonTheLoai = 0;
    do {
        std::cout << "Chon the loai nhac:\n";
        std::cout << "1. Nhac Viet Nam\n";
        std::cout << "2. Nhac Au My\n";
        std::cout << "3. Nhac Han Quoc\n";
        std::cout << "Lua chon (1-3): ";
        std::cin >> chonTheLoai;
        std::cin.ignore(1000, '\n');

        if (chonTheLoai == 1) {
            TheLoai = "Nhac Viet Nam";
        }
        else if (chonTheLoai == 2) {
            TheLoai = "Nhac Au My";
        }
        else if (chonTheLoai == 3) {
            TheLoai = "Nhac Han Quoc";
        }
        else {
            std::cout << "The loai khong hop le! Vui long chon lai.\n";
        }
    } while (chonTheLoai < 1 || chonTheLoai > 3);

    std::cout << "Nhap nam sang tac: ";
    std::cin >> NamSangTac;
    std::cin.ignore(1000, '\n');
    std::cout << "Nhap so luot nghe: ";
    std::cin >> LuotNghe;
    std::cin.ignore(1000, '\n');
}

void BaiHat::XuatThongTin() {
    std::cout << "- Ten bai hat: " << TenBaiHat << std::endl;
    std::cout << "- Loi bai hat: " << LoiBaiHat << std::endl;
    std::cout << "- Ten ca sy: " << TenCaSy << std::endl;
    std::cout << "- The loai: " << TheLoai << std::endl;
    std::cout << "- Nam sang tac: " << NamSangTac << std::endl;
    std::cout << "- So luot nghe: " << LuotNghe << std::endl;
}

// ===== Lop BaiHatPhoThong =====
void BaiHatPhoThong::NhapThongTin() {
    BaiHat::NhapThongTin();
}

void BaiHatPhoThong::XuatThongTin() {
    std::cout << "\n\n===== Thong tin bai hat pho thong =====" << std::endl;
    BaiHat::XuatThongTin();
}

float BaiHatPhoThong::TinhGiaTien(bool isVip) {
    return 0;
}

void BaiHatBanQuyen::NhapThongTin() {
    BaiHat::NhapThongTin();
    std::cout << "Nhap gia tri ban quyen: ";
    std::cin >> GiaTriBanQuyen;
    std::cin.ignore(1000, '\n');
}

void BaiHatBanQuyen::XuatThongTin() {
    std::cout << "\n\n===== Thong tin bai hat ban quyen =====" << std::endl;
    BaiHat::XuatThongTin();
    std::cout << "- Gia tri ban quyen: " << GiaTriBanQuyen << std::endl;
}

float BaiHatBanQuyen::TinhGiaTien(bool isVip) {
    if (isVip) {
        return 0.50f * GiaTriBanQuyen;
    }
    return GiaTriBanQuyen;
}