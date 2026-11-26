#include <iostream>
#include <string>

using namespace std;

// ==========================================
// 1. LỚP TRANG TRẠI (Quản lý bản đồ game)
// ==========================================
class TrangTrai
{
private:
    int **banDo; // Mảng 2 chiều: 0 là đất trống, 1 là Cây, 2 là Vật nuôi
    int chieuRong;
    int chieuDai;

public:
    // Khởi tạo trang trại và cấp phát mảng 2 chiều
    TrangTrai(int r = 10, int d = 10)
    {
        chieuRong = r;
        chieuDai = d;
        banDo = new int *[chieuRong];
        for (int i = 0; i < chieuRong; i++)
        {
            banDo[i] = new int[chieuDai];
            for (int j = 0; j < chieuDai; j++)
            {
                banDo[i][j] = 0; // 0 nghĩa là ô đất đang trống
            }
        }
    }

    // Hàm hủy: Xóa mảng 2 chiều để tránh Memory Leak
    ~TrangTrai()
    {
        for (int i = 0; i < chieuRong; i++)
        {
            delete[] banDo[i];
        }
        delete[] banDo;
    }

    // Kiểm tra xem vị trí x, y có nằm trong bản đồ và đang trống không
    bool kiemTraTrong(int x, int y)
    {
        if (x < 0 || x >= chieuRong || y < 0 || y >= chieuDai)
            return false;
        return banDo[x][y] == 0;
    }

    // Đánh dấu trên bản đồ (loai = 1 là cây, 2 là vật nuôi)
    void datDoiTuong(int x, int y, int loai)
    {
        banDo[x][y] = loai;
    }

    // Xóa đối tượng khỏi bản đồ (gán lại bằng 0)
    void xoaDoiTuong(int x, int y)
    {
        banDo[x][y] = 0;
    }

    // In bản đồ ra màn hình cho dễ nhìn
    void inBanDo()
    {
        cout << "\n--- BAN DO ---" << endl;
        for (int i = 0; i < chieuRong; i++)
        {
            for (int j = 0; j < chieuDai; j++)
            {
                if (banDo[i][j] == 0)
                    cout << ". ";
                else if (banDo[i][j] == 1)
                    cout << "C "; // C = Cây
                else if (banDo[i][j] == 2)
                    cout << "V "; // V = Vật nuôi
            }
            cout << endl;
        }
        cout << "--------------\n";
    }
};

// ==========================================
// 2. LỚP CÂY TRỒNG
// ==========================================
class CayTrong
{
private:
    string ten;
    int loaiCay; // 1: Cây ăn trái, 2: Cây công nghiệp (thay cho enum để đơn giản hơn)
    int giaHatGiong;
    string sanPham;
    int sanLuong;
    int thoiGianThuHoach;
    int toadoX; // Lưu vị trí x trên bản đồ
    int toadoY; // Lưu vị trí y trên bản đồ

public:
    // Tạo lập mặc định
    CayTrong()
    {
        ten = "";
        loaiCay = 1;
        giaHatGiong = 0;
        sanPham = "Chua co";
        sanLuong = 1;
        thoiGianThuHoach = 60;
        toadoX = -1;
        toadoY = -1;
    }

    // Tạo lập 6 tham số
    CayTrong(string t, int l, int g, string sp, int sl, int tg)
    {
        ten = t;
        loaiCay = l;
        giaHatGiong = g;
        sanPham = sp;
        sanLuong = sl;
        thoiGianThuHoach = tg;
        toadoX = -1;
        toadoY = -1;
    }

    // Tạo lập 4 tham số (sản lượng và thời gian lấy mặc định)
    CayTrong(string t, int l, int g, string sp)
    {
        ten = t;
        loaiCay = l;
        giaHatGiong = g;
        sanPham = sp;
        sanLuong = 1;
        thoiGianThuHoach = 60;
        toadoX = -1;
        toadoY = -1;
    }

    // Copy Constructor (Sao chép)
    CayTrong(const CayTrong &ct)
    {
        ten = ct.ten;
        loaiCay = ct.loaiCay;
        giaHatGiong = ct.giaHatGiong;
        sanPham = ct.sanPham;
        sanLuong = ct.sanLuong;
        thoiGianThuHoach = ct.thoiGianThuHoach;
        toadoX = ct.toadoX;
        toadoY = ct.toadoY;
    }

