#include <iostream>
#include <string>
using namespace std;

// Khai bao cau truc Node
struct Node {
    string tenKhachHang; // Ten khach hang
    int tongTien;        // Tong tien cua gio hang
    int soLuongSanPhamA; // So luong san pham A
    Node* tiepTheo;      // Con tro den Node tiep theo
};

// Khai bao hang doi
struct HangDoi {
    Node* dau;  // Diem dau hang doi
    Node* cuoi; // Diem cuoi hang doi

    HangDoi() {
        dau = cuoi = NULL;
    }

    // Kiem tra hang doi rong
    bool laRong() {
        return dau == NULL;
    }

    // Them mot khach hang vao hang doi
    void themKhachHang(string tenKhachHang, int tongTien, int soLuongSanPhamA) {
        Node* nutMoi = new Node{tenKhachHang, tongTien, soLuongSanPhamA, NULL};
        if (cuoi == NULL) {
            dau = cuoi = nutMoi;
        } else {
            cuoi->tiepTheo = nutMoi;
            cuoi = nutMoi;
        }
    }

    // Xoa khach hang khoi hang doi
    void xoaKhachHang() {
        if (laRong()) {
            cout << "Hang doi rong, khong the xoa.\n";
            return;
        }
        Node* tam = dau;
        dau = dau->tiepTheo;
        if (dau == NULL) {
            cuoi = NULL; // Neu hang doi rong, reset cuoi
        }
        delete tam;
    }
};

// Ham tinh tong tien thu duoc tai quay
int tinhTongTien(HangDoi& hangDoi) {
    int tongTien = 0;
    Node* hienTai = hangDoi.dau;
    while (hienTai !=NULL) {
        tongTien += hienTai->tongTien;
        hienTai = hienTai->tiepTheo;
    }
    return tongTien;
}

// Ham dem so luong san pham A da ban
int demSanPhamA(HangDoi& hangDoi) {
    int tongSanPhamA = 0;
    Node* hienTai = hangDoi.dau;
    while (hienTai != NULL) {
        tongSanPhamA += hienTai->soLuongSanPhamA;
        hienTai = hienTai->tiepTheo;
    }
    return tongSanPhamA;
}

int main() {
    HangDoi hangDoi;

    // Them mot so khach hang vao hang doi
    hangDoi.themKhachHang("Khach 1", 195000, 5);
    hangDoi.themKhachHang("Khach  2", 150000, 3);
    hangDoi.themKhachHang("Khach 3", 355000, 7);

    // Tinh tong tien thu duoc
    cout << "Tong tien thu : " << tinhTongTien(hangDoi) << " VND\n";

    // Dem so luong san pham A da ban
    cout << "Tong so luong san pham A da ban: " << demSanPhamA(hangDoi) << "\n";

    // Xoa khach hang dau tien khoi hang doi
    hangDoi.xoaKhachHang();
    cout << "Sau khi xoa mot khach hang:\n";
    cout << "Tong tien thu duoc: " << tinhTongTien(hangDoi) << " VND\n";
    cout << "Tong so luong san pham A da ban: " << demSanPhamA(hangDoi) << "\n";

    return 0;
}

