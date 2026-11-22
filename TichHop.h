#ifndef QUEUE_SYSTEM_H
#define QUEUE_SYSTEM_H

#include "Phong_ServiceCounter.h"
#include <string>
#include <utility>
#include <vector>

struct HeThong {
    std::vector<QuayGiaoDich> quay;
    int sttTiepTheo = 1;
    bool coGoi = false;
    int sttGoiGanNhat = 0;
    int quayGoiGanNhat = 0;
};

struct ThongKeHeThong {
    int soQuay = 0;
    int tongCho = 0;
    int tongGoi = 0;
    int tongHoanThanh = 0;
};

void khoiTaoMau(HeThong& h);
bool khoiTaoThuCong(
    HeThong& h,
    const std::vector<std::pair<std::string, std::string>>& danhSach
);

bool capSo(HeThong& h, int viTriQuay, KhachHang& kh, int& soChoTruoc);

bool goiTiep(HeThong& h, int viTriQuay, KhachHang& kh);
bool goiLai(const HeThong& h, int viTriQuay);
bool hoanTat(HeThong& h, int viTriQuay);

void hienThiCacQuay(const HeThong& h);
void hienThiTiepTheo(const HeThong& h);
void manHinhCho(const HeThong& h);
void hienThiThongKe(const HeThong& h);

bool xemSoTiepTheo(const HeThong& h, int viTriQuay, KhachHang& kh);
ThongKeHeThong layThongKe(const HeThong& h);
void giaiPhongHeThong(HeThong& h);

#endif