    // Toán tử nhập
    friend istream &operator>>(istream &is, CayTrong &ct)
    {
        cout << "Nhap ten cay: ";
        is >> ws; // xóa khoảng trắng thừa
        getline(is, ct.ten);
        cout << "Nhap loai cay (1: An trai, 2: Cong nghiep): ";
        is >> ct.loaiCay;
        cout << "Gia hat giong: ";
        is >> ct.giaHatGiong;
        cout << "Ten san pham: ";
        is >> ws;
        getline(is, ct.sanPham);
        cout << "San luong: ";
        is >> ct.sanLuong;
        cout << "Thoi gian thu hoach: ";
        is >> ct.thoiGianThuHoach;
        return is;
    }

    // Toán tử xuất
    friend ostream &operator<<(ostream &os, const CayTrong &ct)
    {
        string tenLoai = (ct.loaiCay == 1) ? "An trai" : "Cong nghiep";
        os << "Cay: " << ct.ten << " | Loai: " << tenLoai
           << " | SP: " << ct.sanPham << " | San luong: " << ct.sanLuong
           << " | Thoi gian con: " << ct.thoiGianThuHoach << " phut";
        return os;
    }

    // Phương thức trồng cây: Truyền bản đồ vào để kiểm tra
    bool trongCay(TrangTrai &tt, int x, int y)
    {
        if (tt.kiemTraTrong(x, y) == true)
        {
            tt.datDoiTuong(x, y, 1); // 1 là đánh dấu Cây
            toadoX = x;
            toadoY = y;
            return true;
        }
        return false;
    }

    // Tưới nước 1 lần (Toán tử ++)
    CayTrong &operator++()
    {
        thoiGianThuHoach -= 15;
        if (thoiGianThuHoach < 0)
            thoiGianThuHoach = 0;
        return *this;
    }

    // Tưới nước nhiều lần (Toán tử +)
    CayTrong operator+(int soLan)
    {
        CayTrong ketQua = *this; // Tạo bản sao
        ketQua.thoiGianThuHoach -= (15 * soLan);
        if (ketQua.thoiGianThuHoach < 0)
            ketQua.thoiGianThuHoach = 0;
        return ketQua; // Trả về bản sao đã giảm thời gian
    }

    // Hàm phụ trợ để gán lại kết quả sau khi dùng toán tử +
    void capNhatThoiGianTrucTiep(int tg)
    {
        thoiGianThuHoach = tg;
    }

    // Giảm thời gian trôi qua (phục vụ tính năng Ngủ qua đêm)
    void giamThoiGian(int phut)
    {
        thoiGianThuHoach -= phut;
        if (thoiGianThuHoach < 0)
            thoiGianThuHoach = 0;
    }

    // Các hàm lấy thông tin (Getters)
    int getThoiGian() { return thoiGianThuHoach; }
    int getX() { return toadoX; }
    int getY() { return toadoY; }
    string getTen() { return ten; }
    int tinhTien() { return sanLuong * (giaHatGiong * 2); } // Tính tiền khi thu hoạch
};

// ==========================================
// 3. LỚP VẬT NUÔI (Sinh viên tự đề xuất - 1.5đ)
// ==========================================
// Rất giống Cây Trồng, code ngắn gọn dễ hiểu
class VatNuoi
{
private:
    string ten;
    int loaiThu; // 1: Gia súc, 2: Gia cầm
    int giaMua;
    string sanPham;
    int sanLuong;
    int thoiGianThuHoach;
    int toadoX;
    int toadoY;

public:
    VatNuoi(string t, int l, int g, string sp, int sl, int tg)
    {
        ten = t;
        loaiThu = l;
        giaMua = g;
        sanPham = sp;
        sanLuong = sl;
        thoiGianThuHoach = tg;
        toadoX = -1;
        toadoY = -1;
    }

    // Nuôi vào chuồng (giống Trồng cây)
    bool thaChuong(TrangTrai &tt, int x, int y)
    {
        if (tt.kiemTraTrong(x, y) == true)
        {
            tt.datDoiTuong(x, y, 2); // 2 là đánh dấu Vật Nuôi
            toadoX = x;
            toadoY = y;
            return true;
        }
        return false;
    }

