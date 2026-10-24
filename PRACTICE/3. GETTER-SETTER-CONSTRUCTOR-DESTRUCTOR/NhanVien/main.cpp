#include <iostream>
#include "NhanVien.h"
#include <string>
using namespace std;

int main() {
    NhanVien nhanvien;
    
    nhanvien.Nhap();
    nhanvien.Xuat();

    return 0;
}

// void main() {
//     NhanVien a("Dat Thanh", 800);
//     NhanVien b(a);
//     b.SetHoTen("Hai Dang");
//     for (int i = 0; i < 5; i++)
//     {
//         NhanVien clone = b;
//         clone.SetHoTen("De tu thu " + to_string(i) + " cua " + b.GetChucDanh() + " " + b.GetHoTen());
//     }
// }

/*
- Một constructor lớp NhanVien tên là a được khởi tạo với
Họ tên: "Dat Thanh"
Số ngày làm viêc: 800
Chức danh: Trưởng phòng
Tên gọi: Trưởng phòng Thanh
Hệ số lương: 2.25

- Một constructor lớp NhanVien tên là b được khởi tạo để sao chép chức vụ, hệ số lương và số ngày làm việc
Họ tên: "Nguyễn Văn A" (theo mặc đinh)
Số ngày làm việc: 800
Chức danh: Trưởng phòng
Tên gọi: Trưởng phòng A (theo mặc định)
Hệ số lương: 2.25

- Đối tượng b thay đổi tên từ “Nguyễn Văn A” sang “Hai Dang”

- Một vòng lặp for chạy qua 5 lần
- - Lần 1:
- - - Khởi tạo clone bằng cách sao chép b
- - - Đổi tên thành “De tu thu 0 cua Trưởng phòng Hai Dang"
- - - Chạy hàm hủy

- - Lần 2:
- - - Khởi tạo clone bằng cách sao chép b
- - - Đổi tên thành “De tu thu 1 cua Trưởng phòng Hai Dang"
- - - Chạy hàm hủy

- - Lần 3:
- - - Khởi tạo clone bằng cách sao chép b
- - - Đổi tên thành “De tu thu 2 cua Trưởng phòng Hai Dang"
- - - Chạy hàm hủy

- - Lần 4:
- - - Khởi tạo clone bằng cách sao chép b
- - - Đổi tên thành “De tu thu 3 cua Trưởng phòng Hai Dang"
- - - Chạy hàm hủy

- - Lần 5:
- - - Khởi tạo clone bằng cách sao chép b
- - - Đổi tên clone thành “De tu thu 4 cua Trưởng phòng Hai Dang"
- - - Chạy hàm hủy

- Kết thúc chương trình: Chạy hàm hủy b và chạy hàm hủy a
*/