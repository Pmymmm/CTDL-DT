// PHAN 6 - TRUNG: Tich hop chuong trinh va diem khoi chay duy nhat.
// Mo main.cpp va bam Run C/C++ File trong VS Code.
// Kieu nap cac file .cpp nay de VS Code bien dich rieng main.cpp.
// KHONG them cac file .cpp khac vao cung lenh bien dich main.cpp.
#include "Trung_TichHop.h"
#include "Trung_TichHop.cpp"
#include "Phong_KhoiTao.cpp"
#include "Duong_LaySo.cpp"
#include "Kieu_GoiKhach.cpp"
#include "Hau_GiaoDien.cpp"
#include "Hau_Menu.cpp"

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
        cout << "\nDa ket thuc dau vao.\n";
    }

    giaiPhongHeThong(h);
    cout << "Tam biet!\n";
    return 0;
}
