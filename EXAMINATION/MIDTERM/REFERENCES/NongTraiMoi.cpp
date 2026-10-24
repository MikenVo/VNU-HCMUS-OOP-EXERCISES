#include <iostream>
#include <string>

using namespace std;

// ==========================================
// 1. LỚP TRANG TRẠI (Quản lý bản đồ game)
// ==========================================
/*
 * BƯỚC 1: XÂY DỰNG LỚP BẢN ĐỒ TRANG TRẠI (TrangTrai)
 * - Nhiệm vụ: Tạo ra bản đồ ma trận 2 chiều lưu trữ vị trí các đối tượng.
 * - Ý nghĩa giá trị ô đất:
 *   + 0: Ô đất trống
 *   + 1: Ô đất đang trồng Cây
 *   + 2: Ô đất đang nuôi Vật nuôi
 */
class TrangTrai {
private:
    int** banDo;     // Con trỏ cấp 2 để tạo mảng 2 chiều động
    int chieuRong;  // Số hàng của bản đồ
    int chieuDai;   // Số cột của bản đồ

public:
    // --- BƯỚC 1.1: Hàm khởi tạo (Constructor) ---
    // Cấp phát bộ nhớ động cho mảng 2 chiều và gán tất cả ô bằng 0 (đất trống)
    TrangTrai(int r = 5, int d = 5) {
        chieuRong = r;
        chieuDai = d;

        // Cấp phát mảng chứa các con trỏ hàng
        banDo = new int*[chieuRong];
        for (int i = 0; i < chieuRong; i++) {
            // Cấp phát từng cột cho mỗi hàng
            banDo[i] = new int[chieuDai];
            for (int j = 0; j < chieuDai; j++) {
                banDo[i][j] = 0; // Mặc định ban đầu là đất trống
            }
        }
    }

    // --- BƯỚC 1.2: Hàm hủy (Destructor) ---
    // Giải phóng toàn bộ bộ nhớ mảng 2 chiều để tránh Memory Leak
    ~TrangTrai() {
        for (int i = 0; i < chieuRong; i++) {
            delete[] banDo[i]; // Giải phóng từng hàng
        }
        delete[] banDo; // Giải phóng mảng con trỏ hàng
    }

    // --- BƯỚC 1.3: Kiểm tra vị trí trống ---
    // Trả về true nếu tọa độ (x, y) nằm trong bản đồ và chưa có gì trồng ở đó
    bool kiemTraTrong(int x, int y) {
        if (x < 0 || x >= chieuRong || y < 0 || y >= chieuDai) return false;
        return banDo[x][y] == 0; 
    }

    // --- BƯỚC 1.4: Đánh dấu đối tượng lên bản đồ ---
    // loai = 1 (Cây), loai = 2 (Vật nuôi)
    void datDoiTuong(int x, int y, int loai) {
        if (x >= 0 && x < chieuRong && y >= 0 && y < chieuDai) {
            banDo[x][y] = loai;
        }
    }

    // --- BƯỚC 1.5: Xóa đối tượng khỏi bản đồ khi thu hoạch ---
    void xoaDoiTuong(int x, int y) {
        if (x >= 0 && x < chieuRong && y >= 0 && y < chieuDai) {
            banDo[x][y] = 0; // Đưa về ô trống
        }
    }

    // --- BƯỚC 1.6: In bản đồ ma trận ra màn hình ---
    void inBanDo() {
        cout << "\n--- BAN DO TRANG TRAI ---" << endl;
        for (int i = 0; i < chieuRong; i++) {
            for (int j = 0; j < chieuDai; j++) {
                if (banDo[i][j] == 0) cout << ". ";      // Dấu chấm đại diện ô trống
                else if (banDo[i][j] == 1) cout << "C "; // C đại diện cho Cây
                else if (banDo[i][j] == 2) cout << "V "; // V đại diện cho Vật nuôi
            }
            cout << endl;
        }
        cout << "-------------------------\n";
    }
};

