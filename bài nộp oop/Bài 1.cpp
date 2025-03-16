// Bài 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//Tìm ước chung lớn nhất của phân số
int uoc_chung_lon_nhat(int a, int b) {
    if (a == 0) return b;
    return uoc_chung_lon_nhat(b % a, a);

}
//Khai báo hàm class cho phân số gồm tử và mẫu
class phan_so {
public:
    int tu;
    int mau;
    //Nhập phân số 
    void nhap_phan_so() {
        int Tu, Mau;
        do {

            cin >> Tu;
            cin >> Mau;

        } while (Mau == 0);

        tu = Tu;
        mau = Mau;

    }
    //Rút gọn phân số
    void rut_gon() {
        int m = uoc_chung_lon_nhat(tu, mau);
        tu /= m;
        mau /= m;
        if (tu > 0 && mau < 0) {
            tu *= -1;
            mau *= -1;
        }
        else if (tu < 0 && mau < 0) {
            tu *= -1;
            mau *= -1;
        }
    }

    //xuat phan so
    int xuat_phan_so() {
        if (tu == 0) {
            cout << tu;
            return 0;
        }
        cout << tu << "/" << mau;
    }
};
int main()
{
    phan_so a;
    a.nhap_phan_so();
    a.rut_gon();
    a.xuat_phan_so();

}
