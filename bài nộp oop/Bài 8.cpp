#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include<vector>
#include <regex>
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

// Cau truc ngay_bay: luu tru ngay, thang, nam
struct ngay_bay {
    int ngay;
    int thang;
    int nam;

    // Ham nhap ngay bay
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

// Cau truc gio_bay: luu tru gio, phut
struct gio_bay {
    int gio;
    int phut;

    // Ham nhap gio bay
    // Input: gio, phut (int)
    // Output: khong co, nhap gia tri vao cac bien gio, phut
    void nhap2() {
        do {
            cin >> gio >> phut;
            if (gio >= 24 || phut >= 60 || gio < 0 || phut < 0) {
                cout << "Vui long nhap lai gio bay khong kha dung: " << endl;
            }
        } while (gio >= 24 || phut >= 60 || gio < 0 || phut < 0);
    }
};

// Ham kiem tra ma chuyen bay hop le
// Input: name (string)
// Output: true neu hop le, false neu khong hop le
bool checkma(const string& name) {
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
    string vietnameseChars = "ÀÁÂÃÈÉÊÌÍÒÓÔÕÙÚĂĐĨŨƠƯàáâãèéêìíòóôõùúăđĩũơưỲÝỶỸỴỳýỷỹỵ";
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
        }
    }

    return true;
}

// Ham chuyen chuoi sang chu thuong
// Input: str (string)
// Output: chuoi da chuyen sang chu thuong (string)
string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Ham so sanh hai chuoi
// Input: s1, s2 (string)
// Output: true neu hai chuoi giong nhau, false neu khong giong
bool mystr(string s1, string s2) {
    if (s1.size() != s2.size()) return false;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) return false;
    }
    return true;
}

// Lop quan_ly_chuyen_bay: quan ly thong tin chuyen bay
class quan_ly_chuyen_bay {
public:
    string ma;
    ngay_bay ngaybay;
    gio_bay giobay;
    string noidi;
    string noiden;

    // Ham nhap thong tin chuyen bay
    // Input: ma, ngaybay, giobay, noidi, noiden
    // Output: khong co, nhap gia tri vao cac bien tuong ung
    void nhap3() {
        do {
            cout << "nhap ma chuyen bay: " << endl;
            cin.ignore();
            getline(cin, ma);
            if (checkma(ma) == false) {
                cout << "Vui long nhap lai ma khong hop le: ";
            }
        } while (checkma(ma) == false);

        cout << "nhap ngay bay: " << endl;
        ngaybay.nhap1();

        cout << "nhap thoi gian chuyen bay: " << endl;
        giobay.nhap2();

        do {
            cout << "nhap diem xuat phat chuyen bay: " << endl;
            cin.ignore();
            getline(cin, noidi);
            if (dinhdang(noidi) == false) {
                cout << "Vui long nhap lai noi di khong hop le: ";
            }
        } while (dinhdang(noidi) == false);

        do {
            cout << "nhap noi den chuyen bay: " << endl;
            cin.ignore();
            getline(cin, noiden);
            if (dinhdang(noiden) == false) {
                cout << "Vui long nhap lai noi den khong hop le: ";
            }
        } while (dinhdang(noiden) == false);
    }

    // Ham tim kiem chuyen bay theo ma
    // Input: v (vector<quan_ly_chuyen_bay>), ma (string)
    // Output: vector<quan_ly_chuyen_bay> chua cac chuyen bay co ma trung khop
    vector<quan_ly_chuyen_bay> tim_kiem_theo_ma(const vector<quan_ly_chuyen_bay> v, string ma) {
        vector<quan_ly_chuyen_bay> result;
        for (auto a : v) {
            if (mystr(a.ma, ma)) {
                result.push_back(a);
            }
        }
        return result;
    }

    // Ham tim kiem chuyen bay theo noi den
    // Input: v (vector<quan_ly_chuyen_bay>), noican (string)
    // Output: vector<quan_ly_chuyen_bay> chua cac chuyen bay co noi den trung khop
    vector<quan_ly_chuyen_bay> tim_kiem_theo_noi_den(const vector<quan_ly_chuyen_bay> v, string noican) {
        vector<quan_ly_chuyen_bay> ans;
        for (auto a : v) {
            if (mystr(a.noiden, noican)) {
                ans.push_back(a);
            }
        }
        return ans;
    }