// ==========================================
// 2. LỚP CÂY TRỒNG (CayTrong)
// ==========================================
/*
 * BƯỚC 2: XÂY DỰNG LỚP CÂY TRỒNG
 * - Quản lý các thuộc tính của cây: tên, loại cây, giá hạt giống, sản phẩm, thời gian,...
 * - Thực hiện các hành vi: Trồng cây, Tưới nước (++ và +), Giảm thời gian thu hoạch.
 */
class CayTrong {
private:
    string ten;
    int loaiCay;           // 1: Cây ăn trái, 2: Cây công nghiệp
    int giaHatGiong;
    string sanPham;
    int sanLuong;
    int thoiGianThuHoach;  // Đơn vị tính: Phút
    int toadoX;            // Tọa độ X trên bản đồ (-1 nếu chưa trồng)
    int toadoY;            // Tọa độ Y trên bản đồ (-1 nếu chưa trồng)

public:
    // --- BƯỚC 2.1: Phương thức tạo lập mặc định (Default Constructor) ---
    CayTrong() {
        ten = "";
        loaiCay = 1; 
        giaHatGiong = 0;
        sanPham = "Chua co";
        sanLuong = 1;              // Mặc định sản lượng = 1
        thoiGianThuHoach = 60;     // Mặc định thời gian = 60 phút
        toadoX = -1;
        toadoY = -1;
    }

    // --- BƯỚC 2.2: Phương thức tạo lập 6 tham số đầy đủ ---
    CayTrong(string t, int l, int g, string sp, int sl, int tg) {
        ten = t;
        loaiCay = (l == 2) ? 2 : 1; // Chỉ cho phép 1 hoặc 2
        giaHatGiong = g;
        sanPham = sp;
        sanLuong = sl;
        thoiGianThuHoach = tg;
        toadoX = -1;
        toadoY = -1;
    }

    // --- BƯỚC 2.3: Phương thức tạo lập 4 tham số (mặc định sản lượng & thời gian) ---
    CayTrong(string t, int l, int g, string sp) {
        ten = t;
        loaiCay = (l == 2) ? 2 : 1;
        giaHatGiong = g;
        sanPham = sp;
        sanLuong = 1;
        thoiGianThuHoach = 60;
        toadoX = -1;
        toadoY = -1;
    }

    // --- BƯỚC 2.4: Copy Constructor (Khởi tạo sao chép) ---
    CayTrong(const CayTrong& ct) {
        ten = ct.ten;
        loaiCay = ct.loaiCay;
        giaHatGiong = ct.giaHatGiong;
        sanPham = ct.sanPham;
        sanLuong = ct.sanLuong;
        thoiGianThuHoach = ct.thoiGianThuHoach;
        toadoX = ct.toadoX;
        toadoY = ct.toadoY;
    }

    // --- BƯỚC 2.5: Nạp chồng toán tử nhập >> ---
    friend istream& operator>>(istream& is, CayTrong& ct) {
        cout << "Nhap ten cay: "; 
        is >> ws;
        getline(is, ct.ten);
        cout << "Nhap loai cay (1: An trai, 2: Cong nghiep): "; is >> ct.loaiCay;
        cout << "Gia hat giong: "; is >> ct.giaHatGiong;
        cout << "Ten san pham: "; is >> ws; getline(is, ct.sanPham);
        cout << "San luong: "; is >> ct.sanLuong;
        cout << "Thoi gian thu hoach (phut): "; is >> ct.thoiGianThuHoach;
        return is;
    }

    // --- BƯỚC 2.6: Nạp chồng toán tử xuất << ---
    friend ostream& operator<<(ostream& os, const CayTrong& ct) {
        string tenLoai = (ct.loaiCay == 1) ? "An trai" : "Cong nghiep";
        os << "Cay: " << ct.ten << " | Loai: " << tenLoai 
           << " | SP: " << ct.sanPham << " | San luong: " << ct.sanLuong 
           << " | Thoi gian con: " << ct.thoiGianThuHoach << " phut";
        return os;
    }

