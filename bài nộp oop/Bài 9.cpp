#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <string>
#include<vector>
#define MAX 1000000
using namespace std;

// Ham kiem tra nam nhuan
// Input: nam (int)
// Output: true neu la nam nhuan, false neu khong phai
bool is_nam_nhuan(int nam) {
    if (nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0) {
        return true;
    }
    return false;
}

// Ham tra ve so ngay trong thang cua mot nam
// Input: nam (int), thang (int)
// Output: so ngay trong thang (int)
int ngay_theo_thang(int nam, int thang) {
    if (thang == 2) {
        if (is_nam_nhuan(nam)) {
            return 29;
        }
        else return 28;
    }
    else if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12) {
        return 31;
    }
    else if (thang == 4 || thang == 6 || thang == 9 || thang == 11) {
        return 30;
    }
}

// Cau truc ngay: luu tru ngay, thang, nam
struct ngay {
    int ngay;
    int thang;
    int nam;

    // Ham nhap ngay
    // Input: ngay, thang, nam (int)
    // Output: khong co, nhap gia tri vao cac bien ngay, thang, nam
    void nhap1() {
        do {
            cin >> ngay >> thang >> nam;
            if (ngay > ngay_theo_thang(nam, thang) || thang > 12 || thang < 0 || nam < 0) {
                cout << "Vui long nhap lai ngay bay khong kha dung: " << endl;
            }
        } while (ngay > ngay_theo_thang(nam, thang) || thang > 12 || thang < 0 || nam < 0);
    }
};

// Ham kiem tra ma so hop le
// Input: name (string)
// Output: true neu hop le, false neu khong hop le
bool check_ma(const string& name) {
    if (name.length() > 5 || name.length() < 0) return false;
    for (char c : name) {
        if (!(isalpha(c) || isdigit(c))) {
            return false;
        }
        else if (c == ' ') return false;
    }
    return true;
}

// Ham kiem tra ky tu hop le
// Input: c (char)
// Output: true neu hop le, false neu khong hop le
bool isValidChar(char c) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) return true;

    string vietnameseChars =
        "ÀÁÂÃÈÉÊÌÍÒÓÔÕÙÚĂĐĨŨƠ"
        "àáâãèéêìíòóôõùúăđĩũơ"
        "ƯƠĂÂÊÔươăâêô"
        "ĂẰẮẲẴẶÂẦẤẨẪẬ"
        "ÊỀẾỂỄỆÔỒỐỔỖỘƠỜỚỞỠỢ"
        "ươăâêô"
        "àằắẳẵặâầấẩẫậ"
        "êềếểễệôồốổỗộơờớởỡợ"
        "íìịỉĩýỳỵỷỹđ";

    return vietnameseChars.find(c) != string::npos;
}

// Ham kiem tra dinh dang ten hop le
// Input: name (string)
// Output: true neu hop le, false neu khong hop le
bool dinhdang(const string& name) {
    if (name.empty() || name.length() > 30) return false;

    if (!(name[0] >= 'A' && name[0] <= 'Z') && isValidChar(name[0]) == false) return false;

    for (size_t i = 1; i < name.length(); i++) {
        char current = name[i];
        char previous = name[i - 1];

        if (current == ' ') {
            if (previous == ' ') return false;
        }
        else {
            if (!isValidChar(current)) return false;
            if (previous == ' ' && !(current >= 'A' && current <= 'Z')) return false;
            if ((current >= 'A' && current <= 'Z') && (previous >= 'A' && previous <= 'Z')) return false;
        }
    }

    return true;
}

// Ham kiem tra dinh dang loai hop le
// Input: name (string)
// Output: true neu hop le, false neu khong hop le
bool check_loai(const string& name) {
    if (name.empty() || name.length() > 10) return false;

    if (!(name[0] >= 'A' && name[0] <= 'Z') && isValidChar(name[0]) == false) return false;

    for (size_t i = 1; i < name.length(); i++) {
        char current = name[i];
        char previous = name[i - 1];

        if (current == ' ') {
            if (previous == ' ') return false;
        }
        else {
            if (!isValidChar(current)) return false;
            if ((current >= 'A' && current <= 'Z') && (previous >= 'A' && previous <= 'Z')) return false;
        }
    }

    return true;
}

// Ham dem so chu so cua mot so nguyen
// Input: a (int)
// Output: so chu so cua a (int)
int count(int a) {
    int dem = 0;
    while (a) {
        dem++;
        a /= 10;
    }
    return dem;
}

