#include <iostream>
#include <string>
#include <vector>
#include "school.h"
using namespace std;

int main() {
	PhongQuanLy* phongquanly = PhongQuanLy::GetInstance();

	phongquanly->DangKyMau(new GiangVien());
	phongquanly->DangKyMau(new TroGiang());
	phongquanly->DangKyMau(new NghienCuuVien());
	phongquanly->DangKyMau(new ChuyenVien());
	phongquanly->DangKyMau(new ThucTapSinh());

	while (true) {
		cout << "\n\n===== Chao mung den voi truong Dai hoc Khoa hoc Tu nhien =====" << endl;
		cout << "----- Cac thao tac -----" << endl;
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

			string loai = "";
			if (subChoice == 1)
				loai = "GiangVien";
			else if (subChoice == 2)
				loai = "TroGiang";
			else if (subChoice == 3)
				loai = "NghienCuuVien";
			else if (subChoice == 4)
				loai = "ChuyenVien";
			else if (subChoice == 5)
				loai = "ThucTapSinh";

			if (!loai.empty()) {
				phongquanly->ThemNhanSuTheoLoai(loai);
			}
			else {
				cout << "Lua chon khong hop le!\n";
			}
		}
		else if (choice == 2) {
			cout << "\n----- Quan ly nhan su -----" << endl;
			cout << "Nhap ma so nhan vien: ";
			string msnv;
			getline(cin, msnv);

			int index = phongquanly->TimNhanVien(msnv);
			if (index != -1) {
				cout << "\n1. Giao viec cho nhan vien" << endl;
				cout << "2. Xoa nhan vien nay" << endl;
				cout << "Lua chon: ";
				int choice2 = 0;
				cin >> choice2;
				cin.ignore(1000, '\n');

				if (choice2 == 1) {
					phongquanly->GiaoViecchoNhanVien(index);
				}
				else if (choice2 == 2) {
					phongquanly->XoaNhanVien(msnv);
				}
				else {
					cout << "Thao tac khong hop le!\n";
				}
			}
			else {
				cout << "Khong tim thay nhan vien!\n";
			}
		}
		else if (choice == 3) {
			cout << "\n----- Tinh tong luong nhan su -----" << endl;
			if (phongquanly->LaySoluongNhanSu() == 0) {
				cout << "Khong co nhan vien de tinh tong luong" << endl;
			}
			else {
				cout << "Tong luong toan truong: " << phongquanly->TinhTongLuong() << " VND" << endl;
			}
		}
		else if (choice == 4) {
			cout << "\n----- Danh sach nhan su -----" << endl;
			phongquanly->InDanhSachNhanSu();
		}
		else if (choice == 5) {
			cout << "\n----- Tim kiem nhan vien -----" << endl;
			cout << "1. Tim kiem nhan vien dua tren ma so nhan vien" << endl;
			cout << "2. Tim kiem nhan vien co luong cao nhat" << endl;
			int subChoice;
			cout << "Lua chon: ";
			cin >> subChoice;
			cin.ignore(1000, '\n');

			if (subChoice == 1) {
				cout << "Nhap ma so nhan vien: ";
				string msnv;
				getline(cin, msnv);

				int index = phongquanly->TimNhanVien(msnv);
				if (index != -1)
					cout << "Nhan vien co ma so " << msnv << " co trong danh sach (Vi tri: " << index + 1 << ")" << endl;
				else
					cout << "Khong co nhan vien trong danh sach" << endl;
			}
			else if (subChoice == 2) {
				phongquanly->TimNhanVienLuongCao();
			}
			else {
				cout << "Lua chon khong hop le" << endl;
			}
		}
		else if (choice == 6) {
			cout << "Thoat chuong trinh" << endl;
			break;
		}
		else {
			cout << "Thao tac khong hop le!" << endl;
		}
	}

	PhongQuanLy::DeleteInstance();
	return 0;
}