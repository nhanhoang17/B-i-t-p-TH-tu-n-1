

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include<vector>
#define MAX 1000000
using namespace std;
bool is_nam_nhuan(int nam) {
    if (nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0) {
        return true;
    }
    return false;
}
//input nam va thang output tra ve ngay trong thang do
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
struct ngay {
    int ngay;
    int thang;
    int nam;
    void nhap1() {
        do {
            cin >> ngay >> thang >> nam;
            if (ngay > ngay_theo_thang(nam, thang) || thang > 12 || thang < 0 || nam < 0) {
                cout << "Vui long nhap lai ngay bay khong kha dung: " << endl;
            }
        } while (ngay > ngay_theo_thang(nam, thang) || thang > 12 || thang < 0 || nam < 0);
    }
};
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
bool check_loai(const string& name) {
    if (name.length() > 10 || name.length() < 0) return false;
    for (char c : name) {
        if (!(isalpha(c) || c==' ')) {
            return false;
        }
       
    }
    return true;
}
bool dinhdang(string name) {
    if (name.length() < 0 || name.length() > 20) return false;
    for (int i = 0; i < name.size(); i++) {
        if (name[0] < 65 || name[0] > 90) {
            return false;
        }
        if (name[i] >= 65 && name[i] <= 90 && i != 0) {
            if (name[i - 1] != ' ') {
                return false;
            }
        }
        if (!(isalpha(name[i]) || name[i] == ' ')) {
            return false;
        }
    }


    return true;
}

class so_tiet_kiem {
private:
    string ma;
    string loai;
    string ho_ten;
    ngay ngay_gui;
    int cmnd;
    float tien_gui;
public:
    void nhap() {
        do {
            cout << "Nhap ma: ";
            cin.ignore();
            getline(cin, ma);
            if (check_ma(ma) == false) {
                cout << "ma khong hop le vui long nhap lai: "<<endl;
            }
        } while (check_ma(ma) == false);
        do {
            cout << "Nhap loai: ";
            cin.ignore();
            getline(cin, loai);
            if (check_loai(loai) == false) {
                cout << "loai khong hop le vui long nhap lai: " << endl;
            }
        } while (check_loai(loai) == false);
        do {
            cout << "Nhap ho va ten: ";
            cin.ignore();
            getline(cin, ho_ten);
            if (dinhdang(ho_ten) == false) {
                cout << "ten khong hop le vui long nhap lai: " << endl;
            }
        } while (dinhdang(ho_ten) == false);
        ngay_gui.nhap1();
        do {
            cout << "Nhap vao cmnd: ";
            cin >> cmnd;
            if (cmnd != 9 && cmnd != 12) {
                cout << "cmnd khong hop le vui long nhap lai: " << endl;
            }
        } while (cmnd != 9 && cmnd != 12);
        do {
            cout << "Nhap so tien gui: ";
            cin >> tien_gui;
            if (tien_gui <= 0) {
                cout << "so tien gui khong hop le: ";
            }

        } while (tien_gui <= 0);
       
    }
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
    void tim_kiem_cmnd(int Cmnd,vector<so_tiet_kiem>a){
        vector<so_tiet_kiem>ans;
        for (auto x : a) {
            if (x.cmnd == Cmnd) {
                x.xuat();
                return;
            }
        }
    }
    void tim_kiem_ma_so(string maso, vector<so_tiet_kiem>a) {
        for (auto x : a) {
            if (x.ma == maso) {
                x.xuat();
                return;
            }
        }
    }
    static bool cmp1(const so_tiet_kiem s1, const so_tiet_kiem s2) {
        return s1.tien_gui > s2.tien_gui;
    }
    static bool cmp2(const so_tiet_kiem s1,const so_tiet_kiem s2) {
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
    void sap_xep_theo_tien(vector<so_tiet_kiem>& v) {
        sort(v.begin(), v.end(), cmp1);
    }
    void sap_xep_theo_ngay(vector<so_tiet_kiem>& v) {
        sort(v.begin(), v.end(), cmp2);
    }
    vector<so_tiet_kiem> liet_ke(int ngay,int thang,int nam,vector<so_tiet_kiem>a) {
        vector<so_tiet_kiem>result;
        for (auto x : a) {
            if (x.ngay_gui.ngay == ngay && x.ngay_gui.thang == thang && x.ngay_gui.nam == nam) {
                result.push_back(x);
            }
        }
        return result;
    }

};
int main()
{
    int n; cin >> n;
    vector<so_tiet_kiem>A(n);
    for (int i = 0; i < n; i++) {
        A[i].nhap();
    }
    cout << "**tim kiem so chung minh 1234: ";
   A[0].tim_kiem_cmnd(1234, A);
   cout << endl;
   cout << "**tim kiem ma so 23e3";
   A[0].tim_kiem_ma_so("23e3", A);
   cout << "**sap xep theo tien gui: ";
   A[0].sap_xep_theo_tien(A);
   for (auto x : A) {
       x.xuat();
   }
   cout << "**sap xep theo ngay";
   A[0].sap_xep_theo_ngay(A);
   for (auto x : A) {
       x.xuat();
   }
   vector<so_tiet_kiem>ans1 = A[0].liet_ke(12, 2, 2024, A);
   cout << "**Nhung so tiet kiem lap vao ngay 12/2/2024: ";
   for (auto x : ans1) {
       x.xuat();
   }


    

}

