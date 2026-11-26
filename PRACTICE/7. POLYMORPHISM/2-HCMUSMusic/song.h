#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>

class BaiHat {
protected:
    std::string TenBaiHat;
    std::string LoiBaiHat;
    std::string TenCaSy;
    std::string TheLoai;
    int NamSangTac;
    int LuotNghe;

public:
    virtual ~BaiHat();
    int LayLuotNghe() const;
    std::string LayTheLoai() const;
    std::string LayTenBaiHat() const;
    std::string LayTenCaSy() const;

    virtual void NhapThongTin();
    virtual void XuatThongTin();
    virtual float TinhGiaTien(bool isVip) = 0;
};

class BaiHatPhoThong : public BaiHat {
public:
    void NhapThongTin() override;
    void XuatThongTin() override;
    float TinhGiaTien(bool isVip) override;
};

class BaiHatBanQuyen : public BaiHat {
private:
    float GiaTriBanQuyen;

public:
    void NhapThongTin() override;
    void XuatThongTin() override;
    float TinhGiaTien(bool isVip) override;
};

#endif