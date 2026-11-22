#include "TichHop.h"
#include <iomanip>
#include <sstream>
#include <iostream>

using namespace std;

void hienThiCacQuay(const HeThong& h) {
    if (h.quay.empty()) {
        cout << "[!] Chua khoi tao quay giao dich.\n";
        return;
    }

    cout << "\n========== DANH SACH QUAY ==========\n";

    for (const auto& q : h.quay) {
        cout << q.id << ". " << q.tenQuay << "\n";
        cout << "   Muc dich: " << q.mucDich << "\n";
        cout << "   So khach dang cho: " << q.hangDoi.size << "\n";
    }
}

bool xemSoTiepTheo(const HeThong& h, int viTriQuay, KhachHang& kh) {
    if (viTriQuay < 0 || viTriQuay >= static_cast<int>(h.quay.size())) {
        return false;
    }

    return h.quay[viTriQuay].hangDoi.xem(kh);
}

void hienThiTiepTheo(const HeThong& h) {
    cout << "\n========== SO THU TU TAI TUNG QUAY ==========\n";
    cout << "Dang phuc vu: khach da duoc goi vao quay.\n";
    cout << "Se goi tiep: khach DANG CHO dau hang doi.\n";
    cout << "So moi se cap: so danh cho khach DEN SAU.\n";

    if (h.quay.empty()) {
        cout << "[!] Chua khoi tao quay giao dich.\n";
        return;
    }

    for (const auto& q : h.quay) {
        KhachHang tiep;
        cout << "\n--------------------------------------------\n";
        cout << q.tenQuay << " - " << q.mucDich << "\n";

        cout << "  Dang phuc vu: ";
        if (q.coKhach) {
            cout << right << setfill('0') << setw(3) << q.dangPhucVu.stt << setfill(' ') << "\n";
        } else {
            cout << "Chua co khach\n";
        }

        cout << "  So se goi tiep: ";
        if (q.hangDoi.xem(tiep)) {
            cout << right << setfill('0') << setw(3) << tiep.stt << setfill(' ') << "\n";
        } else {
            cout << "Khong co khach dang cho\n";
        }

        cout << "  Tong so dang cho: " << q.hangDoi.size << "\n";
    }

    cout << "\nSo thu tu MOI se cap: "
         << right << setfill('0') << setw(3) << h.sttTiepTheo << setfill(' ') << "\n";
}

void manHinhCho(const HeThong& h) {
    cout << "\n========================================================================\n";
    cout << "                     MAN HINH CHO - HE THONG LAY SO\n";
    cout << "========================================================================\n";

    if (h.quay.empty()) {
        cout << "[!] Chua khoi tao quay giao dich.\n";
        return;
    }

    if (h.coGoi) {
        cout << ">>> MOI SO " << right << setfill('0') << setw(3) << h.sttGoiGanNhat
             << setfill(' ') << " DEN QUAY " << h.quayGoiGanNhat << " <<<\n";
    } else {
        cout << ">>> CHUA CO KHACH NAO DUOC GOI <<<\n";
    }

    cout << left
         << setw(8) << "QUAY"
         << setw(23) << "MUC DICH"
         << setw(12) << "DANG GOI"
         << setw(12) << "GOI TIEP"
         << "DANH SACH CHO\n";
    cout << string(72, '-') << "\n";

    int tongCho = 0;

    for (const auto& q : h.quay) {
        KhachHang khTiep;
        string soDangGoi = "---";
        string soTiep = "---";

        if (q.coKhach) {
            ostringstream ss;
            ss << setfill('0') << setw(3) << q.dangPhucVu.stt;
            soDangGoi = ss.str();
        }

        if (q.hangDoi.xem(khTiep)) {
            ostringstream ss;
            ss << setfill('0') << setw(3) << khTiep.stt;
            soTiep = ss.str();
        }

        cout << left
             << setw(8) << q.id
             << setw(23) << q.mucDich.substr(0, 22)
             << setw(12) << soDangGoi
             << setw(12) << soTiep;

        NutQueue* p = q.hangDoi.front;
        int daHienThi = 0;

        while (p != nullptr && daHienThi < 6) {
            cout << right << setfill('0') << setw(3) << p->data.stt
                 << setfill(' ') << " ";
            p = p->next;
            ++daHienThi;
        }

        if (p != nullptr) {
            cout << "...(con " << (q.hangDoi.size - daHienThi) << " so)";
        }
        if (daHienThi == 0) {
            cout << "(trong)";
        }

        cout << "\n";
        tongCho += q.hangDoi.size;
    }

    cout << string(72, '-') << "\n";
    cout << "Tong khach dang cho: " << tongCho << "\n";
    cout << "So moi se cap: " << setfill('0') << setw(3)
         << h.sttTiepTheo << setfill(' ') << "\n";
}

void hienThiThongKe(const HeThong& h) {
    cout << "\n============= THONG KE HE THONG =============\n";

    for (const auto& q : h.quay) {
        cout << q.tenQuay << "\n";
        cout << "  Dang cho  : " << q.hangDoi.size << "\n";
        cout << "  Da goi    : " << q.daGoi << "\n";
        cout << "  Hoan tat  : " << q.daHoanThanh << "\n";
    }

    ThongKeHeThong kq = layThongKe(h);
    cout << "--------------------------------------------\n";
    cout << "So quay giao dich: " << kq.soQuay << "\n";
    cout << "Tong khach dang cho: " << kq.tongCho << "\n";
    cout << "Tong luot da goi: " << kq.tongGoi << "\n";
    cout << "Tong hoan tat: " << kq.tongHoanThanh << "\n";
}

// ============================================================
// PHAN 6 - TICH HOP | Khong la tinh nang moi trong menu
// Thu hoi tai nguyen va reset lai he thong.
// ============================================================
