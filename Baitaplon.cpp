#include <bits/stdc++.h>
#include <string>
#include <ctime>

using namespace std;

class MonHoc {
private:
    int maMonHoc;
    string tenMonHoc;
    int tongSoTiet;
    string loaiMonHoc;

public:
    MonHoc(int ma, const string& ten, int soTiet, const string& loai)
        : maMonHoc(ma), tenMonHoc(ten), tongSoTiet(soTiet), loaiMonHoc(loai) {}

    int getMaMonHoc() const {
        return maMonHoc;
    }

    const string& getTenMonHoc() const {
        return tenMonHoc;
    }

    int getTongSoTiet() const {
        return tongSoTiet;
    }

    const string& getLoaiMonHoc() const {
        return loaiMonHoc;
    }
};

class SinhVien {
private:
    int maSinhVien;
    string hoTen;
    string diaChi;
    string soDT;
    string lop;

public:
    SinhVien(int ma, const string& ten, const string& diaChi, const string& sdt, const string& lop)
        : maSinhVien(ma), hoTen(ten), diaChi(diaChi), soDT(sdt), lop(lop) {}

    int getMaSinhVien() const {
        return maSinhVien;
    }

    const string& getHoTen() const {
        return hoTen;
    }

    const string& getDiaChi() const {
        return diaChi;
    }

    const string& getSoDT() const {
        return soDT;
    }

    const string& getLop() const {
        return lop;
    }
};

class BangDangKy {
private:
    SinhVien sinhVien;
    vector<MonHoc> danhSachMonHoc;
    string thoiGianDangKy;

public:
    BangDangKy(const SinhVien& sv, const vector<MonHoc>& dsMonHoc, const string& thoiGian)
        : sinhVien(sv), danhSachMonHoc(dsMonHoc), thoiGianDangKy(thoiGian) {}


    const string& getThoiGianDangKy() const {
        return thoiGianDangKy;
    }
	
	static bool compareByName(const BangDangKy& a, const BangDangKy& b) {
        return a.sinhVien.getHoTen() < b.sinhVien.getHoTen();
    }

    // Static function for sorting by registration time
    static bool compareByTime(const BangDangKy& a, const BangDangKy& b) {
        return a.thoiGianDangKy < b.thoiGianDangKy;
    }

    void inThongTin() const {
        cout << "Thong tin Bang Dang Ky:\n";
        cout << "Ma sinh vien: " << sinhVien.getMaSinhVien() << "\n";
        cout << "Ho ten sinh vien: " << sinhVien.getHoTen() << "\n";
        cout << "Dia chi: " << sinhVien.getDiaChi() << "\n";
        cout << "So dien thoai: " << sinhVien.getSoDT() << "\n";
        cout << "Lop: " << sinhVien.getLop() << "\n";
        cout << "Thoi gian dang ky: " << thoiGianDangKy << "\n\n";
        cout << "Danh sach cac mon hoc da dang ky:\n";
        for (int i = 0; i < danhSachMonHoc.size(); ++i) {
            const MonHoc& monHoc = danhSachMonHoc[i];
            cout << "Ma mon hoc: " << monHoc.getMaMonHoc() << "\n";
            cout << "Ten mon hoc: " << monHoc.getTenMonHoc() << "\n";
            cout << "Tong so tiet: " << monHoc.getTongSoTiet() << "\n";
            cout << "Loai mon hoc: " << monHoc.getLoaiMonHoc() << "\n\n";
        }
        cout << "-------------------------------------\n";
    }
};
void nhapDanhSachMonHoc(vector<MonHoc>& danhSachMonHoc) {
    int soLuongMonHoc;
    cout << "Nhap so luong mon hoc: ";
    cin >> soLuongMonHoc;

    for (int i = 0; i < soLuongMonHoc; ++i) {
        int maMonHoc;
        string tenMonHoc;
        int tongSoTiet;
        string loaiMonHoc;

        cout << "Nhap thong tin mon hoc thu " << i + 1 << ":\n";
        cout << "Ma mon hoc: ";
        cin >> maMonHoc;
        cin.ignore();

        cout << "Ten mon hoc: ";
        getline(cin, tenMonHoc);

        cout << "Tong so tiet: ";
        cin >> tongSoTiet;
        cin.ignore();

        cout << "Loai mon hoc (Dai cuong, Co so nganh, ...): ";
        getline(cin, loaiMonHoc);

        MonHoc monHoc(maMonHoc, tenMonHoc, tongSoTiet, loaiMonHoc);
        danhSachMonHoc.push_back(monHoc);
    }
}