    // Ham tim kiem chuyen bay theo noi di
    // Input: v (vector<quan_ly_chuyen_bay>), noican (string)
    // Output: vector<quan_ly_chuyen_bay> chua cac chuyen bay co noi di trung khop
    vector<quan_ly_chuyen_bay> tim_kiem_theo_noi_di(const vector<quan_ly_chuyen_bay> v, string noican) {
        vector<quan_ly_chuyen_bay> ans;
        for (auto a : v) {
            if (mystr(a.noidi, noican)) {
                ans.push_back(a);
            }
        }
        return ans;
    }

    // Ham so sanh hai chuyen bay de sap xep
    // Input: b1, b2 (quan_ly_chuyen_bay)
    // Output: true neu b1 < b2, false neu khong
    static bool cmp(const quan_ly_chuyen_bay& b1, const quan_ly_chuyen_bay& b2) {
        if (b1.ngaybay.nam != b2.ngaybay.nam) return b1.ngaybay.nam < b2.ngaybay.nam;
        if (b1.ngaybay.thang != b2.ngaybay.thang) return b1.ngaybay.thang < b2.ngaybay.thang;
        if (b1.ngaybay.ngay != b2.ngaybay.ngay) return b1.ngaybay.ngay < b2.ngaybay.ngay;
        if (b1.giobay.gio != b2.giobay.gio) return b1.giobay.gio < b2.giobay.gio;
        return b1.giobay.phut < b2.giobay.phut;
    }

    // Ham sap xep danh sach chuyen bay
    // Input: a (vector<quan_ly_chuyen_bay>)
    // Output: khong co, sap xep danh sach a
    static void sapxep(vector<quan_ly_chuyen_bay>& a) {
        sort(a.begin(), a.end(), cmp);
    }

    // Ham tim kiem chuyen bay khoi hanh theo noi di, ngay, thang, nam
    // Input: a (vector<quan_ly_chuyen_bay>), Noidi (string), ngay, thang, nam (int)
    // Output: vector<quan_ly_chuyen_bay> chua cac chuyen bay thoa man dieu kien
    vector<quan_ly_chuyen_bay> dskhoihanh(vector<quan_ly_chuyen_bay> a, string Noidi, int ngay, int thang, int nam) {
        vector<quan_ly_chuyen_bay> result;
        for (auto x : a) {
            if (mystr(x.noidi, Noidi) && ngay == x.ngaybay.ngay && thang == x.ngaybay.thang && nam == x.ngaybay.nam) {
                result.push_back(x);
            }
        }
        return result;
    }

    // Ham dem so chuyen bay theo noi den va noi di
    // Input: Noiden, Noidi (string), v (vector<quan_ly_chuyen_bay>)
    // Output: so luong chuyen bay thoa man dieu kien (int)
    int demso(string Noiden, string Noidi, vector<quan_ly_chuyen_bay> v) {
        int dem = 0;
        for (auto x : v) {
            if (x.noiden == Noiden && x.noidi == Noidi) {
                dem++;
            }
        }
        return dem;
    }

    // Ham xuat thong tin chuyen bay
    // Input: khong co
    // Output: in thong tin chuyen bay ra man hinh
    void xuat() {
        cout << "ma cua chuyen bay: ";
        cout << ma << endl;
        cout << "ngay bay cua chuyen bay: ";
        cout << ngaybay.ngay << "/" << ngaybay.thang << "/" << ngaybay.nam << endl;
        cout << "gio bay: ";
        cout << giobay.gio << ":" << giobay.phut << endl;
        cout << "noi di: ";
        cout << noidi << endl;
        cout << "noi den: ";
        cout << noiden << endl;
    }
};

int main() {
    int n; cin >> n;
    vector<quan_ly_chuyen_bay> A(n);
    for (int i = 0; i < n; i++) {
        A[i].nhap3();
    }

    vector<quan_ly_chuyen_bay> ans = A[0].tim_kiem_theo_ma(A, "1234");
    cout << "ma 1234 cua chuyen bay can tim: ";
    for (auto x : ans) {
        x.xuat();
    }

    A[0].sapxep(A);
    for (auto x : A) {
        x.xuat();
    }
}