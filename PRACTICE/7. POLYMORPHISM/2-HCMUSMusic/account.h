#pragma once
#include <iostream>
#include <string>
#include "playlist.h"

class TaiKhoan {
protected:
    std::string TenDangNhap;
    std::string MatKhau;
    Playlist DanhSachNhacCaNhan;

public:

    void InPlaylistCaNhan();
    bool KiemTraMatKhauHopLe(std::string pass);
    void SetThongTinDangNhap(std::string u, std::string p);
    bool DangNhap();
    virtual void NgheNhac(BaiHat *bh) = 0;
    void ThemVaoPlaylist(BaiHat *bh);
    void XoaKhoiPlaylist(std::string tenBH);

    std::string GetTenDangNhap() const;
    std::string GetMatKhau() const;

    virtual ~TaiKhoan() {}
};

class TaiKhoanThuong : public TaiKhoan {
public:
    void NgheNhac(BaiHat *bh) override;
};

class TaiKhoanVip : public TaiKhoan {
private:
    int ThoiHanDuyTri;
    double MucPhiDuyTriHangThang;

public:
    void NgheNhac(BaiHat *bh) override;
    void GoiYBaiHat(std::string theLoai, const std::vector<BaiHat *> &dsAll);
    void GiaHanTaiKhoan(double soTienNap);
};