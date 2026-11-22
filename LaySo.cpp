#include "TichHop.h"
using namespace std;

bool capSo(HeThong& h, int viTriQuay, KhachHang& kh, int& soChoTruoc) {
    if (viTriQuay < 0 || viTriQuay >= static_cast<int>(h.quay.size())) {
        return false;
    }

    QuayGiaoDich& q = h.quay[viTriQuay];
    soChoTruoc = q.hangDoi.size;

    kh.stt = h.sttTiepTheo;
    kh.mucDich = q.mucDich;
    kh.tenQuay = q.tenQuay;

    q.hangDoi.them(kh);
    ++h.sttTiepTheo;
    return true;
}