// Lop so_tiet_kiem: quan ly thong tin so tiet kiem
class so_tiet_kiem {
private:
    string ma;
    string loai;
    string ho_ten;
    ngay ngay_gui;
    int cmnd;
    float tien_gui;
    float lai_suat;

public:
    // Ham nhap lai suat
    // Input: lai_suat (float)
    // Output: khong co, nhap gia tri vao bien lai_suat
    void nhaplai() {
        do {
            cin >> lai_suat;
            if (lai_suat < 0 || lai_suat > 100) {
                cout << "lai suat khong hop le nhap lai: ";
            }
        } while (lai_suat < 0 || lai_suat > 100);
    }

    // Ham nhap thong tin so tiet kiem
    // Input: ma, loai, ho_ten, ngay_gui, cmnd, tien_gui
    // Output: khong co, nhap gia tri vao cac bien tuong ung
    void nhap() {
        cout << "Nhap ma: ";
        do {
            cin.ignore();
            getline(cin, ma);
            if (check_ma(ma) == false) {
                cout << "ma khong hop le vui long nhap lai: " << endl;
            }
        } while (check_ma(ma) == false);

        cout << "Nhap loai: ";
        do {
            cin.ignore();
            getline(cin, loai);
            if (check_loai(loai) == false) {
                cout << "loai khong hop le vui long nhap lai: " << endl;
            }
        } while (check_loai(loai) == false);

        cout << "Nhap ho va ten: ";
        do {
            cin.ignore();
            getline(cin, ho_ten);
            if (dinhdang(ho_ten) == false) {
                cout << "ten khong hop le vui long nhap lai: " << endl;
            }
        } while (dinhdang(ho_ten) == false);

        cout << "Nhap ngay gui: ";
        ngay_gui.nhap1();

        cout << "Nhap vao cmnd: ";
        do {
            cin >> cmnd;
            if (count(cmnd) != 9 && count(cmnd) != 12) {
                cout << "cmnd khong hop le vui long nhap lai: " << endl;
            }
        } while (count(cmnd) != 9 && count(cmnd) != 12);

        do {
            cout << "Nhap so tien gui: ";
            cin >> tien_gui;
            if (tien_gui <= 0) {
                cout << "so tien gui khong hop le: ";
            }
        } while (tien_gui <= 0);
    }

    // Ham xuat thong tin so tiet kiem
    // Input: khong co
    // Output: in thong tin so tiet kiem ra man hinh
    void xuat() {
        cout << "ma so: ";
        cout << ma << endl;
        cout << "ho ten: ";
        cout << ho_ten << endl;
        cout << "cmnd: ";
        cout << cmnd << endl;
        cout << "loai :";
        cout << loai << endl;
        cout << "ngay gui: ";
        cout << ngay_gui.ngay << "/" << ngay_gui.thang << "/" << ngay_gui.nam << endl;
        cout << "tien gui: ";
        cout << tien_gui << endl;
    }

    // Ham tim kiem so tiet kiem theo cmnd
    // Input: Cmnd (int), a (vector<so_tiet_kiem>)
    // Output: in thong tin so tiet kiem co cmnd trung khop
    void tim_kiem_cmnd(int Cmnd, vector<so_tiet_kiem> a) {
        for (auto x : a) {
            if (x.cmnd == Cmnd) {
                x.xuat();
                return;
            }
        }
    }

    // Ham tim kiem so tiet kiem theo ma so
    // Input: maso (string), a (vector<so_tiet_kiem>)
    // Output: in thong tin so tiet kiem co ma so trung khop
    void tim_kiem_ma_so(string maso, vector<so_tiet_kiem> a) {
        for (auto x : a) {
            if (x.ma == maso) {
                x.xuat();
                return;
            }
        }
    }

    // Ham so sanh hai so tiet kiem theo tien gui
    // Input: s1, s2 (so_tiet_kiem)
    // Output: true neu s1.tien_gui > s2.tien_gui, false neu khong
    static bool cmp1(const so_tiet_kiem s1, const so_tiet_kiem s2) {
        return s1.tien_gui > s2.tien_gui;
    }

    // Ham so sanh hai so tiet kiem theo ngay gui
    // Input: s1, s2 (so_tiet_kiem)
    // Output: true neu s1.ngay_gui < s2.ngay_gui, false neu khong
    static bool cmp2(const so_tiet_kiem s1, const so_tiet_kiem s2) {
        if (s1.ngay_gui.nam != s2.ngay_gui.nam) {
            return s1.ngay_gui.nam < s2.ngay_gui.nam;
        }
        else {
            if (s1.ngay_gui.thang != s2.ngay_gui.thang) {
                return s1.ngay_gui.thang < s2.ngay_gui.thang;
            }
            else return s1.ngay_gui.ngay < s2.ngay_gui.ngay;
        }
    }

