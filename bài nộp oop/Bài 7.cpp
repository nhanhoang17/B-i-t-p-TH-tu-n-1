
#include <iostream>
#include <iomanip>
#include <string>
#include<vector>
#include <algorithm>
#include <regex>
using namespace std;
//check dinh dang cua ten khi nhap vao
//input ho va ten output true hoac false
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
//kiem tra ten co chua cac ky tu so hay ky tu dac biet khong
//input ho va ten output true hoac false
bool isValidName(const string& name) {
	if (name.length() < 3 || name.length() > 50) {
		return false;
	}

	for (char c : name) {
		if (!(isalpha(c) || c == ' ')) {
			return false;
		}
	}
	return true;
}
//chuyen doi thanh chu thuong
//input chuoi can chuyen doi output chuoi da chuyen doi
string toLowerCase(string str) {
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}
class hoc_sinh {
private:
	string ho_ten;
	float diem_toan;
	float diem_van;
	float diem_anh;
	float diem_trung_binh;
	string phan_loai;

public:
	//nhap thong tin cua hoc sinh
	void nhap() {
		do {
			cout << "Nhap ho ten: ";
			cin.ignore();
			getline(cin, ho_ten);
			cout << "Nhap diem toan : ";
			cin >> diem_toan;
			cout << "Nhap diem van : ";
			cin >> diem_van;
			cout << "Nhap diem anh : ";
			cin >> diem_anh;
			if (diem_toan < 0 || diem_van < 0 || diem_anh < 0 || diem_anh>10 || diem_van>10 || diem_toan>10 || dinhdang(ho_ten) == false) {
				cout << "Vui long nhap lai :" << endl;
			}
		} while (diem_toan < 0 || diem_van < 0 || diem_anh < 0 || diem_anh>10 || diem_van>10 || diem_toan>10 || dinhdang(ho_ten) == false);
		diem_trung_binh = ((2 * diem_toan) + diem_van + diem_anh) / 4;
	}
	//phan loai cac hoc sinh bang diem trung binh
	//input diem trung binh cua hoc sinh
	void phanloai() {
		if (diem_trung_binh >= 9) {
			phan_loai = "Xuất sắc";
		}
		else if (diem_trung_binh >= 8 && diem_trung_binh < 9) {
			phan_loai = "Giỏi";
		}
		else if (diem_trung_binh >= 6.5 && diem_trung_binh < 8) {
			phan_loai = "Khá";
		}
		else if (diem_trung_binh >= 5 && diem_trung_binh < 6.5) {
			phan_loai = "Trung bình";
		}
		else if (diem_trung_binh < 5) {
			phan_loai = "Yếu";
		}
	}
	//so sanh 2 hoc sinh dua tren diem trung binh
	static  bool cmp(hoc_sinh hs1, hoc_sinh hs2) {
		return hs1.diem_trung_binh < hs2.diem_trung_binh;
	}
	//tim diem trung binh cao nhat bang cach sort roi lay hoc sinh cuoi
	//input danh sach cac hoc sinh
	void tim_diem_trung_binh_cao_nhat(vector<hoc_sinh>a) {

		sort(a.begin(), a.end(), cmp);
		hoc_sinh hs_max = a.back();
		hs_max.in();

	}
	//tim hoc sinh theo ten
	//input danh sach cac hoc sinh can tim output hoc sinh can tim
	vector<hoc_sinh> tim_theo_ten(const vector<hoc_sinh>a, string name) {
		vector<hoc_sinh>result;
		string lowername = toLowerCase(name);
		for (const auto hs : a) {
			string lowera = toLowerCase(hs.ho_ten);
			if (lowera.find(lowername) != string::npos) {
				result.push_back(hs);
			}
		}
		return result;

	}
	//tim danh sach hoc sinh do toan nhat
	//input danh sach hoc sinh output danh sach cac hoc sinh do toan
	vector<hoc_sinh> tim_min_toan(vector<hoc_sinh>a) {
		vector<hoc_sinh>result;
		float m = 11;
		for (int i = 0; i < a.size(); i++) {
			m = min(m, a[i].diem_toan);
		}

		for (auto x : a) {
			if (m == x.diem_toan) {
				result.push_back(x);
			}
		}
		return result;
	}
	//xuat ra danh sach hoc sinh
	void in() {
		cout << "ho ten: " << ho_ten << endl << "diem toan: " << diem_toan << endl << "diem van: " << diem_van << endl << "diem anh: " << diem_anh << endl << "diem trung binh: " << diem_trung_binh << endl << "xep loai: " << phan_loai << endl;
	}
};
int main()
{
	int n = 3;

	vector<hoc_sinh>danhsach;
	vector<hoc_sinh>searchname;
	vector<hoc_sinh>minmath;
	hoc_sinh hs1, hs2, hs3;
	cout << "Nhap thong tin hoc sinh thu 1: " << endl;
	hs1.nhap();
	cout << "Nhap thong tin hoc sinh thu 2: " << endl;
	hs2.nhap();
	cout << "Nhap thong tin hoc sinh thu 3: " << endl;
	hs3.nhap();
	hs1.phanloai();
	hs2.phanloai();
	hs3.phanloai();
	danhsach.push_back(hs1);
	danhsach.push_back(hs2);
	danhsach.push_back(hs3);
	cout << "------------------------" << endl;
	cout << "danh sach hoc sinh " << endl;
	for (auto x : danhsach) {
		x.in();

	}
	cout << "------------------------" << endl;
	cout << "hoc sinh diem cao nhat: " << endl;
	hs1.tim_diem_trung_binh_cao_nhat(danhsach);
	cout << endl;

	cout << "------------------------" << endl;
	cout << "tim kiem theo ten nhan: " << endl;
	searchname = hs1.tim_theo_ten(danhsach, "nhan");
	for (auto x : searchname) {
		x.in();
	}
	minmath = hs1.tim_min_toan(danhsach);
	cout << "------------------------" << endl;
	cout << "danh sach hoc sinh dot toan " << endl;
	for (auto x : minmath) {
		x.in();
	}



}

