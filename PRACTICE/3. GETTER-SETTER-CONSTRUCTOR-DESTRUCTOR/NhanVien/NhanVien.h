#include <iostream>
#include <string>
using namespace std;

class NhanVien {
    private:
        string hoten; // Need to be inputted
        int so_ngay; // Need to be inputted
        string chuc_danh; // Based on the number of work days
        string ten_goi; // Based on the name and the title
        float hesoluong; // Basaed on the title

    public:
        void Nhap();
        void Xuat();

        // Getter
        string XuatTen();
        int Xuatso_ngay();
        string Xuatchuc_danh();
        string Xuatten_goi();
        float XuatHesoluong();

        // Setter
        void NhapTen(string s);
        void NhapSoNgay(int so_ngay);
        void GanChucDanh();
        void GanTenGoi();
        void GanHesoluong();

        // Default constructor
        NhanVien() {
            hoten = "Nguyễn Văn A";
            so_ngay = 0;
            GanChucDanh();
            GanTenGoi();
            GanHesoluong();
        }

        // Constructor with 5 parameters
        NhanVien(string ten, int ngay, string chuc, string tengoi, float heso) {
            hoten = ten;
            so_ngay = ngay;
            chuc_danh = chuc;
            ten_goi = tengoi;
            hesoluong = heso;
        }

        // Constructor with 2 parameters
        NhanVien(string ten, int ngay) {
            NhapTen(ten);
            NhapSoNgay(ngay);
            GanChucDanh();
            GanTenGoi();
            GanHesoluong();
        }

        // Copy constructor
        NhanVien(const NhanVien &ban_goc) {
            // Copy the title, money rank and the number of work days
            chuc_danh = ban_goc.chuc_danh;
            hesoluong = ban_goc.hesoluong;
            so_ngay = ban_goc.so_ngay;

            // Set the names to default
            hoten = "Nguyễn Văn A";
            ten_goi = chuc_danh + " A";
        }

        // Destructor
        ~NhanVien() {
            cout << "Thông tin nhân viên đã được xóa." << endl;
        }

};