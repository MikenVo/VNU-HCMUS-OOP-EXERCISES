#include <iostream>
#include <string>

using namespace std;

// ==========================================
// 1. LỚP SẢN PHẨM (Đại diện cho hàng hóa)
// ==========================================
class SanPham {
private:
    string tenSP;
    int giaTien;
    int thoiGianDongGoi;  // Thời gian shop chuẩn bị hàng (giờ)
    int thoiGianGiaoHang; // Thời gian đơn vị vận chuyển giao (giờ)

public:
    // Hàm khởi tạo mặc định
    SanPham() {
        tenSP = "Chua co ten";
        giaTien = 0;
        thoiGianDongGoi = 0;
        thoiGianGiaoHang = 0;
    }

    // Hàm khởi tạo đầy đủ tham số
    SanPham(string ten, int gia, int tgDongGoi, int tgGiao) {
        tenSP = ten;
        giaTien = gia;
        thoiGianDongGoi = tgDongGoi;
        thoiGianGiaoHang = tgGiao;
    }

    // Hàm khởi tạo sao chép (Copy Constructor - Quan trọng để copy hàng từ Shop sang Đơn hàng)
    SanPham(const SanPham& sp) {
        tenSP = sp.tenSP;
        giaTien = sp.giaTien;
        thoiGianDongGoi = sp.thoiGianDongGoi;
        thoiGianGiaoHang = sp.thoiGianGiaoHang;
    }

    // Nạp chồng toán tử xuất để in thông tin sản phẩm
    friend ostream& operator<<(ostream& os, const SanPham& sp) {
        os << "SP: " << sp.tenSP << " | Gia: " << sp.giaTien << " VND"
           << " | Chuan bi: " << sp.thoiGianDongGoi << "h | Giao: " << sp.thoiGianGiaoHang << "h";
        return os;
    }

    // Getters
    int getGiaTien() { return giaTien; }
    int getTGDongGoi() { return thoiGianDongGoi; }
    int getTGGiaoHang() { return thoiGianGiaoHang; }
    string getTen() { return tenSP; }
};

// ==========================================
// 2. LỚP CỬA HÀNG (Quản lý các sản phẩm đang bán)
// ==========================================
class CuaHang {
private:
    string tenCuaHang;
    SanPham** danhSachSP; // Mảng con trỏ chứa các sản phẩm
    int soLuongSP;

public:
    CuaHang(string ten) {
        tenCuaHang = ten;
        danhSachSP = NULL;
        soLuongSP = 0;
    }

    // Hàm hủy: Giải phóng bộ nhớ của cửa hàng
    ~CuaHang() {
        if (danhSachSP != NULL) {
            for (int i = 0; i < soLuongSP; i++) {
                delete danhSachSP[i];
            }
            delete[] danhSachSP;
        }
    }

    // Thêm sản phẩm mới lên kệ (Tương tự thêm cây trồng)
    void themSanPham(SanPham* sp) {
        SanPham** mangMoi = new SanPham*[soLuongSP + 1];
        for (int i = 0; i < soLuongSP; i++) {
            mangMoi[i] = danhSachSP[i];
        }
        mangMoi[soLuongSP] = sp;

        if (danhSachSP != NULL) delete[] danhSachSP;
        danhSachSP = mangMoi;
        soLuongSP++;
    }

    // Hiển thị các mặt hàng đang bán
    void xemCuaHang() {
        cout << "\n=== CHAO MUNG DEN GIAN HANG: " << tenCuaHang << " ===" << endl;
        for (int i = 0; i < soLuongSP; i++) {
            cout << "[" << i << "] " << *danhSachSP[i] << endl;
        }
        cout << "==========================================\n";
    }

    // Lấy một sản phẩm (Trả về bản sao để đưa vào đơn hàng)
    SanPham* laySanPham(int viTri) {
        if (viTri >= 0 && viTri < soLuongSP) {
            // Dùng Copy Constructor để tạo ra 1 món đồ mới y hệt, tránh dùng chung con trỏ
            return new SanPham(*danhSachSP[viTri]); 
        }
        return NULL;
    }
};