    // --- BƯỚC 2.7: Phương thức Trồng Cây lên bản đồ ---
    bool trongCay(TrangTrai& tt, int x, int y) {
        // Kiểm tra xem vị trí (x, y) trên bản đồ có hợp lệ và đang trống hay không
        if (tt.kiemTraTrong(x, y)) {
            tt.datDoiTuong(x, y, 1); // 1 = Đánh dấu Cây trồng
            toadoX = x;
            toadoY = y;
            return true; // Trồng thành công
        }
        return false; // Trồng thất bại vì ô đã có vật/cây khác
    }

    // --- BƯỚC 2.8: Toán tử ++ tiền tố đại diện cho việc TƯỚI NƯỚC 1 LẦN ---
    // Giảm thời gian thu hoạch đi 15 phút
    CayTrong& operator++() {
        thoiGianThuHoach -= 15;
        if (thoiGianThuHoach < 0) thoiGianThuHoach = 0;
        return *this;
    }

    // --- BƯỚC 2.9: Toán tử + số nguyên đại diện cho việc TƯỚI NƯỚC NHIỀU LẦN ---
    // Ví dụ: CayTrong + 2 tương ứng giảm (15 * 2 = 30) phút
    CayTrong operator+(int soLan) {
        CayTrong ketQua = *this; // Tạo bản sao
        ketQua.thoiGianThuHoach -= (15 * soLan);
        if (ketQua.thoiGianThuHoach < 0) ketQua.thoiGianThuHoach = 0;
        return ketQua;
    }

    // Đặt lại thời gian thu hoạch trực tiếp sau khi tính toán bằng toán tử +
    void capNhatThoiGianTrucTiep(int tg) {
        thoiGianThuHoach = tg;
    }

    // Giảm thời gian trôi qua ngẫu nhiên/theo sự kiện ngủ
    void giamThoiGian(int phut) {
        thoiGianThuHoach -= phut;
        if (thoiGianThuHoach < 0) thoiGianThuHoach = 0;
    }

    // Getters lấy thông tin cơ bản
    int getThoiGian() { return thoiGianThuHoach; }
    int getX() { return toadoX; }
    int getY() { return toadoY; }
    string getTen() { return ten; }
    int tinhTien() { return sanLuong * (giaHatGiong * 2); } // Giá trị thu hồi khi bán sản phẩm
};

// ==========================================
// 3. LỚP VẬT NUÔI (VatNuoi - Tự đề xuất)
// ==========================================
/*
 * BƯỚC 3: XÂY DỰNG LỚP VẬT NUÔI
 * - Đề xuất thêm đối tượng Vật nuôi tương tự như Cây trồng để tăng tính đa dạng.
 */
class VatNuoi {
private:
    string ten;
    int loaiThu;          // 1: Gia súc, 2: Gia cầm
    int giaMua;
    string sanPham;
    int sanLuong;
    int thoiGianThuHoach;
    int toadoX;
    int toadoY;

public:
    VatNuoi(string t, int l, int g, string sp, int sl, int tg) {
        ten = t; 
        loaiThu = l; 
        giaMua = g; 
        sanPham = sp;
        sanLuong = sl; 
        thoiGianThuHoach = tg;
        toadoX = -1; 
        toadoY = -1;
    }

    // Đưa vật nuôi vào chuồng trên bản đồ
    bool thaChuong(TrangTrai& tt, int x, int y) {
        if (tt.kiemTraTrong(x, y)) {
            tt.datDoiTuong(x, y, 2); // 2 = Đánh dấu Vật nuôi
            toadoX = x;
            toadoY = y;
            return true;
        }
        return false;
    }

    void giamThoiGian(int phut) {
        thoiGianThuHoach -= phut;
        if (thoiGianThuHoach < 0) thoiGianThuHoach = 0;
    }

