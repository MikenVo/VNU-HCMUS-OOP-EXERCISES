#include <iostream>
#include <string>
#include <vector>
#include "initial.h"
using namespace std;

int main() {
    TruongHoc hcmus;
    int luaChon;

    cout << "--- KHOI DONG HE THONG QUAN LY NHAN SU ---" << endl;

    do {
        cout << "\n===== MENU CHUC NANG =====" << endl;
        cout << "1. Them Giang vien" << endl;
        cout << "2. Them Tro giang" << endl;
        cout << "3. Them Nghien cuu vien (VD ma du an: D-Artemis)" << endl;
        cout << "4. Them Chuyen vien (VD ma du an: T-Tiangong)" << endl;
        cout << "5. Xuat toan bo danh sach & Tong luong" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "-> Nhap lua chon cua ban: ";
        cin >> luaChon;

        if (luaChon == 1) {
            GiangVien *gv = new GiangVien();
            cin >> *gv;
            hcmus.ThemNhanSu(gv);
        }
        else if (luaChon == 2) {
            TroGiang *tg = new TroGiang();
            cin >> *tg;
            hcmus.ThemNhanSu(tg);
        }
        else if (luaChon == 3) {
            NghienCuuVien *ncv = new NghienCuuVien();
            cin >> *ncv;
            hcmus.ThemNhanSu(ncv);
        }
        else if (luaChon == 4) {
            ChuyenVien *cv = new ChuyenVien();
            cin >> *cv;
            hcmus.ThemNhanSu(cv);
        }
        else if (luaChon == 5) {
            hcmus.XuatDanhSach();
            cout << "\n=====================================" << endl;
            cout << "=> TONG QUY LUONG CAN TRA: " << (size_t)hcmus.tinhTongLuong() << " VND" << endl;
            cout << "=====================================" << endl;
        }
        else if (luaChon == 0) {
            cout << "Kich hoat Decoupler... Giai phong Heap an toan nhu trong Kerbal Space Program. Tam biet!" << endl;
        }
        else {
            cout << "Giao thuc that bai (Loi dieu huong Warp), vui long thu lai." << endl;
        }
    } while (luaChon != 0);

    return 0;
}