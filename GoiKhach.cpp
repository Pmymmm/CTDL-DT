#include "Trung_TichHop.h"
using namespace std;

bool hoanTat(HeThong& h, int viTriQuay) {
    if (viTriQuay < 0 || viTriQuay >= static_cast<int>(h.quay.size())) {
        return false;
    }

    QuayGiaoDich& q = h.quay[viTriQuay];
    if (!q.coKhach) {
        return false;
    }

    q.coKhach = false;
    ++q.daHoanThanh;
    return true;
}

bool goiTiep(HeThong& h, int viTriQuay, KhachHang& kh) {
    if (viTriQuay < 0 || viTriQuay >= static_cast<int>(h.quay.size())) {
        return false;
    }

    QuayGiaoDich& q = h.quay[viTriQuay];
    if (q.hangDoi.size == 0) {
        return false;
    }

    // Giu nguyen cach xu ly ban dau: goi so moi -> ket thuc so cu.
    if (q.coKhach) {
        hoanTat(h, viTriQuay);
    }

    q.hangDoi.lay(kh);
    q.dangPhucVu = kh;
    q.coKhach = true;
    ++q.daGoi;

    h.coGoi = true;
    h.sttGoiGanNhat = kh.stt;
    h.quayGoiGanNhat = q.id;
    return true;
}

bool goiLai(const HeThong& h, int viTriQuay) {
    if (viTriQuay < 0 || viTriQuay >= static_cast<int>(h.quay.size())) {
        return false;
    }

    return h.quay[viTriQuay].coKhach;
}

