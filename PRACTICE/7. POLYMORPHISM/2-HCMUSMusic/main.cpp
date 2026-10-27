#include <iostream>
#include <string>
#include <vector>
#include "app.h"
#include "account.h"
#include "playlist.h"
#include "song.h"

using namespace std;

int main() {
    AppMusic app;
    int luaChonNgoai;

    while (true) {
        cout << "\n--- HE THONG QUAN LY AM NHAC ---" << endl;
        cout << "1. Dang ky tai khoan" << endl;
        cout << "2. Dang nhap" << endl;
        cout << "0. Thoat ung dung" << endl;
        cout << "Moi chon: ";
        cin >> luaChonNgoai;
        cin.ignore(1000, '\n');

        if (luaChonNgoai == 0) {
            break;
        }
        else if (luaChonNgoai == 1) {
            app.DangKyTaiKhoan();
        }
        else if (luaChonNgoai == 2) {
            if (app.DangNhap()) {
                int luaChonTrong;
                while (true) {
                    cout << "\n--- MENU NGUOI DUNG ---" << endl;
                    cout << "1. Them bai hat vao he thong" << endl;
                    cout << "2. Xuat danh sach bai hat he thong" << endl;
                    cout << "3. Xem bang xep hang top 5" << endl;
                    cout << "4. Them bai hat vao playlist ca nhan" << endl;
                    cout << "5. Xoa bai hat khoi playlist ca nhan" << endl;
                    cout << "6. In playlist ca nhan" << endl;
                    cout << "7. Nghe nhac" << endl;
                    cout << "8. Goi y bai hat HOT nhat (Chi VIP)" << endl;
                    cout << "9. Gia han tai khoan (Chi VIP)" << endl;
                    cout << "0. Dang xuat" << endl;
                    cout << "Moi chon: ";
                    cin >> luaChonTrong;
                    cin.ignore(1000, '\n');

                    if (luaChonTrong == 0) {
                        break;
                    }
                    else if (luaChonTrong == 1) {
                        app.NhapDanhSachBaiHat();
                    }
                    else if (luaChonTrong == 2) {
                        app.XuatDanhSachBaiHat();
                    }
                    else if (luaChonTrong == 3) {
                        app.BXHTop5();
                    }
                    else if (luaChonTrong == 4) {
                        string ten;
                        cout << "Nhap ten bai hat can them vao playlist: ";
                        getline(cin, ten);
                        BaiHat *bhThem = nullptr;
                        vector<BaiHat *> dsBaiHat = app.LayDanhSachBaiHat();
                        for (size_t i = 0; i < dsBaiHat.size(); i++) {
                            if (dsBaiHat[i]->LayTenBaiHat() == ten) {
                                bhThem = dsBaiHat[i];
                                break;
                            }
                        }
                        if (bhThem != nullptr) {
                            app.LayTaiKhoanHienTai()->ThemVaoPlaylist(bhThem);
                        }
                        else {
                            cout << "Khong tim thay bai hat trong he thong" << endl;
                        }
                    }
                    else if (luaChonTrong == 5) {
                        string ten;
                        cout << "Nhap ten bai hat can xoa khoi playlist: ";
                        getline(cin, ten);
                        app.LayTaiKhoanHienTai()->XoaKhoiPlaylist(ten);
                    }
                    else if (luaChonTrong == 6) {
                        app.LayTaiKhoanHienTai()->InPlaylistCaNhan();
                    }
                    else if (luaChonTrong == 7) {
                        string ten;
                        cout << "Nhap ten bai hat muon nghe: ";
                        getline(cin, ten);
                        BaiHat *bhNghe = nullptr;
                        vector<BaiHat *> dsBaiHat = app.LayDanhSachBaiHat();
                        for (int i = 0; i < dsBaiHat.size(); i++) {
                            if (dsBaiHat[i]->LayTenBaiHat() == ten) {
                                bhNghe = dsBaiHat[i];
                                break;
                            }
                        }
                        if (bhNghe != nullptr) {
                            app.LayTaiKhoanHienTai()->NgheNhac(bhNghe);
                        }
                        else {
                            cout << "Khong tim thay bai hat trong he thong" << endl;
                        }
                    }
                    else if (luaChonTrong == 8) {
                        TaiKhoanVip *vip = dynamic_cast<TaiKhoanVip*>(app.LayTaiKhoanHienTai());
                        if (vip != nullptr) {
                            string theLoai;
                            cout << "Nhap the loai can goi y: ";
                            getline(cin, theLoai);
                            vip->GoiYBaiHat(theLoai, app.LayDanhSachBaiHat());
                        }
                        else {
                            cout << "Tinh nang nay chi danh cho tai khoan VIP" << endl;
                        }
                    }
                    else if (luaChonTrong == 9) {
                        TaiKhoanVip *vip = dynamic_cast<TaiKhoanVip *>(app.LayTaiKhoanHienTai());
                        if (vip != nullptr) {
                            double soTien;
                            cout << "Nhap so tien nap gia han: ";
                            cin >> soTien;
                            cin.ignore(1000, '\n');
                            vip->GiaHanTaiKhoan(soTien);
                        }
                        else {
                            cout << "Tinh nang nay chi danh cho tai khoan VIP" << endl;
                        }
                    }
                    else {
                        cout << "Lua chon khong hop le" << endl;
                    }
                }
            }
        }
        else {
            cout << "Lua chon khong hop le" << endl;
        }
    }
    return 0;
}