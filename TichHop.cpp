// ============================================================
// PHAN 6 - TRUNG: Ket noi, thong ke, giai phong tai nguyen
// ============================================================
#include "Trung_TichHop.h"

using namespace std;

ThongKeHeThong layThongKe(const HeThong& h) {
    ThongKeHeThong kq;
    kq.soQuay = static_cast<int>(h.quay.size());

    for (const auto& q : h.quay) {
        kq.tongCho += q.hangDoi.size;
        kq.tongGoi += q.daGoi;
        kq.tongHoanThanh += q.daHoanThanh;
    }

    return kq;
}

void giaiPhongHeThong(HeThong& h) {
    // Moi HangDoi tu giai phong cac nut khi vector.clear().
    h.quay.clear();
    h.sttTiepTheo = 1;
    h.coGoi = false;
    h.sttGoiGanNhat = 0;
    h.quayGoiGanNhat = 0;
}
