#include <iostream>
#include <string>
#include <vector>
using namespace std;

// - Can cho nhap ho va ten, ngay sinh, ma so nhan su. Luong chua can nhap vi con tuy vao tung vi tri
class NhanVien {
protected:
	string hoten;
	string ngaysinh;
	string masons;
	float luong;

public:
	virtual NhanVien* clone() const = 0;
	virtual bool KiemTraLoai(const string& loai) const = 0;

	virtual void TinhLuong() = 0; // Tinh luong du tren tung vi tri nhan su
	float LayLuong();
	virtual void GiaoViec() = 0; // Giao viec tuy theo vi tri
	string LayMSNV();
	friend istream& operator>>(istream& is, NhanVien& nv); // Nhap
	virtual void NhapThongTin(istream& is); // Nhap thong tin sau khi nhan ban
	virtual void InThongTin() = 0; // In toan bo thong tin cua mot nhan vien
	virtual ~NhanVien() {}; // Huy doi tuong
};





// - Giang vien thi ngoai cac thong tin co ban con co Hoc ham, Hoc vi, So nam giang day va Danh sach hoc phan dang dam nhiem
// - Tu day cung tinh luong cua Giang vien de gan vao muc luong hien tai
class GiangVien : public NhanVien {
private:
	string hocham;
	string hocvi;
	unsigned int so_nam_giangday;
	vector<string> dshp;

public:
	NhanVien* clone() const override;
	bool KiemTraLoai(const string& loai) const override;

	void TinhLuong() override; // Tinh luong cua giang vien
	void GiaoViec() override;
	void NhapThongTin(istream& is) override;
	void InThongTin() override; // In toan bo thong tin cua mot giang vien
	~GiangVien() override {};
};




// - Tro giang chi can cho biet So mon tro giang
// - Tinh luong de gan vao luong hien tai
class TroGiang : public NhanVien {
private:
	unsigned int so_mon_trogiang;

public:
	NhanVien* clone() const override;
	bool KiemTraLoai(const string& loai) const override;

	void TinhLuong() override; // Tinh luong cua tro giang
	void GiaoViec() override;
	void NhapThongTin(istream& is) override;
	void InThongTin() override; // In thong tin chi tiet
	~TroGiang() override {};
};





// - Nghien cuu vien co Danh sach du an nghien cuu va So nam lam viec
class NghienCuuVien : public NhanVien {
private:
	vector<string> duanNC;
	unsigned int so_nam_kinhnghiem;

public:
	NhanVien* clone() const override;
	bool KiemTraLoai(const string& loai) const override;

	void TinhLuong() override; // Tinh luong cho nghien cuu vien
	void GiaoViec() override;
	void NhapThongTin(istream& is) override;
	void InThongTin() override; // In thong tin chi tiet
	~NghienCuuVien() override {};
};





// - Chuyen vien co Danh sach du an giao duc va So nam kinh nghiem
class ChuyenVien : public NhanVien {
private:
	vector<string> duanGD;
	unsigned int so_nam_kinhnghiem;

public:
	NhanVien* clone() const override;
	bool KiemTraLoai(const string& loai) const override;

	void TinhLuong() override; // Tinh luong cho chuyen vien
	void GiaoViec() override;
	void NhapThongTin(istream& is) override;
	void InThongTin() override;
	~ChuyenVien() override {};
};





class ThucTapSinh : public NhanVien {
private:
	unsigned int so_thang_thuc_tap;
	vector<string> duanDB;

public:
	NhanVien* clone() const override;
	bool KiemTraLoai(const string& loai) const override;

	void TinhLuong() override;
	void GiaoViec() override;
	void NhapThongTin(istream& is) override;
	void InThongTin() override;
	~ThucTapSinh() override {};
};





class PhongQuanLy {
private:
	static PhongQuanLy* instance;

	PhongQuanLy() {}

	PhongQuanLy(const PhongQuanLy&) = delete; // Huy copy
	PhongQuanLy& operator=(const PhongQuanLy&) = delete; // Huy gan
	// Bao ve tinh duy nhat cua doi tuong

	std::vector<NhanVien*> dsns;
	std::vector<NhanVien*> dsMau;
public:
	static PhongQuanLy* GetInstance();
	static void DeleteInstance();

	void DangKyMau(NhanVien* mau);
	void ThemNhanSuTheoLoai(const std::string& loai);
	int TimNhanVien(const std::string& maso);
	void XoaNhanVien(const std::string& maSo);
	void GiaoViecchoNhanVien(int index);
	float TinhTongLuong();
	void InDanhSachNhanSu();
	int LaySoluongNhanSu();
	void TimNhanVienLuongCao();

	~PhongQuanLy();
};