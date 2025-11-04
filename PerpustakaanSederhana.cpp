#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct anggota{
    int idanggota;
    string nama;
    string alamat;
    int tanggal;
    int bulan;
    int tahun;
    string email;
    int status;
};

int HitungUrutan(string Tahun,string Bulan,string Tanggal){
    ifstream file("anggota.txt"); 
    string line;
    int count = 0;
    string prefix = Tahun + Bulan + Tanggal;

    while (getline(file, line)) { 
        if (line.find(prefix) != string::npos) { 
            count++; 
        }
    }

    file.close();
    return count + 1; 
}


void TambahAnggota(){
    anggota x;
    cout << "Masukkan ID Anggota : ";
    cin>>x.idanggota;
    cout << "Masukkan Nama : ";
    cin.ignore();
    getline(cin,x.nama);
    cout << "Masukkan Alamat : ";
    getline(cin,x.alamat);
    cout << "Masukkan Tanggal Lahir : ";
    cin >> x.tanggal;
    cout << "Masukkan Bulan Lahir : ";
    cin >> x.bulan;
    cout << "Masukkan Tahun Lahir : ";
    cin >> x.tahun;
    cout << "Masukkan Email : ";
    cin.ignore();
    getline(cin,x.email);
    cout << "Apakah Siswa masih aktif (1=aktif, 0=tidak aktif) : ";
    cin >> x.status;
    string strTahun = to_string(x.tahun);
    string strBulan = to_string(x.bulan);
    string strTanggal = to_string(x.tanggal);
    int urutan= HitungUrutan(strTahun,strBulan,strTanggal);

    string urutanString = to_string(urutan); //perubahan st
    while (urutanString.length() < 3) {
    urutanString = "0" + urutanString;
}
string kodeanggota = strTahun + strBulan + strTanggal + urutanString;

ofstream fileOutput("anggota.txt",ios::app);
fileOutput << x.idanggota << ";" << kodeanggota << ";" << x.nama << ";" << x.tanggal << "-" << x.bulan << 
             "-" << x.tahun << ";" << x.alamat << ";" << x.email << ";" << x.status<<endl;
fileOutput.close();
cout << "Data Siswa berhasil ditambahkan!";

}

int main(){
    TambahAnggota();
}

