#ifndef QUEUE_SYSTEM_H
#define QUEUE_SYSTEM_H

#include "Phong_ServiceCounter.h"
#include <string>
#include <utility>
#include <vector>

// ============================================================
// PHAN 6 - TRUNG: TICH HOP
// Day la giao dien lien ket cac phan cua ca nhom.
// Bo kiem thu nam RIENG trong 03_Testing/TestCase.cpp.
// ============================================================
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

// PHAN 3 - PHONG: Khoi tao quay.
void khoiTaoMau(HeThong& h);
bool khoiTaoThuCong(
    HeThong& h,
    const std::vector<std::pair<std::string, std::string>>& danhSach
);

// PHAN 2 - DUONG: Khach hang lay so.
bool capSo(HeThong& h, int viTriQuay, KhachHang& kh, int& soChoTruoc);

// PHAN 4 - KIEU: Goi tiep / goi lai / hoan tat.
bool goiTiep(HeThong& h, int viTriQuay, KhachHang& kh);
bool goiLai(const HeThong& h, int viTriQuay);
bool hoanTat(HeThong& h, int viTriQuay);

// PHAN 5 - HAU: Hien thi quay, so tiep theo va man hinh cho.
void hienThiCacQuay(const HeThong& h);
void hienThiTiepTheo(const HeThong& h);
void manHinhCho(const HeThong& h);
void hienThiThongKe(const HeThong& h);

// Cac thong tin su dung chung giua cac phan.
bool xemSoTiepTheo(const HeThong& h, int viTriQuay, KhachHang& kh);
ThongKeHeThong layThongKe(const HeThong& h);
void giaiPhongHeThong(HeThong& h);

#endif
