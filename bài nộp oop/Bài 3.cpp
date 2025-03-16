
#include <iostream>
#include <iomanip>
#include <algorithm>
#include<vector>
#define MAX 1000000
using namespace std;
//Tìm ước chung lớn nhất của phân số
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
    //xuat phan so da xu ly ra 
    int xuat_phan_so() {
        if (tu == 0) {
            cout << tu;
            return 0;
        }
        cout << tu << "/" << mau;
    }


};
//bội chung nhỏ nhất
//input hai so nguyen a,b output boi chung nho nhat cua a va b
int boi_chung_nho_nhat(int a, int b) {
    return (a * b) / uoc_chung_lon_nhat(a, b);

}
//tinh tong hai phan so
//input phan so p1 va p2 output tong cua p1 p2
phan_so operator+(phan_so p1, phan_so p2) {

    int mau_chung = boi_chung_nho_nhat(p1.mau, p2.mau);
    p1.tu *= (mau_chung / p1.mau);
    p2.tu *= (mau_chung / p2.mau);
    p1.tu += p2.tu;
    p1.mau = mau_chung;
    p1.rut_gon();
    return p1;


}
//hieu hai phan so
//input phan so p1 va p2 output hieu cua p1 p2
phan_so operator-(phan_so p1, phan_so p2) {

    int mau_chung = boi_chung_nho_nhat(p1.mau, p2.mau);
    p1.tu *= (mau_chung / p1.mau);
    p2.tu *= (mau_chung / p2.mau);
    p1.tu -= p2.tu;
    p1.mau = mau_chung;
    p1.rut_gon();
    return p1;


}
//tich hai phan so
//input phan so p1 va p2 output tich cua p1 p2
phan_so operator*(phan_so p1, phan_so p2) {

    p1.tu *= p2.tu;
    p1.mau *= p2.mau;
    int m = uoc_chung_lon_nhat(p1.mau, p1.tu);
    p1.tu /= m;
    p1.mau /= m;
    return p1;



}
//thuong giua hai phan so
//input phan so p1 va p2 output thuong cua p1 p2
phan_so operator/(phan_so p1, phan_so p2) {

    p1.tu *= p2.mau;
    p1.mau *= p2.tu;
    int m = uoc_chung_lon_nhat(p1.mau, p1.tu);
    p1.tu /= m;
    p1.mau /= m;
    return p1;



}
int main()
{
    phan_so a, b;
    a.nhap_phan_so();
    b.nhap_phan_so();
    cout << "tong 2 phan so: " << endl;
    a = a + b;
    a.xuat_phan_so();
    phan_so c, d;
    c.nhap_phan_so();
    d.nhap_phan_so();
    cout << "hieu 2 phan so: " << endl;
    c = c - b;
    c.xuat_phan_so();
    phan_so m, n;
    m.nhap_phan_so();
    n.nhap_phan_so();
    cout << "tich 2 phan so: " << endl;
    m = m * n;
    m.xuat_phan_so();
    phan_so g, k;
    g.nhap_phan_so();
    k.nhap_phan_so();
    cout << "thuong 2 phan so: " << endl;
    g = g / k;
    g.xuat_phan_so();


}
