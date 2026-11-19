#include <iostream>
#include <string>
#include <vector>
using namespace std;

class HocPhan {
    private:
        string tenhocphan;
        int sotinchi;

    public:
        string LayTenHocPhan();
        int LaySotinchi();

        friend istream &operator>>(istream &is, HocPhan &hp);
        friend ostream &operator<<(ostream &os, const HocPhan &hp);
};

class NhanVien {
protected:
    string hoten;
    string ngaysinh;
    string maso;
    float luong;

public:
    float LayLuong();
    virtual void tinhLuong() = 0;
    virtual void XuatThongtin() = 0;
    virtual ~NhanVien() = default;

    friend istream &operator>>(istream &is, NhanVien &nv);
    friend ostream &operator<<(ostream &os, const NhanVien &nv);
};

class GiangVien : public NhanVien {
private:
    string hocham;
    string hocvi;
    int sonamday;
    vector<HocPhan> dshp;

public:
    void ThemHocPhan(HocPhan hp);
    void tinhLuong() override;
    void XuatThongtin() override;

    friend istream &operator>>(istream &is, GiangVien &gv);
    friend ostream &operator<<(ostream &os, const GiangVien &gv);
};

class TroGiang : public NhanVien {
private:
    int somontrogiang;

public:
    void tinhLuong() override;
    void XuatThongtin() override;

    friend istream &operator>>(istream &is, TroGiang &tg);
    friend ostream &operator<<(ostream &os, const TroGiang &tg);
};

class NghienCuuVien : public NhanVien {
private:
    vector<string> dsdl;
    int sonamlam;

public:
    void ThemDuAnNghienCuu(string maduan);
    void tinhLuong() override;
    void XuatThongtin() override;

    friend istream &operator>>(istream &is, NghienCuuVien &ncv);
    friend ostream &operator<<(ostream &os, const NghienCuuVien &ncv);
};

class ChuyenVien : public NhanVien {
private:
    vector<string> dsht;
    int sonamlam;

public:
    void tinhLuong() override;
    void XuatThongtin() override;

    friend istream &operator>>(istream &is, ChuyenVien &cv);
    friend ostream &operator<<(ostream &os, const ChuyenVien &cv);
};

class TruongHoc {
private:
    vector<NhanVien *> dsNhansu;

public:
    void ThemNhanSu(NhanVien *nvMoi);
    void XuatDanhSach();
    float tinhTongLuong();
    ~TruongHoc();
};