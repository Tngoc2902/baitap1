#include <bits/stdc++.h>

using namespace std;

class SinhVien {
    static int count;
    int maSV;
    string ten;
    string diaChi;
    string soDT;
    string lop;
public:
    SinhVien(string ten, string diaChi, string soDT, string lop) : ten(ten), diaChi(diaChi), soDT(soDT), lop(lop) {
        maSV = ++count;
    }

    string getTen() {
        return this->ten;
    }
};

int SinhVien::count = 0;
class MonHoc {
    static int count;
    int maMH;
    string tenMH;
    int tongSoTiet;
    string loaiMH;
public:
    MonHoc(string tenMH, int tongSoTiet,string loaiMH) : tenMH(tenMH), tongSoTiet(tongSoTiet), loaiMH(loaiMH) {
        maMH = ++count;
    }
};

int MonHoc::count = 0;

class BangDangKy {
public:
    SinhVien sv;
    vector<MonHoc> monHocs;
    time_t thoiGianDK;
public:
    BangDangKy(SinhVien sv) : sv(sv) {
        thoiGianDK = time(0);
    }
    void themMonHoc(MonHoc mh) {
        if (monHocs.size() < 8) {
            monHocs.push_back(mh);
        } else {
            cout << "khong the dang ky qua 8 mon hoc trong mot hoc ky.";
        }
    }
};


void lapDanhSachLop(vector<BangDangKy>& ds) {
}

void nhapThongTinSinhVien(vector<SinhVien>& sinhViens) {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        string ten, diaChi, soDT, lop,msv;
        cout << "Nhap ten sinh vien: ";
        cin >> ten;
        cout<<"Nhap ma sinh vien: ";
        cin>> msv;
        cout << "Nhap dia chi: ";
        cin >> diaChi;
        cout << "Nhap so dien thoai: ";
        cin >> soDT;
        cout << "Nhap lop: ";
        cin >> lop;
        sinhViens.push_back(SinhVien(ten, diaChi, soDT, lop));
    }
}

void nhapThongTinMonHoc(vector<MonHoc>& monHocs) {
    int n;
    cout << "Nhap so luong mon hoc: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        string tenMH, loaiMH;
        int tongSoTiet;
        cout << "Nhap ten mon hoc: ";
        cin >> tenMH;
        cout << "Nhap tong so tiet: ";
        cin >> tongSoTiet;
        cout << "Nhap loai mon hoc: ";
        cin >> loaiMH;
        monHocs.push_back(MonHoc(tenMH, tongSoTiet, loaiMH));
    }
}

void nhapThongTinBangDangKy(vector<BangDangKy>& bangDangKys, vector<SinhVien>& sinhViens, vector<MonHoc>& monHocs) {
    int n;
    cout << "Nhap so luong bang dang ky: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int maSV, soMonHoc;
        cout << "Nhap ma sinh vien: ";
        cin >> maSV;
        BangDangKy bd(sinhViens[maSV - 1]);
        cout << "Nhap so luong mon hoc: ";
        cin >> soMonHoc;
        for (int j = 0; j < soMonHoc; j++) {
            int maMH;
            cout << "Nhap ma mon hoc: ";
            cin >> maMH;
            bd.themMonHoc(monHocs[maMH - 1]);
        }
        bangDangKys.push_back(bd);
    }
}

bool comp(BangDangKy x,BangDangKy y) {
    return (x.sv.getTen() < y.sv.getTen() || (x.sv.getTen() == y.sv.getTen() && x.thoiGianDK < y.thoiGianDK));
}

void sapSepBangDangKys(vector<BangDangKy>& bangDangKys) {

   sort(bangDangKys.begin(), bangDangKys.end(), comp);
}

int main() {
    vector<SinhVien> sinhViens;
    vector<MonHoc> monHocs;
    vector<BangDangKy> bangDangKys;

    nhapThongTinSinhVien(sinhViens);
    nhapThongTinMonHoc(monHocs);
    nhapThongTinBangDangKy(bangDangKys, sinhViens, monHocs);
    sapSepBangDangKys(bangDangKys);
    lapDanhSachLop(bangDangKys);

    return 0;
}
