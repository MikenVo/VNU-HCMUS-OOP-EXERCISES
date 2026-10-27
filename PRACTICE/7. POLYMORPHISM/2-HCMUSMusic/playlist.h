#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "song.h"

class Playlist {
private:
    std::string TenPlaylist;
    std::vector<BaiHat*> DanhSachBaiHat;

public:
    void ThemBaiHat(BaiHat *bh);
    void XoaBaiHat(std::string tenBH);
    void InPlaylist();
};