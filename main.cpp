#include "TichHop.h"
#include "TichHop.cpp"
#include "KhoiTao.cpp"
#include "LaySo.cpp"
#include "GoiKhach.cpp"
#include "GiaoDien.cpp"
#include "Menu.cpp"

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

int main() {
    HeThong h;

    try {
        while (true) {
            hienMenu();
            int chon = nhapSo("Nhap lua chon (0-8): ", 0, 8);

            if (chon == 0) {
                break;
            }

            switch (chon) {
                case 1:
                    if (!h.quay.empty()) {
                        int dongY = nhapSo(
                            "Khoi tao lai se xoa du lieu (1=Co, 0=Huy): ",
                            0, 1
                        );
                        if (dongY == 0) {
                            break;
                        }
                    }
                    khoiTaoMau(h);
                    cout << "[OK] Da khoi tao 4 quay mau.\n";
                    break;

                case 2:
                    khoiTaoTheoYMuon(h);
                    break;

                case 3:
                    hienThiCacQuay(h);
                    break;

                case 4:
                    menuLaySo(h);
                    break;

                case 5:
                    menuGoiKhach(h);
                    break;

                case 6:
                    hienThiTiepTheo(h);
                    break;

                case 7:
                    manHinhCho(h);
                    break;

                case 8:
                    hienThiThongKe(h);
                    break;
            }

            cout << "\nNhan Enter de quay lai menu...";
            string tamDung;
            if (!getline(cin, tamDung)) {
                break;
            }
        }
    } catch (const runtime_error&) {
        cout << "\nDa ket thuc.\n";
    }

    giaiPhongHeThong(h);
    cout << "Tam biet!\n";
    return 0;
}
