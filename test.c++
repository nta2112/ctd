#include<iostream>
#include<string>
using namespace std;

struct nhanvien
{
    
    int ID;
    string name;
    float heso;
    float luong;
    int tuoi;
    void tbluong(){
        cout << "luong tb la: " << luong*heso <<endl;
    }
};
int main(void) {
	nhanvien nv;
    cin >> nv.ID;
    cin.ignore();
    getline(cin, nv.name);
    cin >> nv.heso;
    cin >> nv.luong;
    cin >> nv.tuoi;
    cout << nv.ID <<endl;
    cout << nv.name <<endl;
    cout << nv.heso <<endl;
    cout << nv.luong <<endl;
    cout << nv.tuoi <<endl;
    nv.tbluong();
	return 0;
}