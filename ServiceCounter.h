#ifndef SERVICE_COUNTER_H
#define SERVICE_COUNTER_H

#include "Danh_Queue.h"
#include <string>
#include <utility>


struct QuayGiaoDich {
    int id = 0;
    std::string tenQuay;
    std::string mucDich;
    HangDoi hangDoi;

    bool coKhach = false;
    KhachHang dangPhucVu;
    int daGoi = 0;
    int daHoanThanh = 0;

    QuayGiaoDich() = default;

    QuayGiaoDich(int ma, std::string ten, std::string mucDichMoi)
        : id(ma),
          tenQuay(std::move(ten)),
          mucDich(std::move(mucDichMoi)) {}

    QuayGiaoDich(const QuayGiaoDich&) = delete;
    QuayGiaoDich& operator=(const QuayGiaoDich&) = delete;
    QuayGiaoDich(QuayGiaoDich&&) noexcept = default;
    QuayGiaoDich& operator=(QuayGiaoDich&&) noexcept = default;
};

#endif
