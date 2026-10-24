#include <iostream>
#include <string>
#include <vector>
#include "school.h"
using namespace std;

int main() {
	TruongHoc truonghoc;

	while (true) {
		cout << "\n\n===== Chao mung den voi truong Dai hoc Khoa hoc tu nhien =====" << endl;
		cout << "----- Cac thao tac ----- " << endl;
		cout << "1. Them nhan su" << endl;
		cout << "2. Quan ly / Giao viec / Xoa nhan su" << endl;
		cout << "3. Tinh tong luong" << endl;
		cout << "4. In ra toan bo nhan su" << endl;
		cout << "5. Tim kiem nhan su" << endl;
		cout << "6. Thoat ung dung" << endl;
		int choice = 0;

		cout << "Lua chon: ";
		if (!(cin >> choice))
			break;
		cin.ignore(1000, '\n');

		if (choice == 1) {
			cout << "\n----- Them nhan su -----" << endl;
			cout << "1. Giang vien | 2. Tro giang | 3. Nghien cuu vien | 4. Chuyen vien | 5. Thuc tap sinh" << endl;
			cout << "Lua chon: ";
			int subChoice;
			cin >> subChoice;
			cin.ignore(1000, '\n');

			NhanVien *nvmoi = nullptr;
			if (subChoice == 1) {
				GiangVien *gv = new GiangVien();
				cin >> *gv;
				nvmoi = gv;
			}
			else if (subChoice == 2) {
				TroGiang *tg = new TroGiang();
				cin >> *tg;
				nvmoi = tg;
			}
			else if (subChoice == 3) {
				NghienCuuVien *ncv = new NghienCuuVien();
				cin >> *ncv;
				nvmoi = ncv;
			}
			else if (subChoice == 4) {
				ChuyenVien *cv = new ChuyenVien();
				cin >> *cv;
				nvmoi = cv;
			}
			else if (subChoice == 5) {
				ThucTapSinh *tts = new ThucTapSinh();
				cin >> *tts;
				nvmoi = tts;
			}

			if (nvmoi != nullptr) {
				nvmoi->TinhLuong();
				truonghoc.ThemNhanSu(nvmoi);
				cout << "=> Them nhan su thanh cong!\n";
			}
			else {
				cout << "Lua chon không hop le!\n";
			}
		}
		else if (choice == 2) {
			cout << "\n----- Quan ly nhan su -----" << endl;
			cout << "Nhap ma so nhan vien: ";
			string msnv;
			cin >> msnv;
			cin.ignore(1000, '\n');

			int index = truonghoc.TimNhanVien(msnv);
			if (index != -1) {
				cout << "\n1. Giao viec cho nhan vien" << endl;
				cout << "2. Xoa nhan vien nay" << endl;
				cout << "Lua chon: ";
				int choice2 = 0;
				cin >> choice2;
				cin.ignore(1000, '\n');

				if (choice2 == 1) {
					truonghoc.GiaoViecchoNhanVien(index);
				}
				else if (choice2 == 2) {
					truonghoc.XoaNhanVien();
				}
			}
		}
		else if (choice == 3) {
			cout << "\n----- Tinh tong luong nhan su -----" << endl;
			if (truonghoc.LaySoluongNhanSu() == 0) {
				cout << "Khong co nhan vien de tinh tong luong" << endl;
			}
			else {
				cout << "Tong luong toan truong: " << truonghoc.TinhTongLuong() << " VND" << endl;
			}
		}
		else if (choice == 4) {
			cout << "\n----- Danh sach nhan su -----" << endl;
			truonghoc.InDanhSachNhanSu();
		}
		else if (choice == 5) {
			cout << "----- Tim kiem nhan vien -----" << endl;
			cout << "1. Tim kiem nhan vien dua tren ma so nhan vien" << endl;
			cout << "2. Tim kiem nhan vien co luong cao nhat" << endl;
			int subChoice;
			cout << "Lua chon: "; cin >> subChoice;

			if (subChoice == 1) {
				cout << "Nhap ma so nhan vien: ";
				string msnv;
				cin >> msnv;
				cin.ignore(1000, '\n');

				int index = truonghoc.TimNhanVien(msnv);
				if (index != -1)
					cout << "Nhan vien co trong danh sach" << endl;
				else
					cout << "Khong co nhan vien trong danh sach" << endl;
			}
			else if (subChoice == 2) {
				truonghoc.TimNhanVienLuongCao();
			}
		}
		else if (choice == 6) {
			cout << "Thoat chuong trinh\n";
			break;
		}
		else {
			cout << "Thao tac khong hop le!" << endl;
		}
	}

	return 0;
}