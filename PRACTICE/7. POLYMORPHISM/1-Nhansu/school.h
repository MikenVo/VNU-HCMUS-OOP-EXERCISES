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
	virtual void TinhLuong() = 0; // Tinh luong du tren tung vi tri nhan su
	float LayLuong();
	virtual void GiaoViec() = 0; // Giao viec tuy theo vi tri
	string LayMSNV();
	void GanLuong(float luongmoi); // Gan luong moi vao luong hien tai
	friend istream& operator>>(istream& is, NhanVien& nv); // Nhap
	virtual void InThongTin() = 0; // In toan bo thong tin cua mot nhan vien
	virtual ~NhanVien() = 0; // Huy doi tuong
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
	void TinhLuong() override; // Tinh luong cua giang vien
	void GiaoViec() override;
	friend istream& operator>>(istream& is, GiangVien& gv); // Nhap
	void InThongTin() override; // In toan bo thong tin cua mot giang vien
	~GiangVien() override;
};




// - Tro giang chi can cho biet So mon tro giang
// - Tinh luong de gan vao luong hien tai
class TroGiang : public NhanVien {
private:
	unsigned int so_mon_trogiang;

public:
	void TinhLuong() override; // Tinh luong cua tro giang
	void GiaoViec() override;
	friend istream& operator>>(istream& is, TroGiang& tg); // Nhap
	void InThongTin() override; // In thong tin chi tiet
	~TroGiang() override;
};





// - Nghien cuu vien co Danh sach du an nghien cuu va So nam lam viec
class NghienCuuVien : public NhanVien {
private:
	vector<string> duanNC;
	unsigned int so_nam_kinhnghiem;

public:
	void TinhLuong() override; // Tinh luong cho nghien cuu vien
	void GiaoViec() override;
	friend istream& operator>>(istream& is, NghienCuuVien& ncv); // Nhap
	void InThongTin() override; // In thong tin chi tiet
	~NghienCuuVien() override;
};





// - Chuyen vien co Danh sach du an giao duc va So nam kinh nghiem
class ChuyenVien : public NhanVien {
private:
	vector<string> duanGD;
	unsigned int so_nam_kinhnghiem;

public:
	void TinhLuong() override; // Tinh luong cho chuyen vien
	void GiaoViec() override;
	friend istream& operator>>(istream& is, ChuyenVien& cv);
	void InThongTin() override;
	~ChuyenVien() override;
};





class ThucTapSinh : public NhanVien {
private:
	unsigned int so_thang_thuc_tap;
	vector<string> duanDB;

public:
	void TinhLuong() override;
	void GiaoViec() override;
	friend istream& operator>>(istream& is, ThucTapSinh& tts);
	void InThongTin() override;
	~ThucTapSinh() override;
};





class TruongHoc {
private:
	vector<NhanVien*> dsns;                 // Danh sach nhan su

public:
	void ThemNhanSu(NhanVien* nvmoi);
	float TinhTongLuong(); // Tinh tong luon can tra
	int LaySoluongNhanSu();
	int TimNhanVien(string name);
	void TimNhanVienLuongCao();
	void GiaoViecchoNhanVien(int index);
	void XoaNhanVien();
	~TruongHoc();
	void InDanhSachNhanSu();
};