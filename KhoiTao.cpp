#include "Trung_TichHop.h"
#include <string>
#include <vector>

using namespace std;

void khoiTaoMau(HeThong& h) {
    giaiPhongHeThong(h);

    h.quay.emplace_back(1, "Quay 1", "Gui / Rut tien");
    h.quay.emplace_back(2, "Quay 2", "Mo tai khoan / The");
    h.quay.emplace_back(3, "Quay 3", "Vay von / Tin dung");
    h.quay.emplace_back(4, "Quay 4", "Thanh toan hoa don");
}

bool khoiTaoThuCong(
    HeThong& h,
    const vector<pair<string, string>>& danhSach
) {
    if (danhSach.empty() || danhSach.size() > 20) {
        return false;
    }

    for (size_t i = 0; i < danhSach.size(); ++i) {
        if (danhSach[i].second.find_first_not_of(" \t") == string::npos) {
            return false;
        }

        for (size_t j = 0; j < i; ++j) {
            if (danhSach[j].second == danhSach[i].second) {
                return false;
            }
        }
    }

    giaiPhongHeThong(h);

    for (size_t i = 0; i < danhSach.size(); ++i) {
        string ten = danhSach[i].first;
        if (ten.empty()) {
            ten = "Quay " + to_string(i + 1);
        }

        h.quay.emplace_back(
            static_cast<int>(i + 1),
            ten,
            danhSach[i].second
        );
    }

    return true;
}

// ============================================================
// PHAN 2 - DUONG | File goc: customer.h, customer.cpp
// Cap so duy nhat toan he thong, dua khach vao dung hang doi.
// ============================================================
