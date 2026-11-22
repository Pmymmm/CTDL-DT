// PHAN 5 - HAU: Menu va tuong tac nguoi dung
#include "Trung_TichHop.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
using namespace std;

void hienMenu() {
    cout << "\n==================================================\n";
    cout << "            HE THONG LAY SO NGAN HANG\n";
    cout << "==================================================\n";
    cout << " [QUAN LY QUAY]\n";
    cout << "  1. Khoi tao 4 quay giao dich mau\n";
    cout << "  2. Tu thiet lap danh sach quay\n";
    cout << "  3. Xem thong tin cac quay\n";
    cout << "\n [PHUC VU KHACH HANG]\n";
    cout << "  4. Lay so thu tu\n";
    cout << "  5. Goi khach / Goi lai / Hoan tat\n";
    cout << "\n [THEO DOI HE THONG]\n";
    cout << "  6. Xem so dang phuc vu va so se goi tiep\n";
    cout << "  7. Xem man hinh cho\n";
    cout << "  8. Xem thong ke he thong\n";
    cout << "\n  0. Thoat\n";
    cout << "--------------------------------------------------\n";
}

int nhapSo(const string& loiNhac, int min, int max) {
    while (true) {
        cout << loiNhac;

        string dong;
        if (!getline(cin, dong)) {
            throw runtime_error("Het du lieu dau vao");
        }

        istringstream ss(dong);
        int so;
        char kyTuThua;

        if ((ss >> so) && !(ss >> kyTuThua) && so >= min && so <= max) {
            return so;
        }

        cout << "[!] Chi nhap so nguyen tu " << min << " den " << max << ".\n";
    }
}

void khoiTaoTheoYMuon(HeThong& h) {
    if (!h.quay.empty()) {
        int dongY = nhapSo("Khoi tao lai se xoa du lieu (1=Co, 0=Huy): ", 0, 1);
        if (dongY == 0) {
            return;
        }
    }

    int soQuay = nhapSo("Nhap so quay (1-20): ", 1, 20);
    vector<pair<string, string>> danhSach;

    for (int i = 0; i < soQuay; ++i) {
        string ten;
        string mucDich;

        cout << "\n--- THONG TIN QUAY " << i + 1 << " ---\n";
        cout << "Ten quay (Enter = ten mac dinh): ";
        if (!getline(cin, ten)) {
            throw runtime_error("Het du lieu dau vao");
        }

        while (true) {
            cout << "Muc dich giao dich: ";
            if (!getline(cin, mucDich)) {
                throw runtime_error("Het du lieu dau vao");
            }

            bool biTrung = false;
            for (const auto& item : danhSach) {
                if (item.second == mucDich) {
                    biTrung = true;
                    break;
                }
            }

            if (mucDich.find_first_not_of(" \t") != string::npos && !biTrung) {
                break;
            }
            cout << "[!] Muc dich khong duoc rong hoac trung nhau.\n";
        }

        danhSach.emplace_back(ten, mucDich);
    }

    if (khoiTaoThuCong(h, danhSach)) {
        cout << "[OK] Khoi tao " << soQuay << " quay thanh cong.\n";
    } else {
        cout << "[!] Khong the khoi tao vi du lieu khong hop le.\n";
    }
}

void menuLaySo(HeThong& h) {
    if (h.quay.empty()) {
        cout << "[!] Can khoi tao quay truoc.\n";
        return;
    }

    hienThiCacQuay(h);
    int viTri = nhapSo("Chon quay theo muc dich: ", 1, static_cast<int>(h.quay.size())) - 1;

    KhachHang kh;
    int soChoTruoc = 0;

    if (capSo(h, viTri, kh, soChoTruoc)) {
        cout << "\n============== PHIEU SO ==============\n";
        cout << "So thu tu       : " << kh.stt << "\n";
        cout << "Quay            : " << kh.tenQuay << "\n";
        cout << "Muc dich        : " << kh.mucDich << "\n";
        cout << "So khach cho truoc: " << soChoTruoc << "\n";
        cout << "======================================\n";
    }
}

void menuGoiKhach(HeThong& h) {
    if (h.quay.empty()) {
        cout << "[!] Can khoi tao quay truoc.\n";
        return;
    }

    hienThiCacQuay(h);
    int viTri = nhapSo("Chon quay can phuc vu: ", 1, static_cast<int>(h.quay.size())) - 1;

    cout << "\n1. Goi khach tiep theo\n";
    cout << "2. Goi lai khach dang phuc vu\n";
    cout << "3. Hoan tat khach dang phuc vu\n";
    cout << "0. Quay lai\n";

    int thaoTac = nhapSo("Chon thao tac: ", 0, 3);

    if (thaoTac == 1) {
        KhachHang kh;
        if (goiTiep(h, viTri, kh)) {
            cout << ">>> MOI SO " << kh.stt << " DEN " << h.quay[viTri].tenQuay << "!\n";
        } else {
            cout << "[!] Quay khong co khach moi dang cho.\n";
        }
    } else if (thaoTac == 2) {
        if (goiLai(h, viTri)) {
            cout << ">>> GOI LAI SO " << h.quay[viTri].dangPhucVu.stt
                 << " DEN " << h.quay[viTri].tenQuay << "!\n";
        } else {
            cout << "[!] Chua co khach dang phuc vu.\n";
        }
    } else if (thaoTac == 3) {
        if (hoanTat(h, viTri)) {
            cout << "[OK] Da hoan tat phuc vu.\n";
        } else {
            cout << "[!] Chua co khach de hoan tat.\n";
        }
    }
}