// ==========================================
// 3. LỚP ĐƠN HÀNG (Quá trình đóng gói, giao nhận)
// ==========================================
class DonHang {
private:
    SanPham** danhSachMua;
    int soLuongMua;
    int tongTien;
    int tongThoiGianDongGoi;
    int thoiGianGiaoLauNhat;
    
    // Trạng thái đơn hàng: 
    // 0: Chờ xác nhận, 1: Đang đóng gói, 2: Đang giao hàng, 3: Đã nhận hàng
    int trangThai; 

public:
    DonHang() {
        danhSachMua = NULL;
        soLuongMua = 0;
        tongTien = 0;
        tongThoiGianDongGoi = 0;
        thoiGianGiaoLauNhat = 0;
        trangThai = 0; 
    }

    // Hàm hủy
    ~DonHang() {
        if (danhSachMua != NULL) {
            for (int i = 0; i < soLuongMua; i++) {
                delete danhSachMua[i];
            }
            delete[] danhSachMua;
        }
    }

    // Nạp chồng toán tử + để thêm Sản phẩm vào Đơn hàng (Cách điệu OOP)
    DonHang& operator+(SanPham* spMoi) {
        // Cấp phát lại mảng để thêm hàng
        SanPham** mangMoi = new SanPham*[soLuongMua + 1];
        for (int i = 0; i < soLuongMua; i++) {
            mangMoi[i] = danhSachMua[i];
        }
        mangMoi[soLuongMua] = spMoi;

        if (danhSachMua != NULL) delete[] danhSachMua;
        danhSachMua = mangMoi;
        soLuongMua++;

        // Cập nhật các thông số đơn hàng
        tongTien += spMoi->getGiaTien();
        tongThoiGianDongGoi += spMoi->getTGDongGoi(); // Càng nhiều đồ gói càng lâu
        
        // Thời gian giao bằng món có thời gian vận chuyển lâu nhất
        if (spMoi->getTGGiaoHang() > thoiGianGiaoLauNhat) {
            thoiGianGiaoLauNhat = spMoi->getTGGiaoHang();
        }

        return *this;
    }

    // Tính thời điểm giao hàng dự kiến (ETA)
    int tinhThoiGianDuKien() {
        return tongThoiGianDongGoi + thoiGianGiaoLauNhat;
    }

    // Chuyển sang công đoạn tiếp theo
    void capNhatTrangThai() {
        if (trangThai < 3) {
            trangThai++;
        }
    }

    // Xem tiến độ đơn hàng
    void kiemTraTienDo() {
        cout << "\n--- CHI TIET DON HANG ---" << endl;
        cout << "Tong so mon: " << soLuongMua << " | Tong tien: " << tongTien << " VND" << endl;
        cout << "Thoi gian du kien nhan hang: " << tinhThoiGianDuKien() << " gio." << endl;
        
        cout << "Trang thai hien tai: ";
        if (trangThai == 0) cout << "[Cho xac nhan]" << endl;
        else if (trangThai == 1) cout << "[Nguoi ban dang dong goi]" << endl;
        else if (trangThai == 2) cout << "[Don vi van chuyen dang giao]" << endl;
        else if (trangThai == 3) cout << "[Giao hang thanh cong!]" << endl;
        cout << "-------------------------\n";
    }

    int getTongTien() { return tongTien; }
    int getTrangThai() { return trangThai; }
};

// ==========================================
// 4. LỚP KHÁCH HÀNG (Người mua)
// ==========================================
class KhachHang {
private:
    string tenKhach;
    int soDuVi;
    DonHang* gioHang; // Mỗi khách có 1 giỏ hàng/đơn hàng đang xử lý

public:
    KhachHang(string t, int tien) {
        tenKhach = t;
        soDuVi = tien;
        gioHang = new DonHang(); // Khởi tạo giỏ hàng trống
    }

    ~KhachHang() {
        if (gioHang != NULL) {
            delete gioHang;
        }
    }

    // Khách chọn mua 1 món từ Cửa hàng
    void themVaoGio(CuaHang& ch, int viTriSP) {
        // Lấy 1 bản sao của hàng hóa từ Cửa hàng
        SanPham* hangMua = ch.laySanPham(viTriSP);
        if (hangMua != NULL) {
            // Dùng toán tử + của DonHang để thêm món đồ
            *gioHang = *gioHang + hangMua;
            cout << "=> " << tenKhach << " da them [" << hangMua->getTen() << "] vao gio." << endl;
        } else {
            cout << "=> Loi: San pham khong ton tai!" << endl;
        }
    }

