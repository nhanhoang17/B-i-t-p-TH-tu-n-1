
#include <iostream>
#include <iomanip>
#include <algorithm>
#include<vector>
#define MAX 1000000
using namespace std;
//Tìm ước chung lớn nhất của phân số
//input tu va mau output uoc chung lon nhat cua tu va mau
int uoc_chung_lon_nhat(int a, int b) {
    if (a == 0) return b;
    return uoc_chung_lon_nhat(b % a, a);

}
//lập hàm class khai báo đối tượng mẫu và tử của phân số
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
            if (Mau == 0) {
                cout << "enter the input again :";
            }

        } while (Mau == 0);

        tu = Tu;
        mau = Mau;

    }
    //rut gon phan so 
    //input tu va mau
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
    //so sanh hai phan so
    //input phan so 1 va 2
    void so_sanh(phan_so p1, phan_so p2) {
        float k = (float)p1.tu / p1.mau;
        float h = (float)p2.tu / p2.mau;
        if (k > h) {
            p1.rut_gon();
            p1.xuat_phan_so();
        }
        else if (k < h) {
            p2.rut_gon();
            p2.xuat_phan_so();
        }
        else {
            p2.rut_gon();
            p2.xuat_phan_so();
        }
    }

};
int main() {
    phan_so a, b;
    a.nhap_phan_so();
    b.nhap_phan_so();
    a.so_sanh(a, b);
}

