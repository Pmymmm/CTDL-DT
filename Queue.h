#ifndef QUEUE_H
#define QUEUE_H

#include "Duong_Customer.h"
#include <utility>

struct NutQueue {
    KhachHang data;
    NutQueue* next = nullptr;
};

struct HangDoi {
    NutQueue* front = nullptr;
    NutQueue* rear = nullptr;
    int size = 0;

    HangDoi() = default;

    
    HangDoi(const HangDoi&) = delete;
    HangDoi& operator=(const HangDoi&) = delete;

   
    HangDoi(HangDoi&& other) noexcept {
        front = other.front;
        rear = other.rear;
        size = other.size;

        other.front = nullptr;
        other.rear = nullptr;
        other.size = 0;
    }

    HangDoi& operator=(HangDoi&& other) noexcept {
        if (this != &other) {
            xoa();
            front = other.front;
            rear = other.rear;
            size = other.size;

            other.front = nullptr;
            other.rear = nullptr;
            other.size = 0;
        }
        return *this;
    }

    ~HangDoi() {
        xoa();
    }

    void them(const KhachHang& kh) {
        NutQueue* nutMoi = new NutQueue{kh, nullptr};

        if (rear == nullptr) {
            front = nutMoi;
        } else {
            rear->next = nutMoi;
        }

        rear = nutMoi;
        ++size;
    }

    bool lay(KhachHang& kh) {
        if (front == nullptr) {
            return false;
        }

        NutQueue* nutDau = front;
        kh = nutDau->data;
        front = nutDau->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete nutDau;
        --size;
        return true;
    }

    bool xem(KhachHang& kh) const {
        if (front == nullptr) {
            return false;
        }

        kh = front->data;
        return true;
    }

    void xoa() {
        while (front != nullptr) {
            NutQueue* nutDau = front;
            front = front->next;
            delete nutDau;
        }

        rear = nullptr;
        size = 0;
    }
};

#endif