    friend ostream& operator<<(ostream& os, const VatNuoi& vn) {
        os << "Thu: " << vn.ten << " | SP: " << vn.sanPham 
           << " | Thoi gian con: " << vn.thoiGianThuHoach << " phut";
        return os;
    }

    int getThoiGian() { return thoiGianThuHoach; }
    int getX() { return toadoX; }
    int getY() { return toadoY; }
    string getTen() { return ten; }
    int tinhTien() { return sanLuong * (giaMua * 3); }
};

// ==========================================
// 4. LỚP NGƯỜI CHƠI (NguoiChoi)
// ==========================================
/*
 * BƯỚC 4: XÂY DỰNG LỚP NGƯỜI CHƠI QUẢN LÝ MẢNG CON TRỎ
 * - Quản lý tài nguyên: Vàng, Năng lượng, Level.
 * - Quản lý danh sách Cây trồng (`CayTrong** dsCay`) và Vật nuôi (`VatNuoi** dsThu`) dạng mảng con trỏ.
 * - Đảm bảo giải phóng bộ nhớ triệt để trong Hàm hủy (~NguoiChoi).
 */
class NguoiChoi {
private:
    int level;
    int vang;
    int nangLuong;

    // Danh sách Cây trồng quản lý bằng mảng các con trỏ (CayTrong*)
    CayTrong** dsCay; 
    int soCay;

    // Danh sách Vật nuôi quản lý bằng mảng các con trỏ (VatNuoi*)
    VatNuoi** dsThu;
    int soThu;

public:
    // --- BƯỚC 4.1: Khởi tạo thông số người chơi ---
    NguoiChoi() {
        level = 1;
        vang = 500;
        nangLuong = 10;
        dsCay = NULL;
        soCay = 0;
        dsThu = NULL;
        soThu = 0;
    }

    // --- BƯỚC 4.2: HÀM HỦY (QUAN TRỌNG TRÁNH MEMORY LEAK) ---
    // Duyệt qua từng con trỏ trong mảng để delete từng đối tượng, sau đó delete[] mảng con trỏ
    ~NguoiChoi() {
        // 解放 (Giải phóng) mảng cây trồng
        if (dsCay != NULL) {
            for (int i = 0; i < soCay; i++) {
                delete dsCay[i]; // Giải phóng đối tượng CayTrong
            }
            delete[] dsCay;     // Giải phóng mảng con trỏ
        }

        // 解放 (Giải phóng) mảng vật nuôi
        if (dsThu != NULL) {
            for (int i = 0; i < soThu; i++) {
                delete dsThu[i]; // Giải phóng đối tượng VatNuoi
            }
            delete[] dsThu;     // Giải phóng mảng con trỏ
        }
    }

    // --- BƯỚC 4.3: THÊM CÂY TRỒNG VÀO DANH SÁCH (Mảng con trỏ cấp phát động) ---
    void themCay(CayTrong* cayMoi) {
        // 1. Cấp phát mảng con trỏ mới lớn hơn mảng cũ 1 ô
        CayTrong** mangMoi = new CayTrong*[soCay + 1];

        // 2. Sao chép danh sách các con trỏ cũ sang mảng mới
        for (int i = 0; i < soCay; i++) {
            mangMoi[i] = dsCay[i];
        }

        // 3. Đưa con trỏ cây mới vào vị trí cuối cùng
        mangMoi[soCay] = cayMoi;

        // 4. Xóa mảng con trỏ cũ và trỏ sang mảng mới
        if (dsCay != NULL) delete[] dsCay;
        dsCay = mangMoi;
        soCay++;
    }