    // Khách hàng bấm thanh toán
    void thanhToan() {
        cout << "\n=> Tuyen trinh: THANH TOAN DON HANG" << endl;
        int tienCanTra = gioHang->getTongTien();
        
        if (soDuVi >= tienCanTra) {
            soDuVi -= tienCanTra;
            cout << "Thanh toan thanh cong " << tienCanTra << " VND! So du con lai: " << soDuVi << " VND." << endl;
            // Xác nhận đơn, shop bắt đầu đóng gói
            gioHang->capNhatTrangThai(); 
        } else {
            cout << "Thanh toan that bai! Khong du tien trong vi (Can: " << tienCanTra << ", Vi co: " << soDuVi << ")." << endl;
        }
    }

    // Khách hàng tự theo dõi đơn
    void xemDonHang() {
        gioHang->kiemTraTienDo();
    }

    // Khách bấm "Đã nhận được hàng"
    void nhanHang() {
        if (gioHang->getTrangThai() == 2) { // Đang giao
            gioHang->capNhatTrangThai(); // Chuyển sang Đã nhận
            cout << "\n=> " << tenKhach << " da xac nhan nhan hang! Giao dich hoan tat." << endl;
        } else {
            cout << "\n=> Hang chua den, khong the xac nhan!" << endl;
        }
    }

    // Hệ thống thời gian trôi qua, cập nhật trạng thái đơn (Mô phỏng logistics)
    void heThongVanChuyen_XuLy() {
        if (gioHang->getTrangThai() == 1) {
            cout << "\n[He thong] Shop da dong goi xong. Giao cho don vi van chuyen..." << endl;
            gioHang->capNhatTrangThai(); // Chuyển sang Đang giao
        }
    }
};

// ==========================================
// 5. HÀM MAIN - MÔ PHỎNG LUỒNG APP SHOPEE
// ==========================================
int main() {
    cout << "=======================================" << endl;
    cout << "   MO PHONG E-COMMERCE (OOP C++)       " << endl;
    cout << "=======================================" << endl;

    // 1. TẠO CỬA HÀNG VÀ HÀNG HÓA
    CuaHang shopeeMall("Shopee Electronic");
    shopeeMall.themSanPham(new SanPham("Dien thoai XYZ", 5000, 2, 24)); // Đóng gói 2h, Giao 24h
    shopeeMall.themSanPham(new SanPham("Tai nghe Bluetooth", 800, 1, 12));
    shopeeMall.themSanPham(new SanPham("Op lung", 150, 1, 48)); // Hàng quốc tế, ship lâu (48h)

    shopeeMall.xemCuaHang();

    // 2. KHÁCH HÀNG ĐĂNG NHẬP (Ví có 10000 VND)
    KhachHang ngDung("Nguyen Van A", 10000);

    // 3. CHỌN MUA HÀNG (Thêm vào giỏ)
    ngDung.themVaoGio(shopeeMall, 0); // Mua điện thoại
    ngDung.themVaoGio(shopeeMall, 2); // Mua ốp lưng

    // Xem thông tin trước khi thanh toán
    ngDung.xemDonHang();

    // 4. THANH TOÁN
    ngDung.thanhToan();

    // Xem lại sau khi thanh toán, trạng thái sẽ lên [Nguoi ban dang dong goi]
    ngDung.xemDonHang();

    // 5. HỆ THỐNG VẬN CHUYỂN XỬ LÝ ĐƠN (Mô phỏng thời gian)
    ngDung.heThongVanChuyen_XuLy();
    ngDung.xemDonHang(); // Trạng thái: [Don vi van chuyen dang giao]

    // 6. KHÁCH NHẬN HÀNG
    ngDung.nhanHang();
    ngDung.xemDonHang(); // Trạng thái: [Giao hang thanh cong!]

    cout << "=======================================" << endl;
    return 0; // Chương trình kết thúc, Destructor của KhachHang và CuaHang tự động giải phóng toàn bộ RAM.
}