    // Ham sap xep danh sach so tiet kiem theo tien gui
    // Input: v (vector<so_tiet_kiem>)
    // Output: khong co, sap xep danh sach v
    void sap_xep_theo_tien(vector<so_tiet_kiem>& v) {
        sort(v.begin(), v.end(), cmp1);
    }

    // Ham sap xep danh sach so tiet kiem theo ngay gui
    // Input: v (vector<so_tiet_kiem>)
    // Output: khong co, sap xep danh sach v
    void sap_xep_theo_ngay(vector<so_tiet_kiem>& v) {
        sort(v.begin(), v.end(), cmp2);
    }

    // Ham liet ke cac so tiet kiem theo ngay gui
    // Input: ngay, thang, nam (int), a (vector<so_tiet_kiem>)
    // Output: vector<so_tiet_kiem> chua cac so tiet kiem thoa man dieu kien
    vector<so_tiet_kiem> liet_ke(int ngay, int thang, int nam, vector<so_tiet_kiem> a) {
        vector<so_tiet_kiem> result;
        for (auto x : a) {
            if (x.ngay_gui.ngay == ngay && x.ngay_gui.thang == thang && x.ngay_gui.nam == nam) {
                result.push_back(x);
            }
        }
        return result;
    }

    // Ham tinh tien lai
    // Input: ngay_hien_tai, thang_hien_tai, nam_hien_tai (int)
    // Output: tien lai (float)
    float tinh_tien_lai(int ngay_hien_tai, int thang_hien_tai, int nam_hien_tai) {
        int so_thang_gui = (nam_hien_tai - ngay_gui.nam) * 12 + (thang_hien_tai - ngay_gui.thang);
        if (so_thang_gui < 0) return 0;
        return tien_gui * pow(1 + lai_suat / 100, so_thang_gui / 12.0) - tien_gui;
    }

    // Ham rut tien
    // Input: so_tien_rut (float), ngay_hien_tai, thang_hien_tai, nam_hien_tai (int)
    // Output: khong co, thuc hien rut tien va in thong bao
    void rut_tien(float so_tien_rut, int ngay_hien_tai, int thang_hien_tai, int nam_hien_tai) {
        float tien_lai = tinh_tien_lai(ngay_hien_tai, thang_hien_tai, nam_hien_tai);
        float tong_tien = tien_gui + tien_lai;

        if (so_tien_rut > tong_tien) {
            cout << "Khong the rut so tien lon hon so du hien tai!\n";
            return;
        }

        if ((nam_hien_tai - ngay_gui.nam) * 12 + (thang_hien_tai - ngay_gui.thang) < 6) {
            float tien_lai_phat = tinh_tien_lai(ngay_hien_tai, thang_hien_tai, nam_hien_tai) * 0.5;
            cout << "Rut truoc han, tien lai giam con: " << tien_lai_phat << "\n";
            tong_tien = tien_gui + tien_lai_phat;
        }

        tien_gui = tong_tien - so_tien_rut;
        cout << "Rut thanh cong! So du con lai: " << tien_gui << "\n";
    }
};

int main() {
    cout << "Nhap vao so luong so tiet kiem: ";
    int n; cin >> n;

    vector<so_tiet_kiem> A(n);
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin nguoi thu " << i + 1 << endl;
        A[i].nhap();
    }

    cout << "-------------------------" << endl;
    cout << "**tim kiem so chung minh 123456789: ";
    A[0].tim_kiem_cmnd(1234, A);
    cout << endl;

    cout << "-------------------------" << endl;
    cout << "**tim kiem ma so 23e3";
    A[0].tim_kiem_ma_so("23e3", A);

    cout << "-------------------------" << endl;
    cout << "**sap xep theo tien gui: " << endl;
    A[0].sap_xep_theo_tien(A);
    for (auto x : A) {
        x.xuat();
    }

    cout << "-------------------------" << endl;
    cout << "**sap xep theo ngay gui :" << endl;
    A[0].sap_xep_theo_ngay(A);
    for (auto x : A) {
        x.xuat();
    }

    cout << "-------------------------" << endl;
    vector<so_tiet_kiem> ans1 = A[0].liet_ke(12, 2, 2024, A);
    cout << "**Nhung so tiet kiem lap vao ngay 12/2/2024: " << endl;
    for (auto x : ans1) {
    }