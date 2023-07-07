#include<iostream>
#include<string>
using namespace std;

struct hocsinh
{
    
    int ID;
    string name;
    int tuoi;
    string sj;
    float gk;
    float ck;
    void diem(){
        cout << "Diem mon hoc la: " << (gk+ck)/2 <<endl;
    }
};
int main(void) {
	hocsinh hs;
    cout<<"nhap id "; cin >> hs.ID;
    cin.ignore();
    cout<<"nhap ten "; getline(cin, hs.name);
    cout<<"nhap tuoi "; cin >> hs.tuoi;
    cin.ignore();
    cout<<"nhap mon hoc "; getline(cin, hs.sj);
    cout<<"nhap diem gk "; cin >> hs.gk;
    cout<<"nhap diem ck "; cin >> hs.ck;

    cout << hs.ID <<endl;
    cout << hs.name <<endl;
    cout << hs.tuoi <<endl;
    cout << hs.sj <<endl;
    cout << hs.gk <<endl;
    cout << hs.ck <<endl;
    hs.diem();
	return 0;
}