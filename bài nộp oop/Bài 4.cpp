
#include <iostream>
#include <iomanip>
#include <algorithm>
#define MAX 100
using namespace std;
//tinh giai thuc bang de quy
//input so nguyen x output giai thua cua x 
int tinhgiaithua(int x) {
    if (x == 1) return x;
    return tinhgiaithua(x - 1) * x;
}
class tinh_sin {
private:
    float x;
    int n;
public:
    //nhap phan gia tri cua x va n
    void nhap() {
        do {
            cin >> x >> n;
            if (n < 0) {
                cout << "vui long nhap lai";
            }

        } while (n < 0);
    }
    //tao ham tinh sin theo cong thuc
    float tinhsin() {
        float ketqua = 0;
        for (int i = 0; i <= n; i++) {
            ketqua += (pow(-1, i) * pow(x, 2 * i + 1)) / tinhgiaithua(2 * i + 1);

        }
        return ketqua;
    }



};
int main()
{
    tinh_sin a;
    a.nhap();
    cout << a.tinhsin() << setprecision(5);

    return 0;
}