    // --- BƯỚC 4.4: XÓA CÂY TRỒNG KHỎI DANH SÁCH KHI THU HOẠCH ---
    void xoaCay(int viTri) {
        if (soCay == 0 || viTri < 0 || viTri >= soCay) return;

        // 1. Tạo mảng con trỏ mới nhỏ hơn mảng cũ 1 ô
        CayTrong** mangMoi = new CayTrong*[soCay - 1];

        // 2. Chép toàn bộ con trỏ ngoại trừ vị trí cần xóa
        int dem = 0;
        for (int i = 0; i < soCay; i++) {
            if (i != viTri) {
                mangMoi[dem] = dsCay[i];
                dem++;
            }
        }

        // 3. Giải phóng đối tượng cây trồng bị xóa
        delete dsCay[viTri];

        // 4. Xóa mảng cũ và cập nhật danh sách
        if (dsCay != NULL) delete[] dsCay;
        dsCay = mangMoi;
        soCay--;
    }

    // --- BƯỚC 4.5: Hành động TƯỚI NƯỚC (Giảm 1 năng lượng người chơi, giảm 15 phút thời gian cây) ---
    void tuoiNuoc(int viTri) {
        if (viTri < 0 || viTri >= soCay) return;

        if (nangLuong > 0) {
            nangLuong--;       // Giảm năng lượng người chơi
            ++(*dsCay[viTri]); // Gọi toán tử ++ của CayTrong
            cout << "Da tuoi nuoc cho " << dsCay[viTri]->getTen() 
                 << ". Nang luong con lai: " << nangLuong << endl;
        } else {
            cout << "Khong du nang luong de tuoi nuoc!" << endl;
        }
    }

    // --- BƯỚC 4.6: Hành động THU HOẠCH CÂY ---
    void thuHoachCay(TrangTrai& tt, int viTri) {
        if (viTri < 0 || viTri >= soCay) return;

        // Chỉ thu hoạch khi thời gian thu hoạch đã về 0
        if (dsCay[viTri]->getThoiGian() == 0) {
            int tien = dsCay[viTri]->tinhTien();
            vang += tien; // Cộng tài nguyên vàng cho người chơi

            // Xóa ký hiệu trên bản đồ trang trại
            tt.xoaDoiTuong(dsCay[viTri]->getX(), dsCay[viTri]->getY());

            cout << "Da thu hoach " << dsCay[viTri]->getTen() 
                 << "! Nhan duoc " << tien << " vang." << endl;

            // Giải phóng và xóa khỏi mảng con trỏ
            xoaCay(viTri);
        } else {
            cout << dsCay[viTri]->getTen() << " chua chin, chua the thu hoach!" << endl;
        }
    }

    // --- BƯỚC 4.7: TÍNH NĂNG MỚI (1Đ): NGỦ QUA ĐÊM ---
    // Phục hồi full năng lượng + Giảm 120 phút thời gian thu hoạch của tất cả các cây trồng
    void nguQuaDem() {
        cout << "\n[Hanh Dong] Nguoi choi di ngu qua dem..." << endl;
        nangLuong = 10; // Hồi phục tối đa năng lượng

        // Cập nhật lại toàn bộ thời gian thu hoạch của tất cả cây trồng trong danh sách
        for (int i = 0; i < soCay; i++) {
            dsCay[i]->giamThoiGian(120);
        }
        cout << "Qua mot dem: Thoi gian troi qua 120 phut. Nang luong hoi phục ve 10!\n";
    }

    // --- BƯỚC 4.8: In thông tin người chơi và danh sách cây ---
    void inThongTin() {
        cout << "\n=== THONG TIN NGUOI CHOI ===" << endl;
        cout << "Vang: " << vang << " | Nang Luong: " << nangLuong << endl;
        cout << "--- Danh Sach Cay Trong ---" << endl;
        if (soCay == 0) cout << "(Rong)" << endl;
        for (int i = 0; i < soCay; i++) {
            cout << "[" << i << "] " << *dsCay[i] << endl;
        }
        cout << "============================\n";
    }
};