    void giamThoiGian(int phut)
    {
        thoiGianThuHoach -= phut;
        if (thoiGianThuHoach < 0)
            thoiGianThuHoach = 0;
    }

    friend ostream &operator<<(ostream &os, const VatNuoi &vn)
    {
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
// 4. LỚP NGƯỜI CHƠI (Quản lý mảng con trỏ)
// ==========================================
class NguoiChoi
{
private:
    int level;
    int vang;
    int nangLuong;

    // Danh sách Cây Trồng lưu bằng mảng con trỏ
    CayTrong **dsCay;
    int soCay;

    // Danh sách Vật Nuôi lưu bằng mảng con trỏ
    VatNuoi **dsThu;
    int soThu;

public:
    NguoiChoi()
    {
        level = 1;
        vang = 500;
        nangLuong = 10;
        dsCay = NULL;
        soCay = 0;
        dsThu = NULL;
        soThu = 0;
    }

    // HÀM HỦY RẤT QUAN TRỌNG: Giải phóng bộ nhớ mảng con trỏ
    ~NguoiChoi()
    {
        // Xóa danh sách cây
        if (dsCay != NULL)
        {
            for (int i = 0; i < soCay; i++)
            {
                delete dsCay[i]; // Xóa từng cây
            }
            delete[] dsCay; // Xóa mảng
        }
        // Xóa danh sách thú
        if (dsThu != NULL)
        {
            for (int i = 0; i < soThu; i++)
            {
                delete dsThu[i];
            }
            delete[] dsThu;
        }
    }

    // === THÊM CÂY VÀO DANH SÁCH BẰNG MẢNG ĐỘNG ===
    void themCay(CayTrong *cayMoi)
    {
        // 1. Tạo mảng mới bự hơn 1 ô
        CayTrong **mangMoi = new CayTrong *[soCay + 1];
        // 2. Chép dữ liệu từ mảng cũ sang mảng mới
        for (int i = 0; i < soCay; i++)
        {
            mangMoi[i] = dsCay[i];
        }
        // 3. Đưa cây mới vào cuối mảng
        mangMoi[soCay] = cayMoi;
        // 4. Xóa mảng cũ đi và cập nhật lại
        if (dsCay != NULL)
            delete[] dsCay;
        dsCay = mangMoi;
        soCay++;
    }

    // === XÓA CÂY KHỎI DANH SÁCH (KHI THU HOẠCH) ===
    void xoaCay(int viTri)
    {
        if (soCay == 0 || viTri < 0 || viTri >= soCay)
            return;

        CayTrong **mangMoi = new CayTrong *[soCay - 1];
        int dem = 0;
        for (int i = 0; i < soCay; i++)
        {
            if (i != viTri)
            {
                mangMoi[dem] = dsCay[i];
                dem++;
            }
        }
        delete dsCay[viTri]; // Giải phóng cây bị xóa
        if (dsCay != NULL)
            delete[] dsCay;
        dsCay = mangMoi;
        soCay--;
    }

    // Tính năng TƯỚI NƯỚC (tốn 1 năng lượng)
    void tuoiNuoc(int viTri)
    {
        if (viTri < 0 || viTri >= soCay)
            return;

        if (nangLuong > 0)
        {
            nangLuong--;       // Giảm năng lượng
            ++(*dsCay[viTri]); // Gọi toán tử ++ của cây trồng
            cout << "Da tuoi nuoc cho " << dsCay[viTri]->getTen()
                 << ". Nang luong con lai: " << nangLuong << endl;
        }
        else
        {
            cout << "Het nang luong roi!" << endl;
        }
    }

    // Tính năng THU HOẠCH
    void thuHoachCay(TrangTrai &tt, int viTri)
    {
        if (viTri < 0 || viTri >= soCay)
            return;

        if (dsCay[viTri]->getThoiGian() == 0)
        {
            // Cây đã chín
            int tien = dsCay[viTri]->tinhTien();
            vang += tien;                                               // Cộng tiền
            tt.xoaDoiTuong(dsCay[viTri]->getX(), dsCay[viTri]->getY()); // Xóa trên bản đồ
            cout << "Da thu hoach " << dsCay[viTri]->getTen() << ". Cong: " << tien << " vang." << endl;
            xoaCay(viTri); // Xóa khỏi danh sách quản lý
        }
        else
        {
            cout << "Cay chua chin, khong the thu hoach!" << endl;
        }
    }

    // === TÍNH NĂNG MỚI (1 Điểm): NGỦ QUA ĐÊM ===
    // Phục hồi năng lượng tối đa, ép thời gian trôi đi 120 phút cho toàn bộ danh sách
    void nguQuaDem()
    {
        cout << "\n[Hanh dong] Nguoi choi di ngu..." << endl;
        nangLuong = 10; // Hồi phục max

        // Cập nhật lại toàn bộ thời gian thu hoạch (Yêu cầu đề bài 0.5đ)
        for (int i = 0; i < soCay; i++)
        {
            dsCay[i]->giamThoiGian(120);
        }
        cout << "Thoi gian da troi qua 120 phut. Nang luong hoi phuc de!\n";
    }

    void inThongTin()
    {
        cout << "Vang: " << vang << " | Nang luong: " << nangLuong << endl;
        cout << "--- DANH SACH CAY ---" << endl;
        for (int i = 0; i < soCay; i++)
        {
            cout << "[" << i << "] " << *dsCay[i] << endl;
        }
    }
};

// ==========================================
// 5. HÀM MAIN (Mô phỏng trò chơi theo yêu cầu)
// ==========================================
int main()
{
    cout << "=== GAME NONG TRAI OOP ===" << endl;

    TrangTrai map(5, 5); // Khởi tạo bản đồ 5x5
    NguoiChoi player;

    // 1. Quá trình người chơi trồng cây (Dùng con trỏ theo yêu cầu)
    cout << "\n=> 1. NGUOI CHOI TRONG CAY:" << endl;

    CayTrong *tao = new CayTrong("Cay Tao", 1, 20, "Qua Tao", 5, 60);
    if (tao->trongCay(map, 1, 1) == true) {
        player.themCay(tao); // Chỉ thêm vào danh sách nếu trồng lên map thành công
        cout << "Trong Cay Tao thanh cong tai (1,1)" << endl;
    }
    else {
        delete tao; // Trồng thất bại thì xóa đi tránh leak
    }

    CayTrong *lua = new CayTrong("Lua Mi", 2, 10, "Thoc", 10, 40);
    if (lua->trongCay(map, 2, 2) == true) {
        player.themCay(lua);
        cout << "Trong Lua Mi thanh cong tai (2,2)" << endl;
    }
    else {
        delete lua;
    }

    map.inBanDo();
    player.inThongTin();

    // 2. Chăm sóc cây cối bằng toán tử ++ và +
    cout << "\n=> 2. CHAM SOC CAY COI:" << endl;
    // Tưới bằng cách ++ (Tốn năng lượng)
    player.tuoiNuoc(0); // Tưới cây táo ở vị trí số 0

    // Tưới bằng toán tử + số nguyên (Ví dụ: Lua Mi + 2)
    cout << "Tuoi nuoc 2 lan cho Lua mi bang toan tu + :" << endl;
    CayTrong luaSauKhiTuoi = *lua + 2;                         // Giảm 30 phút vào biến tạm
    lua->capNhatThoiGianTrucTiep(luaSauKhiTuoi.getThoiGian()); // Gán lại vào con trỏ gốc

    player.inThongTin();

    // 3. Kích hoạt tính năng mới: Ngủ qua đêm để thời gian trôi qua nhanh
    cout << "\n=> 3. KICH HOAT TINH NANG MOI:" << endl;
    player.nguQuaDem();
    player.inThongTin(); // In ra để thấy thời gian thu hoạch tất cả đã về 0 (chín)

    // 4. Thu hoạch (Nhận tiền, xóa khỏi bản đồ, xóa khỏi mảng con trỏ)
    cout << "\n=> 4. THU HOACH:" << endl;
    player.thuHoachCay(map, 0); // Thu hoạch cây đầu tiên trong mảng (Cây Táo)

    // Vì Cây Táo bị xóa, mảng bị dồn lại nên Lúa Mì sẽ rớt xuống vị trí số 0
    player.thuHoachCay(map, 0); // Thu hoạch Lúa Mì

    cout << "\n=> KET QUA CUOI CUNG:" << endl;
    player.inThongTin();
    map.inBanDo(); // Bản đồ sẽ trống trơn vì đã bị thu hoạch sạch

    return 0; // Tự động gọi Destructor giải phóng sạch bộ nhớ
}