void inDanhSachMonHoc(const vector<MonHoc>& danhSachMonHoc) {
	cout << "-------------------------------------\n";
    cout << "Danh sach cac mon hoc da co:\n";
    for (int i = 0; i < danhSachMonHoc.size(); ++i) {
        const MonHoc& monHoc = danhSachMonHoc[i];
        cout << "Ma mon hoc: " << monHoc.getMaMonHoc() << "\n";
        cout << "Ten mon hoc: " << monHoc.getTenMonHoc() << "\n";
        cout << "Tong so tiet: " << monHoc.getTongSoTiet() << "\n";
        cout << "Loai mon hoc: " << monHoc.getLoaiMonHoc() << "\n\n";
    }
}

void nhapDanhSachSinhVien(vector<SinhVien>& danhSachSinhVien) {
    int soLuongSinhVien;
    cout << "Nhap so luong sinh vien: ";
    cin >> soLuongSinhVien;

    for (int i = 0; i < soLuongSinhVien; ++i) {
        int maSinhVien;
        string hoTen;
        string diaChi;
        string soDT;
        string lop;

        cout << "Nhap thong tin sinh vien thu " << i + 1 << ":\n";
        cout << "Ma sinh vien: ";
        cin >> maSinhVien;
        cin.ignore();

        cout << "Ho ten sinh vien: ";
        getline(cin, hoTen);

        cout << "Dia chi: ";
        getline(cin, diaChi);

        cout << "So dien thoai: ";
        getline(cin, soDT);

        cout << "Lop: ";
        getline(cin, lop);

        SinhVien sinhVien(maSinhVien, hoTen, diaChi, soDT, lop);
        danhSachSinhVien.push_back(sinhVien);
    }
}

void inDanhSachSinhVien(const vector<SinhVien>& danhSachSinhVien) {
        cout << "-------------------------------------\n"; 
    cout << "Danh sach sinh vien da co:\n";
    for (int i = 0; i < danhSachSinhVien.size(); ++i) {
        const SinhVien& sinhVien = danhSachSinhVien[i];
        cout << "Ma sinh vien: " << sinhVien.getMaSinhVien() << "\n";
        cout << "Ho ten sinh vien: " << sinhVien.getHoTen() << "\n";
        cout << "Dia chi: " << sinhVien.getDiaChi() << "\n";
        cout << "So dien thoai: " << sinhVien.getSoDT() << "\n";
        cout << "Lop: " << sinhVien.getLop() << "\n\n";
    }
}

int main() {
    vector<MonHoc> danhSachMonHoc;
    vector<SinhVien> danhSachSinhVien;
    vector<BangDangKy> danhSachBangDangKy;

    nhapDanhSachMonHoc(danhSachMonHoc);
    inDanhSachMonHoc(danhSachMonHoc);

    nhapDanhSachSinhVien(danhSachSinhVien);
    inDanhSachSinhVien(danhSachSinhVien);
cout << "Nhap mon hoc dang ky: " << endl;
    for (int i = 0; i < danhSachSinhVien.size(); i++) {
        vector<MonHoc> dsMonHocChoSinhVien;
        nhapDanhSachMonHoc(dsMonHocChoSinhVien);

        time_t now = time(0);
        tm* ltm = localtime(&now);

        char buffer[80]; 
        strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M", ltm);
        string thoiGianDangKy(buffer);

        BangDangKy bangDangKy(danhSachSinhVien[i], dsMonHocChoSinhVien, thoiGianDangKy);
        danhSachBangDangKy.push_back(bangDangKy);
    }

    for (int i = 0; i < danhSachBangDangKy.size(); i++) {
        danhSachBangDangKy[i].inThongTin();
    }
    
    sort(danhSachBangDangKy.begin(), danhSachBangDangKy.end(), BangDangKy::compareByName);

cout << "Danh sach sau khi sap xep theo ten sinh vien:\n";
for (int i = 0; i < danhSachBangDangKy.size(); i++) {
    danhSachBangDangKy[i].inThongTin();
}

sort(danhSachBangDangKy.begin(), danhSachBangDangKy.end(), BangDangKy::compareByTime);

cout << "Danh sach sau khi sap xep theo thoi gian dang ky:\n";
for (int i = 0; i < danhSachBangDangKy.size(); i++) {
    danhSachBangDangKy[i].inThongTin();
}

vector<vector<BangDangKy> > classGroups;
vector<BangDangKy> currentGroup;

for (int i = 0; i < danhSachBangDangKy.size(); i++) {
    currentGroup.push_back(danhSachBangDangKy[i]);
    if (currentGroup.size() == 30 || i == danhSachBangDangKy.size() - 1) {
        classGroups.push_back(currentGroup);
        currentGroup.clear();
    }
}


	for (int i = 0; i < classGroups.size(); i++) {
    cout << "Lop " << i + 1 << ":\n";
    for (int j = 0; j < classGroups[i].size(); j++) {
        classGroups[i][j].inThongTin();
    }
}
    return 0;
}