// ==========================================
// 5. HÀM MAIN - MÔ PHỎNG LUỒNG TRÒ CHƠI
// ==========================================
int main() {
    cout << "=======================================" << endl;
    cout << "   DEMO TRO CHOI NONG TRAI OOP C++    " << endl;
    cout << "=======================================" << endl;

    // KỊCH BẢN MÔ PHỎNG BẰNG CÁC BƯỚC LOGIC:

    // --- BƯỚC MAIN 1: Khởi tạo Bản đồ và Người chơi ---
    TrangTrai map(5, 5); // Tạo bản đồ 5x5
    NguoiChoi player;    // Tạo người chơi với số vốn mặc định

    // --- BƯỚC MAIN 2: Người chơi trồng cây vào bản đồ ---
    cout << "\n=> BƯOC 1: NGUOI CHOI TRONG CAY TRONG" << endl;

    // Tạo cây Táo bằng con trỏ động
    CayTrong* tao = new CayTrong("Cay Tao", 1, 20, "Qua Tao", 5, 60);
    if (tao->trongCay(map, 1, 1)) {
        player.themCay(tao); // Thêm con trỏ vào mảng người chơi
        cout << "Trong Cay Tao thanh cong tai vi tri (1, 1)" << endl;
    } else {
        delete tao; // Giải phóng nếu trồng không thành công
    }

    // Tạo cây Lúa Mì bằng con trỏ động
    CayTrong* lua = new CayTrong("Lua Mi", 2, 10, "Thoc", 10, 40);
    if (lua->trongCay(map, 2, 2)) {
        player.themCay(lua);
        cout << "Trong Lua Mi thanh cong tai vi tri (2, 2)" << endl;
    } else {
        delete lua;
    }

    // Hiển thị trạng thái bản đồ và thông tin người chơi
    map.inBanDo();
    player.inThongTin();

    // --- BƯỚC MAIN 3: Chăm sóc cây cối ---
    cout << "\n=> BƯOC 2: CHAM SOC CAY COI (TUOI NUOC)" << endl;

    // Tưới nước bằng toán tử ++ (Tốn 1 năng lượng, giảm 15 phút)
    player.tuoiNuoc(0); // Tưới cây đầu tiên (Cây Táo)

    // Tưới nước bằng toán tử + (Ví dụ: Tưới 2 lần cho Lúa Mì)
    cout << "Tuoi nuoc 2 lan cho Lua Mi bang toan tu + :" << endl;
    CayTrong luaSauKhiTuoi = *lua + 2; // Giảm 30 phút trên bản sao
    lua->capNhatThoiGianTrucTiep(luaSauKhiTuoi.getThoiGian()); // Cập nhật lại cho cây thật

    player.inThongTin();

    // --- BƯỚC MAIN 4: Kích hoạt Tính năng mới (Ngủ qua đêm) ---
    cout << "\n=> BƯOC 3: KICH HOAT TINH NANG MOI (NGU QUA DEM)" << endl;
    player.nguQuaDem(); 
    player.inThongTin(); // Lúc này thời gian thu hoạch của tất cả cây đều đã về 0 (chín)

    // --- BƯỚC MAIN 5: Thu hoạch cây trồng ---
    cout << "\n=> BƯOC 4: THU HOACH SAN PHAM" << endl;
    // Thu hoạch cây tại chỉ số 0 (Cây Táo)
    player.thuHoachCay(map, 0); 

    // Vì Cây Táo bị xóa nên Lúa Mì được dồn lên chỉ số 0
    player.thuHoachCay(map, 0); 

    // --- BƯỚC MAIN 6: Kết quả cuối cùng ---
    cout << "\n=> KET QUA CUOI CUNG SAU KHI THU HOACH:" << endl;
    player.inThongTin();
    map.inBanDo(); // Bản đồ trở về trạng thái trống (toàn bộ là dấu .)

    return 0; // Khi kết thúc hàm main, Destructor (~NguoiChoi và ~TrangTrai) sẽ tự động giải phóng toàn bộ bộ nhớ còn lại.
}