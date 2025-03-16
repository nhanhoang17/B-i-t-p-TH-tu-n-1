#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#define MAX 1000000
using namespace std;

class tim_mang_con {
private:
    int A[MAX];
    int B[MAX];
    int a, b;

public:
    // Ham nhap_mang: Nhap du lieu cho mang A va B
    // Input:
    //   - Hai so nguyen a va b (so phan tu cua mang A va B).
    //   - Mang A gom a phan tu.
    //   - Mang B gom b phan tu.
    // Output:
    //   - Khong co output truc tiep. Ham nay chi doc du lieu va luu vao cac mang A va B.
    void nhap_mang() {
        cin >> a >> b;

        for (int i = 0; i < a; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < b; i++) {
            cin >> B[i];
        }
    }

    // Ham tim_mang: Tim kiem xem mang A co phai la mang con cua mang B hay khong
    // Input:
    //   - Mang A va B da duoc nhap tu ham nhap_mang().
    // Output:
    //   - Neu tim thay mang A la mang con cua B:
    //     + In ra so lan mang A xuat hien trong B.
    //     + In ra cac vi tri bat dau cua mang A trong B.
    //   - Neu khong tim thay:
    //     + In ra thong bao "khong tim thay".
    void tim_mang() {
        int count1 = 0;
        int count2 = 0;
        vector<int> ans;

        for (int i = 0; i < b; i++) {
            for (int j = 0; j < a; j++) {
                if (A[j] == B[i + j]) {
                    count1++;
                }
            }
            if (count1 == a) {
                ans.push_back(i);
                count2++;
            }
            count1 = 0;
        }

        if (count2 > 0) {
            cout << count2;
            cout << endl;
            for (auto x : ans) {
                cout << x << " ";
            }
        }
        else {
            cout << "khong tim thay";
        }
    }
};


int main() {
    tim_mang_con a;
    a.nhap_mang();
    a.tim_mang();
}