#include <iostream>
#include <string>
#include <vector>
#include "playlist.h"

void Playlist::ThemBaiHat(BaiHat *bh) {
    if (bh == nullptr) {
        std::cout << "Loi: Bài hat khong hop le\n";
        return;
    }

    for (BaiHat *item : DanhSachBaiHat) {
        if (item != nullptr && item->LayTenBaiHat() == bh->LayTenBaiHat()) {
            std::cout << "Bai hat '" << bh->LayTenBaiHat() << "' da co trong Playlist\n";
            return;
        }
    }

    DanhSachBaiHat.push_back(bh);
    std::cout << "Da them bai hat '" << bh->LayTenBaiHat() << "' vao Playlist thanh cong\n";
}

void Playlist::XoaBaiHat(std::string tenBH) {
    if (DanhSachBaiHat.empty()) {
        std::cout << "Playlist khong co bai hat nao\n";
        return;
    }

    bool timThay = false;
    for (auto it = DanhSachBaiHat.begin(); it != DanhSachBaiHat.end(); ++it) {
        if (*it != nullptr && (*it)->LayTenBaiHat() == tenBH) {
            DanhSachBaiHat.erase(it);
            std::cout << "Da xoa bai hat '" << tenBH << "' khoi Playlist\n";
            timThay = true;
            break;
        }
    }

    if (!timThay) {
        std::cout << "Khong tim thay bai hat '" << tenBH << "' trong Playlist\n";
    }
}

void Playlist::InPlaylist() {
    std::cout << "\n\n===== DANH SACH BAI HAT TRONG PLAYLIST: " << (TenPlaylist.empty() ? "Ca Nhan" : TenPlaylist) << " =====" << std::endl;

    if (DanhSachBaiHat.empty()) {
        std::cout << "- Playlist hien chua co bai hat nao\n";
        return;
    }

    for (int i = 0; i < DanhSachBaiHat.size(); ++i) {
        if (DanhSachBaiHat[i] != nullptr) {
            std::cout << i + 1 << ". " << DanhSachBaiHat[i]->LayTenBaiHat() << " - Ca sy: " << DanhSachBaiHat[i]->LayTenCaSy() << " | The loai: " << DanhSachBaiHat[i]->LayTheLoai() << std::endl;
        }
    }
}