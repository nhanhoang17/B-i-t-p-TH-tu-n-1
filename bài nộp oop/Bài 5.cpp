
#include <iostream>
#include <iomanip>
#include <algorithm>
#define MAX 100
using namespace std;
//check nam nhuan
//input nhap vao nam output tra ve dung khi nam do la nam nhuan hoac sai khi khong
bool is_nam_nhuan(int nam) {
    if (nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0) {
        return true;
    }
    return false;
}
//ham xac dinh ngay trong thang do
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
class ngay_trong_nam {
private:
    int ngay;
    int thang;
    int nam;
public:
    //nhap ngay thang nam
    void nhap() {
        do {
            cin >> ngay >> thang >> nam;
            if (thang > 12 || ngay <= 0 || ngay > ngay_theo_thang(nam, thang) || nam <= 0 || thang <= 0) {
                cout << "Vui long nhap lai";
            }
        } while (thang > 12 || ngay <= 0 || ngay > ngay_theo_thang(nam, thang) || nam <= 0 || thang <= 0);

    }
    //ham xac dinh ngay tiep theo
    int xac_dinh_ngay_tiep_theo() {

        if (ngay == ngay_theo_thang(nam, thang)) {
            return 1;
        }


        return ++ngay;
    }
    //ham xac dinh ngay truoc do
    int xac_dinh_ngay_truoc() {
        if (ngay == 1) {
            return ngay_theo_thang(nam, --thang);
        }
        return --ngay;
    }
    //ham xac dinh thu tu ngay do trong nam
    int ngay_thu_may_trong_nam() {
        int ketqua = 0;
        for (int i = 1; i < thang; i++) {
            ketqua += ngay_theo_thang(nam, i);
        }
        ketqua += ngay;
        return ketqua;
    }


};
int main()
{
    ngay_trong_nam n;
    n.nhap();
    ngay_trong_nam a;
    a = n;
    cout << n.xac_dinh_ngay_truoc() << endl;

    cout << a.xac_dinh_ngay_tiep_theo() << endl;
    cout << n.ngay_thu_may_trong_nam() << endl;

}
